#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->booksButton, SIGNAL(clicked()), this, SLOT(booksButton_clicked()));
    connect(ui->readersBooksButton, SIGNAL(clicked()), this, SLOT(readersBooksButton_clicked()));
    connect(ui->readersButton, SIGNAL(clicked()), this, SLOT(readersButton_clicked()));
    connect(ui->debtorsButton, SIGNAL(clicked()), this, SLOT(debtorsButton_clicked()));
    connect(ui->addReaderButton, SIGNAL(clicked()), this, SLOT(addReaderButton_clicked()));
    connect(ui->addBookButton, SIGNAL(clicked()), this, SLOT(addBookButton_clicked()));
    connect(ui->findBookEdit, SIGNAL(editingFinished()), this, SLOT(findBookEdit_editingFinished()));
    connect(ui->findReaderEdit, SIGNAL(editingFinished()), this, SLOT(findReaderEdit_editingFinished()));
    connect(ui->sortButton, SIGNAL(clicked()), this, SLOT(sortButton_clicked()));

    library = new Library;

    QFile books("booksList.txt");
            if(books.open(QIODevice::ReadWrite)){
                QTextStream stream(&books);
                qDebug() << "isOpen";


                QString line; //temporary string
                int count = 0;
                while(!stream.atEnd()){
                    stream.readLine();
                    count++;
                }
                library->setBooksAmount(count / 5);

                library->booksList = new Book[count / 5];

                stream.seek(0); //set at the begin

                for(int i = 0; i < count / 5; i++){
                    line = stream.readLine();
                    library->booksList[i].setBookCode(line.toInt());

                    line = stream.readLine();
                    library->booksList[i].setAuthorSurname(line);

                    line = stream.readLine();
                    library->booksList[i].setTitle(line);

                    line = stream.readLine();
                    library->booksList[i].setYear(line.toInt());

                    line = stream.readLine();
                    library->booksList[i].setLanguage(line);
                }
                books.close();
            }

    QFile readers("readersList.txt");

    if(readers.open(QIODevice::ReadWrite)){
        QTextStream stream(&readers);
        qDebug() << "isOpen";


        QString line; //temporary string
        int count = 0;
        while(!stream.atEnd()){
            stream.readLine();
            count++;
        }
        library->setReadersAmount(count / 4);

        library->readersList = new Reader[count / 4];

        stream.seek(0); //set at the begin

        for(int i = 0; i < count / 4; i++){
            line = stream.readLine();
            library->readersList[i].setCode(line.toInt());

            line = stream.readLine();
            library->readersList[i].setFIO(line);

            line = stream.readLine();
            library->readersList[i].setHomeAddress(line);

            line = stream.readLine();
            library->readersList[i].setContactNumber(line);
        }
        readers.close();
    }
}

MainWindow::~MainWindow()
{
    delete [] library->readersList;
    delete [] library->booksList;
    delete library;
    delete ui;
}


void MainWindow::booksButton_clicked()
{
    this->rewriteBooks();
}

void MainWindow::readersBooksButton_clicked()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    QStringList headers = QStringList() << ("Код читателя")
                                        << ("Код книги")
                                        << ("Дата выдачи")
                                        <<  ("Треб. дата возвр.")
                                        <<  ("Реал. дата возвр.");

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

void MainWindow::readersButton_clicked()
{
    rewriteReaders();
}

void MainWindow::debtorsButton_clicked()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    QStringList headers = QStringList() << ("Код читателя")
                                        << ("ФИО")
                                        << ("Домашний адрес")
                                        <<  ("Телефон");

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void MainWindow::addBookButton_clicked()
{
    QString code = ui->bookCodeEdit->text();
    QString surname = ui->authorSurnameEdit->text();
    QString title = ui->titleEdit->text();
    QString year = ui->yearEdit->text();
    QString language = ui->languageEdit->text();

    if(code.toInt() != 0 && year.toInt() != 0){

        Book* tmp = new Book[library->getBooksAmount()];
        for(int i = 0; i < library->getBooksAmount(); i++){
            tmp[i] = library->booksList[i];
        }
        delete [] library->booksList;

        library->booksList = new Book[library->getBooksAmount() + 1];   //reallocate memory

        for(int i = 0; i < library->getBooksAmount(); i++){
            library->booksList[i] = tmp[i];
        }
        delete [] tmp;
        library->booksList[library->getBooksAmount()] = Book(code.toInt(), surname, title, year.toInt(), language);

        library->setBooksAmount(library->getBooksAmount() + 1);


        QFile books("booksList.txt");
        if(books.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&books);
            qDebug() << "isOpen";

            stream << code + "\n";
            stream << surname + "\n";
            stream << title + "\n";
            stream << year + "\n";
            stream << language + "\n";

            books.close();
        }

        this->rewriteBooks();

        ui->bookCodeEdit->clear();
        ui->authorSurnameEdit->clear();
        ui->titleEdit->clear();
        ui->yearEdit->clear();
        ui->languageEdit->clear();
    } else {
        QMessageBox::warning(this, "Error", "Invalid input!\nTry again");
    }

}

void MainWindow::addReaderButton_clicked()
{
    QString code = ui->readerCodeEdit->text();
    QString FIO = ui->readerFIOEdit->text();
    QString address = ui->addressEdit->text();
    QString number = ui->phoneEdit->text();
    if(code.toInt() != 0 && number.toInt() != 0){
        Reader* tmp = new Reader[library->getReadersAmount()];

        for(int i = 0; i < library->getReadersAmount(); i++){
            tmp[i] = library->readersList[i];
        }

        delete [] library->readersList;

        library->readersList = new Reader[library->getReadersAmount() + 1];

        for(int i = 0; i < library->getReadersAmount(); i++){
            library->readersList[i] = tmp[i];
        }
        delete [] tmp;

        library->readersList[library->getReadersAmount()] = Reader(code.toInt(), FIO, address, number);

        library->setReadersAmount(library->getReadersAmount() + 1);

        QFile readers("readersList.txt");
        if(readers.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&readers);
            qDebug() << "isOpen";

            stream << code + "\n";
            stream << FIO + "\n";
            stream << address + "\n";
            stream << number + "\n";

            readers.close();
        }
        this->rewriteReaders();
         ui->readerCodeEdit->clear();
         ui->readerFIOEdit->clear();
         ui->addressEdit->clear();
         ui->phoneEdit->clear();

    } else {
        QMessageBox::warning(this, "Error", "Invalid input!\nTry again");
    }
}

void MainWindow::rewriteBooks()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    QStringList headers = QStringList() << ("Код книги")
                                        << ("Фамилия автора")
                                        << ("Название")
                                        <<  ("Год издания")
                                        <<  ("Язык издания");

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for(int i = 0; i < library->getBooksAmount(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(library->booksList[i].getBookCode()))); //add dates to table
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(library->booksList[i].getAuthorSurname()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(library->booksList[i].getTitle()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(library->booksList[i].getYear())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(library->booksList[i].getLanguage()));
    }
}

void MainWindow::rewriteReaders()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    QStringList headers = QStringList() << ("Код читателя")
                                        << ("ФИО")
                                        << ("Домашний адрес")
                                        <<  ("Телефон");

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    for(int i = 0; i < library->getReadersAmount(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(library->readersList[i].getCode()))); //add dates to table
        qDebug() << QString::number(library->readersList[i].getCode());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(library->readersList[i].getFIO()));
        qDebug() << library->readersList[i].getFIO();
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(library->readersList[i].getHomeAddress()));
        qDebug() << library->readersList[i].getHomeAddress();
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(library->readersList[i].getContactNumber()));
        qDebug() << library->readersList[i].getContactNumber();
    }
}

void MainWindow::findBookEdit_editingFinished()
{
    qDebug() << "im here";
    QString text = ui->findBookEdit->text();
    for(int i = 0; i < library->getBooksAmount(); i++){
        if(library->booksList[i].getTitle().contains(text, Qt::CaseInsensitive)){
            qDebug() << "and here";
            for(int j = 0; j < 5; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::yellow));
        }
    }
}

void MainWindow::findReaderEdit_editingFinished()
{
    qDebug() << "im find reader";
    QString text = ui->findReaderEdit->text();
    for(int i = 0; i < library->getReadersAmount(); i++){
        if(library->readersList[i].getFIO().contains(text, Qt::CaseInsensitive)){
            qDebug() << "im there is";
            for(int j = 0; j < 4; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::blue));
        }
    }
}

void MainWindow::sortButton_clicked()
{
    if(ui->booksButton->isChecked()){       //shell sort
        int size = library->getBooksAmount();
        int i, j;
        Book temp;
        for (int step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                temp = library->booksList[i];
                 for (j = i; j >= step; j -= step) {
                     if (temp.getYear() <= library->booksList[j - step].getYear()) break;
                     library->booksList[j] = library->booksList[j - step];
                 }
                library->booksList[j] = temp;
            }
        }
        rewriteBooks();
        rewriteBooksInFile();
     }
    if(ui->readersButton->isChecked())
    {
        int size = library->getReadersAmount();
        int i, j;
        Reader temp;
        for (int step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                temp = library->readersList[i];
                 for (j = i; j >= step; j -= step) {
                     if (temp.getCode() <= library->readersList[j - step].getCode()) break;
                     library->readersList[j] = library->readersList[j - step];
                 }
                library->readersList[j] = temp;
            }
        }
        rewriteReaders();
        rewriteReadersInFile();
    }
}

void MainWindow::rewriteBooksInFile()
{
    QFile books("booksList.txt");
    if(books.open(QIODevice::ReadWrite)){
        QTextStream stream(&books);
        qDebug() << "isOpen";
        for(int i = 0; i < library->getBooksAmount(); i++){
            stream << library->booksList[i].getBookCode() << "\n";
            stream << library->booksList[i].getAuthorSurname() << "\n";
            stream << library->booksList[i].getTitle() << "\n";
            stream << library->booksList[i].getYear() << "\n";
            stream << library->booksList[i].getLanguage() << "\n";
        }
    }

}

void MainWindow::rewriteReadersInFile()
{
    QFile readers("readersList.txt");
    if(readers.open(QIODevice::ReadWrite)){
        QTextStream stream(&readers);
        qDebug() << "isOpen";
        for(int i = 0; i < library->getReadersAmount(); i++){
            stream << library->readersList[i].getCode() << "\n";
            stream << library->readersList[i].getFIO() << "\n";
            stream << library->readersList[i].getHomeAddress() << "\n";
            stream << library->readersList[i].getContactNumber() << "\n";
        }
    }
}
