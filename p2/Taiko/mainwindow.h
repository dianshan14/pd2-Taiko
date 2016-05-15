
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
#include <QFont>
#include <QMediaPlayer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int sec , score , mode , music_mode , x_pos;
    QGraphicsPixmapItem * an[10];
    QPixmap p_arr1,p_arr2,p_headshot;
    int tim[10];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void keyPressEvent(QKeyEvent *);
    Ui::MainWindow *ui;
    QLabel * Lab ,*Lab2, * Score , *final , *lab_K , *lab_D , *lab_pause ;
    QGraphicsScene *Scene;
    QGraphicsView *View;
    QGraphicsPixmapItem *pic , *point , *btn_K , *btn_D , *item_headshot ;
    QPushButton * btnGO , *btnExit , *pause , *btnGO2;
    QTimer * timer , * countdown , *it , *its;
    QDialog * end;
    QMediaPlayer * letitgo , *headshot , *bgm;
    QString comment ;
    int filter[10];
private slots:
    void setbg(bool);
    void setbg2(bool);
    void movemove();
    void down();
    void pause_now(bool);
    void for_it();
    void for_its();
};

#endif // MAINWINDOW_H
