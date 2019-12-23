/********************************************************************************
** Form generated from reading UI file 'platform_control1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLATFORM_CONTROL1_H
#define UI_PLATFORM_CONTROL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlantScannerClass
{
public:
    QWidget *centralWidget;
    QPushButton *LaserOpenButton;
    QPushButton *LaserCloseButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *OnButtonUp1;
    QPushButton *OnButtonDown1;
    QPushButton *OnButtonStop1;
    QLabel *label_3;
    QPushButton *OnButtonUp2;
    QPushButton *OnButtonDown2;
    QPushButton *OnButtonStop2;
    QLabel *label_4;
    QPushButton *OnButtonUp3;
    QPushButton *OnButtonDown3;
    QPushButton *OnButtonReset3;
    QPushButton *OnButtonStop3;
    QLabel *label_5;
    QPushButton *OnButtonUp4;
    QPushButton *OnButtonDown4;
    QPushButton *OnButtonReset4;
    QPushButton *OnButtonStop4;
    QLabel *label_6;
    QComboBox *port_number;
    QComboBox *port_baudate;
    QLabel *label_7;
    QPushButton *OpenPortButton;
    QPushButton *CloseButton;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QMainWindow *PlantScannerClass)
    {
        if (PlantScannerClass->objectName().isEmpty())
            PlantScannerClass->setObjectName(QStringLiteral("PlantScannerClass"));
        PlantScannerClass->setWindowModality(Qt::NonModal);
        PlantScannerClass->resize(367, 259);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/SJTU.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        PlantScannerClass->setWindowIcon(icon);
        PlantScannerClass->setDocumentMode(true);
        PlantScannerClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(PlantScannerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LaserOpenButton = new QPushButton(centralWidget);
        LaserOpenButton->setObjectName(QStringLiteral("LaserOpenButton"));
        LaserOpenButton->setGeometry(QRect(190, 140, 75, 23));
        LaserCloseButton = new QPushButton(centralWidget);
        LaserCloseButton->setObjectName(QStringLiteral("LaserCloseButton"));
        LaserCloseButton->setGeometry(QRect(280, 140, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 120, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 10, 54, 12));
        OnButtonUp1 = new QPushButton(centralWidget);
        OnButtonUp1->setObjectName(QStringLiteral("OnButtonUp1"));
        OnButtonUp1->setGeometry(QRect(190, 30, 75, 23));
        OnButtonDown1 = new QPushButton(centralWidget);
        OnButtonDown1->setObjectName(QStringLiteral("OnButtonDown1"));
        OnButtonDown1->setGeometry(QRect(190, 60, 75, 23));
        OnButtonStop1 = new QPushButton(centralWidget);
        OnButtonStop1->setObjectName(QStringLiteral("OnButtonStop1"));
        OnButtonStop1->setGeometry(QRect(190, 90, 75, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 10, 54, 12));
        OnButtonUp2 = new QPushButton(centralWidget);
        OnButtonUp2->setObjectName(QStringLiteral("OnButtonUp2"));
        OnButtonUp2->setGeometry(QRect(280, 30, 75, 23));
        OnButtonUp2->setAutoDefault(false);
        OnButtonUp2->setFlat(false);
        OnButtonDown2 = new QPushButton(centralWidget);
        OnButtonDown2->setObjectName(QStringLiteral("OnButtonDown2"));
        OnButtonDown2->setGeometry(QRect(280, 60, 75, 23));
        OnButtonStop2 = new QPushButton(centralWidget);
        OnButtonStop2->setObjectName(QStringLiteral("OnButtonStop2"));
        OnButtonStop2->setGeometry(QRect(280, 90, 75, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 61, 16));
        OnButtonUp3 = new QPushButton(centralWidget);
        OnButtonUp3->setObjectName(QStringLiteral("OnButtonUp3"));
        OnButtonUp3->setGeometry(QRect(10, 30, 75, 23));
        OnButtonDown3 = new QPushButton(centralWidget);
        OnButtonDown3->setObjectName(QStringLiteral("OnButtonDown3"));
        OnButtonDown3->setGeometry(QRect(10, 60, 75, 23));
        OnButtonReset3 = new QPushButton(centralWidget);
        OnButtonReset3->setObjectName(QStringLiteral("OnButtonReset3"));
        OnButtonReset3->setGeometry(QRect(10, 90, 75, 23));
        OnButtonStop3 = new QPushButton(centralWidget);
        OnButtonStop3->setObjectName(QStringLiteral("OnButtonStop3"));
        OnButtonStop3->setGeometry(QRect(10, 120, 75, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 10, 61, 16));
        OnButtonUp4 = new QPushButton(centralWidget);
        OnButtonUp4->setObjectName(QStringLiteral("OnButtonUp4"));
        OnButtonUp4->setGeometry(QRect(100, 30, 75, 23));
        OnButtonDown4 = new QPushButton(centralWidget);
        OnButtonDown4->setObjectName(QStringLiteral("OnButtonDown4"));
        OnButtonDown4->setGeometry(QRect(100, 60, 75, 23));
        OnButtonReset4 = new QPushButton(centralWidget);
        OnButtonReset4->setObjectName(QStringLiteral("OnButtonReset4"));
        OnButtonReset4->setGeometry(QRect(100, 90, 75, 23));
        OnButtonStop4 = new QPushButton(centralWidget);
        OnButtonStop4->setObjectName(QStringLiteral("OnButtonStop4"));
        OnButtonStop4->setGeometry(QRect(100, 120, 75, 23));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 150, 54, 12));
        port_number = new QComboBox(centralWidget);
        port_number->setObjectName(QStringLiteral("port_number"));
        port_number->setGeometry(QRect(10, 170, 71, 22));
        port_baudate = new QComboBox(centralWidget);
        port_baudate->setObjectName(QStringLiteral("port_baudate"));
        port_baudate->setGeometry(QRect(10, 220, 71, 22));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 200, 54, 12));
        OpenPortButton = new QPushButton(centralWidget);
        OpenPortButton->setObjectName(QStringLiteral("OpenPortButton"));
        OpenPortButton->setGeometry(QRect(100, 170, 75, 23));
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(100, 220, 75, 23));
        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(230, 220, 131, 22));
        PlantScannerClass->setCentralWidget(centralWidget);

        retranslateUi(PlantScannerClass);
        QObject::connect(LaserOpenButton, SIGNAL(clicked()), PlantScannerClass, SLOT(on_LaserOpenButton()));
        QObject::connect(LaserCloseButton, SIGNAL(clicked()), PlantScannerClass, SLOT(on_LaserCloseButton()));
        QObject::connect(OnButtonUp1, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonUp1()));
        QObject::connect(OnButtonDown1, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonDown1()));
        QObject::connect(OnButtonStop1, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonStop1()));
        QObject::connect(OnButtonUp2, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonUp2()));
        QObject::connect(OnButtonDown2, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonDown2()));
        QObject::connect(OnButtonStop2, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonStop2()));
        QObject::connect(OnButtonUp3, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonUp3()));
        QObject::connect(OnButtonDown3, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonDown3()));
        QObject::connect(OnButtonReset3, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonReset3()));
        QObject::connect(OnButtonStop3, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonStop3()));
        QObject::connect(OnButtonUp4, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonUp4()));
        QObject::connect(OnButtonDown4, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonDown4()));
        QObject::connect(OnButtonReset4, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonReset4()));
        QObject::connect(OnButtonStop4, SIGNAL(clicked()), PlantScannerClass, SLOT(on_ClickedButtonStop4()));
        QObject::connect(OpenPortButton, SIGNAL(clicked()), PlantScannerClass, SLOT(on_OpenPortButton()));
        QObject::connect(CloseButton, SIGNAL(clicked()), PlantScannerClass, SLOT(on_CloseButton()));

        OnButtonUp2->setDefault(false);


        QMetaObject::connectSlotsByName(PlantScannerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PlantScannerClass)
    {
        PlantScannerClass->setWindowTitle(QApplication::translate("PlantScannerClass", "\346\244\215\347\211\251\346\211\253\346\217\217\344\273\252_SJTU", nullptr));
        LaserOpenButton->setText(QApplication::translate("PlantScannerClass", "\346\211\223\345\274\200", nullptr));
        LaserCloseButton->setText(QApplication::translate("PlantScannerClass", "\345\205\263\351\227\255", nullptr));
        label->setText(QApplication::translate("PlantScannerClass", "\346\277\200\345\205\211\345\217\221\345\260\204\345\231\250", nullptr));
        label_2->setText(QApplication::translate("PlantScannerClass", "\351\241\266\351\203\250\344\270\235\346\235\240", nullptr));
        OnButtonUp1->setText(QApplication::translate("PlantScannerClass", "\344\270\212\345\215\207", nullptr));
        OnButtonDown1->setText(QApplication::translate("PlantScannerClass", "\344\270\213\351\231\215", nullptr));
        OnButtonStop1->setText(QApplication::translate("PlantScannerClass", "\345\201\234\346\255\242", nullptr));
        label_3->setText(QApplication::translate("PlantScannerClass", "\346\277\200\345\205\211\344\270\235\346\235\240", nullptr));
        OnButtonUp2->setText(QApplication::translate("PlantScannerClass", "\344\270\212\345\215\207", nullptr));
        OnButtonDown2->setText(QApplication::translate("PlantScannerClass", "\344\270\213\351\231\215", nullptr));
        OnButtonStop2->setText(QApplication::translate("PlantScannerClass", "\345\201\234\346\255\242", nullptr));
        label_4->setText(QApplication::translate("PlantScannerClass", "\350\277\234\346\237\234\351\227\250\344\270\235\346\235\240", nullptr));
        OnButtonUp3->setText(QApplication::translate("PlantScannerClass", "\344\270\212\345\215\207", nullptr));
        OnButtonDown3->setText(QApplication::translate("PlantScannerClass", "\344\270\213\351\231\215", nullptr));
        OnButtonReset3->setText(QApplication::translate("PlantScannerClass", "\345\244\215\344\275\215", nullptr));
        OnButtonStop3->setText(QApplication::translate("PlantScannerClass", "\345\201\234\346\255\242", nullptr));
        label_5->setText(QApplication::translate("PlantScannerClass", "\350\277\221\346\237\234\351\227\250\344\270\235\346\235\240", nullptr));
        OnButtonUp4->setText(QApplication::translate("PlantScannerClass", "\344\270\212\345\215\207", nullptr));
        OnButtonDown4->setText(QApplication::translate("PlantScannerClass", "\344\270\213\351\231\215", nullptr));
        OnButtonReset4->setText(QApplication::translate("PlantScannerClass", "\345\244\215\344\275\215", nullptr));
        OnButtonStop4->setText(QApplication::translate("PlantScannerClass", "\345\201\234\346\255\242", nullptr));
        label_6->setText(QApplication::translate("PlantScannerClass", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        label_7->setText(QApplication::translate("PlantScannerClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        OpenPortButton->setText(QApplication::translate("PlantScannerClass", "Open", nullptr));
        CloseButton->setText(QApplication::translate("PlantScannerClass", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlantScannerClass: public Ui_PlantScannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLATFORM_CONTROL1_H
