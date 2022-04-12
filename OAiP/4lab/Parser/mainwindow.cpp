#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <regex>
#include <QDebug>
#include <stack>
#include <QLibrary>
#include <Windows.h>

class __declspec(dllimport) String
{
    private:
        char* str;
        size_t size;
        size_t capacity;
    public:
         String();
         ~String();
};
__declspec(dllimport) class String* CreateObject();


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->updateInfoButton, SIGNAL(clicked()), this, SLOT(updateInfoButton_clicked()));
    connect(ui->openFileButton, SIGNAL(clicked()), this, SLOT(openFileButton_clicked()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBox_currentIndexChanged(int)));

    const int size = 8;

    QString arr[size] = { "Variables", "Classes and Arrays", "Functions", "Variable's changes",
                      "Local var-s", "Overload functions", "Depth-branch", "Logic errors" };

    for(int i = 0; i < size; ++i){
        ui->comboBox->addItem(arr[i]);
    }

    //"E:/labs/labs2sem/4lab/build-StringClass_DLL-Desktop_Qt_5_9_9_MSVC2015_32bit-Debug/debug/StringClass_DLL.dll"

    //****************work with DLL******************************//
    HINSTANCE load;
    load = LoadLibrary(L"E:/labs/labs2sem/4lab/build-StringClass_DLL-Desktop_Qt_5_9_9_MSVC2015_32bit-Debug/debug/StringClass_DLL.dll");

    if(!load){
        return;
    }
    String *ptr = (String*)GetProcAddress(load, "CreateObject");

    typedef void (String::*pConstructor)();

    pConstructor constructor;
    //??0String@@QAE@XZ - имя коструктора в dll файле
    (FARPROC &)constructor = GetProcAddress(load, "??0String@@QAE@XZ");

    // Создаём объект на стеке
    char _c[12];
    String &c = *(String *)_c;

    // Создаём объект в куче
    char *_pc = new char[12];
    String *pc = (String *)_pc;

    // Явно вызываем конструкторы для обоих объектов
    (c.*constructor)();
    (pc->*constructor)();

    typedef void (String::*pDestructor)();

    pDestructor destructor;
    //??1String@@QAE@XZ - имя деструктора в dll файле
    (FARPROC &)destructor = GetProcAddress(load, "??1String@@QAE@XZ");

    // Явно вызываем деструкторы для обоих объектов
    (c.*destructor)();
    (pc->*destructor)();


    FreeLibrary(load);
    //****************work with DLL******************************//
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::getVariablesInfo()
{
    //clear old values
    varInfo.clear();
    varNames.clear();


    std::regex variables_init_regex("((size_t|int|double|float|char)\\s*[\\*]*)\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    std::smatch res;

    std::string str = codeText.toStdString();

    while(std::regex_search(str, res, variables_init_regex)){
        varInfo.push_back(res.str());
        varNames.push_back(res[3]);
        str = res.suffix();
    }
}

int* MainWindow::getClassesAndArraysInfo()
{
    std::regex classes_regex("(class|struct)\\s*(\\w+)\\s*\\{");
    std::smatch res;

    std::string str = codeText.toStdString();

    classesNames.clear();
    arraysNames.clear();
    objectsNames.clear();

    while(std::regex_search(str, res, classes_regex)){
        classesNames.push_back(res[2]);
        str = res.suffix();
    }

    str = codeText.toStdString(); //reinit string

    size_t class_count = 0;

    //erase constructors and destructors
    //for not including it to class_count
    size_t size = classesNames.size();
    for(size_t i = 0; i < size; ++i){
        int pos = str.find(classesNames[i]);
        //find closed bracket using stack
        std::stack<char> brackets_stack;
        brackets_stack.push('{');
        size_t first_bracket = str.find('{', pos);
        size_t last_bracket, counter = first_bracket + 1;
        while(!brackets_stack.empty() && counter < str.size()){
            if(str[counter] == '{'){
                brackets_stack.push('{');
            }
            if(str[counter] == '}'){
                brackets_stack.pop();
            }
            ++counter;
        }
        last_bracket = counter - 1;
        try {
            if(counter != str.size()) str.erase(first_bracket, last_bracket - first_bracket + 1); //erase body of class
        } catch (...) {
            qDebug() << "Exception in erase. function : \"getClassesAndArraysInfo\"";
        }

    }


    //count classes and structs
    size_t pos;
    for(size_t i = 0; i < classesNames.size(); ++i){
        pos = str.find(classesNames[i]);
        while(pos != std::string::npos){
            if(pos > str.find("int main()")) ++class_count; //if object init in main()
            str.erase(pos, classesNames[i].size());
            pos = str.find(classesNames[i]);
        }
    }



    //add objects names to array
    std::string init_object_regex_str("\\s*[\\*]*\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(int i = 0; i < classesNames.size(); ++i){
        str = codeText.toStdString();
        std::regex init_obj_regex("\\s*" + classesNames[i] + init_object_regex_str);
        while(std::regex_search(str, res, init_obj_regex)){
            objectsNames.push_back(pair<std::string, std::string>(classesNames[i], res[1]));
            str = res.suffix();
        }
    }

    std::regex arrays_decl_regex("\\s*\\w+\\s+(\\w+)\\s*((\\[[\\w]*\\])+)\\s*=?\\s*(\\{[^;]*\\})?\\s*;");

    str = codeText.toStdString(); //reinit string

    while (std::regex_search(str, res, arrays_decl_regex)) {
        arraysNames.push_back(res[1]);
        str = res.suffix();
    }
    size_t array_count = 0;

    str = codeText.toStdString(); //reinit string

    for(size_t i = 0; i < arraysNames.size(); ++i){
        if(str.find(arraysNames[i]) != std::string::npos){  //count arrays
            ++array_count;
            str.erase(str.find(arraysNames[i]), arraysNames[i].size());
        }
    }
    int* nums = new int[2];
    nums[0] = class_count;
    nums[1] = array_count;
    return nums;
}

void MainWindow::getFunctionsInfo()
{
    std::regex functions_regex("\\s*((\\w+)\\s+(\\w+|\\w+[:]{2}\\w+)\\s*\\([\\w, =]*\\))\\s*(\\{([^\\}]*|\\{[\\w ;\\.\\(\\)]*\\})\\}|;)");
    //clear old values
    functionsInfo.clear();
    functionsNames.clear();
    functionsPositions.clear();

    QStringList list = codeText.split("\n");
    std::vector<std::string> str_array;
    for(int i = 0; i < list.size(); ++i){
        str_array.push_back(list[i].toStdString());
    }

    std::smatch res;

    std::string str = codeText.toStdString();


    std::vector<bool> visited(str_array.size(), false);
    while (std::regex_search(str, res, functions_regex)) {
        if(res[3] != "if"){
            for(size_t i = 0; i < str_array.size(); ++i){
                if(str_array[i].find(res[1]) != std::string::npos && !visited[i]){
                    functionsPositions.push_back(i);
                    visited[i] = true;
                    break;
                }
            }
            functionsInfo.push_back(res[1]);
            functionsNames.push_back(res[3]);
        }
        str = res.suffix();
    }
}

void MainWindow::getVarsChanges()
{
    getVariablesInfo();
    getClassesAndArraysInfo();
    QStringList list = codeText.split("\n");
    std::vector<std::string> str_array;
    for(int i = 0; i < list.size(); ++i){
        str_array.push_back(list[i].toStdString());
    }

    QString text = "Rows of changes:\n";

    std::string change_regex_str = "\\s*=\\s+[\\w \\+\\*/\\-%\\(\\)]+\\s*;";
    std::string dec_inc_regex_str = "(\\+\\+|\\-\\-)+";

    std::regex variables_init_regex("((size_t|int|double|float|char)\\s*[\\*]*)\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");

    bool isUsed;
    //for variables
    std::smatch res;
    for(size_t i = 0; i < varNames.size(); ++i)
    {
        isUsed = false;
        std::regex regex("\\b\\s*" + varNames[i] + change_regex_str);
        std::regex inc_dec_regex("\\b\\s*" + dec_inc_regex_str + varNames[i] + dec_inc_regex_str);
        //parse each string
        for(int j = 0; j < str_array.size(); ++j)
        {
            if(std::regex_search(str_array[j], res, regex) || std::regex_search(str_array[j], res, inc_dec_regex))
            {
                //if it's not initialization
                if(!std::regex_search(str_array[j], res, variables_init_regex))
                {
                    text += QString::fromStdString(varNames[i]) + ":" + QString::number(j + 1) + "\n";
                }
            }
        }
        if(isUsed) text += "\n";
    }
    //for arrays
    std::regex arrays_decl_regex("\\s*\\w+\\s+(\\w+)\\s*((\\[\\w*\\])+)\\s*=?\\s*(\\{[^;]*\\})?\\s*;");
    std::string change_array_regex("\\s*(\\[\\s*\\w+\\s*\\])+\\s*=\\s*[^;];");
    for(size_t i = 0; i < arraysNames.size(); ++i)
    {
        isUsed = false;

        std::regex regex("\\b\\s*" + arraysNames[i] + change_array_regex);

        //parse each string
        for(int j = 0; j < str_array.size(); ++j)
        {
            if(std::regex_search(str_array[j], res, regex))
            {
                //if it's not initialization
                if(!std::regex_search(str_array[j], res, arrays_decl_regex))
                {
                    text += QString::fromStdString(arraysNames[i]) + ":" + QString::number(j + 1) + "\n";
                }
            }
        }
        if(isUsed) text += "\n";
    }
    //for objects
    std::string class_init_regex_str("\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < objectsNames.size(); ++i)
    {
        //qDebug() << QString::fromStdString(classesNames[i] + change_regex_str) << "\n";
        isUsed = false;
        std::regex regex("\\b\\s*" + objectsNames[i].second + change_regex_str);
        std::regex init_regex("\\b\\s*" + objectsNames[i].first + "\\s*[\\*]*\\s*" +
                              objectsNames[i].second + class_init_regex_str);
        //parse each string
        for(int j = 0; j < str_array.size(); ++j)
        {
            //qDebug() << QString::fromStdString(str_array[j]) << "\n";
            if(std::regex_search(str_array[j], res, regex))
            {
                //if it's not initialization
                if(!std::regex_search(str_array[j], res, init_regex))
                {
                    text += QString::fromStdString(objectsNames[i].second) + ":" + QString::number(j + 1) + "\n";
                }
            }
        }
        if(isUsed) text += "\n";
    }
    ui->textBrowser->setText(text);
}

void MainWindow::getLocalVarsInfo()
{
    getClassesAndArraysInfo();
    QStringList str = codeText.split('\n');
    std::vector<std::string> rows;
    for(int i = 0; i < str.size(); ++i){
        rows.push_back(str[i].toStdString());
    }
    int balance = 0;
    std::vector<int> position;
    std::regex variables_init_regex("((size_t|int|double|float|char)\\s*[\\*]*)\\s*([\\w]+)\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < rows.size(); ++i){
        for(size_t j = 0; j < rows[i].size(); ++j){
            if(rows[i][j] == '{'){
                ++balance;
            }
            if(rows[i][j] == '}'){
                --balance;
            }
        }
        if(std::regex_search(rows[i], variables_init_regex)){
            if(balance != 0){
                position.push_back(i);
            }
        }
    }
    std::string class_init_regex_str("\\s*(=\\s*[\\w+ ]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?;");
    for(size_t i = 0; i < rows.size(); ++i){
        for(size_t j = 0; j < rows[i].size(); ++j){
            if(rows[i][j] == '{'){
                ++balance;
            }
            if(rows[i][j] == '}'){
                --balance;
            }
        }
        if(balance != 0){
            for(size_t k = 0; k < objectsNames.size(); ++k){
                std::regex obj_regex(objectsNames[k].first + "\\s*" + objectsNames[k].second + class_init_regex_str);
                if(std::regex_search(rows[i], obj_regex)){
                    position.push_back(i);
                }
            }
        }

    }

    QString text = "Count of local var-s: " + QString::number(position.size()) + "\n";
    text += "Rows of declaration:\n";
    for(int i = 0; i < position.size(); ++i){
        text += QString::number(position[i]) + "\n";
    }
    ui->textBrowser->setText(text);
}

void MainWindow::getOverloadFunctionsInfo()
{
    getFunctionsInfo();
    QStringList str = codeText.split('\n');
    std::vector<std::string> rows;
    for(int i = 0; i < str.size(); ++i)
    {
        rows.push_back(str[i].toStdString());
    }

    int count_of_overload_funcs = 0;
    std::vector<int> positions;
    std::vector<bool> visited(functionsNames.size(), false);
    for(int i = 0; i < functionsNames.size(); ++i)
    {
        for(int j = i + 1; j < functionsNames.size(); ++j)
        {
            //if they overloaded
            if(functionsNames[i] == functionsNames[j] && !visited[i] && !visited[j])
            {
                count_of_overload_funcs += 2;
                visited[i] = visited[j] = true;
                positions.push_back(functionsPositions[i]);
                positions.push_back(functionsPositions[j]);
            }
        }
    }
    QString text = "Number of overloaded functions:" + QString::number(count_of_overload_funcs) + "\n";
    text += "rows:\n";
    for(int i = 0; i < positions.size(); ++i){
        text += QString::number(positions[i]) + "\n";
    }
    ui->textBrowser->setText(text);
}

void MainWindow::getDepthBranch()
{
    std::string str = codeText.toStdString();
    std::vector<int> depthArray;
    int currAmount = 0;
    std::stack<char> pos;
    for(int i = 0; i < str.size() - 5; ++i){
        if(str[i] != 'e' && str[i + 1] != 'l' && str[i + 2] != 's' && str[i + 3] != 'e'
                && str[i + 4] == 'i' && str[i + 5] == 'f'){
            ++currAmount;
            pos.push('{');
        }
        if(str[i] == 'e' && str[i + 1] == 'l' && str[i + 2] == 's' && str[i + 3] == 'e'
                && str[i + 4] == 'i' && str[i + 5] == 'f'){
            //++currAmount;
            pos.push('{');
        }
        if(!pos.empty() && str[i] == '}'){
            depthArray.push_back(currAmount);
            --currAmount;
            pos.pop();
        }
    }
    QString text;
    for(int i = 0; i < depthArray.size(); ++i){
        text += QString::number(depthArray[i]) + "\n";
    }
    ui->textBrowser->setText(text);

}

void MainWindow::getLogicErrors()
{
    std::regex logic_error_whileF_regex("\\s*while\\(\\s*false\\s*\\)");

    QStringList list = codeText.split('\n');
    std::vector<std::string> code;
    for(size_t i = 0; i < list.size(); ++i){
        code.push_back(list[i].toStdString());
    }

    QString text;
    std::smatch res;
    for(size_t i = 0; i < code.size(); ++i){
        if(std::regex_search(code[i], logic_error_whileF_regex)){
            text += "while(false){...} : " + QString::number(i) + "\n";
        }
    }

    std::regex logic_error_if_true_regex("if\\(\\s*true\\s*\\)");
    for(size_t i = 0; i < code.size(); ++i){
        if(std::regex_search(code[i], logic_error_if_true_regex)){
            text += "if(true){...} : " + QString::number(i) + "\n";
        }
    }

    std::regex logic_error_if_false_regex("if\\(\\s*false\\s*\\)");
    for(size_t i = 0; i < code.size(); ++i){
        if(std::regex_search(code[i], logic_error_if_false_regex)){
           text += "if(false){...} : " + QString::number(i) + "\n";
        }
    }

    std::regex logic_error_empty_if_regex("if\\(\\s*\\)");
    for(size_t i = 0; i < code.size(); ++i){
        if(std::regex_search(code[i], logic_error_empty_if_regex)){
            text += "if(){...} : " + QString::number(i) + "\n";
        }
    }
    ui->textBrowser->setText(text);
}




void MainWindow::openFileButton_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, "Выберите файл", "E:\\", "*.cpp");

    QFile file(name);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        codeText = stream.readAll();
        ui->textEdit->setText(codeText);
        comboBox_currentIndexChanged(ui->comboBox->currentIndex());
    }
    else {
        QMessageBox::warning(this, "Error", "Oops...File not opened.");
    }

}

void MainWindow::comboBox_currentIndexChanged(int index)
{
    codeText = ui->textEdit->toPlainText();
    QString text;   //output text
    if(index == Variables){
        getVariablesInfo();
        size_t int_count = 0, char_count = 0, double_count = 0, float_count = 0, size_t_count = 0;
        for(auto& it : varInfo){    //count number of variables of each type
            if(it.find("int") != std::string::npos){
                ++int_count;
            }
            if(it.find("float") != std::string::npos){
                ++float_count;
            }
            if(it.find("double") != std::string::npos){
                ++double_count;
            }
            if(it.find("char") != std::string::npos){
                ++char_count;
            }
            if(it.find("size_t") != std::string::npos){
                ++size_t_count;
            }
            text += QString::fromStdString(it) + "\n";
        }
        text += "amount:\nint:" + QString::number(int_count) + "\nfloat:" + QString::number(float_count)
                + "\ndouble:" + QString::number(double_count) + "\nchar:" + QString::number(char_count) + "\nsize_t:" + QString::number(size_t_count);
    }
    else if(index == ObjectsAndArrays){
        int* nums = getClassesAndArraysInfo();

        text += "Objects:" + QString::number(nums[0]) + "\n";
        text += "Arrays:" + QString::number(nums[1]) + "\n";

        delete[] nums;
    } else if(index == Functions){
        getFunctionsInfo();
        text = "Prototypes:\n";
        for(const auto& it : functionsInfo){
            text += QString::fromStdString(it) + ";\n";
        }
    } else if(index == Variables_changes){
        getVarsChanges();
    } else if(index == Local_vars){
        getLocalVarsInfo();
    } else if(index == Overload_functions){
        getOverloadFunctionsInfo();
    } else if(index == Depth_branch){
        getDepthBranch();
    } else if(index == Logic_errors) {
        getLogicErrors();
    }

    if(text != "") ui->textBrowser->setText(text);
}

void MainWindow::updateInfoButton_clicked()
{
    comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}


