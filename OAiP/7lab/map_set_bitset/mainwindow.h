#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "set.h"
#include "Bitset.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString map_functions[12] = { "at(const KeyType& k)", "insert(const pair<KeyT, ValT>& v)", "clear()","count(const KeyType& k)",
    "empty()", "erase(const KeyType& k)", "find(const KeyType& it)", "size()", "for(auto& it : map)",
                               "reverse loop", "list loop", "reverse list loop"};
    enum map { at, insertM, clearM, countM, emptyM, eraseM, findM, sizeM, loopM, rloopM, l_loopM, rl_loopM };

    QString set_functions[12] = { "contains(const KeyType& k)", "insert(const ValueType& v)", "clear()","count(const KeyType& k)",
    "empty()", "erase(const KeyType& k)", "find(const KeyType& k)", "size()", "for(auto& it : set)",
                               "reverse loop", "list loop", "reverse list loop"};
    enum set { contains, insertS, clearS, countS, emptyS, eraseS, findS, sizeS, loopS, rloopS, l_loopS, rl_loopS };


    QString bitset_functions[14] = { "all()", "any()", "count()", "flip()", "flip(size_t pos)", "none()", "reset()",
        "set()", "set(size_t pos,bool val = true)", "size()", "test(size_t pos)", "to_string()", "to_ulong()", "to_ullong()" };
    enum bitset { all, any, count, flip, flipPos, none, reset, _set, setPos, size, test, to_string, to_ulong, to_ullong };



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mapInput();

    void setInput();

    void bitsetInput();

private slots:
    void change_combo_box();

    void inputData();

private:
    Ui::MainWindow *ui;
    Map<int, QString> map;
    Set<int> set;
    Bitset<128> bitset;
};
#endif // MAINWINDOW_H
