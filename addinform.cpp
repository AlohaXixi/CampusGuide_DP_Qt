#include "addinform.h"
#include "ui_addinform.h"
#include "process.h"
#include "alldistancedata.h"

#include <QString>
#include <QDebug>


AddInform::AddInform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddInform)
{
    ui->setupUi(this);
    Init();
}


AddInform::~AddInform()
{
    delete ui;
}



/*************************************功能函数实现************************************************/
void AddInform::Init(){

    //初始化QButtonGroup，以及把相应的选择出发时间的QRadioButton添加进来并设置ID
    btnGroupStartTime = new QButtonGroup(this);
    btnGroupStartTime->addButton(ui->radioButton_1,1);
    btnGroupStartTime->addButton(ui->radioButton_2,2);


    connect(ui->pbt1,SIGNAL(clicked(bool)),this,SLOT(doProcessAddStartPlace(bool)));
    connect(ui->pbt2,SIGNAL(clicked(bool)),this,SLOT(doProcessAddOtherPlaceAndStartTime(bool)));
    connect(ui->ptb_clear,SIGNAL(clicked(bool)),this,SLOT(doProcessClean(bool)));
    connect(ui->findroute,SIGNAL(clicked(bool)),this,SLOT(doProcessFindRoute(bool)));
    connect(this,SIGNAL(startNow()),this,SLOT(doProcessStartNow()));
    connect(this,SIGNAL(startSet()),this,SLOT(doProcessStartSet()));
    connect(this,SIGNAL(inputFile()),this,SLOT(doProcessInputFile()));


    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->groupBox_output->setStyleSheet("QGroupBox{background:rgb(255, 255, 166);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}");
    ui->groupBox_alltime->setStyleSheet("QGroupBox{background:rgb(255, 255, 166);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}");

    ui->pbt1->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->pbt2->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->ptb_clear->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->findroute->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );


  /*  QDateTime *datetime=new QDateTime(QDateTime::currentDateTime());
        QString tmp=datetime->date().toString()+" "+datetime->time().toString();
        ui->label->setText(tmp);*/

      //  QDateTime time1=QDateTime::fromString("19:45:20","hh:mm:ss");
        //QDateTime time2=time1.addSecs(4980);
       // qDebug()<<time1.toString("yyyy-MM-dd hh:mm:ss");
       // qDebug()<<myAddMinute(time1,15).toString("yyyy-MM-dd hh:mm:ss");
}


void AddInform::InitMatrix(int map[15][15]){    //初始化所选择景点的距离矩阵，及压缩矩阵
    int i, j;
    matrix = (int**)new int* [selectedPlaceNum];              //初始化所选择景点的距离矩阵
    for (i = 0; i < selectedPlaceNum; i++)
        matrix[i] = new int[selectedPlaceNum];
    for(i=0;i<selectedPlaceNum;i++)
        for (j = 0; j < selectedPlaceNum; j++) {
            matrix[i][j] = map[selectedPlace[i]][selectedPlace[j]];
        }

    dp = new Process* [selectedPlaceNum];                      //为压缩矩阵申请空间
    for (int i = 0; i < selectedPlaceNum; i++) {
        dp[i] = new Process[1 << (selectedPlaceNum - 1)];
    }
}

void AddInform::GetShortestDistance(){
    int i, j, k;
    //初始化第一列
    for (i = 0; i < selectedPlaceNum; i++)
    {
        dp[i][0].distance = matrix[i][0];           //第一列即为所选择地点距离矩阵第一列，因为是到终点（同时为起点）
        dp[i][0].pre = i;                           //前一景点下标为当前的i（压缩矩阵的第i行）
        dp[i][0].now = 0;
    }
    //初始化剩余列
    for (j = 1; j < (1 << (selectedPlaceNum - 1)); j++)    //j表示列
    {
        for (i = 0; i < selectedPlaceNum; i++)            //i表示行
        {
            dp[i][j].distance = 0x7ffff;//设0x7ffff为无穷大

            //对于数字x，要看它的第i位是不是1，通过判断布尔表达式 (((x >> (i - 1) ) & 1) == 1的真值来实现
            // 判断后续所走集合中是否包含前一已走过地点
            if (((j >> (i - 1)) & 1) == 1)
            {
                continue;
            }
            for (k = 1; k < selectedPlaceNum; k++)
            {
                //不能达到k城市
                if (((j >> (k - 1)) & 1) == 0)           //判断地点选择集合中是否包含k城市
                {
                    continue;
                }
                if (dp[i][j].distance > matrix[i][k] + dp[k][j ^ (1 << (k - 1))].distance)
                {
                    dp[i][j].distance = matrix[i][k] + dp[k][j ^ (1 << (k - 1))].distance;
                    dp[i][j].pre = i;
                    dp[i][j].now = k;
                    dp[i][j].next = j ^ (1 << (k - 1));

                }
            }
        }
    }
   // cout << "最短路径为" << dp[0][(1 << (selectedPlaceNum - 1)) - 1].distance << endl;
   // cout << endl;
    shortestDistance=dp[0][(1 << (selectedPlaceNum - 1)) - 1].distance;

}

void AddInform::GetRoute(){
    fp.open("route.txt", ios::out | ios::in);
    int i = 0,j= (1 << (selectedPlaceNum - 1)) - 1;
    int temp_i, temp_j;
    double each_time = 0;
    int temp;
    for (int k = 0; k < selectedPlaceNum ; k++) {
        route.push(dp[i][j].pre);                     //从出发地点开始，依次将pre push进队列
        each_time = matrix[dp[i][j].pre][dp[i][j].now] / (vel*1.0);     //计算路径上相邻两地点的步行时间
        temp = (int)(each_time + 0.5);      //将步行时间的小数四舍五入为整数
        time.push(temp);
        temp_i = dp[i][j].now;
        temp_j = dp[i][j].next;
        i = temp_i;
        j = temp_j;
    }

   int d=0;                                          //输出路径信息
   QString sRoute{""};
    while (!route.empty()) {
        int x = route.front();
        route.pop();
        if(d>0){
        stayTime_route[d] = stayTime_order[x];
        }
        walkRoute[d] = selectedPlace[x]+1;
        d++;
        sRoute = sRoute + QString::number(selectedPlace[x]+1)+" -> ";        
        fp << selectedPlace[x] + 1 << " -> ";
    }
    walkRoute[d] = selectedPlace[0]+1;
    sRoute = sRoute + QString::number(selectedPlace[0]+1);
    ui->label_route->setText(sRoute);
    fp << selectedPlace[0] + 1 << endl;
    fp.close();

    //qDebug()<<"步行时间依次为：";
    int k=0;
    while (!time.empty()) {
        int t = time.front();
        walkTime[k]=t;
        k++;
        time.pop();
      //qDebug() << QString::number(t) + " ";
    }

    QString SStayTime{""};
    for(int i=1;i<selectedPlaceNum;i++){
       SStayTime = SStayTime + QString::number(stayTime_route[i]) + "min ";
    }
    ui->label_staytime->setText(SStayTime);

}


QDateTime AddInform::myAddMinute(QDateTime time1, int addtime){    //addtime以分钟为单位
    const QTimeZone zone = time1.timeZone();
    const QDate qdate = time1.date();
    int hour = time1.toString("hh").toInt();
    int minute = time1.toString("mm").toInt();
    int second = time1.toString("ss").toInt();
    int tempTime = addtime*60;              //将addtime转换为秒为单位
    int addhour = tempTime/3600;
    int addminute = (tempTime%3600)/60;
    int addsecond = (tempTime%3600)%60;

    int nowhour,nowminute,nowsecond;

    nowsecond = second + addsecond;

    if(nowsecond>=60){
        addminute++;
        nowsecond = nowsecond%60;
    }

    nowminute = minute + addminute;
    if(nowminute>=60){
        addhour++;
        nowminute = nowminute%60;
    }

    nowhour = (hour+addhour)%24;

    QTime qtime(nowhour,nowminute,nowsecond,0);
    QDateTime result(qdate,qtime,zone);
    return result;

}


void AddInform::calculateAllTime(){
    QString sAllTime{""};
    for(int i=0;i<selectedPlaceNum;i++){
        allTime = allTime + walkTime[i];
        if(i>0){
          allTime = allTime + stayTime_route[i];
        }

    }
    sAllTime = QString::number(allTime) + "min";
    ui->label_alltime->setText(sAllTime);

}

void AddInform::overtime(){
    QMessageBox::StandardButton ret = QMessageBox::information(this,"提示",
                                                               "您选择的路线时间超过22点，景点多已关闭，建议您更改地点\nYes：全部清空   No：继续   Reset：修改",
                                                               QMessageBox::Yes|QMessageBox::No|QMessageBox::Reset,QMessageBox::Yes);
    if(ret == QMessageBox::Yes){
        clean();
    }else if(ret == QMessageBox::Reset){
        modify();
    }
}

void AddInform::clean(){
    ui->lineEdit1->setText("");
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");

    //ui->radioButton_1->s
    //ui->radioButton_2->setChecked(false);

    ui->checkBox_1->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->checkBox_4->setCheckState(Qt::Unchecked);
    ui->checkBox_5->setCheckState(Qt::Unchecked);
    ui->checkBox_6->setCheckState(Qt::Unchecked);
    ui->checkBox_7->setCheckState(Qt::Unchecked);
    ui->checkBox_8->setCheckState(Qt::Unchecked);
    ui->checkBox_9->setCheckState(Qt::Unchecked);
    ui->checkBox_10->setCheckState(Qt::Unchecked);
    ui->checkBox_11->setCheckState(Qt::Unchecked);
    ui->checkBox_12->setCheckState(Qt::Unchecked);
    ui->checkBox_13->setCheckState(Qt::Unchecked);
    ui->checkBox_14->setCheckState(Qt::Unchecked);
    ui->checkBox_15->setCheckState(Qt::Unchecked);

    for(int i = 0; i < 20; i++){
        selectedPlace[i] = 0;           //用于记录已选择的地点序号
        stayTime_order[i] = 0;          //用于停留时间（按顺序）设置
        stayTime_route[i] = 0;
        walkTime[i] = 0;         //存储按路径行走 两两地点间隔时间
        walkRoute[i] = 0;
    }
    for(int i = 0; i < selectedPlaceNum; i++)
        for (int j = 0; j < selectedPlaceNum; j++) {
            matrix[i][j] = 0;
        }
    shortestDistance = 0;
    selectedPlaceNum = 0;
    allTime = 0;
    ui->label_route->setText("");
    ui->label_alltime->setText("");
    ui->label_staytime->setText("");
    ui->label_arrivetime_1->setText("");
    ui->label_arrivetime_2->setText("");

}

void AddInform::modify(){
    for(int i = 0; i < 20; i++){
        selectedPlace[i] = 0;           //用于记录已选择的地点序号
        stayTime_order[i] = 0;          //用于停留时间（按顺序）设置
        stayTime_route[i] = 0;
        walkTime[i] = 0;         //存储按路径行走 两两地点间隔时间
        walkRoute[i] = 0;
    }
    for(int i = 0; i < selectedPlaceNum; i++)
        for (int j = 0; j < selectedPlaceNum; j++) {
            matrix[i][j] = 0;
        }
    shortestDistance = 0;
    selectedPlaceNum = 0;
    allTime = 0;
}

/*************************************槽函数实现**************************************/

void AddInform::doProcessAddStartPlace(bool){
    //添加地点 读取LineEdit内容
    QString s=ui->lineEdit1->text();
    inputNum=s.toInt();
    //qDebug()<<inputNum<<endl;
    selectedPlace[selectedPlaceNum]=inputNum-1;    //存储的是序号对应地点的下标
    selectedPlaceNum++;
}

void AddInform::doProcessAddOtherPlaceAndStartTime(bool){    
    //输入后续点

    QString SStayTime{""};

    if(ui->checkBox_1->isChecked()){
        selectedPlace[selectedPlaceNum] = 0;     //0为该地点对应的下标
        QString timeS = ui->lineEdit_1->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_2->isChecked()){
        selectedPlace[selectedPlaceNum] = 1;     //1为该地点对应的下标
        QString timeS = ui->lineEdit_2->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_3->isChecked()){
        selectedPlace[selectedPlaceNum] = 2;     //2为该地点对应的下标
        QString timeS = ui->lineEdit_3->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_4->isChecked()){
        selectedPlace[selectedPlaceNum] = 3;     //3为该地点对应的下标
        QString timeS = ui->lineEdit_4->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_5->isChecked()){
        selectedPlace[selectedPlaceNum] = 4;     //4为该地点对应的下标
        QString timeS = ui->lineEdit_5->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_6->isChecked()){
        selectedPlace[selectedPlaceNum] = 5;     //5为该地点对应的下标
        QString timeS = ui->lineEdit_6->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_7->isChecked()){
        selectedPlace[selectedPlaceNum] = 6;     //6为该地点对应的下标
        QString timeS = ui->lineEdit_7->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_8->isChecked()){
        selectedPlace[selectedPlaceNum] = 7;     //7为该地点对应的下标
        QString timeS = ui->lineEdit_8->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_9->isChecked()){
        selectedPlace[selectedPlaceNum] = 8;     //8为该地点对应的下标
        QString timeS = ui->lineEdit_9->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_10->isChecked()){
        selectedPlace[selectedPlaceNum] = 9;     //9为该地点对应的下标
        QString timeS = ui->lineEdit_10->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_11->isChecked()){
        selectedPlace[selectedPlaceNum] = 10;     //10为该地点对应的下标
        QString timeS = ui->lineEdit_11->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_12->isChecked()){
        selectedPlace[selectedPlaceNum] = 11;     //11为该地点对应的下标
        QString timeS = ui->lineEdit_12->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_13->isChecked()){
        selectedPlace[selectedPlaceNum] = 12;     //12为该地点对应的下标
        QString timeS = ui->lineEdit_13->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_14->isChecked()){
        selectedPlace[selectedPlaceNum] = 13;     //13为该地点对应的下标
        QString timeS = ui->lineEdit_14->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
    if(ui->checkBox_15->isChecked()){
        selectedPlace[selectedPlaceNum] = 14;     //2为该地点对应的下标
        QString timeS = ui->lineEdit_15->text();
        int time = timeS.toInt();
        stayTime_order[selectedPlaceNum] = time;
        selectedPlaceNum++;
    }
}



void AddInform::doProcessFindRoute(bool){     //初始化所选择景点的距离矩阵，及压缩矩阵，发送信号，进行路径选择
    QString s{""};
    /*for(int i=0;i<selectedPlaceNum;i++){
        qDebug()<<QString::number(selectedPlace[i])+" "<<QString::number(stayTime_route[i]);
    }   */
    InitMatrix(BJUTmap);
    GetShortestDistance();
    //qDebug()<<shortestDistance;
    GetRoute();
    calculateAllTime();
    if(ui->radioButton_1->isChecked()){
        emit startNow();
    }
    if(ui->radioButton_2->isChecked()){
        emit startSet();
    }

    // 发射传递参数的信号
    emit signalDataToInform(selectedPlaceNum);
    emit SignalWalkRouteToInform(walkRoute[0],walkRoute[1],walkRoute[2],walkRoute[3],walkRoute[4],walkRoute[5],walkRoute[6],walkRoute[7],walkRoute[8],
            walkRoute[9],walkRoute[10],walkRoute[11],walkRoute[12],walkRoute[13],walkRoute[14],walkRoute[15],walkRoute[16],walkRoute[17],
            walkRoute[18],walkRoute[19]);
    emit SignalArriveTimeToInform(arriveTimeS[0],arriveTimeS[1],arriveTimeS[2],arriveTimeS[3],arriveTimeS[4],arriveTimeS[5],arriveTimeS[6],
            arriveTimeS[7],arriveTimeS[8],arriveTimeS[9],arriveTimeS[10],arriveTimeS[11],arriveTimeS[12],arriveTimeS[13],arriveTimeS[14],
            arriveTimeS[15],arriveTimeS[16],arriveTimeS[17],arriveTimeS[18],arriveTimeS[19]);    //传递arriveTime[allPlaceNum]
    emit SignalStayTimeRouteToInform(stayTime_route[0],stayTime_route[1],stayTime_route[2],stayTime_route[3],stayTime_route[4],
            stayTime_route[5],stayTime_route[6],stayTime_route[7],stayTime_route[8],stayTime_route[9],stayTime_route[10],stayTime_route[11],
            stayTime_route[12],stayTime_route[13],stayTime_route[14],stayTime_route[15],stayTime_route[16],stayTime_route[17],
            stayTime_route[18],stayTime_route[19]);
    emit inputFile();

}

void AddInform::doProcessStartNow(){                        //以当前时间为开始时间，用于计算依次到达时间
    QDateTime *NowTime=new QDateTime(QDateTime::currentDateTime());
    QDateTime temp = myAddMinute(*NowTime,stayTime_route[0]);
    QString sTime1{""};
    QString sTime2{""};
    //qDebug()<<NowTime->date().toString()+" "+NowTime->time().toString();
    //qDebug()<<temp.toString("yyyy-MM-dd hh:mm:ss");
    arriveTime[0] = temp;                                                   //起点时间为当前时间
    //qDebug()<<arriveTime[0].toString("yyyy-MM-dd hh:mm:ss");
   // qDebug()<<arriveTime[0].toString("hh:mm");
    sTime1 = sTime1 + arriveTime[0].toString("hh:mm")+"  ";
    arriveTimeS[0]=arriveTime[0].toString("hh:mm");
    for(int i=1;i<selectedPlaceNum+1;i++){
        //qDebug()<<"111";        
        temp = myAddMinute(temp,walkTime[i-1]);                              //之后每次的到达时间，先在上次循环结束的基础上加上步行时间，记录为到达时间
        arriveTime[i]=temp;
        arriveTimeS[i] = arriveTime[i].toString("hh:mm");
        //qDebug()<<arriveTime[i].toString("yyyy-MM-dd hh:mm:ss");
        //qDebug()<<arriveTime[i].toString("hh:mm");
        if(i<8){
            sTime1 = sTime1 + arriveTime[i].toString("hh:mm")+"  ";
        }
        else{
            sTime2 = sTime2 + arriveTime[i].toString("hh:mm")+"  ";
        }
        temp = myAddMinute(temp,stayTime_route[i]);                        //之后在到达时间上，加上停留时间，为每次离开时间
    }

    ui->label_arrivetime_1->setText(sTime1);
    ui->label_arrivetime_2->setText(sTime2);

    int hour =arriveTime[selectedPlaceNum].toString("hh").toInt();
    //qDebug()<<"hour: "<<hour;
    if(hour > 21|| hour < 6){
        overtime();
    }

}

void AddInform::doProcessStartSet(){                                  //以自定义时间为开始时间，用于计算依次到达时间
    QDateTime setTime = ui->dateTimeEdit->dateTime();
    //qDebug()<<setTime.toString("hh:mm");
    QDateTime temp = myAddMinute(setTime,stayTime_route[0]);
    QString sTime1{""};
    QString sTime2{""};
    //qDebug()<<NowTime->date().toString()+" "+NowTime->time().toString();
    //qDebug()<<temp.toString("yyyy-MM-dd hh:mm:ss");
    arriveTime[0] = temp;                                            //起点时间为开始时间
    //qDebug()<<arriveTime[0].toString("yyyy-MM-dd hh:mm:ss");
    //qDebug()<<arriveTime[0].toString("hh:mm");
    sTime1 = sTime1 + arriveTime[0].toString("hh:mm")+" ";
    arriveTimeS[0]=arriveTime[0].toString("hh:mm");
    for(int i=1;i<selectedPlaceNum+1;i++){
        temp = myAddMinute(temp,walkTime[i-1]);                     //之后每次的到达时间，先在上次循环结束的基础上加上步行时间，记录为到达时间
        arriveTime[i] = temp;
        arriveTimeS[i] = arriveTime[i].toString("hh:mm");
        //qDebug()<<arriveTime[i].toString("yyyy-MM-dd hh:mm:ss");
        //qDebug()<<arriveTime[i].toString("hh:mm");
        if(i<8){
            sTime1 = sTime1 + arriveTime[i].toString("hh:mm")+"  ";
        }
        else{
            sTime2 = sTime2 + arriveTime[i].toString("hh:mm")+"  ";
        }
        temp = myAddMinute(temp,stayTime_route[i]);                 //之后在到达时间上，加上停留时间，为每次离开时间
    }


    ui->label_arrivetime_1->setText(sTime1);
    ui->label_arrivetime_2->setText(sTime2);

    int hour =arriveTime[selectedPlaceNum].toString("hh").toInt();
   // qDebug()<<"hour: "<<hour;
    if(hour > 21|| hour < 6 ){
        overtime();
    }

}


void AddInform::doProcessAddMap(bool){
    emit AddMap();
}

void AddInform::doProcessClean(bool){
    clean();
}

void AddInform::doProcessInputFile(){
    QString txt = "";

    QFile file("D:\\Junior1\\DS_Qt\\CampusGuide_DP_QT\\Email\\route.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    txt.append("您所查询的路径为:\n");
    QString route1 = "";
    for(int i = 0; i < selectedPlaceNum; i++){
        route1.append(placeName[walkRoute[i]-1]+"->");
    }
    route1.append(placeName[walkRoute[0]-1]+"\n");
    txt.append(route1);

    txt.append("\n依次到达时间为（第一个时间为起始时间）：\n");
    QString atime = "";
    for(int i = 0; i < selectedPlaceNum+1; i++){
        atime.append(arriveTimeS[i]+"  ");
    }
    txt.append(atime+"\n");

    txt.append("\n依次停留时间为（无起点）：\n");
    QString stime ="";
    for(int i = 1; i < selectedPlaceNum; i++){
        stime.append(QString::number(stayTime_route[i])+"min  ");
    }
    txt.append(stime+"\n");

    txt.append("\n总用时为：" + QString::number(allTime)+"min\n");


    file.write(txt.toUtf8());
}







