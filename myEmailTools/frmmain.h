#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>

namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

private slots:
    void on_btnSelect_clicked();

    void on_btnSend_clicked();

    void on_cboxServer_currentIndexChanged(int index);

private:
    Ui::frmMain *ui;
    bool Check();
};

#endif // FRMMAIN_H
