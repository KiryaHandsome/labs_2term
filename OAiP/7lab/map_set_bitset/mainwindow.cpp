#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(auto& it : map_functions){
        ui->comboBox->addItem(it);
    }

    connect(ui->mapButton, SIGNAL(clicked()), this, SLOT(change_combo_box()));
    connect(ui->setButton, SIGNAL(clicked()), this, SLOT(change_combo_box()));
    connect(ui->bitsetButton, SIGNAL(clicked()), this, SLOT(change_combo_box()));
    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(inputData()));

    ui->positionEdit->hide();
    ui->valueBoolEdit->hide();
}


void MainWindow::change_combo_box()
{
    ui->comboBox->clear();
    if(ui->mapButton->isChecked()){
        for(auto& it : map_functions){
            ui->comboBox->addItem(it);
        }
        ui->keyEdit->show();
        ui->valueEdit->show();
        ui->valueBoolEdit->hide();
        ui->positionEdit->hide();
    }

    if(ui->setButton->isChecked()){
        for(auto& it : set_functions){
            ui->comboBox->addItem(it);
        }
        ui->valueEdit->hide();
        ui->valueBoolEdit->hide();
        ui->positionEdit->hide();
        ui->keyEdit->show();
    }

    if(ui->bitsetButton->isChecked()){
        for(auto& it : bitset_functions){
            ui->comboBox->addItem(it);
        }
        ui->valueEdit->hide();
        ui->keyEdit->hide();
        ui->valueBoolEdit->show();
        ui->positionEdit->show();
    }
}

void MainWindow::inputData()
{
    if(ui->setButton->isChecked()){
        setInput();
    }

    else if(ui->bitsetButton->isChecked()){
        bitsetInput();
    }
    else {
        mapInput();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mapInput()
{
    int curr_index = ui->comboBox->currentIndex();
    QString key = ui->keyEdit->text();
    QString value = ui->valueEdit->text();
    size_t count = 0;
    bool erase_val = false;
    qDebug() << "Im in mapInput()";
    switch(curr_index)
    {
    case map::at:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else{
            QString val;
            try {
                val = map.at(key.toInt());
                ui->textBrowser->setText("Returned value: \"" + val + "\"");
            } catch (const std::out_of_range& e) {
                ui->textBrowser->setText("std::out_of_range was caught. what() : " + QString::fromStdString(e.what()));
            }
        }
        break;
    case map::clearM:
        if(map.size() == 0){
            ui->textBrowser->setText("Nothing to clear");
        }
        else {
            map.clear();
            ui->textBrowser->setText("Successful cleared");
        }
        break;
    case map::countM:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            count = map.count(key.toInt());
            ui->textBrowser->setText("count = " + QString(char(count + '0')));
        }
        break;
    case map::emptyM:
        ui->textBrowser->setText("result = " + QString(map.empty() ? "is empty" : "is NOT empty"));
        break;
    case map::eraseM:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            erase_val = map.erase(key.toInt());
            ui->textBrowser->setText(erase_val ? "erase was successful" : "no element with key " + key);
        }
        break;
    case map::findM:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            auto p = map.find(key.toInt());
            if(p != map.end()){
                ui->textBrowser->setText("{" + QString::number((*p).first) + ", \"" + (*p).second + "\"}");
            }
            else {
                ui->textBrowser->setText("No pair with key " + key);
            }
        }

        break;
    case map::insertM:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            auto p = map.insert({key.toInt(), value});
            if(p.second) {
                ui->textBrowser->setText("Pair {" + key + ',' + "\"" + value + "\"} was inserted.");
            }
            else {
                ui->textBrowser->setText("Pair with key " + key + " already exist");
            }
        }
        break;
    case map::sizeM:
        ui->textBrowser->setText("size = " + QString::number(map.size()));
        break;
    case map::loopM:
        if(!map.empty()){
            QString text;
            for(auto& it : map){
                text += QString::number(it.first) + " - " + it.second + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("map is empty");
        }
        break;
    case map::rloopM:
        if(!map.empty()){
            QString text;
            for(auto it = map.rbegin(); it != map.rend(); ++it){
                text += QString::number((*it).first) + " - " + (*it).second + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("map is empty");
        }
        break;
    case map::l_loopM:
        if(!map.empty()){
            QString text;
            for(auto it = map.l_begin(); it != map.l_end(); ++it){
                text += QString::number((*it).first) + " - " + (*it).second + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("map is empty");
        }
        break;
    case map::rl_loopM:
        if(!map.empty()){
            QString text;
            for(auto it = map.rl_begin(); it != map.rl_end(); ++it){
                text += QString::number((*it).first) + " - " + (*it).second + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("map is empty");
        }
        break;
    };
}

void MainWindow::setInput()
{
    int curr_index = ui->comboBox->currentIndex();
    QString key = ui->keyEdit->text();

    switch(curr_index)
    {
    case set::contains:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else{
            if(set.contains(key.toInt())){
                ui->textBrowser->setText("Such key exist");
            }
            else {
                ui->textBrowser->setText("No such key");
            }
        }
        break;
    case set::clearS:
        if(set.size() == 0){
            ui->textBrowser->setText("Nothing to clear");
        }
        else {
            set.clear();
            ui->textBrowser->setText("Successful cleared");
        }
        break;
    case set::countS:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            size_t count = set.count(key.toInt());
            ui->textBrowser->setText("count = " + QString(char(count + '0')));
        }
        break;
    case set::emptyS:
        ui->textBrowser->setText("result = " + QString(map.empty() ? "is empty" : "is NOT empty"));
        break;
    case set::eraseS:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            bool erase_val = set.erase(key.toInt());
            ui->textBrowser->setText(erase_val ? "erase was successful" : "no element with key " + key);
        }
        break;
    case set::findS:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            auto p = set.find(key.toInt());
            if(p != set.end()){
                ui->textBrowser->setText("Element with such key founded.");
            }
            else {
                ui->textBrowser->setText("No element ");
            }
        }

        break;
    case set::insertS:
        if(key.toInt() == 0 && key != "0"){
            ui->textBrowser->setText("Incorrect key");
        }
        else {
            auto p = set.insert(key.toInt());
            if(p.second) {
                ui->textBrowser->setText("Key " + key + " was inserted");
            }
            else {
                ui->textBrowser->setText("Key " + key + " already exist");
            }
        }
        break;
    case set::sizeS:
        ui->textBrowser->setText("size = " + QString::number(set.size()));
        break;
    case set::loopS:
        if(!set.empty()){
            QString text;
            for(auto& it : set){
                text += QString::number(it) + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("set is empty");
        }
        break;
    case set::rloopS:
        if(!set.empty()){
            QString text;
            for(auto it = set.rbegin(); it != set.rend(); ++it){
                text += QString::number(*it) + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("set is empty");
        }
        break;
    case set::l_loopS:
        if(!set.empty()){
            QString text;
            for(auto it = set.l_begin(); it != set.l_end(); ++it){
                text += QString::number(*it) + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("set is empty");
        }
        break;
    case set::rl_loopS:
        if(!set.empty()){
            QString text;
            for(auto it = set.rl_begin(); it != set.rl_end(); ++it){
                text += QString::number(*it) + '\n';
            }
            ui->textBrowser->setText(text);
        }
        else {
            ui->textBrowser->setText("set is empty");
        }
        break;
    };

}

void MainWindow::bitsetInput()
{
    int curr_index = ui->comboBox->currentIndex();
    QString pos = ui->positionEdit->text();
    QString value = ui->valueBoolEdit->text();
    bool return_value = false;
    size_t number = 0;

    //enum bitset { all, any, count, flip, flipPos, none, reset, _set, setPos, size, test, to_string, to_ulong, to_ullong };
    switch(curr_index)
    {
    case bitset::all:
        return_value = bitset.all();
        if(return_value){
            ui->textBrowser->setText("All bits are true");
        }
        else {
            ui->textBrowser->setText("Not all bits are true");
        }
        break;
    case bitset::any:
        return_value = bitset.any();
        if(return_value){
            ui->textBrowser->setText("Any bits are set to true");
        }
        else {
            ui->textBrowser->setText("No bits are set to true");
        }
        break;
    case bitset::count:
        number = bitset.count();
        ui->textBrowser->setText(QString::number(number) + " - number of bits are set to true");
        break;
    case bitset::flip:
        bitset.flip();
        ui->textBrowser->setText("Successful flip");
        break;
    case bitset::flipPos:
        if(pos.toInt() == 0 && pos != "0"){
            ui->textBrowser->setText("Incorrect position");
        }
        else {
            try{
                bitset.flip(pos.toInt());
                ui->textBrowser->setText("Successful flip");
            } catch(const std::out_of_range& e){
                ui->textBrowser->setText("std::out_of_range was caught. what() : " + QString::fromStdString(e.what()));
            }
        }
        break;
    case bitset::_set:
        bitset.set();
        ui->textBrowser->setText("All bits are set true");
        break;
    case bitset::none:
        return_value = bitset.none();
        if(return_value){
            ui->textBrowser->setText("None of the bits are set to true");
        }
        else {
            ui->textBrowser->setText("Some bits are set to true");
        }
        break;
    case bitset::reset:
        bitset.reset();
        ui->textBrowser->setText("All bits are set false");
        break;
    case bitset::setPos:
        if(pos.toInt() == 0 && pos != "0"){
            ui->textBrowser->setText("Incorrect position");
        }
        else if(value != "0" && value != "1"){
            ui->textBrowser->setText("Incorrect value");
            if(value == "") value = "1";
        }
        else {
            try {
                bitset.set(pos.toInt(), value.toInt());
                ui->textBrowser->setText("bit is set");
            } catch (const std::out_of_range& e) {
                ui->textBrowser->setText("std::out_of_range was caught. what() : " + QString::fromStdString(e.what()));
            }
        }
        break;
    case bitset::size:
        ui->textBrowser->setText("size = " + QString::number(bitset.size()));
        break;
    case bitset::test:
        if(pos.toInt() == 0 && pos != "0"){
            ui->textBrowser->setText("Incorrect position");
        }
        else {
            try {
                return_value = bitset.test(pos.toInt());
                ui->textBrowser->setText("value of this bit = " + QString(return_value ? "true" : "false"));
            } catch (const std::out_of_range& e) {
                ui->textBrowser->setText("std::out_of_range was caught. what() : " + QString::fromStdString(e.what()));
            }
        }
        break;
    case bitset::to_string:
        ui->textBrowser->setText(QString::fromStdString(bitset.to_string()));
        break;
    case bitset::to_ullong:
        try {
            ui->textBrowser->setText(QString::number(bitset.to_ullong()));
        } catch(const std::overflow_error& e){
            ui->textBrowser->setText("std::overflow_error was caught. what() : " + QString::fromStdString(e.what()));
        }
        break;
    case bitset::to_ulong:
        try {
            ui->textBrowser->setText(QString::number(bitset.to_ulong()));
        } catch(const std::overflow_error& e){
            ui->textBrowser->setText("std::overflow_error was caught. what() : " + QString::fromStdString(e.what()));
        }
        break;
    }

}

