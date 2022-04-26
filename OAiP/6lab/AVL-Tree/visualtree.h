#ifndef VISUALTREE_H
#define VISUALTREE_H

#include <QWidget>
#include <QLabel>
#include "Tree.h"

namespace Ui {
class VisualTree;
}

class VisualTree : public QWidget
{
    Q_OBJECT

    struct VNode
    {
        VNode(Node* node, int x = 0, int y = 0) : node(node), x(x), y(y) {}
        Node* node;
        int x, y;
    };


public:
    explicit VisualTree(QWidget *parent = nullptr);
    ~VisualTree();

    void setTree(Tree* tree);

    void drawTree();

    void clearNodes();

    void paintEvent(QPaintEvent *event);



private:
    Ui::VisualTree *ui;
    Tree* tree = nullptr;
    std::vector<QLabel*> nodes;
    std::vector<QLine> links;
};

#endif // VISUALTREE_H
