/********************************************************************************
** Form generated from reading UI file 'platform_control.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLATFORM_CONTROL_H
#define UI_PLATFORM_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Platform_control
{
public:
    QDateTimeEdit *dateTimeEdit;
    QPushButton *ButtonDown1;
    QPushButton *ButtonReset1;
    QPushButton *ButtonStop1;
    QPushButton *ButtonReset2;
    QComboBox *port_baud;
    QLabel *label_6;
    QPushButton *CloseButton;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *ButtonUp1;
    QLabel *label_5;
    QPushButton *ButtonDown2;
    QComboBox *port_number;
    QPushButton *ButtonUp2;
    QPushButton *ButtonStop2;
    QPushButton *OpenPortButton;

    void setupUi(QDialog *Platform_control)
    {
        if (Platform_control->objectName().isEmpty())
            Platform_control->setObjectName(QStringLiteral("Platform_control"));
        Platform_control->resize(400, 187);
        dateTimeEdit = new QDateTimeEdit(Platform_control);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(210, 40, 131, 22));
        ButtonDown1 = new QPushButton(Platform_control);
        ButtonDown1->setObjectName(QStringLiteral("ButtonDown1"));
        ButtonDown1->setGeometry(QRect(10, 80, 75, 23));
        ButtonReset1 = new QPushButton(Platform_control);
        ButtonReset1->setObjectName(QStringLiteral("ButtonReset1"));
        ButtonReset1->setGeometry(QRect(10, 110, 75, 23));
        ButtonStop1 = new QPushButton(Platform_control);
        ButtonStop1->setObjectName(QStringLiteral("ButtonStop1"));
        ButtonStop1->setGeometry(QRect(10, 140, 75, 23));
        ButtonReset2 = new QPushButton(Platform_control);
        ButtonReset2->setObjectName(QStringLiteral("ButtonReset2"));
        ButtonReset2->setGeometry(QRect(100, 110, 75, 23));
        port_baud = new QComboBox(Platform_control);
        port_baud->setObjectName(QStringLiteral("port_baud"));
        port_baud->setGeometry(QRect(210, 140, 71, 22));
        label_6 = new QLabel(Platform_control);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 70, 54, 12));
        CloseButton = new QPushButton(Platform_control);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(300, 140, 75, 23));
        label_4 = new QLabel(Platform_control);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 61, 16));
        label_7 = new QLabel(Platform_control);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 120, 54, 12));
        ButtonUp1 = new QPushButton(Platform_control);
        ButtonUp1->setObjectName(QStringLiteral("ButtonUp1"));
        ButtonUp1->setGeometry(QRect(10, 50, 75, 23));
        label_5 = new QLabel(Platform_control);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 30, 61, 16));
        ButtonDown2 = new QPushButton(Platform_control);
        ButtonDown2->setObjectName(QStringLiteral("ButtonDown2"));
        ButtonDown2->setGeometry(QRect(100, 80, 75, 23));
        port_number = new QComboBox(Platform_control);
        port_number->setObjectName(QStringLiteral("port_number"));
        port_number->setGeometry(QRect(210, 90, 71, 22));
        ButtonUp2 = new QPushButton(Platform_control);
        ButtonUp2->setObjectName(QStringLiteral("ButtonUp2"));
        ButtonUp2->setGeometry(QRect(100, 50, 75, 23));
        ButtonStop2 = new QPushButton(Platform_control);
        ButtonStop2->setObjectName(QStringLiteral("ButtonStop2"));
        ButtonStop2->setGeometry(QRect(100, 140, 75, 23));
        OpenPortButton = new QPushButton(Platform_control);
        OpenPortButton->setObjectName(QStringLiteral("OpenPortButton"));
        OpenPortButton->setGeometry(QRect(300, 90, 75, 23));

        retranslateUi(Platform_control);

        QMetaObject::connectSlotsByName(Platform_control);
    } // setupUi

    void retranslateUi(QDialog *Platform_control)
    {
        Platform_control->setWindowTitle(QApplication::translate("Platform_control", "Platform_control", nullptr));
        ButtonDown1->setText(QApplication::translate("Platform_control", "\344\270\213\351\231\215", nullptr));
        ButtonReset1->setText(QApplication::translate("Platform_control", "\345\244\215\344\275\215", nullptr));
        ButtonStop1->setText(QApplication::translate("Platform_control", "\345\201\234\346\255\242", nullptr));
        ButtonReset2->setText(QApplication::translate("Platform_control", "\345\244\215\344\275\215", nullptr));
        label_6->setText(QApplication::translate("Platform_control", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        CloseButton->setText(QApplication::translate("Platform_control", "Quit", nullptr));
        label_4->setText(QApplication::translate("Platform_control", "\350\277\234\346\237\234\351\227\250\344\270\235\346\235\240", nullptr));
        label_7->setText(QApplication::translate("Platform_control", "\346\263\242\347\211\271\347\216\207", nullptr));
        ButtonUp1->setText(QApplication::translate("Platform_control", "\344\270\212\345\215\207", nullptr));
        label_5->setText(QApplication::translate("Platform_control", "\350\277\221\346\237\234\351\227\250\344\270\235\346\235\240", nullptr));
        ButtonDown2->setText(QApplication::translate("Platform_control", "\344\270\213\351\231\215", nullptr));
        ButtonUp2->setText(QApplication::translate("Platform_control", "\344\270\212\345\215\207", nullptr));
        ButtonStop2->setText(QApplication::translate("Platform_control", "\345\201\234\346\255\242", nullptr));
        OpenPortButton->setText(QApplication::translate("Platform_control", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Platform_control: public Ui_Platform_control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLATFORM_CONTROL_H
