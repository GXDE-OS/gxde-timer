/*
 * 名称：定时器
 * 版本：1.0
 * 作者：gfdgd xi
 * 程序所需依赖（已知）：libnotify-bin
*/
#include "mainwindow.h"
#include <DApplication>
#include <DWidgetUtil>
//#include <DApplicationSettings>
#include <DSpinner>
#include <DAboutDialog>
DWIDGET_USE_NAMESPACE
#define PROGRAM_VERSION "1.1.0"
int main(int argc, char *argv[])
{
    /*
     * 设置窗口
     */
    DApplication::loadDXcbPlugin();  //让bar处在标题栏中
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();
    a.setOrganizationName("GXDE");
    a.setApplicationVersion(DApplication::buildVersion(PROGRAM_VERSION));
    a.setApplicationHomePage("https://gitee.com/gfdgd-xi/timer");
    a.setApplicationAcknowledgementPage("https://gitee.com/gfdgd-xi/timer");
    a.setProductIcon(QIcon::fromTheme("deepin-launcher"));  //设置Logo
    a.setProductName("倒计时");
    a.setApplicationName("倒计时"); //只有在这儿修改窗口标题才有效
    a.setApplicationDescription(QObject::tr("一个可以倒计时提醒的程序"));

    MainWindow w;
    // 设置关于窗口
    DAboutDialog *dialog = new DAboutDialog(&w);
    dialog->setLicense("基于 GPLV3 开源");
    dialog->setVersion(QString(PROGRAM_VERSION) + "~" + __DATE__ + " " + QString(__TIME__));
    dialog->setDescription(QObject::tr("一个可以倒计时提醒的程序，基于 DTK 制作"));
    dialog->setProductName("dtk 倒计时");
    dialog->setWebsiteLink("https://gitee.com/gfdgd-xi/timer");
    dialog->setWebsiteName("https://gitee.com/gfdgd-xi/timer");
    //dialog->setIcon(QIcon::fromTheme("deepin-launcher"));
    dialog->setProductIcon(QIcon::fromTheme("deepin-launcher"));
    a.setAboutDialog(dialog);
    //DApplicationSettings settings;
    w.show();
    //让打开时界面显示在正中
    Dtk::Widget::moveToCenter(&w);
    return a.exec();
}
