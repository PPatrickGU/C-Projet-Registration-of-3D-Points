#include "platform_control.h"
#include "ui_platform_control.h"
#include <QMessageBox>
#include <QFileDialog>
#include <qdatetime.h>


Platform_control::Platform_control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Platform_control)
{
    ui->setupUi(this);
//设置时间显示
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    process = new QProcess();

    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            QSerialPort serial;
            serial.setPort(info);
            if(serial.open(QIODevice::ReadWrite))
            {
                ui->port_number->addItem(serial.portName());
                serial.close();
            }
        }

        //查找可用的串口    

        //设置波特率下拉菜单默认显示
        QString str[] = { "300", "1200", "9600", "19200" };
        for (int i = 0; i < 4; i++)
        {
            ui->port_baud->addItem(str[i]);
        }
        ui->port_baud->setCurrentIndex(2);     //设置波特率下拉菜单默认显示第3项

        connect(ui->OpenPortButton, SIGNAL(clicked()), this, SLOT(on_OpenPortButton_clicked()), Qt::UniqueConnection);
        connect(ui->CloseButton, SIGNAL(clicked()), this, SLOT(on_CloseButton_clicked()), Qt::UniqueConnection);

        connect(ui->ButtonUp1, SIGNAL(clicked()), this, SLOT(on_ButtonUp1_clicked()), Qt::UniqueConnection);
        connect(ui->ButtonDown1, SIGNAL(clicked()), this, SLOT(on_ButtonDown1_clicked()), Qt::UniqueConnection);
        connect(ui->ButtonReset1, SIGNAL(clicked()), this, SLOT(on_ButtonReset1_clicked()), Qt::UniqueConnection);
        connect(ui->ButtonStop1, SIGNAL(clicked()), this, SLOT(on_ButtonStop1_clicked()), Qt::UniqueConnection);

        connect(ui->ButtonUp1, SIGNAL(clicked()), this, SLOT(on_ButtonUp2_clicked()), Qt::UniqueConnection);
        connect(ui->ButtonDown1, SIGNAL(clicked()), this, SLOT(on_ButtonDown2_clicked()), Qt::UniqueConnection);
        connect(ui->ButtonReset1, SIGNAL(clicked()), this, SLOT(on_ButtonReset2_clicked()), Qt::UniqueConnection);
        connect(ui->ButtonStop1, SIGNAL(clicked()), this, SLOT(on_ButtonStop2_clicked()), Qt::UniqueConnection);

        connect(process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)), Qt::UniqueConnection);
}

Platform_control::~Platform_control()
{
    delete ui;
}


void Platform_control::on_OpenPortButton_clicked()
{
    if (ui ->OpenPortButton->text() == tr("Open"))
    {
        serial = new QSerialPort;
        //设置串口名字
        serial->setPortName(ui->port_number->currentText());
        //以读写方式串口
        serial->open(QIODevice::ReadWrite);
        //设置波特率
        serial->setBaudRate(ui->port_baud->currentText().toInt());
        //设置8数据位数
        serial->setDataBits(QSerialPort::Data8);
        //设置奇偶校验
        serial->setParity(QSerialPort::NoParity);
        //设置1位停止位
        serial->setStopBits(QSerialPort::OneStop);
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);

// 打开之后把字改为关闭，以方便判断
        ui->OpenPortButton->setText(tr("Close"));

    }

    else
    {
        //关闭串口
        serial->close();
        ui->port_baud->setEnabled(true);
        ui->port_number->setEnabled(true);
        ui->OpenPortButton->setText(tr("Open"));
    }

}

//关闭串口,退出程序
void Platform_control::on_CloseButton_clicked()
{
    close();
    //关闭外部程序
    if (process)
    {
        process->close();
        delete process;
        process = NULL;
    }
}

//远柜门丝杠槽函数

void Platform_control::on_ButtonUp1_clicked()
{
    QByteArray dataSend = "C0004L";
    if (ui->OpenPortButton->text() == "Close") //判断串口属于打开状态
    {
        serial->write(dataSend);
    }
}


void Platform_control::on_ButtonDown1_clicked()
{
    QByteArray dataSend = "C0008L";
    if (ui->OpenPortButton->text() == "Close")  //判断串口属于打开状态
    {
        serial->write(dataSend);
    }
}

void Platform_control::on_ButtonReset1_clicked()
{
    QByteArray dataSend = "C0010L";
    if (ui->OpenPortButton->text() == "Close")  //判断串口属于打开状态
    {
        serial->write(dataSend);
    }
}

void Platform_control::on_ButtonStop1_clicked()
{
    QByteArray dataSend = "C0020L";
    if (ui->OpenPortButton->text() == "Close")  //判断串口属于打开状态
    {
        serial->write(dataSend);
    }
}

//近柜门丝杠槽函数

void Platform_control::on_ButtonUp2_clicked()
{
    QByteArray dataSend = "C4000L";
    if (ui->OpenPortButton->text() == "Close")
    {
        serial->write(dataSend);
    }
}

void Platform_control::on_ButtonDown2_clicked()
{
    QByteArray dataSend = "C8000L";
    if (ui->OpenPortButton->text() == "Close")
    {
        serial->write(dataSend);
    }
}

void Platform_control::on_ButtonReset2_clicked()
{
    QByteArray dataSend = "C0001L";
    if (ui->OpenPortButton->text() == "Close")
    {
        serial->write(dataSend);
    }
}

void Platform_control::on_ButtonStop2_clicked()
{
    QByteArray dataSend = "C0002L";
    if (ui->OpenPortButton->text() == "Close")
    {
        serial->write(dataSend);
    }
}









