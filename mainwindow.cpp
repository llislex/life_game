#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(250);
    life = new Life(320, 640);
    ui->widget->set(life);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete life;
}

void MainWindow::showExpanded()
{
    show();
}

void MainWindow::on_bReset_clicked()
{
    life->reset();
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    (void) event;
    if(life)
    {
        QString ratio = QString::number(life->aliveRatio(), 'g', 4);
        ui->label->setText(QString("cycle %1 alive %2 (%3%)").arg(life->step()).arg(life->alive()).arg(ratio));
        ui->widget->repaint();
    }
}
