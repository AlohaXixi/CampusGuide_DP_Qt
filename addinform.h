#ifndef ADDINFORM_H
#define ADDINFORM_H

#include <QWidget>
#include <QDateTime>
#include <QTime>
#include <QTimeZone>
#include <QDate>
#include <QButtonGroup>
#include <QMessageBox>
#include <QFile>

#include "process.h"

#include <queue>
#include <fstream>
#include <iostream>

#define allPlaceNum 20
#define vel 70     //人正常的步行速度 70m/min
using namespace::std;


namespace Ui {
class AddInform;
}

class AddInform : public QWidget
{
    Q_OBJECT

public:
    explicit AddInform(QWidget *parent = nullptr);
    ~AddInform();

    int selectedPlace[allPlaceNum]{0};           //用于记录已选择的地点序号
    int stayTime_order[allPlaceNum]{0};          //用于停留时间（按顺序）设置
    int stayTime_route[allPlaceNum]{0};          //用于停留时间（按路径）设置
    int selectedPlaceNum{0};                     //所选地点个数
    queue <int> route;                   //保存具体路径
    queue <int> time;                  //保存两两景点间步行所需时间
    int walkTime[allPlaceNum];         //存储按路径行走 两两地点间隔时间
    int walkRoute[allPlaceNum];        //存储路径
    int allTime{0};                    //总用时
    QDateTime arriveTime[allPlaceNum];       //存储到达时间
    QString arriveTimeS[allPlaceNum];        //字符串形式的存储到达时间，用于传递参数
    QString placeName[allPlaceNum]={"二号宿舍楼","信息楼","软件楼","实训楼","经管楼","人文楼","奥林匹克体育馆","奥运餐厅","逸夫图书馆",
                                   "游泳馆","校医院","北田径场","建国饭店","金工楼","网球场"};

    fstream fp;

signals:
    void startNow();                     //若开始时间为当前时间
    void startSet();                     //自定义开始时间
    void AddMap();                      //addInform发射给Imformation的信号
    void SignalDataToMap(int walkRoute[allPlaceNum],QDateTime arriveTime[allPlaceNum],int stayTime_route[allPlaceNum],int walkTime[allPlaceNum]);
    //void SignalDataToMap(int,QDateTime,int,int);
   // void SignalDataToMap(int walkRoute[allPlaceNum],QDateTime,int stayTime_route[allPlaceNum],int walkTime[allPlaceNum]);
    void signalDataToInform(int);   //传递selectedPlaceNum
    void SignalWalkRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);    //传递walkRoute[allPlaceNum]
    void SignalArriveTimeToInform(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);    //传递arriveTime[allPlaceNum]
    void SignalStayTimeRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);    //传递stayTime_route[allPlaceNum]
    void inputFile();

private slots:
    void doProcessAddStartPlace(bool);       //接受“添加”按钮的槽,读取LineText,增加起始地点
    void doProcessAddOtherPlaceAndStartTime(bool);     //接受“确定”按钮的槽，根据QCheckBox和QLineEdit进行地点选择和停留时间输入
  //  void doProcessOutput(bool);         //接受“添加”“完成”按钮的槽，在QPlainTextEdit输出
    void doProcessFindRoute(bool);       //初始化所选择景点的距离矩阵，及压缩矩阵，发送信号，进行路径选择
    void doProcessStartNow();            //目前时间为开始时间，计算到达时间
    void doProcessStartSet();            //自定义起始时间，计算到达时间
    void doProcessAddMap(bool);              //显示地图的槽
    void doProcessClean(bool);           //清空所有信息
    void doProcessInputFile();           //将信息输入进txt文件

private:
    Ui::AddInform *ui;
    int inputNum;              //每次输入LineEdit的数字
    int** matrix;              //所选地点之间距离  用二维矩阵存储
    Process** dp;              //状态压缩矩阵
    int shortestDistance{0};   //所走路径最短距离
    QButtonGroup *btnGroupPlace;    //存储选择地点的QButtonGroup
    QButtonGroup *btnGroupStartTime;   //存储选择开始时间方式的QButtonGroup


    void Init();
    void InitMatrix(int map[15][15]);
    void GetShortestDistance();              //选择最短路径
    void GetRoute();                      //求具体路径
    void Output();
    QDateTime myAddMinute(QDateTime time1,int addtime);
    void calculateAllTime();
    void overtime();
    void clean();
    void modify();


};

#endif // ADDINFORM_H
