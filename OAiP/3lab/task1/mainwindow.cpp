#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
//#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    entry = new Entrance;
    entry->show();
    connect(entry, SIGNAL(ok()), this, SLOT(defaulInput()));
    connect(entry, SIGNAL(file()), this, SLOT(fileInput()));



    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Reg. number"
                                                             << "Author"
                                                             << "Title"
                                                             << "Year"
                                                             << "Publisher"
                                                             << "Pages");
    ui->tableWidget->setEditTriggers(QAbstractItemView::EditTriggers(0));

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_fileName = "defaultFile.txt";
    ui->fileNameLabel->setText(m_fileName);

    window = new Dialog;
    connect(window, SIGNAL(addBook(Book,int)), this, SLOT(addBook_called(Book,int)));

    connect(ui->addBookButton, SIGNAL(clicked()), this, SLOT(addBookButton_clicked()));
    connect(ui->sortByYearButton, SIGNAL(clicked()), this, SLOT(sortByYearButton_clicked()));
    connect(ui->searchByAuthorSurEdit, SIGNAL(textChanged(QString)), this, SLOT(searchByAuthorSurEdit_textChanged(QString)));
    connect(ui->searchByNumberEdit, SIGNAL(textChanged(QString)), this, SLOT(searchByNumberEdit_textChanged(QString)));
    connect(ui->openNewFileAction, SIGNAL(triggered()), this, SLOT(openNewFileAction_triggered()));
    connect(ui->deleteBookEdit, SIGNAL(returnPressed()), this, SLOT(deleteBookEdit_returnPressed()));
    connect(ui->updateListInFileButton, SIGNAL(clicked()), this, SLOT(updateListInFileButton_clicked()));
    connect(ui->changeBookButton, SIGNAL(clicked()), this, SLOT(changeBookButton_clicked()));
    connect(window, SIGNAL(changeBook(Book,int)), this, SLOT(changeBook_called(Book,int)));
}

MainWindow::~MainWindow()
{
    delete window;
    delete ui;
}


void MainWindow::sortByYearButton_clicked()
{
    if(list.size() == 0){
        QMessageBox::warning(this, "Error", "List is empty.");
    } else{
        list.sort();
        printListInTable();
    }
}

void MainWindow::addBookButton_clicked()
{
    this->hide();
    window->show();
    window->setLabelText("Position");
    window->setSizeOfList(list.size());
}

void MainWindow::deleteBookEdit_returnPressed()
{
    int position = ui->deleteBookEdit->text().toInt();
    if(list.size() == 0){
        QMessageBox::warning(this, "Error", "List is empty");
    }
    else if(position <= 0 || position > list.size()){
        QMessageBox::warning(this, "Error", "Incorrect input. Pay attention.");
    } else {
        list.erase(position);
        printListInTable();
        ui->deleteBookEdit->clear();
    }
}

void MainWindow::addBook_called(Book book, int pos)
{
    this->show();
    if(list.size()){
        for(auto it = list.begin(); it != list.end(); ++it){
            if((*it).regNumber == book.regNumber){
                QMessageBox::warning(this, "Error", "Book with such code already exist");
                return;
            }
        }
    }
    list.insert(book, pos);
    window->hide();
    printListInTable();
}

void MainWindow::changeBook_called(Book book, int pos)
{
    this->show();
    if(list.size()){
        for(auto it = list.begin(); it != list.end(); ++it){
            if((*it).regNumber == book.regNumber){
                QMessageBox::warning(this, "Error", "Book with such code already exist");
                return;
            }
        }
    } else if(pos > list.size()){
        QMessageBox::warning(this, "Error", "Position > 0");
    } else {
        list.erase(pos);
        list.insert(book, pos);
        window->hide();
        printListInTable();
    }
}


void MainWindow::updateListInFileButton_clicked()
{
    if(list.size()){
        bool isCorrect = writeListInFile(m_fileName);
        if(isCorrect) QMessageBox::information(this, "Info", "File was updated successfully. Check it.");
    } else {
        QMessageBox::warning(this, "Error", "List is empty. Add some books.");
    }

}

void MainWindow::searchByNumberEdit_textChanged(QString string)
{
    if(list.size() != 0){
        for(int i = 0; i < ui->tableWidget->rowCount(); i++){
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
            }
        }
        int counter = 0;
        for(auto it = list.begin(); it != list.end(); ++it){
            if(QString::number((*it).regNumber).contains(string) && string != ""){
                for(int j = 0; j < 6; j++) ui->tableWidget->item(counter, j)->setBackground(QBrush(Qt::yellow));
            }
            counter++;
        }
    } else {
        if(string != "") QMessageBox::warning(this, "Error", "List is empty. Add some books.");
    }

}

void MainWindow::searchByAuthorSurEdit_textChanged(QString string)
{
    if(list.size() == 0){
        if(string != "") QMessageBox::warning(this, "Error", "List is empty.\nAdd some books");
    } else {
        for(int i = 0; i < ui->tableWidget->rowCount(); i++){
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
            }
        }
        int counter = 0;
        for(auto it = list.begin(); it != list.end(); ++it){
            if((*it).author.contains(string) && string != ""){
                for(int j = 0; j < 6; j++) ui->tableWidget->item(counter, j)->setBackground(QBrush(Qt::yellow));
            }
            counter++;
        }
    }
}

void MainWindow::printListInTable()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Reg. number"
                                                             << "Author"
                                                             << "Title"
                                                             << "Year"
                                                             << "Publisher"
                                                             << "Pages");

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    int counter = 0;
    if(list.size() != 0) {
        for(auto it = list.begin(); it != list.end(); ++it){
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::number((*it).regNumber))); //add data to table
            ui->tableWidget->setItem(counter, 1, new QTableWidgetItem((*it).author));
            ui->tableWidget->setItem(counter, 2, new QTableWidgetItem((*it).title));
            ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::number((*it).year)));
            ui->tableWidget->setItem(counter, 4, new QTableWidgetItem((*it).publisher));
            ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(QString::number((*it).pages)));
            counter++;
        }
    } else {
        QMessageBox::warning(this, "Error", "List is empty");
    }

}

void MainWindow::defaulInput()
{
    delete entry;
    m_fileName = "defaultFile.txt";
    ui->fileNameLabel->setText(m_fileName);
    this->show();
}

void MainWindow::fileInput()
{
    delete entry;
    this->show();
    this->openNewFileAction_triggered();
}

void MainWindow::openNewFileAction_triggered()
{
    QString name = QFileDialog::getOpenFileName(this, "Choose file", "C:\\", "*.txt");

    readListFromFile(name);
}

void MainWindow::changeBookButton_clicked()
{
    if(list.size() != 0){
        window->show();
        this->hide();
        window->setSizeOfList(list.size());
        window->setLabelText("Pos to change");
    } else {
        QMessageBox::warning(this, "Error", "List is empty. Nothing to change.");
    }
}

bool MainWindow::writeListInFile(const QString& name)
{
    QFile file(name);
    if(file.open(QIODevice::ReadWrite)){
       QTextStream stream(&file);
       for(auto it = list.begin(); it != list.end(); ++it){
           QString out = QString::number((*it).regNumber) + '|' + (*it).author + '|' + (*it).title +
                   '|' +  QString::number((*it).year) + '|' + (*it).publisher + '|' + QString::number((*it).pages) + '\n';
           stream << out;
           stream.flush();
           qDebug() << out;
       }
       file.close();
       return true;
    } else {
        QMessageBox::warning(this, "Error", "File not opened.");
        return false;
    }
}

void MainWindow::readListFromFile(const QString& fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        QString line;
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "" && !Book().isCorrectBook(line)){
                file.close();
                QMessageBox::warning(this, "Error", "Data in file not correct!\nChoose another file.");
                return;
            }
        }
        int list_size = list.size();
        for(int i = 0; i < list_size; ++i){
            list.erase(1);      //clear old list
        }
        m_fileName = fileName;
        QStringList fileList = fileName.split('/');
        ui->fileNameLabel->setText(fileList[fileList.size() - 1]);
        stream.seek(0);
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "") list.insert(Book().convertToBook(line), list.size() + 1);
        }
        file.close();
        printListInTable();

    }
    else {
        QMessageBox::warning(this, "Error", "Oops...File not opened.");
    }
}




