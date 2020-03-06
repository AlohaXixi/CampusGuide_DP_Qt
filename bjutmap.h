#ifndef BJUTMAP_H
#define BJUTMAP_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QScreen>
#include <QWindow>
#include <QRect>
#include <QLabel>*
#include "addinform.h"

#define allPoint 47

namespace Ui {
class bjutmap;
}

class bjutmap : public QWidget
{
    Q_OBJECT

public:
    explicit bjutmap(QWidget *parent = nullptr);
    ~bjutmap();

                         //所选地点个数
signals:
    void callSendEmail();
    void ReturnToInquiry();


private slots:
    void doProcessDataToMap(int);
    void doProcessSaveWalkRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void doProcessSaveArriveTimeToMap(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);    //传递arriveTime[allPlaceNum]
    void doProcessSaveStayTimeRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void doProcessClickedSendEmail(bool);       //点击发送邮件的按钮
    void doProcessGrabScreen(bool);       //点击截图的按钮
    void doProcessReturnToInquiry(bool);

protected:
   void paintEvent(QPaintEvent*event);

private:
    Ui::bjutmap *ui;
    QPoint point[allPoint];            //存储所有的点
    int flag_point[allPoint][allPoint];   //点与点之间是否有连线标志位，如果有，值为1，否则为0
    int walkRoute[allPlaceNum];         //walkroute存储的不是下标，而是标号
    QString arriveTime[allPlaceNum];
    int selectedPlaceNum{0};
    int s=4;
    int walk[4]={1,2,3,1};
    int a=1;
    int i,help;
    int stayTime_route[allPlaceNum];
    QScreen *screen;
    QWindow *window/*=windowHandle()*/;
   //int walkTime[allPlaceNum];
    QPixmap pic[allPlaceNum];
    QLabel *label[allPlaceNum];


   void Init();
   void InitPoint();
   void InitPic();
   void setRouteLine();      //通过设置flag标志位，设置点之间的线段
   void outputInformation();   //用于页面显示路径等信息
   void printPlaceOrder();

};

#endif // BJUTMAP_H
