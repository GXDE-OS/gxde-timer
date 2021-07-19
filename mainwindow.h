#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "widget.h"
#include <iostream>
#include <string>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
DWIDGET_USE_NAMESPACE
//int minute = 0;
//int second = 0;
class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Widget *w;
};

#endif // MAINWINDOW_H
