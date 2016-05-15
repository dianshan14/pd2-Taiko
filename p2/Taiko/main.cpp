#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QGraphicsScene>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

 //   QGraphicsScene * Scene = new QGraphicsScene;

    // ================= Setting Windows Size =================
//    QDesktopWidget wid;
//    int screenW = 1000; // change to 400 to fit the screen
//    int screenH = 1000; // change to 700 to fit the screen
//    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH); //設定視窗
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("Taiko~");
    w.setWindowIcon(QIcon("../img/img/kilo.png"));
    w.setFixedHeight(900);
    w.setFixedWidth(1200);
    w.show();

    return a.exec();
}
