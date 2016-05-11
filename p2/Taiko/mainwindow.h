
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QGraphicsTextItem>
#include <QString>
#include <QKeyEvent>
#include <QMessageBox>
#include "taiko.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int val=1000;
    int sec , score;
    QGraphicsPixmapItem * an[10];
    QPixmap p_arr[10];
    int tim[10];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void keyPressEvent(QKeyEvent *);
    Ui::MainWindow *ui;
    QLabel * Lab , * Score , *final;
    QGraphicsScene *Scene;
    QGraphicsView *View;
    QGraphicsPixmapItem *pic , *point , *ani ;
    QPushButton * btnGO , *btnExit;
    QTimer * timer , * countdown;
    QDialog * end;
    int filter[10]={0};
private slots:
    void setbg(bool);
    void movemove();
    void down();
};

#endif // MAINWINDOW_H
