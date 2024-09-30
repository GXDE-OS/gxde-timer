#include "widget.h"
#include "ui_widget.h"
#include <QTimerEvent>
#include <QMessageBox>
//#include <DMessageManager>
//#include <dmessagemanager.h>
#include <QMessageBox>
#include <DDesktopServices>
#include <ddesktopservices.h>
#include <iostream>
using namespace std;
#define TIMER_TIMEOUT (1*1000)
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/**************
 * 开始按钮事件 *
 **************/
void Widget::on_pushButton_clicked()
{
    // 设置变量
    minute = ui->spinBox->value();
    second = 0;
    // 设置控件
    ui->pushButton->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    // 显示数字
    ui->lcdNumber->display(minute);
    ui->lcdNumber_2->display(0);
    // 启动定时器
    m_nTimerID = this->startTimer(TIMER_TIMEOUT);
}

/****************
 * 定时器重复逻辑 *
 ****************/
void Widget::timerEvent(QTimerEvent *event){
    if (stop) return;  // 停顿逻辑
    second--;          // 减少秒数
    if (minute <= 0 && second <= 0){  // 判断退出
        handleTimeout();              // 执行退出
        return;                       // 结束这一次定时器调用
    }
    if (second <= 0){  // 当秒数为 0 时
        // 设置变量
        second = 59;   // 设置默认值
        minute--;      // 减少分钟数
    }
    // 显示数字
    ui->lcdNumber->display(minute);
    ui->lcdNumber_2->display(second);
}

/****************
 * 定时器结束逻辑 *
 ****************/
void Widget::handleTimeout()
 {
    // 设置控件
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    ui->pushButton->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    // 结束定时器
    killTimer(m_nTimerID);
    // “暂停”变量设定为否
    stop = false;
    // 显示提示
    system("notify-send -i gxde-timer '定时器' '时间到！'");
    QMessageBox::information(this, tr("提示"), tr("时间到！"));
 }

/**************
 * 终止按钮事件 *
 **************/
void Widget::on_pushButton_3_clicked()
{
    handleTimeout();  // 调用结束函数
}

/******************
 * 暂停/继续按钮事件 *
 ******************/
void Widget::on_pushButton_2_clicked()
{
    // 设置变量
    stop = !stop;
    // 根据变量内容设置按钮文本
    if (stop) {
        ui->pushButton_2->setText("继续");
        return;
    }
    ui->pushButton_2->setText("暂停");
}
