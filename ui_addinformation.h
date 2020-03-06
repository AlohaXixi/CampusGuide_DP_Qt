/********************************************************************************
** Form generated from reading UI file 'addinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINFORMATION_H
#define UI_ADDINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddInformation
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *AddInformation)
    {
        if (AddInformation->objectName().isEmpty())
            AddInformation->setObjectName(QString::fromUtf8("AddInformation"));
        AddInformation->resize(511, 458);
        label = new QLabel(AddInformation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 341, 121));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(36);
        label->setFont(font);
        label_2 = new QLabel(AddInformation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 420, 72, 15));

        retranslateUi(AddInformation);

        QMetaObject::connectSlotsByName(AddInformation);
    } // setupUi

    void retranslateUi(QWidget *AddInformation)
    {
        AddInformation->setWindowTitle(QApplication::translate("AddInformation", "Form", nullptr));
        label->setText(QApplication::translate("AddInformation", "\345\255\220\347\252\227\345\217\243", nullptr));
        label_2->setText(QApplication::translate("AddInformation", "\345\225\212\345\225\212\345\225\212\345\225\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddInformation: public Ui_AddInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINFORMATION_H
