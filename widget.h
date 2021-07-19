#ifndef WIDGET_H
#define WIDGET_H
#include <QObject>
#include <QWidget> 
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void timerEvent(QTimerEvent *event);
    void handleTimeout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    int m_nTimerID = 0;
    int minute = 0;
    int second = 0;
    bool stop = false;
};

#endif // WIDGET_H
