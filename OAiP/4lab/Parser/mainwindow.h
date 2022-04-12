#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "my_pair.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void getVariablesInfo();

    int* getClassesAndArraysInfo();

    void getFunctionsInfo();

    void getVarsChanges();

    void getLocalVarsInfo();

    void getOverloadFunctionsInfo();

    void getDepthBranch();

    void getLogicErrors();

    enum {
        Variables, ObjectsAndArrays, Functions, Variables_changes,
                              Local_vars, Overload_functions, Depth_branch, Logic_errors
    };



private slots:
    void openFileButton_clicked();

    void comboBox_currentIndexChanged(int index);

    void updateInfoButton_clicked();


private:
    Ui::MainWindow *ui;

    //QStringList codeList;   //store words in textEdit

    QString codeText;   //store current text in textEdit

    std::vector<std::string> varInfo;   //information about variables(type + base value)
    std::vector<std::string> varNames;  //variables names

    std::vector<std::string> classesNames;
    std::vector<pair<std::string, std::string>> objectsNames; //first is class name, second - object name
    std::vector<std::string> arraysNames;

    std::vector<std::string> functionsInfo;
    std::vector<int> functionsPositions;
    std::vector<std::string> functionsNames;
};


#endif // MAINWINDOW_H
