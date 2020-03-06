#ifndef INQUIRY_H
#define INQUIRY_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QUrl>
#include <QDesktopServices>
#include "introduction.h"

namespace Ui {
class Inquiry;
}

class Inquiry : public QWidget
{
    Q_OBJECT

public:
    explicit Inquiry(QWidget *parent = nullptr);
    ~Inquiry();

private slots:
    void doProcessAddPlace(bool);
    void doProcessOpenHotelWeb(bool);
    void doProcessOpenBadmintonWeb(bool);
    void doProcessOpenSwimWeb(bool);
    void doProcessOpenSchoolWeb(bool);

private:
    Ui::Inquiry *ui;
    int place;   //地点编号 从1开始 对应右边提示
    QString introduction;
    PlaceIntro Intro[15];

    void Init();
    void InitIntroduction();
    void ShowIntroduction();

};

#endif // INQUIRY_H
