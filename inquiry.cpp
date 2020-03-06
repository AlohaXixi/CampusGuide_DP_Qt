#include "inquiry.h"
#include "ui_inquiry.h"
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>

Inquiry::Inquiry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inquiry)
{
    ui->setupUi(this);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    Init();
}

Inquiry::~Inquiry()
{
    delete ui;
}



/*********************************功能函数实现****************************/
void Inquiry::Init(){

    ui->groupBox_help->setStyleSheet("QGroupBox{background:rgb(255, 255, 166);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}");

    ui->pushButton_inquiry->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->pushButton_swim->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->pushButton_hotel->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->pushButton_badminton->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );
    ui->pushButton_schoolweb->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );

    QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\bjut.jpg");
    ui->label_picture->setPixmap(pic);

    connect(ui->pushButton_inquiry,SIGNAL(clicked(bool)),this,SLOT(doProcessAddPlace(bool)));
    connect(ui->pushButton_hotel,SIGNAL(clicked(bool)),this,SLOT(doProcessOpenHotelWeb(bool)));
    connect(ui->pushButton_badminton,SIGNAL(clicked(bool)),this,SLOT(doProcessOpenBadmintonWeb(bool)));
    connect(ui->pushButton_swim,SIGNAL(clicked(bool)),this,SLOT(doProcessOpenSwimWeb(bool)));
    connect(ui->pushButton_schoolweb,SIGNAL(clicked(bool)),this,SLOT(doProcessOpenSchoolWeb(bool)));
    InitIntroduction();

}

void Inquiry::InitIntroduction(){

    Intro[0].num = 1;
    Intro[0].str = "\t\t1 -- 女生宿舍楼\n"
                   "    二号宿舍楼为女生宿舍楼，毗邻新食堂、京客隆超市、第一教学楼，与西门、北门都比较近，生活学校都相对便利。";

    Intro[1].num = 2;
    Intro[1].str ="\t\t2 -- 信息楼\n"
                  "     信息楼位于西门地铁站对面，主要为信息学部计算机学院所使用。信息西楼、北楼主要为学生实验室及老师办公室，"
                  "信息南楼为一些专业实验室，信息东楼为教室。";

    Intro[2].num = 3;
    Intro[2].str = "\t\t3 -- 软件楼\n"
                   "    软件楼位于校园东南角。相邻交通楼、环能楼、实训楼，毗邻月亮湖。\n   软件楼既有信息学部办公区域，也有软件学院的实验室。";

    Intro[3].num = 4;
    Intro[3].str = "\t\t4 -- 实训楼\n"
                   "    实训楼位于校园东南角。相邻交通楼、软件楼，毗邻月亮湖。\n   软件楼一二层为机房，以上为物理实验室、电路实验室等，供学生上机实验。";

    Intro[4].num = 5;
    Intro[4].str = "\t\t5 -- 经管楼\n"
                   "    经管楼位于校园西南处。一层大厅摆放几张小圆桌，供学生讨论自习。经管类的课多于此进行授课。";

    Intro[5].num = 6;
    Intro[5].str = "\t\t6 -- 人文楼\n"
                   "    人文楼位于学校西南侧。英语选修课让全校同学曾在这里学习过。平时多为英语专业、法律专业、社会学等人文学科专业的的同学的学习圣地。";

    Intro[6].num = 7;
    Intro[6].str = "\t\t7 -- 奥林匹克体育馆\n"
                   "    奥林匹克体育馆是为2008北京奥运会建立而成的，承担了当时的羽毛球比赛，现在仍是师生以及校外人员打羽毛球的圣地。"
                   "同时，奥林匹克体育馆也经常承办大型演出、活动、发布会等，是工大的一张名片。\n\n"
                   "营业时间：10：00-21:00\n"
                   "其中，周一、二、四、五的中午12:00-13:00为师生的免费时间。\n"
                   "其余工作日10:00-18:00，师生每小时10元，校外人员每小时60元。工作日18:00-21:00，师生每小时60元，校外人员每小时80元。\n"
                   "周末10：00-18:00,师生每小时50元，18:00-21:00，师生每小时70元。周末各时段校外人员均为每小时80元。";


    Intro[7].num = 8;
    Intro[7].str = "\t\t8 -- 奥运餐厅\n"
                   "    奥运餐厅，顾名思义，是在奥运会期间为运动员提供饮食的餐厅。现如今作为学生的食堂，每天仍人头攒动。\n"
                   "一层主要提供基本伙，特点是价格便宜，味道也不错。供应速度较快。离三教比较近，是同学们满课时的好选择。\n"
                   "二层除了提供基本伙，还包括一些物美价廉的特色饮食，例如石锅拌饭、铁板饭等。同时，还有甜点窗口，售卖小蛋糕、蛋挞、饼干等甜点，"
                   "是热爱甜食的同学们的心心念念之处。";

    Intro[8].num = 9;
    Intro[8].str = "\t\t9 -- 逸夫图书馆\n"
                   "    逸夫图书馆自2019年秋季学期开放，瞬间变成了工大网红打卡处。逸夫图书馆建筑面积共有4万余平方米，从负一层到五层共有六个楼层。"
                   "新图书馆南入口西侧为下沉广场，由此可进入自习室，同时还有即将开放的咖啡店。在面积最大的阅读区，每张长桌配有台灯、插座，十分便利。"
                   "此外，新图还包括南入口处3000多平方米的学术会议区，以及三四层的20余间大小不一的研讨室和2个功能齐备的影音室。";

    Intro[9].num = 10;
    Intro[9].str = "\t\t11 -- 游泳馆\n"
                   "    工大游泳馆为标准50米泳道，分为浅水区和深水区两部分。浅水区水深最深处为1.2米，深水区为1.6m-2.0m。在无游泳课的时间段，对师生以及校外人员开放"
                   "营业时间：11:30-20:30(仅无游泳课时开放)\n\n"
                   "收费标准：师生 10元/1.5小时\n"
                   "        校外人员 50元/1.5小时\n"
                   "所需证件：进泳池均需要健康证，可在校医院办理（20元）；进入深水区需要深水证，可当场进行考取。";

    Intro[10].num = 11;
    Intro[10].str ="\t\t11 -- 校医院\n"
                   "    校医院包含内科、外科、中医、眼科、牙科等多个科室，十分完善。且处于校园内部，对难免头疼脑热的同学们来说非常便利。\n\n"
                   "正常营业时间：8:00-11:30,13:30-17:00\n"
                   "急诊：24小时\n"
                   "一般挂号费用：1元（须现金）";

    Intro[11].num = 12;
    Intro[11].str = "\t\t12 -- 北田径场\n"
                    "   北田径场是对社会全天开放的田径场，位于游泳馆东侧。北田径场西南角，配备有健身器材，是同学、附近居民每日跑步健身的好去处。"
                    "到傍晚，更是能欣赏到附近居民组成的行走团，以及广场舞，十分具有生活气息。";

    Intro[12].num = 13;
    Intro[12].str = "\t\t13 -- 建国饭店\n"
                    "   工大建国饭店是位于校内的一家豪华型酒店，位于校园东南侧。主要为许多来工大参加会议的老师领导提供食宿，同时也用于商业用途。";

    Intro[13].num = 14;
    Intro[13].str = "\t\t14 -- 金工楼\n"
                    "   金工楼应该是洒满所有工大学子汗水的地方。所有的工大人都将在此打磨并拥有自己的小锤子。并且，机电学院的同学们，更有许多机会在此大展身手。";

    Intro[14].num = 15;
    Intro[14].str = "\t\t15 -- 网球场\n"
                    "   网球场位于南田径场北侧，除有网球课的时间段，均全天对校内外人员开放。准备好自己的球拍和球，不妨来这里和小伙伴过过招，"
                    "体会一下运动的乐趣。";

}

void Inquiry::ShowIntroduction(){
    if(place == 1){
        ui->textEdit->setText(Intro[0].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 2){
        ui->textEdit->setText(Intro[1].str);
        //ui->textEdit->append(Intro[1].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\Resource\\22.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 3){
        ui->textEdit->setText(Intro[2].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\33.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 4){
        ui->textEdit->setText(Intro[3].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\44.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 5){
        ui->textEdit->setText(Intro[4].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\55.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 6){
        ui->textEdit->setText(Intro[5].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\66.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 7){
        ui->textEdit->setText(Intro[6].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\77.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 8){
        ui->textEdit->setText(Intro[7].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\88.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 9){
        ui->textEdit->setText(Intro[8].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\99.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 10){
        ui->textEdit->setText(Intro[9].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1010.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 11){
        ui->textEdit->setText(Intro[10].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1111.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 12){
        ui->textEdit->setText(Intro[11].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1212.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 13){
    ui->textEdit->setText(Intro[12].str);
    QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1313.jpg");
    ui->label_picture->setPixmap(pic);
    }
    if(place == 14){
        ui->textEdit->setText(Intro[13].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1414.jpg");
        ui->label_picture->setPixmap(pic);
    }
    if(place == 15){
        ui->textEdit->setText(Intro[14].str);
        QPixmap pic=QPixmap("..\\CampusGuide_DP_QT\\\\Resource\\1515.jpg");
        ui->label_picture->setPixmap(pic);
    }



}



/********************************槽函数实现*****************************/
void Inquiry::doProcessAddPlace(bool){
    QString s=ui->lineEdit_num->text();
    place=s.toInt();
    qDebug()<<place<<endl;
    ShowIntroduction();
    //const QUrl regUrl(QLatin1String("http://www.baidu.com"));
    //QDesktopServices::openUrl(regUrl);
}

void Inquiry::doProcessOpenHotelWeb(bool){
    const QUrl regUrl(QLatin1String("https://hotels.ctrip.com/hotel/467314.html"));
    QDesktopServices::openUrl(regUrl);
}

void Inquiry::doProcessOpenBadmintonWeb(bool){
    const QUrl regUrl(QLatin1String("http://www.dianping.com/shop/91072974"));
    QDesktopServices::openUrl(regUrl);
}

void Inquiry::doProcessOpenSwimWeb(bool){
    const QUrl regUrl(QLatin1String("http://www.dianping.com/shop/2474359"));
    QDesktopServices::openUrl(regUrl);
}

void Inquiry::doProcessOpenSchoolWeb(bool){
    const QUrl regUrl(QLatin1String("http://www.bjut.edu.cn/"));
    QDesktopServices::openUrl(regUrl);
}
