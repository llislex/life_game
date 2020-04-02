#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QPixmap>
#include <QGraphicsPixmapItem>
#include "life.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    virtual void timerEvent(QTimerEvent *event);
    Life* life;
    QPixmap field;
    QGraphicsPixmapItem* fieldPixmap;
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void showExpanded();
private slots:
    void on_bReset_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
