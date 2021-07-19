#include "mainwindow.h"
#include <DMainWindow>
#include <DSpinner>
DWIDGET_USE_NAMESPACE
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    w = new Widget;
    resize(w->size()); //设置窗口大小
    // 设置窗口
    this->setWindowFlags(windowFlags() &~ Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{

}
