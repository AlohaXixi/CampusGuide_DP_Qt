#include "Information.h"
#include "ui_information.h"
#include <QDebug>

Information::Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    Init();

}

Information::~Information()
{
    delete ui;
}


/***************************************************功能实现*********************************************/

void Information::Init(){

    /***********************设置背景色****************************************/

    setAutoFillBackground(true);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,240));
    setPalette(palette);

    /**********************设置背景色完毕**************************************/

    /**********************设置右侧地点信息栏背景色******************************/

    QPalette p1;
    p1.setColor(QPalette::Background, QColor(87,87,87));
    ui->placeInformation->setAutoFillBackground(true);
    ui->placeInformation->setPalette(p1);
    ui->pushButton_addMap->hide();
            /***********************设置完毕******************************************/

    /***********************按钮设置***************************************/

    ui->tb1->setStyleSheet(
                "QToolButton{background-color:rgb(255, 255, 0);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QToolButton:hover{background-color:rgb(255, 255, 136)}"
                "QToolButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );

    ui->tb2->setStyleSheet(
                "QToolButton{background-color:rgb(255, 255, 0);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QToolButton:hover{background-color:rgb(255, 255, 136)}"
                "QToolButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );

    ui->tb3->setStyleSheet(
                "QToolButton{background-color:rgb(255, 255, 0);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QToolButton:hover{background-color:rgb(255, 255, 136)}"
                "QToolButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );

    ui->tb4->setStyleSheet(
                "QToolButton{background-color:rgb(255, 255, 0);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}"
                "QToolButton:hover{background-color:rgb(255, 255, 136)}"
                "QToolButton:pressed{background-color:rgb(227, 227, 0);border-style:inset;}"
                );

    ui->pushButton_addMap->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );

    /**********************按钮设置完毕**************************************/

    addInformaitonForm = new AddInform(this);
    addInformaitonForm->hide();
    inquiry = new Inquiry(this);
    inquiry->hide();
    profession = new Profession(this);
    profession->hide();
    MyMap = new bjutmap();
    MyMap->hide();
    recommend = new Recommend(this);
    recommend->hide();

    //点击信息录入按钮，进入信息录入界面
    connect(ui->tb1,SIGNAL(clicked(bool)),this,SLOT(GoToAddInformation(bool)));
    //addInformaitonForm=new AddInformation(this);
    connect(ui->tb2,SIGNAL(clicked(bool)),this,SLOT(GoToInquiry(bool)));
    //connect(addInformaitonForm,SIGNAL(AddMap()),this,SLOT(GoToMap()));
    connect(ui->tb3,SIGNAL(clicked(bool)),this,SLOT(GoToProfessionIntro(bool)));
    connect(ui->tb4,SIGNAL(clicked(bool)),this,SLOT(GoToRecommend(bool)));
    connect(ui->pushButton_addMap,SIGNAL(clicked(bool)),this,SLOT(GoToMap(bool)));
    connect(MyMap,SIGNAL(callSendEmail()),this,SLOT(GoToSendEmail()));



    //将数据从addInform传到Information,再从Information传到bjutmap
    connect(addInformaitonForm,SIGNAL(signalDataToInform(int)),this,SLOT(doProcessDataToInform(int)));
    connect(this,SIGNAL(SignalDataToMap(int)),MyMap,SLOT(doProcessDataToMap(int)));

    connect(addInformaitonForm,SIGNAL(SignalWalkRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)),
            this,SLOT(doProcessSaveWalkRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)));
    connect(this,SIGNAL(SignalWalkRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)),
            MyMap,SLOT(doProcessSaveWalkRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)));

    connect(addInformaitonForm,SIGNAL(SignalArriveTimeToInform(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)),
            this,SLOT(doProcessSaveArriveTimeToInform(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)));
    connect(this,SIGNAL(SignalArriveTimeToMap(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)),
            MyMap,SLOT(doProcessSaveArriveTimeToMap(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)));

    connect(addInformaitonForm,SIGNAL(SignalStayTimeRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)),
            this,SLOT(doProcessSaveStayTimeRouteToInform(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)));
    connect(this,SIGNAL(SignalStayTimeRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)),
            MyMap,SLOT(doProcessSaveStayTimeRouteToMap(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int)));

    connect(MyMap,SIGNAL(ReturnToInquiry()),this,SLOT(BjutMapReturnToThis()));


}



/*********************************************槽实现**********************************************************/

void Information::GoToAddInformation(bool){
    flag_addInformation = 1;
    //addInformaitonForm = new AddInform(this);
    addInformaitonForm->show();
    addInformaitonForm->move(230,70);
    ui->pushButton_addMap->show();
    ui->label->hide();
    if(flag_inquiry == 1){
        inquiry->hide();
        flag_inquiry=0;
    }
    if(flag_profession == 1){
        profession->hide();
        flag_profession = 0;
    }
    if(flag_recommend == 1){
        recommend->hide();
        flag_recommend = 0;
    }
}

void Information::GoToInquiry(bool){
    flag_inquiry=1;
    //inquiry=new Inquiry(this);
    if(flag_addInformation == 1){
        addInformaitonForm->hide();
        flag_addInformation = 0;
     }
    if(flag_profession == 1){
        profession->hide();
        flag_profession = 0;
    }
    if(flag_recommend == 1){
        recommend->hide();
        flag_recommend = 0;
    }
    ui->pushButton_addMap->hide();
    inquiry->show();
    inquiry->move(230,100);
}


void Information::GoToProfessionIntro(bool){
    flag_profession = 1;
    if(flag_addInformation == 1){
        addInformaitonForm->hide();
        flag_addInformation = 0;
     }
    if(flag_inquiry == 1){
        inquiry->hide();
        flag_inquiry=0;
    }
    if(flag_recommend == 1){
        recommend->hide();
        flag_recommend = 0;
    }
    ui->label->hide();
    ui->pushButton_addMap->hide();
    profession->show();
    profession->move(230,100);

}

void Information::GoToRecommend(bool){
    flag_recommend = 1;
    if(flag_addInformation == 1){
        addInformaitonForm->hide();
        flag_addInformation = 0;
     }
    if(flag_inquiry == 1){
        inquiry->hide();
        flag_inquiry=0;
    }
    if(flag_profession == 1){
        profession->hide();
        flag_profession = 0;
    }
    ui->label->hide();
    ui->pushButton_addMap->hide();
    recommend->show();
    recommend->move(230,100);

}

void Information::GoToMap(bool){
   // qDebug()<<"11111111111";
   // MyMap = new bjutmap();

    //inquiry->hide();
    this->hide();
    MyMap->show();

}

/*void Information::doProcessSaveData(int walkRoute_s[allPlaceNum],QDateTime arriveTime_s[allPlaceNum],int stayTime_route_s[allPlaceNum],int walkTime_s[allPlaceNum]){
    QString str{"555555"};
    ui->label_2->setText(str);
}*/

void Information::doProcessDataToInform(int selectedPlaceNum){
    //ui->label_3->setText(QString::number(selectedPlaceNum));
    emit SignalDataToMap(selectedPlaceNum);
}

void Information::doProcessSaveWalkRouteToInform(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t){
    emit SignalWalkRouteToMap(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t);
}

void Information::doProcessSaveArriveTimeToInform(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QString h,QString i,QString j,QString k,QString l,QString m,QString n,QString o,QString p,QString q,QString r,QString s,QString t){
    emit SignalArriveTimeToMap(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t);
}

void Information::doProcessSaveStayTimeRouteToInform(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t){
    emit SignalStayTimeRouteToMap(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t);
}

void Information::GoToSendEmail(){
    //MyMap->hide();
   // frmMain w;
    //设置窗体居中
    int deskWidth=qApp->desktop()->availableGeometry().width();
    int deskHeigth=qApp->desktop()->availableGeometry().height();
    int frmX=w.width();
    int frmY=w.height();
    QPoint movePoint(deskWidth/2-frmX/2,deskHeigth/2-frmY/2);
    w.move(movePoint);
    w.show();
}

void Information::BjutMapReturnToThis(){
    MyMap->hide();
    this->show();
    inquiry->hide();
    addInformaitonForm->show();

}








