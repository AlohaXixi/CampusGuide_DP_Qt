#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include <QTextCodec>
#include <QDesktopWidget>
#include "AddInform.h"
#include "inquiry.h"
#include "bjutmap.h"
#include "profession.h"
#include "frmmain.h"
#include "recommend.h"


namespace Ui {
class Information;
}

class Information : public QWidget
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

signals:
    void SignalDataToMap(int);
    void SignalWalkRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);    //传递walkRoute[allPlaceNum]
    void SignalArriveTimeToMap(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);    //传递arriveTime[allPlaceNum]
    void SignalStayTimeRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);    //传递stayTime_route[allPlaceNum]

private slots:
    void GoToAddInformation(bool);
    void GoToInquiry(bool);
    void GoToProfessionIntro(bool);
    void GoToRecommend(bool);
    void GoToMap(bool);
    void GoToSendEmail();
    void BjutMapReturnToThis();

    //用于传递参数的槽
    void doProcessDataToInform(int);
    void doProcessSaveWalkRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void doProcessSaveArriveTimeToInform(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);    //传递arriveTime[allPlaceNum]
    void doProcessSaveStayTimeRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);


private:
    Ui::Information *ui;
    AddInform *addInformaitonForm;
    Inquiry *inquiry;
    Profession *profession;
    Recommend *recommend;
    bjutmap *MyMap;
    frmMain w;
    int flag_addInformation = 0; //标记信息录入界面是否被选中
    int flag_inquiry = 0;   //标记信息查询界面是否被选中
    int flag_profession = 0;    //标记专业介绍界面是否被选中
    int flag_recommend = 0;    //标记选修课推荐界面是否被选中

    int walkRoute[allPlaceNum];
    QDateTime arriveTime[allPlaceNum];
    int stayTime_route[allPlaceNum];
    int walkTime[allPlaceNum];

    void Init();
};

#endif // INFORMATION_H
