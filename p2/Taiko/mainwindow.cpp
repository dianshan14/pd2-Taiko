#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    qsrand(time(NULL));
    qsrand(QDateTime::currentDateTime ().toTime_t ());
    View = new QGraphicsView(this);
    setCentralWidget(View);//換view 換視窗
    //Scene = new QGraphicsScene(0,300,1000,400,View);
    Scene = new QGraphicsScene(0,50,1200,800,View);
    View->setScene(Scene);
    pic = new QGraphicsPixmapItem;
//    p = new QPixmap("../img/img/bgg.png");
    QPixmap p(":/img/img/1.jpg");
    p = p.scaled(p.width()*1.1,p.height()*1.15,Qt::IgnoreAspectRatio);
    pic->setPixmap(p);
//    pic->setPixmap(QPixmap("../img/img/bg.png"));
    Scene->addItem(pic);
///////////////////////////////////////////////////////////////////////////
    ani = new QGraphicsPixmapItem;
    QPixmap an("../img/img");
///////////////////////////////////////////////////////////////////////////
    btnGO = new QPushButton(this);
    btnGO->setStyleSheet("border-image:url(:/img/img/burstballoon.png);"); //問處加 甚麼意思
 //   btnGO->setIcon(QIcon("../img/img/burstballoon.png"));
    btnGO->setGeometry(1000,500,200,50); //x是1000靠最右
    btnGO->connect(btnGO,SIGNAL(clicked(bool)),this,SLOT(setbg(bool)));
///////////////////////////////////////////////////////////////////////////
    btnExit = new QPushButton(this);
    btnExit->setIcon(QIcon(":/img/img/burstballoon.png"));
    btnExit->setGeometry(1000,700,200,50);
    btnExit->connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));
///////////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setbg(bool)
{
    if(sec==-1)
    {
        end->close();
        delete Lab;
        delete Score;
        delete final;
    }
    score=0;
    sec=5;
    delete Scene;
    delete btnGO;
    delete btnExit;
    Scene = new QGraphicsScene(0,50,1200,800,View);
    View->setScene(Scene); /////////////////////////這裡可以寫另一個Scene
    pic = new QGraphicsPixmapItem;
    QPixmap p2(":/img/img/bg.png");
    p2 = p2.scaled(p2.width()*2.4,p2.height()*2.3,Qt::IgnoreAspectRatio);
    pic->setPixmap(p2);

    point = new QGraphicsPixmapItem;
    QPixmap p3(":/img/img/_a.png");
    p3 = p3.scaled(p3.width()*0.8,p3.height()*0.8,Qt::IgnoreAspectRatio);
    point->setPixmap(p3);
    point->setPos(-50,220);

//////////////
    ani = new QGraphicsPixmapItem;
//    QPixmap p3("../img/img/mtaikoflash_red.png");
 //   QPixmap p3;
 //   p3.load("../img/img/mtaikoflash_red.png");
 //   p3 = p3.scaled(p3.width()*2.5,p3.height()*2.5,Qt::IgnoreAspectRatio);
 //   ani->setPixmap(p3);
///////
    Scene->addItem(pic);
    Scene->addItem(point);

    int i,k;
    for(i=0;i<5;++i)
    {
        an[i]= new QGraphicsPixmapItem;
        p_arr[i].load(":/img/img/dancer/dancer_2a5.png");
        p_arr[i] = p_arr[i].scaled(p_arr[i].width()*1.5,p_arr[i].height()*1.5,Qt::IgnoreAspectRatio);
        an[i]->setPixmap(p_arr[i]);
        for(k=0;k<10;++k)
        if((qrand()%5500+1400)-tim[k]>500)
        tim[i] = qrand()%5500+1400;
        an[i]->setPos(tim[i],250);
        Scene->addItem(an[i]);
    }
    for(i=5;i<10;++i)
    {
        an[i]= new QGraphicsPixmapItem;
        p_arr[i].load(":/img/img/dancer/dancer_2n8.png");
        p_arr[i] = p_arr[i].scaled(p_arr[i].width()*1.5,p_arr[i].height()*1.5,Qt::IgnoreAspectRatio);
        an[i]->setPixmap(p_arr[i]);
        for(k=0;k<10;++k)
        if((qrand()%5500+1400)-tim[k]>500)
        tim[i] = qrand()%5500+1400;
        an[i]->setPos(tim[i],250);
        Scene->addItem(an[i]);
    }
///////
 //   ani->setPos(-250,200);

 //   Scene->addItem(ani);
    timer = new QTimer(this);
    timer->connect(timer,SIGNAL(timeout()),this,SLOT(movemove())); //再創一個timer來做鼓 ? (利用count++ 控制鼓的數量 ?) 每隔一段時間做一個鼓(偶數或基數判斷) 還有 當作藍色或紅色
    timer->start(10);
    ////有可能按一次鍵盤 偵測到兩個消失
    ///////////////////////////////////////假如 按到就rand重新設定位置
///////////////////////////////////////////////////
    Lab = new QLabel(this);
    Score = new QLabel(this);
    countdown = new QTimer(this);
    countdown->connect(countdown,SIGNAL(timeout()),this,SLOT(down()));
    countdown->start(1000);


}

/*void MainWindow::movemove()
{
    val=val-2.5;
    ani->setPos(val,200);
    if(val<-200)
    {
        val=1000;
        return;
    }
}*/
void MainWindow::movemove()
{
    int j,l;
    for(j=0;j<10;++j)
        tim[j]=tim[j]-8;
    an[0]->setPos(tim[0],250);
    an[1]->setPos(tim[1],250);
    an[2]->setPos(tim[2],250);
    an[3]->setPos(tim[3],250);
    an[4]->setPos(tim[4],250);
    an[5]->setPos(tim[5],250);
    an[6]->setPos(tim[6],250);
    an[7]->setPos(tim[7],250);
    an[8]->setPos(tim[8],250);
    an[9]->setPos(tim[9],250);
    for(j=0;j<10;++j)
        if(tim[j]<-200)
            for(l=0;l<10;++l)
                if(qrand()%5500+1400-tim[l]>500)
                    tim[j]=qrand()%5500+1400;
    QString scor = "Score : ";
    scor = scor + QString::number(score);
    Score->setText(scor);
    Score->setGeometry(500,500,500,500);
    Score->show();
}

void MainWindow::down()
{

//    Scene->addItem();
//    Scene->addItem(Lab);
    QString str = "timer : ";
    str = str + QString::number(sec);

    Lab->setText(str);
    Lab->setGeometry(400,400,500,500);
    Lab->show();

    sec--;
    if(sec==-1)
    {
        countdown->stop();
        timer->stop();
        if(end==0)
        {
            end = new QDialog(this);
            end->setGeometry(700,300,500,300);

            btnExit = new QPushButton(end);
            btnExit->setText("Exit~Bye~");
            btnExit->setGeometry(300,150,150,100);
            btnExit->connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));
//        QMessageBox::information(end,"Title","Text");
            btnGO = new QPushButton(end);
            btnGO->setText("Restart~");
//   btnGO->setStyleSheet("border-image:url(../img/img/burstballoon.png);"); //問處加 甚麼意思
            btnGO->setGeometry(50,150,150,100); //x是1000靠最右
            btnGO->connect(btnGO,SIGNAL(clicked(bool)),this,SLOT(setbg(bool)));

            final = new QLabel(end);
            QString end_score = "Final Score : ";
            end_score = end_score + QString::number(score);
            final->setText(end_score);
            final->setGeometry(200,50,100,100);

            end->show();
        }
        else
        {
            btnExit = new QPushButton(end);
            btnExit->setGeometry(300,150,150,100);
            btnExit->setText("Exit~Bye~");
            btnExit->connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));
            btnGO = new QPushButton(end);
            btnGO->setText("Restart~");
            btnGO->setGeometry(50,150,150,100); //x是1000靠最右
            btnGO->connect(btnGO,SIGNAL(clicked(bool)),this,SLOT(setbg(bool)));

            final = new QLabel(end);
            QString end_score = "Final Score : ";
            end_score = end_score + QString::number(score);
            final->setText(end_score);
            final->setGeometry(200,50,100,100);

            end->show();
        }
    }

}


/*void MainWindow::down()
{
    QGraphicsTextItem * text = new QGraphicsTextItem;
    text->setPlainText("AAAAAA");
    text->setPos(500,500);
    Scene->addItem(text);
}*/

//QGraphicsTextItem;
// timer = new QGraphicsEffect
//         setPlaintext(Qstrimd)

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_D)
    {
        int i,k,tmp,count=0;
        for(i=0;i<5;++i)
        {
            if(tim[i]<=100 && tim[i]>=-50)
            {
                delete an[i];
                an[i] = new QGraphicsPixmapItem;
                an[i]->setPixmap(p_arr[i]);
                k=0;
                tmp = qrand()%7500+2400;
                while(1)
                {
                    //for(k=0;k<10;++k)
                    //{

                        if(tmp-tim[k]>500)
                        {
                            count++;
                        }
                        if(count==50)
                        {
                            count=0;
                            k=0;
                            tim[i] = tmp;
                            break;
                        }
                    k++;
                    if(k==9)
                    {
                        tmp = qrand()%7500+2400;
                        k=0;
                    }
                }
//                for(k=0;k<10;++k)
//                    if((qrand()%5500+1400)-tim[k]>500)
//                        tim[i] = qrand()%5500+1400;
                an[i]->setPos(tim[i],250);
                Scene->addItem(an[i]);
                score++;
            }
        }
    }
    if(event->key() == Qt::Key_F)
    {
        int i,k,tmp,count=0;
        for(i=5;i<10;++i)
        {
            if(tim[i]<=100 && tim[i]>=-50)
            {
                delete an[i];
                an[i] = new QGraphicsPixmapItem;
                an[i]->setPixmap(p_arr[i]);
                k=0;
                tmp = qrand()%7500+2400;
                while(1)
                {
                    //for(k=0;k<10;++k)
                    //{

                        if(tmp-tim[k]>500)
                        {
                            count++;
                        }
                        if(count==50)
                        {
                            count=0;
                            k=0;
                            tim[i] = tmp;
                            break;
                        }
                    k++;
                    if(k==9)
                    {
                        tmp = qrand()%7500+2400;
                        k=0;
                    }
                }
//                for(k=0;k<10;++k)
//                    if((qrand()%5500+1400)-tim[k]>500)
//                        tim[i] = qrand()%5500+1400;
                an[i]->setPos(tim[i],250);
                Scene->addItem(an[i]);
                score++;
            }
        }
    }
}
