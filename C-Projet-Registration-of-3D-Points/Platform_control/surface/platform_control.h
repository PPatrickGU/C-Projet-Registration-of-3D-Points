#ifndef PLATFORM_CONTROL_H
#define PLATFORM_CONTROL_H


#include "ui_platform_control.h"

#include <QProcess.h>
#include<QDebug.h>
#include<QMessageBox>
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class Platform_control;
}

class Platform_control : public QDialog
{
    Q_OBJECT

public:
    explicit Platform_control(QWidget *parent = 0);
    ~Platform_control();

private:
    Ui::Platform_control *ui;
    QSerialPort *serial;
    QProcess *process;

    private slots:

    //远柜门丝杠槽函数
    void on_ButtonUp1_clicked();
    void on_ButtonDown1_clicked();
    void on_ButtonReset1_clicked();
    void on_ButtonStop1_clicked();

    //近柜门丝杠槽函数
    void on_ButtonUp2_clicked();
    void on_ButtonDown2_clicked();
    void on_ButtonReset2_clicked();
    void on_ButtonStop2_clicked();

    void on_OpenPortButton_clicked();
    void on_CloseButton_clicked();


};

#endif // PLATFORM_CONTROL_H


