#include "library.h"
#include "./ui_library.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);

    connect(ui->booksButton, SIGNAL(clicked()), this, SLOT(booksButton_clicked()));
    connect(ui->readersBooksButton, SIGNAL(clicked()), this, SLOT(readersBooksButton_clicked()));
    connect(ui->readersButton, SIGNAL(clicked()), this, SLOT(readersButton_clicked()));
    connect(ui->debtorsButton, SIGNAL(clicked()), this, SLOT(debtorsButton_clicked()));
    connect(ui->addReaderButton, SIGNAL(clicked()), this, SLOT(addReaderButton_clicked()));
    connect(ui->addBookButton, SIGNAL(clicked()), this, SLOT(addBookButton_clicked()));
    connect(ui->sortBooksButton, SIGNAL(clicked()), this, SLOT(sortBooksButton_clicked()));
    connect(ui->sortReadersButton, SIGNAL(clicked()), this, SLOT(sortReadersButton_clicked()));
    connect(ui->findBookEdit, SIGNAL(textChanged(const QString&)), this, SLOT(findBookEdit_textChanged(const QString&)));
    connect(ui->findReaderEdit, SIGNAL(textChanged(const QString&)), this, SLOT(findReaderEdit_textChanged(const QString&)));
    connect(ui->changeBookButton, SIGNAL(clicked()), this, SLOT(changeBookButton_clicked()));
    connect(ui->changeReaderButton, SIGNAL(clicked()), this, SLOT(changeReaderButton_clicked()));
    connect(ui->deleteBookButton, SIGNAL(clicked()), this, SLOT(deleteBookButton_clicked()));
    connect(ui->deleteReaderButton, SIGNAL(clicked()), this, SLOT(deleteReaderButton_clicked()));


    ui->bookCodeEdit->setMaxLength(12);
    ui->authorSurnameEdit->setMaxLength(20);
    ui->titleEdit->setMaxLength(25);
    ui->yearEdit->setMaxLength(8);
    ui->languageEdit->setMaxLength(12);

    ui->readerCodeEdit->setMaxLength(15);
    ui->readerFIOEdit->setMaxLength(30);
    ui->addressEdit->setMaxLength(25);
    ui->phoneEdit->setMaxLength(14);


    this->readBooksFromFile();
    this->readReadersFromFile();



}


Library::~Library()
{
    if(booksAmount != 0)  delete [] bookList;
    if(readersAmount != 0) delete [] readerList;
    delete ui;
}

void Library::readBooksFromFile()
{
    QFile file("bookList.txt");

    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);


        QString line; //temporary string
        int count = 0;
        while(!stream.atEnd()){
            line = stream.readLine();   //count lines in file
            if(line != "") count++;
        }

        booksAmount = count;

        stream.seek(0); //set at the begin
        int _code;
        QString _authorSurname;
        QString _title;
        int _year;
        QString _language;

        bookList = new Book[booksAmount];    //allocate memory

        QStringList list;

        for(int i = 0; i < booksAmount; i++){         //write data from file to array
            list = stream.readLine().split('|');
            _code = list[0].toInt();
            _authorSurname = list[1];
            _title = list[2];
            _year = list[3].toInt();
            _language = list[4];

            ui->bookComboBox->addItem(_title);

            bookList[i] = Book(_code, _authorSurname, _title, _year, _language);
        }
        file.close();

    }
}

void Library::readReadersFromFile()
{
    QFile readers("readerList.txt");

    if(readers.open(QIODevice::ReadWrite)){
        QTextStream stream(&readers);


        QString line; //temporary string
        int count = 0;
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "") count++;
        }
        readersAmount = count;

        readerList = new Reader[readersAmount];

        stream.seek(0); //set at the begin

        int _code;
        long _contactNumber;
        QString _FIO, _homeAddress;

        QStringList list;

        for(int i = 0; i < readersAmount; i++){
            list = stream.readLine().split('|');

            _code = list[0].toInt();
            _FIO = list[1];
            _homeAddress = list[2];
            _contactNumber = list[3].toLong();

            ui->readerComboBox->addItem(_FIO);

            readerList[i] = Reader(_code, _FIO, _homeAddress, _contactNumber);
        }
        readers.close();
    }
}

void Library::clearTable()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
}

void Library::booksButton_clicked()
{
    this->clearTable();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Код книги")
                                                             << ("Фамилия автора")
                                                             << ("Название")
                                                             <<  ("Год выпуска")
                                                             <<  ("Язык издания"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for(int i = 0; i < booksAmount; i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(bookList[i].getBookCode()))); //add dates to table
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(bookList[i].getAuthorSurname()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(bookList[i].getTitle()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(bookList[i].getYear())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(bookList[i].getLanguage()));
    }
}

void Library::readersBooksButton_clicked()
{
    this->clearTable();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Код книги")
                                                             << ("Фамилия автора")
                                                             << ("Название")
                                                             <<  ("Год выпуска")
                                                             <<  ("Язык издания"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int books = rand() % booksAmount;
    int i;
    QString nums;
    for(int j = 0; j < books; j++){
        i = rand() % booksAmount;
        if(!nums.contains((QChar)('0' + i))){   //for no duplicates
            nums += (QChar)('0' + i);
            ui->tableWidget->insertRow(j);
            ui->tableWidget->setItem(j, 0, new QTableWidgetItem(QString::number(bookList[i].getBookCode()))); //add dates to table
            ui->tableWidget->setItem(j, 1, new QTableWidgetItem(bookList[i].getAuthorSurname()));
            ui->tableWidget->setItem(j, 2, new QTableWidgetItem(bookList[i].getTitle()));
            ui->tableWidget->setItem(j, 3, new QTableWidgetItem(QString::number(bookList[i].getYear())));
            ui->tableWidget->setItem(j, 4, new QTableWidgetItem(bookList[i].getLanguage()));
        }
    }
}

void Library::readersButton_clicked()
{
    this->clearTable();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Код читателя")
                                                             << ("ФИО")
                                                             << ("Домашний адрес")
                                                             <<  ("Телефон"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for(int i = 0; i < readersAmount; i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(readerList[i].getCode()))); //add dates to table
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(readerList[i].getFIO()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(readerList[i].getHomeAddress()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(readerList[i].getContactNumber())));
    }
}

void Library::debtorsButton_clicked()
{
    this->clearTable();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Код читателя")
                                                             << ("ФИО")
                                                             << ("Домашний адрес")
                                                             <<  ("Телефон"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int readers = rand() % readersAmount;
    int temp;
    QString nums;
    for(int i = 0; i < readers; i++){
        temp = rand() % readersAmount;
        if(!nums.contains((QChar)('0' + temp))){   //for no duplicates
            nums += (QChar)('0' + temp);
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(readerList[temp].getCode()))); //add data to table
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(readerList[temp].getFIO()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(readerList[temp].getHomeAddress()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(readerList[temp].getContactNumber())));
        }
    }
}

void Library::addBookButton_clicked()
{
    QString code = ui->bookCodeEdit->text();
    QString surname = ui->authorSurnameEdit->text();
    QString title = ui->titleEdit->text();
    QString year = ui->yearEdit->text();
    QString language = ui->languageEdit->text();

    bool isExist = false;
    for(int i = 0; i < booksAmount; i++){
        if(bookList[i].getBookCode() == code.toInt()) isExist = true;
    }
    if(isExist){
        QMessageBox::warning(this, "Ошибка", "Книга с данным кодом уже существует.");
    }
    else if(code.toInt() != 0 && year.toInt() != 0 && !surname.contains(' ') && !containsDigit(surname) && !containsDigit(title)
            && !containsDigit(language) && !language.contains(' ') && year.size() < 5){

        Book* tmp = new Book[booksAmount];
        for(int i = 0; i < booksAmount; i++){
            tmp[i] = bookList[i];
        }
        delete [] bookList;

        bookList = new Book[booksAmount + 1];   //reallocate memory

        for(int i = 0; i < booksAmount; i++){
            bookList[i] = tmp[i];
        }
        delete [] tmp;

        bookList[booksAmount] = Book(code.toInt(), surname, title, year.toInt(), language);

        booksAmount += 1;


        QFile file("bookList.txt");
        if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&file);

            stream << code + "|";
            stream << surname + "|";
            stream << title + "|";
            stream << year + "|";
            stream << language + "\n";

            file.close();
            ui->bookCodeEdit->clear();
            ui->authorSurnameEdit->clear();
            ui->titleEdit->clear();
            ui->yearEdit->clear();
            ui->languageEdit->clear();
        }

        this->booksButton_clicked();    //rewrite table

        ui->bookComboBox->addItem(title);
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!\nБудьте внимательны.\nВ фамилии не должно быть пробелов.");
    }

}

void Library::addReaderButton_clicked()
{
    QString code = ui->readerCodeEdit->text();
    QString FIO = ui->readerFIOEdit->text();
    QString address = ui->addressEdit->text();
    QString number = ui->phoneEdit->text();
    bool isExist = false;
    for(int i = 0; i < readersAmount; i++){
        if(readerList[i].getCode() == code.toInt()) isExist = true;
    }
    if(isExist){
        QMessageBox::warning(this, "Ошибка", "Читатель с данным кодом уже существует.");
    }
    else if(code.toInt() != 0 && number.toLong() != 0 && !isExist && !containsDigit(FIO)){
        Reader* tmp = new Reader[readersAmount];

        for(int i = 0; i < readersAmount; i++){
            tmp[i] = readerList[i];
        }

        delete [] readerList;

        readerList = new Reader[readersAmount + 1];

        for(int i = 0; i < readersAmount; i++){
            readerList[i] = tmp[i];
        }
        delete [] tmp;

        readerList[readersAmount] = Reader(code.toInt(), FIO, address, number.toLong());

        ui->readerComboBox->addItem(FIO);

        readersAmount += 1;

        QFile readers("readerList.txt");
        if(readers.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&readers);

            stream << code + "|";
            stream << FIO + "|";
            stream << address + "|";
            stream << number + "\n";

            readers.close();
            ui->readerCodeEdit->clear();
            ui->readerFIOEdit->clear();
            ui->addressEdit->clear();
            ui->phoneEdit->clear();
        }
        this->readersButton_clicked();

    }
    else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!\nБудьте внимательны.");
    }

}


void Library::rewriteBooksInFile()
{
    QFile file("bookList.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        for(int i = 0; i < booksAmount; i++){
            stream << bookList[i].getBookCode() << "|" << bookList[i].getAuthorSurname() << "|" << bookList[i].getTitle() << "|"
                   << bookList[i].getYear() << "|" << bookList[i].getLanguage() << "\n";
        }
        file.close();
    }
    else {
        qDebug() << "File not open\n";
    }

}

void Library::sortBooksButton_clicked()
{
    if(ui->booksButton->isChecked()){
        int size = booksAmount;
        int i, j;
        Book temp;
        for (int step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                temp = bookList[i];
                 for (j = i; j >= step; j -= step) {
                     if (temp.getYear() <= bookList[j - step].getYear()) break;
                     bookList[j] = bookList[j - step];
                 }
                bookList[j] = temp;
            }
        }
        this->booksButton_clicked();
        this->rewriteBooksInFile();
    }
}

void Library::rewriteReadersInFile()
{
    QFile readers("readerList.txt");
    if(readers.open(QIODevice::WriteOnly)){
        QTextStream stream(&readers);
        for(int i = 0; i < readersAmount; i++){
            stream << readerList[i].getCode() << "|";
            stream << readerList[i].getFIO() << "|";
            stream << readerList[i].getHomeAddress() << "|";
            stream << readerList[i].getContactNumber() << "\n";
        }
    }
}

void Library::sortReadersButton_clicked()
{
    if(ui->readersButton->isChecked())
    {
        int size = readersAmount;
        int i, j;
        Reader temp;
        for (int step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                temp = readerList[i];
                 for (j = i; j >= step; j -= step) {
                     if (temp.getCode() <= readerList[j - step].getCode()) break;
                     readerList[j] = readerList[j - step];
                 }
                readerList[j] = temp;
            }
        }
        this->readersButton_clicked();
        this->rewriteReadersInFile();
    }
}




void Library::findBookEdit_textChanged(const QString &arg1)
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
        }
    }
    if(ui->booksButton->isChecked() && arg1 != ""){
        for(int i = 0; i < booksAmount; i++){
            if(bookList[i].getTitle().contains(arg1, Qt::CaseInsensitive)){
                for(int j = 0; j < 5; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::yellow));
            }
        }
    }
}


void Library::findReaderEdit_textChanged(const QString &arg1)
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white)); //clear table
        }
    }
    if(ui->readersButton->isChecked() && arg1 != ""){
        for(int i = 0; i < readersAmount; i++){
            if(readerList[i].getFIO().contains(arg1, Qt::CaseInsensitive)){
                for(int j = 0; j < 4; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::blue));
            }
        }
    }
}

void Library::changeBookButton_clicked()
{
    QString _title = ui->bookComboBox->currentText();

    QString code = ui->bookCodeEdit->text();
    QString surname = ui->authorSurnameEdit->text();
    QString title = ui->titleEdit->text();
    QString year = ui->yearEdit->text();
    QString language = ui->languageEdit->text();

    if(code.toInt() != 0 && year.toInt() != 0 && !containsDigit(surname) && !containsDigit(title)
            && !containsDigit(language) && year.size() < 5){
        for(int i = 0; i < booksAmount; i++){
            if(bookList[i].getTitle() == _title){
                bookList[i] = Book(code.toInt(), surname, title, year.toInt(), language);
                break;
            }
        }
        ui->bookComboBox->insertItem(ui->bookComboBox->currentIndex(), title);
        ui->bookComboBox->removeItem(ui->bookComboBox->currentIndex());

        ui->bookCodeEdit->clear();
        ui->authorSurnameEdit->clear();
        ui->titleEdit->clear();
        ui->yearEdit->clear();
        ui->languageEdit->clear();

        this->rewriteBooksInFile();
        this->booksButton_clicked();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!\nБудьте внимательны.\nВ фамилии и названии не должно быть пробелов.");
    }

}
void Library::changeReaderButton_clicked()
{
    QString _FIO = ui->readerComboBox->currentText();

    QString code = ui->readerCodeEdit->text();
    QString FIO = ui->readerFIOEdit->text();
    QString address = ui->addressEdit->text();
    QString number = ui->phoneEdit->text();
    if(code.toInt() != 0 && number.toLong() != 0 && !FIO.contains(" ") && !address.contains(" ")
            && !containsDigit(FIO)){
        for(int i = 0; i < readersAmount; i++){
            if(readerList[i].getFIO() == _FIO){
                readerList[i] = Reader(code.toInt(), FIO, address, number.toLong());
                break;
            }
        }

        ui->readerComboBox->insertItem(ui->readerComboBox->currentIndex(), FIO);
        ui->readerComboBox->removeItem(ui->readerComboBox->currentIndex());

        ui->readerCodeEdit->clear();
        ui->readerFIOEdit->clear();
        ui->addressEdit->clear();
        ui->phoneEdit->clear();

        this->rewriteReadersInFile();
        this->readersButton_clicked();

    }
    else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!\nБудьте внимательны.\nВ ФИО и адресе не должно быть пробелов.");
    }
}

bool containsDigit(const QString& string)
{
    for(int i = 0; i < string.size(); i++){
        if(string[i].isDigit()) return true;
    }
    return false;
}

void Library::deleteBookButton_clicked()
{
    if(booksAmount > 0){

        Book* tmp = new Book[booksAmount - 1];
        int count = 0;
        for(int i = 0; i < booksAmount; i++){
            if(bookList[i].getTitle() != ui->bookComboBox->currentText()){
                tmp[count] = bookList[i];
                count++;
            }
        }
        delete [] bookList;

        bookList = new Book[booksAmount - 1];   //reallocate memory

        for(int i = 0; i < booksAmount - 1; i++){
            bookList[i] = tmp[i];
        }
        delete [] tmp;


        booksAmount -= 1;

        ui->bookComboBox->removeItem(ui->bookComboBox->currentIndex());
        this->rewriteBooksInFile();
        this->booksButton_clicked();
    } else {
        QMessageBox::warning(this, "Ошибка", "Cписок пуст!");
    }
}

void Library::deleteReaderButton_clicked()
{
    if(readersAmount > 0){   //if readers amount > 0
        Reader* tmp = new Reader[readersAmount - 1];
        int count = 0;
        for(int i = 0; i < readersAmount; i++){
            if(readerList[i].getFIO() != ui->readerComboBox->currentText()){
                tmp[count] = readerList[i];
                count++;
            }
        }

        delete [] readerList;

        readerList = new Reader[readersAmount - 1];

        for(int i = 0; i < readersAmount - 1; i++){
            readerList[i] = tmp[i];
        }
        delete [] tmp;

        ui->readerComboBox->removeItem(ui->readerComboBox->currentIndex());

        readersAmount -= 1;
       this->readersButton_clicked();
       this->rewriteReadersInFile();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Cписок пуст!");
    }
}
