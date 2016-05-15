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
// initializer
    end=0;
    mode=0;
    music_mode=2;
//
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
//    pic->setPos(0,750);
//    pic->setPixmap(QPixmap("../img/img/bg.png"));
    Scene->addItem(pic);
///////////////////////////////////////////////////////////////////////////
    btnGO2 = new QPushButton(this);
    btnGO2->setStyleSheet("border-image:url(:/img/poke/pokeball.png)"); //問處加 甚麼意思
 //   btnGO->setIcon(QIcon("../img/img/burstballoon.png"));
    btnGO2->setGeometry(550,450,200,200); //x是1000靠最右
    btnGO2->connect(btnGO2,SIGNAL(clicked(bool)),this,SLOT(setbg2(bool)));
///////////////////////////////////////////////////////////////////////////
    btnGO = new QPushButton(this);
    btnGO->setStyleSheet("border-image:url(:/img/img/start.png)"); //問處加 甚麼意思
 //   btnGO->setIcon(QIcon("../img/img/burstballoon.png"));
    btnGO->setGeometry(310,670,200,200); //x是1000靠最右
    btnGO->connect(btnGO,SIGNAL(clicked(bool)),this,SLOT(setbg(bool)));
///////////////////////////////////////////////////////////////////////////
    btnExit = new QPushButton(this);
    btnExit->setStyleSheet("border-image:url(:/img/img/stop.png);");
 //    btnExit->setIcon(QIcon(":/img/img/burstballoon.png"));
    btnExit->setGeometry(700,660,220,230);
    btnExit->connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));
///////////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setbg(bool)
{
    music_mode=0;
    int i;
    letitgo = new QMediaPlayer(this);
    letitgo->setMedia(QUrl("qrc:/img/img/letitgo.mp3"));
    letitgo->play();

    bgm = new QMediaPlayer(this);
    bgm->setMedia(QUrl("qrc:/img/img/bgg.mp3"));
    bgm->play();

    if(sec==-1)
    {
        end->close();
        delete Lab;
        delete Score;
        delete final;
        for(i=0;i<10;++i)
            delete an[i];
    }
    score=0;
    sec=29;
    delete Scene;
    delete btnGO;
    delete btnExit;
    delete btnGO2;
    Scene = new QGraphicsScene(0,50,1200,800,View);
    View->setScene(Scene); /////////////////////////這裡可以寫另一個Scene
    pic = new QGraphicsPixmapItem;
    QPixmap p2(":/img/img/field.jpg");
    p2 = p2.scaled(p2.width()*2.4/344*512,p2.height()*2.3/146*384,Qt::IgnoreAspectRatio);
    pic->setPixmap(p2);

    point = new QGraphicsPixmapItem;
    QPixmap p3(":/img/img/point.png");
    p3 = p3.scaled(p3.width(),p3.height()*0.8/255*384,Qt::IgnoreAspectRatio);
    point->setPixmap(p3);
    point->setPos(0,220);

    p_arr1.load(":/img/img/dancer/dancer_2a5.png");
    p_arr1 = p_arr1.scaled(p_arr1.width()*1.5,p_arr1.height()*1.5,Qt::IgnoreAspectRatio);
    p_arr2.load(":/img/img/dancer/dancer_2n8.png");
    p_arr2 = p_arr2.scaled(p_arr2.width()*1.5,p_arr2.height()*1.5,Qt::IgnoreAspectRatio);
    p_headshot.load(":/img/img/headshot.png");
    p_headshot = p_headshot.scaled(p_headshot.width()*0.5,p_headshot.height()*0.5,Qt::IgnoreAspectRatio);

    btn_D = new QGraphicsPixmapItem;
    btn_D->setPos(50,500);
    btn_D->setPixmap(p_arr1);

    btn_K = new QGraphicsPixmapItem;
    btn_K->setPos(275,450);
    btn_K->setPixmap(p_arr2);

    pause = new QPushButton(this);
    pause->setStyleSheet("border-image:url(:/img/img/pause.png);");
    pause->setGeometry(900,530,233,216);
    pause->connect(pause,SIGNAL(clicked(bool)),this,SLOT(pause_now(bool)));
    pause->show();
//////////////
//    QPixmap p3("../img/img/mtaikoflash_red.png");
 //   QPixmap p3;
 //   p3.load("../img/img/mtaikoflash_red.png");
 //   p3 = p3.scaled(p3.width()*2.5,p3.height()*2.5,Qt::IgnoreAspectRatio);
 //   ani->setPixmap(p3);
///////
    Scene->addItem(pic);
    Scene->addItem(point);
    Scene->addItem(btn_D);
    Scene->addItem(btn_K);
    int fir_x,c,ele,tmp;


    for(i=0;i<5;++i)
    {
        an[i]= new QGraphicsPixmapItem;
   //     p_arr[i].load(":/img/img/dancer/dancer_2a5.png");
   //     p_arr[i] = p_arr[i].scaled(p_arr[i].width()*1.5,p_arr[i].height()*1.5,Qt::IgnoreAspectRatio);
        an[i]->setPixmap(p_arr1);

        /*for(k=0;k<10;++k)
        if((qrand()%5500+1400)-tim[k]>500)
        tim[i] = qrand()%5500+1400;
        an[i]->setPos(tim[i],250);
        Scene->addItem(an[i]);*/
    }
    for(i=5;i<10;++i)
    {
        an[i]= new QGraphicsPixmapItem;
  //      p_arr[i].load(":/img/img/dancer/dancer_2n8.png");
  //      p_arr[i] = p_arr[i].scaled(p_arr[i].width()*1.5,p_arr[i].height()*1.5,Qt::IgnoreAspectRatio);
        an[i]->setPixmap(p_arr2);
        /*for(k=0;k<10;++k)
        if((qrand()%5500+1400)-tim[k]>500)
        tim[i] = qrand()%5500+1400;
        an[i]->setPos(tim[i],250);
        Scene->addItem(an[i]);*/
    }
    for(i=0;i<10;++i)
        filter[i]=0;
    fir_x = 1400;
    c=0;
    while(c!=10)
    {
        c=0;
        ele=qrand()%10;
        if(filter[ele]==0)
        {
            filter[ele]++;
            tim[ele] = fir_x + rand()%200;
          //  tim[ele] = fir_x;
            fir_x=fir_x+300;
            if(ele==5 || ele==6 || ele==7 || ele==8 || ele==9)
                tmp=200;
            else
                tmp=250;
            an[ele]->setPos(tim[ele],tmp);
            Scene->addItem(an[ele]);
        }
        for(i=0;i<10;++i)
        {
            if(filter[i]!=0)
                c++;
        }
    }
    for(i=0;i<10;++i)
        filter[i]=0;
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
    Lab2 = new QLabel(this);
    Score = new QLabel(this);
    lab_D = new QLabel(this);
    lab_K = new QLabel(this);
    lab_pause = new QLabel(this);

    int sec2;
    sec2=30;
    QString st = "timer : ";
    st = st + QString::number(sec2);
    Lab2->setText(st);
    Lab2->setFont(QFont("Courier",40,QFont::Black));
    Lab2->setGeometry(0,-50,400,300);
    Lab2->show();

    QString str_D = "D";
    lab_D->setText(str_D);
    lab_D->setFont(QFont("Courier",40,QFont::Black));
    lab_D->setGeometry(190,500,300,300);
    lab_D->show();

    QString str_K = "K";
    lab_K->setText(str_K);
    lab_K->setFont(QFont("Courier",40,QFont::Black));
    lab_K->setGeometry(405,500,300,300);
    lab_K->show();

    QString str_pause = "P";
    lab_pause->setText(str_pause);
    lab_pause->setFont(QFont("Courier",40,QFont::Black));
    lab_pause->setGeometry(1000,590,300,300);
    lab_pause->show();

    countdown = new QTimer(this);
    countdown->connect(countdown,SIGNAL(timeout()),this,SLOT(down()));
    countdown->start(1000);

    it = new QTimer(this);
    its = new QTimer(this);

    item_headshot = new QGraphicsPixmapItem;
    item_headshot->setPixmap(p_headshot);
    item_headshot->setPos(-500,-500);
    Scene->addItem(item_headshot);
    item_headshot->hide();

}

void MainWindow::setbg2(bool)
{
    music_mode=1;
    int i;


    bgm = new QMediaPlayer(this);
    bgm->setMedia(QUrl("qrc:/img/poke/bgm.mp3"));
    bgm->play();

    if(sec==-1)
    {
        end->close();
        delete Lab;
        delete Score;
        delete final;
        for(i=0;i<10;++i)
            delete an[i];
    }
    score=0;
    sec=29;
    delete Scene;
    delete btnGO;
    delete btnExit;
    delete btnGO2;
    Scene = new QGraphicsScene(0,50,1200,800,View);
    View->setScene(Scene); /////////////////////////這裡可以寫另一個Scene
    pic = new QGraphicsPixmapItem;
    QPixmap p2(":/img/poke/bg5.jpg");
    p2 = p2.scaled(p2.width()*2.4*512/258,p2.height()*2.3*384/196,Qt::IgnoreAspectRatio);
    pic->setPixmap(p2);

    point = new QGraphicsPixmapItem;
    QPixmap p3(":/img/poke/openball.png");
    p3 = p3.scaled(p3.width()*1.5,p3.height()*1.5,Qt::IgnoreAspectRatio);
    point->setPixmap(p3);
    point->setPos(-90,200);

    p_arr1.load(":/img/poke/a.png");
    p_arr1 = p_arr1.scaled(p_arr1.width()*0.9,p_arr1.height()*0.9,Qt::IgnoreAspectRatio);
    p_arr2.load(":/img/poke/b.png");
    p_arr2 = p_arr2.scaled(p_arr2.width()*0.9,p_arr2.height()*0.9,Qt::IgnoreAspectRatio);
    p_headshot.load(":/img/poke/pokeball.png");
    p_headshot = p_headshot.scaled(p_headshot.width()*1.5,p_headshot.height()*1.5,Qt::IgnoreAspectRatio);

    btn_D = new QGraphicsPixmapItem;
    btn_D->setPos(0,500);
    btn_D->setPixmap(p_arr1);

    btn_K = new QGraphicsPixmapItem;
    btn_K->setPos(230,510);
    btn_K->setPixmap(p_arr2);

    pause = new QPushButton(this);
    pause->setStyleSheet("border-image:url(:/img/img/pause.png);");
    pause->setGeometry(900,530,233,216);
    pause->connect(pause,SIGNAL(clicked(bool)),this,SLOT(pause_now(bool)));
    pause->show();
//////////////
//    QPixmap p3("../img/img/mtaikoflash_red.png");
 //   QPixmap p3;
 //   p3.load("../img/img/mtaikoflash_red.png");
 //   p3 = p3.scaled(p3.width()*2.5,p3.height()*2.5,Qt::IgnoreAspectRatio);
 //   ani->setPixmap(p3);
///////
    Scene->addItem(pic);
    Scene->addItem(point);
    Scene->addItem(btn_D);
    Scene->addItem(btn_K);
    int fir_x,c,ele,tmp;


    for(i=0;i<5;++i)
    {
        an[i]= new QGraphicsPixmapItem;
   //     p_arr[i].load(":/img/img/dancer/dancer_2a5.png");
   //     p_arr[i] = p_arr[i].scaled(p_arr[i].width()*1.5,p_arr[i].height()*1.5,Qt::IgnoreAspectRatio);
        an[i]->setPixmap(p_arr1);

        /*for(k=0;k<10;++k)
        if((qrand()%5500+1400)-tim[k]>500)
        tim[i] = qrand()%5500+1400;
        an[i]->setPos(tim[i],250);
        Scene->addItem(an[i]);*/
    }
    for(i=5;i<10;++i)
    {
        an[i]= new QGraphicsPixmapItem;
  //      p_arr[i].load(":/img/img/dancer/dancer_2n8.png");
  //      p_arr[i] = p_arr[i].scaled(p_arr[i].width()*1.5,p_arr[i].height()*1.5,Qt::IgnoreAspectRatio);
        an[i]->setPixmap(p_arr2);
        /*for(k=0;k<10;++k)
        if((qrand()%5500+1400)-tim[k]>500)
        tim[i] = qrand()%5500+1400;
        an[i]->setPos(tim[i],250);
        Scene->addItem(an[i]);*/
    }
    for(i=0;i<10;++i)
        filter[i]=0;
    fir_x = 1400;
    c=0;
    while(c!=10)
    {
        c=0;
        ele=qrand()%10;
        if(filter[ele]==0)
        {
            filter[ele]++;
            tim[ele] = fir_x + rand()%200;
          //  tim[ele] = fir_x;
            fir_x=fir_x+300;
            if(ele==5 || ele==6 || ele==7 || ele==8 || ele==9)
               tmp=230;
            else
                tmp=250;
            an[ele]->setPos(tim[ele],tmp);
            Scene->addItem(an[ele]);
        }
        for(i=0;i<10;++i)
        {
            if(filter[i]!=0)
                c++;
        }
    }
    for(i=0;i<10;++i)
        filter[i]=0;
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
    Lab2 = new QLabel(this);
    Score = new QLabel(this);
    lab_D = new QLabel(this);
    lab_K = new QLabel(this);
    lab_pause = new QLabel(this);

    int sec2;
    sec2=30;
    QString st = "timer : ";
    st = st + QString::number(sec2);
    Lab2->setText(st);
    Lab2->setFont(QFont("Courier",40,QFont::Black));
    Lab2->setGeometry(0,-50,400,300);
    Lab2->show();

    QString str_D = "V";
    lab_D->setText(str_D);
    lab_D->setFont(QFont("Courier",40,QFont::Black));
    lab_D->setGeometry(180,500,300,300);
    lab_D->show();

    QString str_K = "N";
    lab_K->setText(str_K);
    lab_K->setFont(QFont("Courier",40,QFont::Black));
    lab_K->setGeometry(400,500,300,300);
    lab_K->show();

    QString str_pause = "P";
    lab_pause->setText(str_pause);
    lab_pause->setFont(QFont("Courier",40,QFont::Black));
    lab_pause->setGeometry(1100,500,300,300);
    lab_pause->show();

    countdown = new QTimer(this);
    countdown->connect(countdown,SIGNAL(timeout()),this,SLOT(down()));
    countdown->start(1000);

    it = new QTimer(this);
    its = new QTimer(this);

    item_headshot = new QGraphicsPixmapItem;
    item_headshot->setPixmap(p_headshot);
    item_headshot->setPos(-500,-500);
    Scene->addItem(item_headshot);
    item_headshot->hide();

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
    int j,l,t;
    t=0;
    for(j=0;j<10;++j)
    {
        tim[j]=tim[j]-5;
        if(music_mode==0 && (j==0 || j==1 || j==2 || j==3 || j==4))
            an[j]->setPos(tim[j],250);
        else if(music_mode==0 && (j==5 || j==6 || j==7 || j==8 || j==9))
            an[j]->setPos(tim[j],200);
        else if(music_mode==1 && (j==0 || j==1 || j==2 || j==3 || j==4))
            an[j]->setPos(tim[j],250);
        else if(music_mode==1 && (j==5 || j==6 || j==7 || j==8 || j==9))
            an[j]->setPos(tim[j],230);
    }
   // an[0]->setPos(tim[0],250);
  //  an[1]->setPos(tim[1],250);
  //  an[2]->setPos(tim[2],250);
  //  an[3]->setPos(tim[3],250);
  //  an[4]->setPos(tim[4],250);
  //  an[5]->setPos(tim[5],200);
  //  an[6]->setPos(tim[6],200);
  //  an[7]->setPos(tim[7],200);
  //  an[8]->setPos(tim[8],200);
  //  an[9]->setPos(tim[9],200);
/*    for(j=0;j<10;++j)
        if(tim[j]<-200)
            for(l=0;l<10;++l)
                if(qrand()%5500+1400-tim[l]>500)
                    tim[j]=qrand()%5500+1400;*/
    for(j=0;j<10;++j)
        if(tim[j]<-200)
        {
            for(l=0;l<10;++l)
                if(tim[l]>t)
                    t=tim[l];
            tim[j]=t+200+qrand()%250;
        }
    t=0;
    QString scor = "Score : ";
    scor = scor + QString::number(score);
    Score->setText(scor);
    Score->setFont(QFont("Courier",40,QFont::Black));
    Score->setGeometry(450,-50,400,300);
    Score->show();

}

void MainWindow::down()
{

//    Scene->addItem();
//    Scene->addItem(Lab);
    QString str = "timer : ";
    str = str + QString::number(sec);

    Lab->setText(str);
    Lab->setFont(QFont("Courier",40,QFont::Black));
    Lab->setGeometry(0,-50,400,300);
    Lab->show();
    Lab2->close();

    sec--;
    if(sec==-1)
    {
        bgm->stop();
        countdown->stop();
        timer->stop();
        if(end==0)
        {
            end = new QDialog(this);
            end->setGeometry(700,300,650,300);

            btnExit = new QPushButton(end);
            btnExit->setText("Exit~Bye~");
            btnExit->setFont(QFont("Courier",12,QFont::Black));
            btnExit->setGeometry(450,150,150,100);
            btnExit->connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));
//        QMessageBox::information(end,"Title","Text");
            btnGO = new QPushButton(end);
            btnGO->setText("Restart~1");
            btnGO->setFont(QFont("Courier",12,QFont::Black));
//   btnGO->setStyleSheet("border-image:url(../img/img/burstballoon.png);"); //問處加 甚麼意思
            btnGO->setGeometry(50,150,150,100); //x是1000靠最右
            btnGO->connect(btnGO,SIGNAL(clicked(bool)),this,SLOT(setbg(bool)));

            btnGO2 = new QPushButton(end);
            btnGO2->setText("Restart~2");
            btnGO2->setFont(QFont("Courier",12,QFont::Black));
            btnGO2->setGeometry(250,150,150,100); //x是1000靠最右
            btnGO2->connect(btnGO2,SIGNAL(clicked(bool)),this,SLOT(setbg2(bool)));

            final = new QLabel(end);
            QString end_score = "Final Score : ";
            if(score<20)
                comment = "   Comment: Bad！";
            else if(score >= 20 && score <= 40)
                comment = "   Comment: Good！";
            else if(score>40)
                comment = "   Comment: Best！";
            end_score = end_score + QString::number(score)+comment;
            final->setText(end_score);
            final->setFont(QFont("Courier",12,QFont::Black));
            final->setGeometry(130,50,400,100);



            lab_D->hide();
            lab_K->hide();

            end->show();
        }
        else
        {
            btnExit = new QPushButton(end);
            btnExit->setGeometry(450,150,150,100);
            btnExit->setText("Exit~Bye~");
            btnExit->setFont(QFont("Courier",12,QFont::Black));
            btnExit->connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));
            btnGO = new QPushButton(end);
            btnGO->setText("Restart~1");
            btnGO->setFont(QFont("Courier",12,QFont::Black));
            btnGO->setGeometry(50,150,150,100); //x是1000靠最右
            btnGO->connect(btnGO,SIGNAL(clicked(bool)),this,SLOT(setbg(bool)));

            btnGO2 = new QPushButton(end);
            btnGO2->setText("Restart~2");
            btnGO2->setFont(QFont("Courier",12,QFont::Black));
            btnGO2->setGeometry(250,150,150,100); //x是1000靠最右
            btnGO2->connect(btnGO2,SIGNAL(clicked(bool)),this,SLOT(setbg2(bool)));

            final = new QLabel(end);
            QString end_score = "Final Score : ";
            if(score<20)
                comment = "   Comment: Bad！";
            else if(score >= 20 && score <= 40)
                comment = "   Comment: Good！";
            else if(score>40)
                comment = "   Comment: Best！";
            end_score = end_score + QString::number(score)+comment;
            final->setText(end_score);
            final->setFont(QFont("Courier",12,QFont::Black));
            final->setGeometry(130,50,400,100);

            lab_D->hide();
            lab_K->hide();

            end->show();
        }
    }

}

void MainWindow::pause_now(bool)
{
    if(mode==0)
    {
        countdown->stop();
        timer->stop();
        mode=1;
        bgm->pause();
    }
    else
    {
        countdown->start(1000);
        timer->start(10);
        mode=0;
        bgm->play();
    }
}

void MainWindow::for_it()
{
    it->stop();
    if(music_mode==0)
    {
        item_headshot->setPos(x_pos,330);
        item_headshot->show();
    }
    else if(music_mode==1)
    {
        item_headshot->setPos(-45,180);
        item_headshot->show();
    }
    its->connect(its,SIGNAL(timeout()),this,SLOT(for_its()));
    its->start(200);
}

void MainWindow::for_its()
{
    item_headshot->hide();
    its->stop();
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
 //   int fir_y;
    int t;
    t=0;
 //   fir_y=3000;
    if(event->key() == Qt::Key_D && music_mode==0)
    {
        int i,k;
      //  int tmp,count=0;
        for(i=0;i<5;++i)
        {
            if(tim[i]<=100 && tim[i]>=-100)
            {
                headshot = new QMediaPlayer(this);
                headshot->setMedia(QUrl("qrc:/img/img/headshot2.mp3"));
                headshot->play();
                x_pos=tim[i];
                delete an[i];
                an[i] = new QGraphicsPixmapItem;
                an[i]->setPixmap(p_arr1);
                /*k=0;
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
                Scene->addItem(an[i]);*/

            //    tim[i]=fir_y;
            //   fir_y=fir_y+200;
                it->connect(it,SIGNAL(timeout()),this,SLOT(for_it()));
                it->start(100);
                for(k=0;k<10;++k)
                    if(tim[k]>t)
                        t=tim[k];
                tim[i]=t+200+qrand()%250;
                t=0;
                an[i]->setPos(tim[i],250);
                Scene->addItem(an[i]);
                score++;
            }
        }
    }
    if(event->key() == Qt::Key_K && music_mode==0)
    {
        int i,k;
  //      int tmp,count=0;
        for(i=5;i<10;++i)
        {
            if(tim[i]<=100 && tim[i]>=-100)
            {
                headshot = new QMediaPlayer(this);
                headshot->setMedia(QUrl("qrc:/img/img/headshot2.mp3"));
                headshot->play();
                x_pos=tim[i];
                delete an[i];
                an[i] = new QGraphicsPixmapItem;
                an[i]->setPixmap(p_arr2);
                /*k=0;
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
                Scene->addItem(an[i]);*/
                it->connect(it,SIGNAL(timeout()),this,SLOT(for_it()));
                it->start(100);
                for(k=0;k<10;++k)
                    if(tim[k]>t)
                        t=tim[k];
                tim[i]=t+200+qrand()%250;
                t=0;
            //    tim[i]=fir_y;
            //    fir_y=fir_y+200;
                an[i]->setPos(tim[i],200);
                Scene->addItem(an[i]);
                score++;
               // delete headshot;
            }
        }
    }
    if(event->key() == Qt::Key_P && music_mode!=2)
    {
        if(mode==0)
        {
            countdown->stop();
            timer->stop();
            mode=1;
            bgm->pause();
        }
        else
        {
            countdown->start(1000);
            timer->start(10);
            mode=0;
            bgm->play();
        }
    }
    if(event->key() == Qt::Key_V && music_mode==1)
    {
        int i,k;
      //  int tmp,count=0;
        for(i=0;i<5;++i)
        {
            if(tim[i]<=100 && tim[i]>=-70)
            {
                //headshot = new QMediaPlayer(this);
                //headshot->setMedia(QUrl("qrc:/img/poke/get2.mp3"));
                //headshot->play();
                x_pos=tim[i];
                delete an[i];
                an[i] = new QGraphicsPixmapItem;
                an[i]->setPixmap(p_arr1);
                /*k=0;
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
                Scene->addItem(an[i]);*/

            //    tim[i]=fir_y;
            //   fir_y=fir_y+200;
                it->connect(it,SIGNAL(timeout()),this,SLOT(for_it()));
                it->start(100);
                for(k=0;k<10;++k)
                    if(tim[k]>t)
                        t=tim[k];
                tim[i]=t+200+qrand()%250;
                t=0;
                an[i]->setPos(tim[i],250);
                Scene->addItem(an[i]);
                score++;
            }
        }
    }
    if(event->key() == Qt::Key_N && music_mode==1)
    {
        int i,k;
  //      int tmp,count=0;
        for(i=5;i<10;++i)
        {
            if(tim[i]<=100 && tim[i]>=-50)
            {
                //headshot = new QMediaPlayer(this);
                //headshot->setMedia(QUrl("qrc:/img/poke/get2.mp3"));
                //headshot->play();
                x_pos=tim[i];
                delete an[i];
                an[i] = new QGraphicsPixmapItem;
                an[i]->setPixmap(p_arr2);
                /*k=0;
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
                Scene->addItem(an[i]);*/
                it->connect(it,SIGNAL(timeout()),this,SLOT(for_it()));
                it->start(100);
                for(k=0;k<10;++k)
                    if(tim[k]>t)
                        t=tim[k];
                tim[i]=t+200+qrand()%250;
                t=0;
            //    tim[i]=fir_y;
            //    fir_y=fir_y+200;
                if(music_mode==0)
                    an[i]->setPos(tim[i],200);
                else if(music_mode==1)
                    an[i]->setPos(tim[i],230);
                Scene->addItem(an[i]);
                score++;
               // delete headshot;
            }
        }
    }
    if(event->key() == Qt::Key_unknown)
    {
        ;
    }

}
