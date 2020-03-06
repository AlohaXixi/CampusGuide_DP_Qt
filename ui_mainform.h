/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QLabel *title;
    QLabel *placeInformation;
    QToolButton *tb1;
    QToolButton *tb2;
    QLabel *label;
    QToolButton *tb2_2;

    void setupUi(QWidget *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName(QString::fromUtf8("Information"));
        Information->setWindowModality(Qt::NonModal);
        Information->resize(1214, 659);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Information->setFont(font);
        title = new QLabel(Information);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(320, 0, 351, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        title->setFont(font1);
        title->setMouseTracking(false);
        placeInformation = new QLabel(Information);
        placeInformation->setObjectName(QString::fromUtf8("placeInformation"));
        placeInformation->setGeometry(QRect(980, 0, 231, 661));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setBold(false);
        font2.setWeight(50);
        placeInformation->setFont(font2);
        tb1 = new QToolButton(Information);
        tb1->setObjectName(QString::fromUtf8("tb1"));
        tb1->setGeometry(QRect(20, 90, 171, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        tb1->setFont(font3);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resource/icon10_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb1->setIcon(icon);
        tb1->setIconSize(QSize(50, 50));
        tb1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tb2 = new QToolButton(Information);
        tb2->setObjectName(QString::fromUtf8("tb2"));
        tb2->setGeometry(QRect(20, 170, 171, 61));
        tb2->setFont(font3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resource/icon11_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb2->setIcon(icon1);
        tb2->setIconSize(QSize(50, 50));
        tb2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label = new QLabel(Information);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 240, 351, 151));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setWeight(50);
        label->setFont(font4);
        tb2_2 = new QToolButton(Information);
        tb2_2->setObjectName(QString::fromUtf8("tb2_2"));
        tb2_2->setGeometry(QRect(20, 250, 171, 61));
        tb2_2->setFont(font3);
        tb2_2->setIcon(icon1);
        tb2_2->setIconSize(QSize(50, 50));
        tb2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        retranslateUi(Information);

        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QWidget *Information)
    {
        Information->setWindowTitle(QApplication::translate("Information", "Information", nullptr));
        title->setText(QApplication::translate("Information", "\345\214\227\345\267\245\345\244\247\346\240\241\345\233\255\345\257\274\350\210\252\347\263\273\347\273\237", nullptr));
        placeInformation->setText(QApplication::translate("Information", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      1  \344\272\214\345\217\267\345\256\277\350\210\215\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      2  \344\277\241\346\201\257\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; m"
                        "argin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      3  \350\275\257\344\273\266\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      4  \345\256\236\350\256\255\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      5  \347\273\217\347\256\241\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      6  \344\272\272\346\226\207\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      7  \345\245\245\346\236\227\345\214\271\345\205\213\344\275\223\350\202\262\351\246\206</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      8  \345\245\245\350\277\220\351\244\220\345\216\205</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      9  \351\200\270\345\244\253\345\233\276\344\271\246\351\246\206</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      10 \346\270\270\346\263\263\351\246\206</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      11 \346\240\241\345\214\273\351\231\242</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:"
                        "'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      12 \345\214\227\347\224\260\345\276\204\345\234\272</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      13 \345\273\272\345\233\275\351\245\255\345\272\227</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      14 \351\207\221\345\267\245\346\245\274</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273"
                        "\221 Light'; font-size:10pt; font-weight:600; color:#ffffff;\">      15 \347\275\221\347\220\203\345\234\272</span></p></body></html>", nullptr));
        tb1->setText(QApplication::translate("Information", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        tb2->setText(QApplication::translate("Information", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("Information", "\346\254\242\350\277\216\346\235\245\345\210\260\346\231\272\350\203\275\345\257\274\350\210\252\347\263\273\347\273\237", nullptr));
        tb2_2->setText(QApplication::translate("Information", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
