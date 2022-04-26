#include "visualtree.h"
#include "ui_visualtree.h"
#include <QDebug>
#include <QPainter>

VisualTree::VisualTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualTree)
{
    ui->setupUi(this);
}

VisualTree::~VisualTree()
{
    delete ui;
}

void VisualTree::setTree(Tree *tree)
{
    this->tree = tree;
}

void VisualTree::drawTree()
{
    const int labelWidth = 70, labelHeight = 50;
    int dir_x = 30, dir_y = 70;

    clearNodes();
    tree->printInOrder();

    auto createNode = [&](int x, int y, int key, std::string info) {
        QLabel* node = new QLabel(this);
        node->setAlignment(Qt::AlignHCenter);
        node->setStyleSheet("background-color: green");
        QFont label_font;
        label_font.setPointSize(12);
        node->setFont(label_font);
        node->setGeometry(x, y, labelWidth, labelHeight);
        node->setText(QString::number(key) + "\n" + QString::fromStdString(info));

        return node;
    };

    auto rootNode = tree->getRoot();

    std::queue<VNode> queue;
    queue.push(VNode(rootNode, this->geometry().width() / 2 - labelWidth / 2, 10));
    QLabel* root = createNode(this->geometry().width() / 2 - labelWidth / 2, 10, rootNode->key, rootNode->info);
    nodes.push_back(root);

    int height = rootNode->height;
    qDebug() << height;

    while(!queue.empty())
    {
        auto vnode = queue.front();
        queue.pop();

        int dx = 70 * vnode.node->height;

        QLabel* node;
        if(vnode.node->left){
            queue.push(VNode(vnode.node->left, vnode.x - dx, vnode.y + dir_y));
            node = createNode(vnode.x - dx, vnode.y + dir_y, vnode.node->left->key, vnode.node->left->info);
            links.push_back(QLine(vnode.x, vnode.y + labelHeight, vnode.x - dx + labelWidth, vnode.y + dir_y));
            nodes.push_back(node);
        }
        if(vnode.node->right){
            queue.push(VNode(vnode.node->right, vnode.x + dx, vnode.y + dir_y));
            node = createNode(vnode.x + dx, vnode.y + dir_y, vnode.node->right->key, vnode.node->right->info);
            links.push_back(QLine(vnode.x + labelWidth, vnode.y + labelHeight, vnode.x + dx, vnode.y + dir_y));
            nodes.push_back(node);
        }
    }
    repaint();

}

void VisualTree::clearNodes()
{
    for(auto &it : nodes){
        delete it;
    }
    links.clear();
    nodes.clear();
}

void VisualTree::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    for(size_t i = 0; i < links.size(); ++i){
        painter.drawLine(links[i]);
    }
}
