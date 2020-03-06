#ifndef PROFESSION_H
#define PROFESSION_H

#include <QWidget>
#include <QComboBox>

namespace Ui {
class Profession;
}

class Profession : public QWidget
{
    Q_OBJECT

public:
    explicit Profession(QWidget *parent = nullptr);
    ~Profession();

private slots:
    void valueChanged(int x);

private:
    Ui::Profession *ui;


    void Init();
    void PrintIntroduction(int index);

};

#endif // PROFESSION_H
