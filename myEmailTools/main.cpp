#include "frmmain.h"
#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置UTF-8编码
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
   // QTextCodec::setCodecForLocale(codec);
    //QTextCodec::setCodecForCStrings(codec);
    //QTextCodec::setCodecForTr(codec);
    //设置全局样式
    qApp->setStyle("Plastique");

    frmMain w;
    //设置窗体居中
    int deskWidth=qApp->desktop()->availableGeometry().width();
    int deskHeigth=qApp->desktop()->availableGeometry().height();
    int frmX=w.width();
    int frmY=w.height();
    QPoint movePoint(deskWidth/2-frmX/2,deskHeigth/2-frmY/2);
    w.move(movePoint);
    w.show();

    return a.exec();
}
