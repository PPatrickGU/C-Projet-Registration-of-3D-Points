/********************************************************************************
** Form generated from reading UI file 'surface.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACE_H
#define UI_SURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_surface
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuPlatform_control;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *surface)
    {
        if (surface->objectName().isEmpty())
            surface->setObjectName(QStringLiteral("surface"));
        surface->resize(400, 300);
        centralWidget = new QWidget(surface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        surface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(surface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 17));
        menuPlatform_control = new QMenu(menuBar);
        menuPlatform_control->setObjectName(QStringLiteral("menuPlatform_control"));
        surface->setMenuBar(menuBar);
        mainToolBar = new QToolBar(surface);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        surface->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(surface);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        surface->setStatusBar(statusBar);

        menuBar->addAction(menuPlatform_control->menuAction());

        retranslateUi(surface);

        QMetaObject::connectSlotsByName(surface);
    } // setupUi

    void retranslateUi(QMainWindow *surface)
    {
        surface->setWindowTitle(QApplication::translate("surface", "surface", nullptr));
        menuPlatform_control->setTitle(QApplication::translate("surface", "Platform control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class surface: public Ui_surface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACE_H
