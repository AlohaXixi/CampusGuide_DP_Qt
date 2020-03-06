#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <QWidget>
#include "subject.h"
#define CourceNum 11

namespace Ui {
class Recommend;
}

class Recommend : public QWidget
{
    Q_OBJECT

public:
    explicit Recommend(QWidget *parent = nullptr);
    ~Recommend();

private slots:
    void getCourceNum(bool);

private:
    Ui::Recommend *ui;
    Subject cource[CourceNum];
    int courceNum{0};

    void Init();
    void InitCource();
    void showRecommend();

};

#endif // RECOMMEND_H
