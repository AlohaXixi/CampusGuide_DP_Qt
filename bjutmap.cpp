#include "bjutmap.h"
#include "ui_bjutmap.h"
#include <QDebug>
#include <QSize>

bjutmap::bjutmap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bjutmap)
{
    ui->setupUi(this);
    Init();
}

bjutmap::~bjutmap()
{
    delete ui;
}

/**********************************功能函数实现***********************************************/
void bjutmap::Init(){
    setAutoFillBackground(true);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(87,87,87));
    setPalette(palette);

    QPalette p1;
    p1.setColor(QPalette::Background, QColor(70,70,70));
    ui->placeInformation->setAutoFillBackground(true);
    ui->placeInformation->setPalette(p1);


    ui->pushButton_screen->setStyleSheet(
                "QPushButton{background-color:rgb(255, 255, 168);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QPushButton:hover{background-color:rgb(255, 255, 221)}"
                "QPushButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );
    ui->pushButton_email->setStyleSheet(
                "QPushButton{background-color:rgb(255, 255, 168);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QPushButton:hover{background-color:rgb(255, 255, 221)}"
                "QPushButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );
    ui->pushButton_return->setStyleSheet(
                "QPushButton{background-color:rgb(255, 255, 168);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QPushButton:hover{background-color:rgb(255, 255, 221)}"
                "QPushButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );


    screen = QGuiApplication::primaryScreen();

    connect(ui->pushButton_email,SIGNAL(clicked(bool)),this,SLOT(doProcessClickedSendEmail(bool)));
    connect(ui->pushButton_screen,SIGNAL(clicked(bool)),this,SLOT(doProcessGrabScreen(bool)));
    connect(ui->pushButton_return,SIGNAL(clicked(bool)),this,SLOT(doProcessReturnToInquiry(bool)));

    InitPoint();
    InitPic();
    //printPlaceOrder();

}

void bjutmap::InitPoint(){

    //初始化各点的坐标
    point[0] = QPoint(170,180);
    point[1] = QPoint(82,565);
    point[2] = QPoint(865,675);
    point[3] = QPoint(801,750);
    point[4] = QPoint(138,715);
    point[5] = QPoint(340,855);
    point[6] = QPoint(580,745);
    point[7] = QPoint(435,655);
    point[8] = QPoint(240,593);
    point[9] = QPoint(452,340);
    point[10] = QPoint(425,115);
    point[11] = QPoint(478,340);
    point[12] = QPoint(145,825);
    point[13] = QPoint(493,130);
    point[14] = QPoint(485,450);
    point[15] = QPoint(240,180);
    point[16] = QPoint(425,180);
    point[17] = QPoint(468,340);
    point[18] = QPoint(468,180);
    point[19] = QPoint(493,180);
    point[20] = QPoint(468,407);
    point[21] = QPoint(485,407);
    point[22] = QPoint(485,655);
    point[23] = QPoint(240,655);
    point[24] = QPoint(82,180);
    point[25] = QPoint(82,407);
    point[26] = QPoint(240,407);
    point[27] = QPoint(192,407);
    point[28] = QPoint(290,407);
    point[29] = QPoint(192,593);
    point[30] = QPoint(290,593);
    point[31] = QPoint(80,665);
    point[32] = QPoint(159,665);
    point[33] = QPoint(159,710);
    point[34] = QPoint(159,825);
    point[35] = QPoint(318,855);
    point[36] = QPoint(318,670);
    point[37] = QPoint(318,780);
    point[38] = QPoint(485,783);
    point[39] = QPoint(743,718);
    point[40] = QPoint(695,625);
    point[41] = QPoint(598,407);
    point[42] = QPoint(192,658);
    point[43] = QPoint(290,645);
    point[44] = QPoint(485,675);
    point[45] = QPoint(435,673);
    point[46] = QPoint(600,716);


    //设置flag标志位初始为0
    for(int i = 0; i < allPoint; i++)
        for(int j = 0; j < allPoint; j++){
            flag_point[i][j] = 0;
        }
}


void bjutmap::InitPic(){
    pic[0] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location1.png");
    pic[1] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location2.png");
    pic[2] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location3.png");
    pic[3] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location4.png");
    pic[4] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location5.png");
    pic[5] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location6.png");
    pic[6] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location7.png");
    pic[7] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location8.png");
    pic[8] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location9.png");
    pic[9] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location10.png");
    pic[10] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location11.png");
    pic[11] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location12.png");
    pic[12] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location13.png");
    pic[13] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location14.png");
    pic[14] = QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\location15.png");

    QSize picSize(50,50);
    pic[0] = pic[0].scaled(picSize, Qt::KeepAspectRatio);
    pic[1] = pic[1].scaled(picSize, Qt::KeepAspectRatio);
    pic[2] = pic[2].scaled(picSize, Qt::KeepAspectRatio);
    pic[3] = pic[3].scaled(picSize, Qt::KeepAspectRatio);
    pic[4] = pic[4].scaled(picSize, Qt::KeepAspectRatio);
    pic[5] = pic[5].scaled(picSize, Qt::KeepAspectRatio);
    pic[6] = pic[6].scaled(picSize, Qt::KeepAspectRatio);
    pic[7] = pic[7].scaled(picSize, Qt::KeepAspectRatio);
    pic[8] = pic[8].scaled(picSize, Qt::KeepAspectRatio);
    pic[9] = pic[9].scaled(picSize, Qt::KeepAspectRatio);
    pic[10] = pic[10].scaled(picSize, Qt::KeepAspectRatio);
    pic[11] = pic[11].scaled(picSize, Qt::KeepAspectRatio);
    pic[12] = pic[12].scaled(picSize, Qt::KeepAspectRatio);
    pic[13] = pic[13].scaled(picSize, Qt::KeepAspectRatio);
    pic[14] = pic[14].scaled(picSize, Qt::KeepAspectRatio);

    for(int i = 0; i < allPlaceNum; i++){    //标签[0]对应地点1 指标号飞下标
        label[i] = new QLabel(this);
        label[i]->setGeometry(point[i].rx()-20,point[i].ry()-50,50,50);
    }
}






void bjutmap::outputInformation(){
    //输出路线信息
    QString routeS1{""};
    QString routeS2{""};
    QString routeS3{""};
    QString routeS4{""};

    for(int i = 0; i < selectedPlaceNum; i++){
        if(i < 4){
           routeS1 = routeS1 + QString::number(walkRoute[i])+" -> ";
        }else if(i < 8){
           routeS2 = routeS2 + QString::number(walkRoute[i])+" -> ";
        }else if(i < 12){
           routeS3 = routeS3 + QString::number(walkRoute[i])+" -> ";
        }else{
           routeS4 = routeS4 + QString::number(walkRoute[i])+" -> ";
        }
    }

    //添加起点
    if(selectedPlaceNum < 4){
       routeS1 = routeS1 + QString::number(walkRoute[0]);
    }else if(selectedPlaceNum < 8){
       routeS2 = routeS2 + QString::number(walkRoute[0]);
    }else if(selectedPlaceNum < 12){
       routeS3 = routeS3 + QString::number(walkRoute[0]);
    }else{
       routeS4 = routeS4 + QString::number(walkRoute[0]);
    }

    QPalette p;
    p.setColor(QPalette::WindowText,QColor(255,255,197));
    ui->label_route_1->setPalette(p);
    ui->label_route_2->setPalette(p);
    ui->label_route_3->setPalette(p);
    ui->label_route_4->setPalette(p);
    ui->label_route_1->setText(routeS1);
    ui->label_route_2->setText(routeS2);
    ui->label_route_3->setText(routeS3);
    ui->label_route_4->setText(routeS4);

    //输出到达时间信息
    QString arriveTimeS1{""};
    QString arriveTimeS2{""};
    QString arriveTimeS3{""};
    QString arriveTimeS4{""};

    for(int i = 0; i < selectedPlaceNum+1; i++){
        if(i < 4){
           arriveTimeS1 = arriveTimeS1 + arriveTime[i]+" ";
        }else if(i < 8){
           arriveTimeS2 = arriveTimeS2 + arriveTime[i]+" ";
        }else if(i < 12){
           arriveTimeS3 = arriveTimeS3 + arriveTime[i]+" ";
        }else{
           arriveTimeS4 = arriveTimeS4 + arriveTime[i]+" ";
        }
    }

    ui->label_arrivetime_1->setPalette(p);
    ui->label_arrivetime_2->setPalette(p);
    ui->label_arrivetime_3->setPalette(p);
    ui->label_arrivetime_4->setPalette(p);
    ui->label_arrivetime_1->setText(arriveTimeS1);
    ui->label_arrivetime_2->setText(arriveTimeS2);
    ui->label_arrivetime_3->setText(arriveTimeS3);
    ui->label_arrivetime_4->setText(arriveTimeS4);

    //输出停留时间信息
    QString stayTimeS1{""};
    QString stayTimeS2{""};
    QString stayTimeS3{""};
    QString stayTimeS4{""};

    for(int i = 1; i < selectedPlaceNum; i++){
        if(i < 5){
           stayTimeS1 = stayTimeS1 + QString::number(stayTime_route[i])+"min ";
        }else if(i < 9){
           stayTimeS2 = stayTimeS2 + QString::number(stayTime_route[i])+"min ";
        }else if(i < 13){
           stayTimeS3 = stayTimeS3 + QString::number(stayTime_route[i])+"min ";
        }else{
           stayTimeS4 = stayTimeS4 + QString::number(stayTime_route[i])+"min ";
        }
    }

    ui->label_staytime_1->setPalette(p);
    ui->label_staytime_2->setPalette(p);
    ui->label_staytime_3->setPalette(p);
    ui->label_staytime_4->setPalette(p);
    ui->label_staytime_1->setText(stayTimeS1);
    ui->label_staytime_2->setText(stayTimeS2);
    ui->label_staytime_3->setText(stayTimeS3);
    ui->label_staytime_4->setText(stayTimeS4);
}


void bjutmap::setRouteLine(){

    for(int i = 0; i < selectedPlaceNum; i++){
            if(( walkRoute[i]== 1) && (walkRoute[i+1] == 2)){      //宿舍楼到信息楼   tip walkRoute的值是景点标号，flag_point中是景点下标
                flag_point[0][24]=1;
                flag_point[24][25]=1;
                flag_point[25][1]=1;
            }
            if((walkRoute[i] == 1) && (walkRoute[i+1] == 3)){      //宿舍楼到软件楼
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][41]=1;
                flag_point[41][39]=1;
                flag_point[39][2]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==4)){            //宿舍楼到实训楼
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][41]=1;
                flag_point[41][39]=1;
                flag_point[39][3]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==5)){            //宿舍楼到经管楼
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==6)){            //宿舍楼到人文楼
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][28]=1;
                flag_point[28][43]=1;
                flag_point[43][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==7)){            //宿舍楼到奥林匹克体育馆
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][21]=1;
                flag_point[21][38]=1;
                flag_point[38][6]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==8)){            //宿舍楼到奥运餐厅
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][21]=1;
                flag_point[21][22]=1;
                flag_point[22][7]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==9)){            //宿舍楼到逸夫图书馆
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][27]=1;
                flag_point[27][29]=1;
                flag_point[29][8]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==10)){            //宿舍楼到游泳馆
                flag_point[0][18]=1;
                flag_point[18][17]=1;
                flag_point[17][9]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==11)){            //宿舍楼到校医院
                flag_point[0][16]=1;
                flag_point[16][10]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==12)){            //宿舍楼到北田径场
                flag_point[0][18]=1;
                flag_point[18][17]=1;
                flag_point[17][11]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==13)){            //宿舍楼到建国饭店
                flag_point[0][15]=1;
                flag_point[15][26]=1;
                flag_point[26][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==14)){            //宿舍楼到金工楼
                flag_point[0][19]=1;
                flag_point[19][13]=1;
            }
            if((walkRoute[i]==1)&&(walkRoute[i+1]==15)){            //宿舍楼到网球场
                flag_point[0][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][14]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 1)){      //信息楼到宿舍楼   tip walkRoute的值是景点标号，flag_point中是景点下标
                flag_point[1][25]=1;
                flag_point[25][24]=1;
                flag_point[24][0]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 3)){      //信息楼到软件楼
                flag_point[1][31]=1;
                flag_point[31][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 4)){      //信息楼到实训楼
                flag_point[1][31]=1;
                flag_point[31][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 5)){      //信息楼到经管楼
                flag_point[1][31]=1;
                flag_point[31][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 6)){      //信息楼到人文楼
                flag_point[1][31]=1;
                flag_point[31][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 7)){      //信息楼到奥林匹克体育馆
                flag_point[1][31]=1;
                flag_point[31][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 8)){      //信息楼到奥运餐厅
                flag_point[1][31]=1;
                flag_point[31][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 9)){      //信息楼到逸夫图书馆
                flag_point[1][31]=1;
                flag_point[31][23]=1;
                flag_point[23][8]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 10)){      //信息楼到游泳馆
                flag_point[1][31]=1;
                flag_point[31][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 11)){      //信息楼到校医院
                flag_point[1][25]=1;
                flag_point[25][24]=1;
                flag_point[24][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 12)){      //信息楼到北田径场
                flag_point[1][25]=1;
                flag_point[25][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 13)){      //信息楼到建国饭店
                flag_point[1][31]=1;
                flag_point[31][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 14)){      //信息楼到金工楼
                flag_point[1][25]=1;
                flag_point[25][24]=1;
                flag_point[24][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 2) && (walkRoute[i+1] == 15)){      //信息楼到网球场
                flag_point[1][25]=1;
                flag_point[25][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i] == 3) && (walkRoute[i+1] == 1)){      //软件楼到宿舍楼
                flag_point[2][39]=1;
                flag_point[39][41]=1;
                flag_point[41][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 2)){      //软件楼到信息楼
                flag_point[2][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 4)){      //软件楼到实训楼
                flag_point[2][3]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 5)){      //软件楼到经管楼
                flag_point[2][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 6)){      //软件楼到人文楼
                flag_point[2][39]=1;
                flag_point[39][46]=1;
                flag_point[46][38]=1;
                flag_point[38][37]=1;
                flag_point[37][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 7)){      //软件楼到奥林匹克体育馆
                flag_point[2][39]=1;
                flag_point[39][46]=1;
                flag_point[46][6]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 8)){      //软件楼到奥运餐厅
                flag_point[2][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 9)){      //软件楼到逸夫图书馆
                flag_point[2][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][23]=1;
                flag_point[23][8]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 10)){      //软件楼到游泳馆
                flag_point[2][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 11)){      //软件楼到校医院
                flag_point[2][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 12)){      //软件楼到北田径场
                flag_point[2][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 13)){      //软件楼到建国饭店
                flag_point[2][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 14)){      //软件楼到金工楼
                flag_point[2][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 3) && (walkRoute[i+1] == 15)){      //软件楼到网球场
                flag_point[2][39]=1;
                flag_point[39][41]=1;
                flag_point[41][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==4)&&(walkRoute[i+1]==1)){            //实训楼到宿舍楼
                flag_point[3][39]=1;
                flag_point[39][41]=1;
                flag_point[41][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 2)){      //实训楼到信息楼
                flag_point[3][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 3)){      //实训楼到软件楼
                flag_point[3][2]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 5)){      //实训楼到经管楼
                flag_point[3][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 6)){      //实训楼到人文楼
                flag_point[3][39]=1;
                flag_point[39][46]=1;
                flag_point[46][38]=1;
                flag_point[38][37]=1;
                flag_point[37][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 7)){      //实训楼到奥林匹克体育馆
                flag_point[3][39]=1;
                flag_point[39][46]=1;
                flag_point[46][6]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 8)){      //实训楼到奥运餐厅
                flag_point[3][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 9)){      //实训楼到逸夫图书馆
                flag_point[3][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][23]=1;
                flag_point[23][8]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 10)){      //实训楼到游泳馆
                flag_point[3][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 11)){      //实训楼到校医院
                flag_point[3][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 12)){      //实训楼到北田径场
                flag_point[3][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 13)){      //实训楼到建国饭店
                flag_point[3][39]=1;
                flag_point[39][40]=1;
                flag_point[40][44]=1;
                flag_point[44][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 14)){      //实训楼到金工楼
                flag_point[3][39]=1;
                flag_point[39][41]=1;
                flag_point[41][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 4) && (walkRoute[i+1] == 15)){      //实训楼到网球场
                flag_point[3][39]=1;
                flag_point[39][41]=1;
                flag_point[41][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==5)&&(walkRoute[i+1]==1)){            //经管楼到宿舍楼
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 2)){      //经管楼到信息楼
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 3)){      //经管楼到软件楼
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 4)){      //经管楼到实训楼
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 6)){      //经管楼到人文楼
                flag_point[4][33]=1;
                flag_point[33][34]=1;
                flag_point[34][5]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 7)){      //经管楼到奥林匹克体育馆
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][44]=1;
                flag_point[44][38]=1;
                flag_point[38][46]=1;
                flag_point[46][6]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 8)){      //经管楼到奥运餐厅
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 9)){      //经管楼到逸夫图书馆
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][23]=1;
                flag_point[23][8]=1;
            }
            if((walkRoute[i]==5)&&(walkRoute[i+1]==10)){            //经管楼到游泳馆
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if((walkRoute[i]==5)&&(walkRoute[i+1]==11)){            //经管楼到校医院
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if((walkRoute[i]==5)&&(walkRoute[i+1]==12)){            //经管楼到北田径场
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 13)){      //经管楼到建国饭店
                flag_point[4][33]=1;
                flag_point[33][34]=1;
                flag_point[34][12]=1;
            }
            if((walkRoute[i]==5)&&(walkRoute[i+1]==14)){            //经管楼到金工楼
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 5) && (walkRoute[i+1] == 15)){      //经管楼到网球场
                flag_point[4][33]=1;
                flag_point[33][32]=1;
                flag_point[32][44]=1;
                flag_point[44][14]=1;
            }
            if((walkRoute[i]==6)&&(walkRoute[i+1]==1)){            //人文楼到宿舍楼
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][43]=1;
                flag_point[43][28]=1;
                flag_point[28][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 2)){      //人文楼到信息楼
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 3)){      //人文楼到软件楼
                flag_point[5][35]=1;
                flag_point[35][37]=1;
                flag_point[37][38]=1;
                flag_point[38][46]=1;
                flag_point[46][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 4)){      //人文楼到实训楼
                flag_point[5][35]=1;
                flag_point[35][37]=1;
                flag_point[37][38]=1;
                flag_point[38][46]=1;
                flag_point[46][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 5)){      //人文楼到经管楼
                flag_point[5][34]=1;
                flag_point[34][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 7)){      //人文楼到奥林匹克体育馆
                flag_point[5][35]=1;
                flag_point[35][37]=1;
                flag_point[37][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 8)){      //人文楼到奥运餐厅
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 9)){      //人文楼到逸夫图书馆
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][23]=1;
                flag_point[23][8]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 10)){      //人文楼到游泳馆
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 11)){      //人文楼到校医院
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 12)){      //人文楼到北田径场
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 13)){      //人文楼到建国饭店
                flag_point[5][12]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 14)){      //人文楼到金工楼
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 6) && (walkRoute[i+1] == 15)){      //人文楼到网球场
                flag_point[5][35]=1;
                flag_point[35][36]=1;
                flag_point[36][44]=1;
                flag_point[44][14]=1;
            }
            if((walkRoute[i]==7)&&(walkRoute[i+1]==1)){            //奥林匹克体育馆到宿舍楼
                flag_point[6][38]=1;
                flag_point[38][21]=1;
                flag_point[21][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 2)){      //奥林匹克体育馆到信息楼
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 3)){      //奥林匹克体育馆到软件楼
                flag_point[6][46]=1;
                flag_point[46][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 4)){      //奥林匹克体育馆到实训楼
                flag_point[6][46]=1;
                flag_point[46][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 5)){      //奥林匹克体育馆到经管楼
                flag_point[6][46]=1;
                flag_point[46][38]=1;
                flag_point[38][44]=1;
                flag_point[44][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 6)){      //奥林匹克体育馆到人文楼
                flag_point[6][38]=1;
                flag_point[38][37]=1;
                flag_point[37][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 8)){      //奥林匹克体育馆到奥运餐厅
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 9)){      //奥林匹克体育馆到逸夫图书馆
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][23]=1;
                flag_point[23][8]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 10)){      //奥林匹克体育馆到游泳馆
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 11)){      //奥林匹克体育馆到校医院
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 12)){      //奥林匹克体育馆到北田径场
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 13)){      //奥林匹克体育馆到建国饭店
                flag_point[6][38]=1;
                flag_point[38][37]=1;
                flag_point[37][35]=1;
                flag_point[35][12]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 14)){      //奥林匹克体育馆到金工楼
                flag_point[6][38]=1;
                flag_point[38][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 7) && (walkRoute[i+1] == 15)){      //奥林匹克体育馆到网球场
                flag_point[6][38]=1;
                flag_point[38][14]=1;
            }
            if((walkRoute[i]==8)&&(walkRoute[i+1]==1)){            //奥运餐厅到宿舍楼
                flag_point[7][22]=1;
                flag_point[22][21]=1;
                flag_point[21][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 2)){      //奥运餐厅到信息楼
                flag_point[7][45]=1;
                flag_point[45][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 3)){      //奥运餐厅到软件楼
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 4)){      //奥运餐厅到实训楼
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 5)){      //奥运餐厅到经管楼
                flag_point[7][45]=1;
                flag_point[45][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 6)){      //奥运餐厅到人文楼
                flag_point[7][45]=1;
                flag_point[45][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 7)){      //奥运餐厅到奥林匹克体育馆
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 9)){      //奥运餐厅到逸夫图书馆
                flag_point[7][45]=1;
                flag_point[45][23]=1;
                flag_point[23][8]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 10)){      //奥运餐厅到游泳馆
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 11)){      //奥运餐厅到校医院
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 12)){      //奥运餐厅到北田径场
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 13)){      //奥运餐厅到建国饭店
                flag_point[7][45]=1;
                flag_point[45][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 14)){      //奥运餐厅到金工楼
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 8) && (walkRoute[i+1] == 15)){      //奥运餐厅到网球场
                flag_point[7][45]=1;
                flag_point[45][44]=1;
                flag_point[44][14]=1;
            }
            if((walkRoute[i]==9)&&(walkRoute[i+1]==1)){            //逸夫图书馆到宿舍楼
                flag_point[8][29]=1;
                flag_point[29][27]=1;
                flag_point[27][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 2)){      //逸夫图书馆到信息楼
                flag_point[8][23]=1;
                flag_point[23][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 3)){      //逸夫图书馆到软件楼
                flag_point[8][23]=1;
                flag_point[23][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 4)){      //逸夫图书馆到实训楼
                flag_point[8][23]=1;
                flag_point[23][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 5)){      //逸夫图书馆到经管楼
                flag_point[8][23]=1;
                flag_point[23][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 6)){      //逸夫图书馆到人文楼
                flag_point[8][23]=1;
                flag_point[23][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 7)){      //逸夫图书馆到奥林匹克体育馆
                flag_point[8][23]=1;
                flag_point[23][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 8)){      //逸夫图书馆到奥运餐厅
                flag_point[8][23]=1;
                flag_point[23][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 10)){      //逸夫图书馆到游泳馆
                flag_point[8][30]=1;
                flag_point[30][28]=1;
                flag_point[28][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 11)){      //逸夫图书馆到校医院
                flag_point[8][30]=1;
                flag_point[30][28]=1;
                flag_point[28][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 12)){      //逸夫图书馆到北田径场
                flag_point[8][30]=1;
                flag_point[30][28]=1;
                flag_point[28][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 13)){      //逸夫图书馆到建国饭店
                flag_point[8][23]=1;
                flag_point[23][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 14)){      //逸夫图书馆到金工楼
                flag_point[8][30]=1;
                flag_point[30][28]=1;
                flag_point[28][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 9) && (walkRoute[i+1] == 15)){      //逸夫图书馆到网球场
                flag_point[8][30]=1;
                flag_point[30][28]=1;
                flag_point[28][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==10)&&(walkRoute[i+1]==1)){            //游泳馆到宿舍楼
                flag_point[9][17]=1;
                flag_point[17][18]=1;
                flag_point[18][0]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 2)){      //游泳馆到信息楼
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 3)){      //游泳馆到软件楼
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 4)){      //游泳馆到实训楼
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][3]=1;
            }
            if((walkRoute[i]==10)&&(walkRoute[i+1]==5)){            //游泳馆到经管楼
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 6)){      //游泳馆到人文楼
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 7)){      //游泳馆到奥林匹克体育馆
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 8)){      //游泳馆到奥运餐厅
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 9)){      //游泳馆到逸夫图书馆
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][28]=1;
                flag_point[28][30]=1;
                flag_point[30][8]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 11)){      //游泳馆到校医院
                flag_point[9][17]=1;
                flag_point[17][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 12)){      //游泳馆到北田径场
                flag_point[9][11]=1;
            }
            if((walkRoute[i]==10)&&(walkRoute[i+1]==13)){            //游泳馆到建国饭店
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 14)){      //游泳馆到金工楼
                flag_point[9][17]=1;
                flag_point[17][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 10) && (walkRoute[i+1] == 15)){      //游泳馆到网球场
                flag_point[9][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==11)&&(walkRoute[i+1]==1)){            //校医院到宿舍楼
                flag_point[10][16]=1;
                flag_point[16][0]=1;
            }
            if(( walkRoute[i]==11) && (walkRoute[i+1] == 2)){      //校医院到信息楼
                flag_point[10][16]=1;
                flag_point[16][24]=1;
                flag_point[24][25]=1;
                flag_point[25][1]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 3)){      //校医院到软件楼
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 4)){      //校医院到实训楼
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][3]=1;
            }
            if((walkRoute[i]==11)&&(walkRoute[i+1]==5)){            //校医院到经管楼
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 6)){      //校医院到人文楼
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]==11) && (walkRoute[i+1] == 7)){      //校医院到奥林匹克体育馆
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 8)){      //校医院到奥运餐厅
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]==11) && (walkRoute[i+1] == 9)){      //校医院到逸夫图书馆
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][28]=1;
                flag_point[28][30]=1;
                flag_point[30][8]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 10)){      //校医院到游泳馆
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 12)){      //校医院到北田径场
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][17]=1;
                flag_point[17][11]=1;
            }
            if((walkRoute[i]==11)&&(walkRoute[i+1]==13)){            //校医院到建国饭店
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 14)){      //校医院到金工楼
                flag_point[10][16]=1;
                flag_point[16][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 11) && (walkRoute[i+1] == 15)){      //校医院到网球场
                flag_point[10][16]=1;
                flag_point[16][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==12)&&(walkRoute[i+1]==1)){            //北田径场到宿舍楼
                flag_point[11][17]=1;
                flag_point[17][18]=1;
                flag_point[18][0]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 2)){      //北田径场到信息楼
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][25]=1;
                flag_point[25][1]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 3)){      //北田径场到软件楼
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 4)){      //北田径场到实训楼
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][3]=1;
            }
            if((walkRoute[i]==12)&&(walkRoute[i+1]==5)){            //北田径场到经管楼
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 6)){      //北田径场到人文楼
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 7)){      //北田径场到奥林匹克体育馆
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 8)){      //北田径场到奥运餐厅
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 9)){      //北田径场到逸夫图书馆
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][28]=1;
                flag_point[28][30]=1;
                flag_point[30][8]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 10)){      //北田径场到游泳馆
                flag_point[11][9]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 11)){      //北田径场到校医院
                flag_point[11][17]=1;
                flag_point[17][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if((walkRoute[i]==12)&&(walkRoute[i+1]==13)){            //北田径场到建国饭店
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 14)){      //北田径场到金工楼
                flag_point[11][17]=1;
                flag_point[17][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 12) && (walkRoute[i+1] == 15)){      //北田径场到网球场
                flag_point[11][17]=1;
                flag_point[17][20]=1;
                flag_point[20][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==13)&&(walkRoute[i+1]==1)){            //建国饭店到宿舍楼
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][26]=1;
                flag_point[26][15]=1;
                flag_point[15][0]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 2)){      //建国饭店到信息楼
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][31]=1;
                flag_point[31][1]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 3)){      //建国饭店到软件楼
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 4)){      //建国饭店到实训楼
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][44]=1;
                flag_point[44][40]=1;
                flag_point[40][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 5)){      //建国饭店到经管楼
                flag_point[12][34]=1;
                flag_point[34][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 6)){      //建国饭店到人文楼
                flag_point[12][5]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 7)){      //建国饭店到奥林匹克体育馆
                flag_point[12][35]=1;
                flag_point[35][37]=1;
                flag_point[37][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 8)){      //建国饭店到奥运餐厅
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 9)){      //建国饭店到逸夫图书馆
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][23]=1;
                flag_point[23][8]=1;
            }
            if((walkRoute[i]==13)&&(walkRoute[i+1]==10)){            //建国饭店到游泳馆
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if((walkRoute[i]==13)&&(walkRoute[i+1]==11)){            //建国饭店到校医院
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if((walkRoute[i]==13)&&(walkRoute[i+1]==12)){            //建国饭店到北田径场
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if((walkRoute[i]==13)&&(walkRoute[i+1]==14)){            //建国饭店到金工楼
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][42]=1;
                flag_point[42][27]=1;
                flag_point[27][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
            if(( walkRoute[i]== 13) && (walkRoute[i+1] == 15)){      //建国饭店到网球场
                flag_point[12][34]=1;
                flag_point[34][32]=1;
                flag_point[32][44]=1;
                flag_point[44][14]=1;
            }
            if((walkRoute[i]==14)&&(walkRoute[i+1]==1)){            //金工楼到宿舍楼
                flag_point[13][19]=1;
                flag_point[19][0]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 2)){      //金工楼到信息楼
                flag_point[13][19]=1;
                flag_point[19][24]=1;
                flag_point[24][25]=1;
                flag_point[25][1]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 3)){      //金工楼到软件楼
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 4)){      //金工楼到实训楼
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][41]=1;
                flag_point[41][39]=1;
                flag_point[39][3]=1;
            }
            if((walkRoute[i]==14)&&(walkRoute[i+1]==5)){            //金工楼到经管楼
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 6)){      //金工楼到人文楼
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 7)){      //金工楼到奥林匹克体育馆
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 8)){      //金工楼到奥运餐厅
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 9)){      //金工楼到逸夫图书馆
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][28]=1;
                flag_point[28][30]=1;
                flag_point[30][8]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 10)){      //金工楼到游泳馆
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 11)){      //金工楼到校医院
                flag_point[13][19]=1;
                flag_point[19][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 12)){      //金工楼到北田径场
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][17]=1;
                flag_point[17][11]=1;
            }
            if((walkRoute[i]==14)&&(walkRoute[i+1]==13)){            //金工楼到建国饭店
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][27]=1;
                flag_point[27][42]=1;
                flag_point[42][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 14) && (walkRoute[i+1] == 15)){      //金工楼到网球场
                flag_point[13][19]=1;
                flag_point[19][18]=1;
                flag_point[18][20]=1;
                flag_point[20][21]=1;
                flag_point[21][14]=1;
            }
            if((walkRoute[i]==15)&&(walkRoute[i+1]==1)){            //网球场到宿舍楼
                flag_point[14][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][0]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 2)){      //网球场到信息楼
                flag_point[14][21]=1;
                flag_point[21][25]=1;
                flag_point[25][1]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 3)){      //网球场到软件楼
                flag_point[14][21]=1;
                flag_point[21][41]=1;
                flag_point[41][39]=1;
                flag_point[39][2]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 4)){      //网球场到实训楼
                flag_point[14][21]=1;
                flag_point[21][41]=1;
                flag_point[41][39]=1;
                flag_point[39][3]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 5)){      //网球场到经管楼
                flag_point[14][44]=1;
                flag_point[44][32]=1;
                flag_point[32][33]=1;
                flag_point[33][4]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 6)){      //网球场到人文楼
                flag_point[14][44]=1;
                flag_point[44][36]=1;
                flag_point[36][35]=1;
                flag_point[35][5]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 7)){      //网球场到奥林匹克体育馆
                flag_point[14][38]=1;
                flag_point[38][6]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 8)){      //网球场到奥运餐厅
                flag_point[14][44]=1;
                flag_point[44][45]=1;
                flag_point[45][7]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 9)){      //网球场到逸夫图书馆
                flag_point[14][21]=1;
                flag_point[21][28]=1;
                flag_point[28][30]=1;
                flag_point[30][8]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 10)){      //网球场到游泳馆
                flag_point[14][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][9]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 11)){      //网球场到校医院
                flag_point[14][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][16]=1;
                flag_point[16][10]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 12)){      //网球场到北田径场
                flag_point[14][21]=1;
                flag_point[21][20]=1;
                flag_point[20][17]=1;
                flag_point[17][11]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 13)){      //网球场到建国饭店
                flag_point[14][44]=1;
                flag_point[44][32]=1;
                flag_point[32][34]=1;
                flag_point[34][12]=1;
            }
            if(( walkRoute[i]== 15) && (walkRoute[i+1] == 14)){      //网球场到金工楼
                flag_point[14][21]=1;
                flag_point[21][20]=1;
                flag_point[20][18]=1;
                flag_point[18][19]=1;
                flag_point[19][13]=1;
            }
        }
}



void bjutmap::paintEvent(QPaintEvent*event){
    QPainter painter(this);
    //"D:\\Junior1\\DS_Qt\\CampusGuide_DP_QT\\Resource\\BJUT_MAP1.jpg"
    painter.drawPixmap(30,30,1025,890,QPixmap("../CampusGuide_DP_QT/Resource/BJUT_MAP2.png"));
    QPen pen1;
    pen1.setStyle(Qt::DotLine);
    pen1.setColor(Qt::red);
    pen1.setWidth(5);
    painter.setPen(pen1);
    //painter.drawLine(QPoint(0,0),QPoint(this->width(),this->height()));
    painter.drawPoint(435,673);
    InitPoint();
    setRouteLine();
    outputInformation();
    printPlaceOrder();
    for(int i = 0; i < allPoint; i++)
        for(int j = 0; j < allPoint; j++){
            /*if((i<=j)&&(flag_point[i][j] == 1)){
                painter.drawLine(point[i],point[j]);
            }*/
           if(( flag_point[i][j] == 1) && (flag_point[j][i] != 1)){
                painter.setPen(pen1);
                painter.drawLine(point[i],point[j]);
               // qDebug()<<"11111";
            }
            if(( flag_point[i][j] == 1) && (flag_point[j][i] == 1)){
                QPen pen2;
                pen2.setColor(Qt::red);
                pen2.setWidth(5);
                painter.setPen(pen2);
                painter.drawLine(point[i],point[j]);
                //qDebug()<<flag_point[j][i];
            }
            //painter.setPen(pen);
        }

}



void bjutmap::printPlaceOrder(){

    int nowplace;     //记录的是标号，不是下标
   // qDebug()<<endl;
   // qDebug()<<"placeNum: "<<selectedPlaceNum<<endl;
    for(int i = 0; i < selectedPlaceNum; i++){
        nowplace = walkRoute[i];
        label[nowplace-1]->setPixmap(pic[i]);
    }

}

/*************************************槽函数实现***********************************************/

void bjutmap::doProcessDataToMap(int num){
    //ui->label->setText(QString::number(num));
    selectedPlaceNum = num;
   // qDebug()<<"num: "<<num;
}

void bjutmap::doProcessSaveWalkRouteToMap(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t){
    walkRoute[0] = a;
    walkRoute[1] = b;
    walkRoute[2] = c;
    walkRoute[3] = d;
    walkRoute[4] = e;
    walkRoute[5] = f;
    walkRoute[6] = g;
    walkRoute[7] = h;
    walkRoute[8] = i;
    walkRoute[9] = j;
    walkRoute[10] = k;
    walkRoute[11] = l;
    walkRoute[12] = m;
    walkRoute[13] = n;
    walkRoute[14] = o;
    walkRoute[15] = p;
    walkRoute[16] = q;
    walkRoute[17] = r;
    walkRoute[18] = s;
    walkRoute[19] = t;


}

void bjutmap::doProcessSaveArriveTimeToMap(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QString h,QString i,QString j,QString k,QString l,QString m,QString n,QString o,QString p,QString q,QString r,QString s,QString t){
    arriveTime[0] = a;
    arriveTime[1] = b;
    arriveTime[2] = c;
    arriveTime[3] = d;
    arriveTime[4] = e;
    arriveTime[5] = f;
    arriveTime[6] = g;
    arriveTime[7] = h;
    arriveTime[8] = i;
    arriveTime[9] = j;
    arriveTime[10] = k;
    arriveTime[11] = l;
    arriveTime[12] = m;
    arriveTime[13] = n;
    arriveTime[14] = o;
    arriveTime[15] = p;
    arriveTime[16] = q;
    arriveTime[17] = r;
    arriveTime[18] = s;
    arriveTime[19] = t;

}

void bjutmap::doProcessSaveStayTimeRouteToMap(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t){
    stayTime_route[0] = a;
    stayTime_route[1] = b;
    stayTime_route[2] = c;
    stayTime_route[3] = d;
    stayTime_route[4] = e;
    stayTime_route[5] = f;
    stayTime_route[6] = g;
    stayTime_route[7] = h;
    stayTime_route[8] = i;
    stayTime_route[9] = j;
    stayTime_route[10] = k;
    stayTime_route[11] = l;
    stayTime_route[12] = m;
    stayTime_route[13] = n;
    stayTime_route[14] = o;
    stayTime_route[15] = p;
    stayTime_route[16] = q;
    stayTime_route[17] = r;
    stayTime_route[18] = s;
    stayTime_route[19] = t;

}

void bjutmap::doProcessClickedSendEmail(bool){
    emit callSendEmail();
}

void bjutmap::doProcessGrabScreen(bool){
    //screen->grabWindow(0).save("result","jpg");
    //QPixmap pixmap = screen->grabWindow(0);
    QPixmap pixmap = screen->grabWindow(0);
    pixmap.save("D:\\Junior1\\DS_Qt\\CampusGuide_DP_QT\\Email\\result.jpg");
}

void bjutmap::doProcessReturnToInquiry(bool){
    emit ReturnToInquiry();
}

