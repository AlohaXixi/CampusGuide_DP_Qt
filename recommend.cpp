#include "recommend.h"
#include "ui_recommend.h"

Recommend::Recommend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Recommend)
{
    ui->setupUi(this);
    Init();
}

Recommend::~Recommend()
{
    delete ui;
}

void Recommend::Init(){

    ui->groupBox1->setStyleSheet("QGroupBox{background:rgb(255, 255, 166);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}");
    ui->groupBox2->setStyleSheet("QGroupBox{background:rgb(255, 255, 166);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}");
    ui->groupBox3->setStyleSheet("QGroupBox{background:rgb(255, 255, 166);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px;}");

    ui->pushButton_certain->setStyleSheet(
                "QPushButton{background-color:rgb(255, 181, 106);border-style:outset;border:2px groove gray;border-radius:10px;padding:2px 4px}"
                "QPushButton:hover{background-color:rgb(255, 213, 170)}"
                "QPushButton:pressed{background-color:rgb(255, 163, 70);border-style:inset;}"
                );

    InitCource();

    connect(ui->pushButton_certain,SIGNAL(clicked(bool)),this,SLOT(getCourceNum(bool)));

}

void Recommend::InitCource(){
    cource[0].num = 1;
    cource[0].str ="\t\t1 体育舞蹈\n"
                   "推荐等级：五颗星\n"
                   "推荐原因：\n"
                   "\t非常有意思的一门课！能让你全身心的投入。学习国际标准舞，一般是华尔兹。最后考试跳两支舞。需要寻找男女舞伴，可以结伴一起报这个课~也可以去认识新的小伙伴\n"
                   "\t另外，果梅老师真的非常好！没学会的舞步和动作会亲自带你跳！老师跳舞很美很有气质！给分也高！";

    cource[1].num = 2;
    cource[1].str = "\t\t2 生活化学实验\n"
                    "推荐等级：四颗星\n"
                    "推荐原因：\n"
                    "\t很有趣的一门课，文科生理科生都可以报~小班课，做一些关于生活的趣味化学实验，下午连着上四节，课程容量较大，不会闲着，"
                    "想水课的就不要选了。课程任务比较多，分为实验安全考试、每节课的实验及报告、最后设计自己的试验等等，成绩与你的参与程度成正比。"
                    "喜欢化学实验的同学不要错过！";

    cource[2].num = 3;
    cource[2].str = "\t\t3 文献检索\n"
                    "推荐等级：四颗星\n"
                    "推荐理由：\n"
                    "\t是一门满满干货的课！每节课都有任务，最后上机考试，是知网、万方等搜索文献的使用。老师很有耐心，会在群里细致地解答问题。"
                    "上完之后对你的毕业论文的撰写会很有帮助！";

    cource[3].num = 4;
    cource[3].str = "\t\t4 中国传统文化\n"
                    "推荐等级：四颗星\n"
                    "推荐理由：\n"
                    "上课非常轻松，以小组形式做ppt，不是自己组的演讲不用到场。最后以论文结课。阮老师对于课堂要求不高，但很有学识，在点评中"
                    "也能讲到很多东西~属于想水的同学可以水，认真听的同学也能学到东西！最重要的是，给分高！";

    cource[4].num = 5;
    cource[4].str = "\t\t5 基础乐理与作品赏析\n"
                    "推荐等级：五颗星\n"
                    "推荐理由：\n"
                    "黄健老师三部曲No.1。考勤严格，老师在业内很有名，实属难得好课。上完这节课感觉自己变成了一个懂音乐的人~也能完成一首歌的创作"
                    "有一定音乐素养的小伙伴不妨来试试！";

    cource[5].num = 6;
    cource[5].str ="\t\t6 篆刻艺术作品赏析与实践\n"
                   "推荐等级：四颗星\n"
                   "推荐理由：\n"
                   "课堂要求的参与度比较高。每节课写50个小篆，下周上去给大家展示、聊心得，"
                   "并评价其他同学的作品。课堂之后的时间就是刻章，最后需要交印五方章，是能留下印记的一门课。";

    cource[6].num = 7;
    cource[6].str ="\t\t7 兵法与商战\n"
                   "推荐等级：四颗星\n"
                   "推荐理由：\n"
                   "杨老师人很好，很博学，也很敢说，会结合近期发生的事进行讲解~有三次作业，每次一篇小论文。"
                   "有特殊情况的话可以和老师说。";

    cource[7].num = 8;
    cource[7].str ="\t\t8 经济学原理\n"
                   "推荐等级：三颗星\n"
                   "推荐理由：\n"
                   "老师讲的很好！深入浅出，是一门可以学到知识的课。然而，期末考试，内容比较专业，如果能抱到经管同学的"
                   "大腿会容易些！";

    cource[8].num = 9;
    cource[8].str ="\t\t9 股票投资与证券实务\n"
                   "推荐等级：三颗星\n"
                   "推荐理由：\n"
                   "给分可能并不是很高的一门课。保研党和出国党慎选。但是课程内容很有意思很实用，老师会讲一些选股票的方法，每位"
                   "同学都会进行模拟炒股，挑选一支自己的股票，看能赚多少钱~";

    cource[9].num = 10;
    cource[9].str ="\t\t10 数学建模\n"
                   "推荐等级：五颗星\n"
                   "推荐理由：\n"
                   "干货满满！适合准备参加数学建模竞赛的同学，韩敏老师讲的非常好。平均下来，基本每两节课交一次建模作业，没有期末考试。"
                   "好好做给分还是挺高的。";

    cource[10].num = 11;
    cource[10].str = "\t\t11 形式语言与自动机\n"
                     "推荐等级：五颗星\n"
                     "推荐理由：\n"
                     "蒋宗礼老师讲课真的太好了！不听真的很亏。但这门课是编译原理的前导课，还是很有难度的。而且期末不划范围、不给重点，想水课的"
                     "同学趁早放弃。";

}

void Recommend::showRecommend(){
    if(courceNum == 1){
        ui->textEdit->setText(cource[0].str);
    }
    if(courceNum == 2){
        ui->textEdit->setText(cource[1].str);
    }
    if(courceNum == 3){
        ui->textEdit->setText(cource[2].str);
    }
    if(courceNum == 4){
        ui->textEdit->setText(cource[3].str);
    }
    if(courceNum == 5){
        ui->textEdit->setText(cource[4].str);
    }
    if(courceNum == 6){
        ui->textEdit->setText(cource[5].str);
    }
    if(courceNum == 7){
        ui->textEdit->setText(cource[6].str);
    }
    if(courceNum == 8){
        ui->textEdit->setText(cource[7].str);
    }
    if(courceNum == 9){
        ui->textEdit->setText(cource[8].str);
    }
    if(courceNum == 10){
        ui->textEdit->setText(cource[9].str);
    }
    if(courceNum == 11){
        ui->textEdit->setText(cource[10].str);
    }
}


/*********************槽函数******************/
void Recommend::getCourceNum(bool){
    QString s=ui->lineEdit->text();
    courceNum = s.toInt();
    showRecommend();
}
