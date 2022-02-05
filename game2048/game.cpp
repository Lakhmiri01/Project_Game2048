#include "game.h"
#include <QMessageBox>
#include <QPainterPath>
#include <QDebug>
#include <gameover.h>
#include <QPixmap>
#include <windows.h>

game::game(QWidget *parent) :
      QWidget(parent),score(0),state(false)
{
    setStyleSheet("{ background-color: rgb(187,173,160) }");

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            board[i][j]=0;
    undo = new QPushButton(this);
    undo->setGeometry(420,7,80,57);
    undo->setIconSize((QSize(56,68)));
    QPixmap* pixmap1 = new QPixmap(":/new/prefix1/undo");
    QIcon icon1(*pixmap1);
    undo->setIcon(icon1);
    undo->setEnabled(false);
    undo->setEnabled(true);
    Start_restart = new QPushButton("Start game",this);
Start_restart->setStyleSheet(" background-color: rgb(244,122,102); border-radius: 10px; font: bold; color: white; ");
    Start_restart->setGeometry(95,500,300,50);
    Start_restart->setEnabled(false);
    Start_restart->setEnabled(true);

    scr = new QPushButton(this);
 scr->setGeometry(170,0,145,100);
    scr->setIconSize((QSize(145,100)));
    QPixmap* pixmap2 = new QPixmap(":/new/prefix1/scoreboard");
    QIcon icon2(*pixmap2);
    scr->setIcon(icon2);
    scr->setEnabled(false);
//
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));//Random function
    connect(Start_restart,SIGNAL(clicked()),this,SLOT(Start()));

    connect(undo,SIGNAL(clicked()),this,SLOT(load()));
}

void game::paintEvent(QPaintEvent *)
{

    QPainter p(this);
    p.setBrush(Qt::blue);
   // p.setPen(QColor(4,12,102));
    p.setFont(QFont("Helvetica",20,100,false));
    p.setPen(QColor(245,125,95) );
    QString strscore;
    p.drawText(QPoint(220,60),QString::number(score));


    QPainterPath path;
    QPainterPath text;
    setStyleSheet("border-radius: 10px; font: 30pt;");

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            p.setPen(Qt::transparent);
            if(board[i][j] == 0){
              p.setBrush(QColor(204,192,179));
//                p.drawRect(i*85+78,j*85+120,80,80);
             p.setRenderHint(QPainter::Antialiasing);
                path.addRoundedRect(QRectF(i*85+78,j*85+120,80,80), 10, 10);
                p.fillPath(path, QColor(204,192,179));
                p.drawPath(path);

            }
            else if(board[i][j] == 2){
                p.setBrush(QColor(238,228,218));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(119,110,101));
                p.setFont(QFont("Helvetica",25,700,false));
                p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(2),QTextOption(Qt::AlignCenter));
            }
            else if(board[i][j] == 4){
                p.setBrush(QColor (237,224,200));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(119,110,101));
                p.setFont(QFont("Helvetica",25,700,false));
                p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(4),QTextOption(Qt::AlignCenter));}
            else if(board[i][j] == 8){
                p.setBrush(QColor(242,177,121));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(8),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 16){
                p.setBrush(QColor(245,150,100));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(16),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 32){
                p.setBrush(QColor(245,125,95));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(32),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 64){
                p.setBrush(QColor (245,95,60));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(64),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 128){
                p.setBrush(QColor(237,207,114));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(128),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 256){
                p.setBrush(QColor(237,204,97));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(256),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 512){
                p.setBrush(QColor(237,204,97));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(512),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 1024){
                p.setBrush(QColor(237,204,97));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(1024),QTextOption(Qt::AlignCenter));            }
            else if(board[i][j] == 2048){
                p.setBrush(QColor(237,204,97));
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(2048),QTextOption(Qt::AlignCenter));            }
            else{
                p.setBrush(Qt::darkBlue);
                p.drawRoundedRect(i*85+78,j*85+120,80,80,10,10);
                p.setPen(QColor(255,255,255));
                p.setFont(QFont("Helvetica",25,700,false));
               p.drawText(QRectF(i*85+78,j*85+120,80,80),QString::number(2048),QTextOption(Qt::AlignCenter));
            }

        }
}

void game::keyPressEvent(QKeyEvent *event)
{
    if(!state)
       return;



   switch(event->key())
   {
    case Qt::Key_Z  :
       save(board);
       MoveUp();
       win();
         break;
     case  Qt::Key_W:
       save(board);
       MoveUp();
       win();
       break;

    case Qt::Key_S:
       save(board);
       MoveDown();
       win();
         break;
    case Qt::Key_Q:
       save(board);
      MoveLeft();
       win();
       break;
   case Qt::Key_A:
       save(board);
      MoveLeft();
       win();
       break;
    case Qt::Key_D:
       save(board);
       MoveRight();
       win();
         break;

    default:return;//Ignore other Starts
   }

   Randomtile();
   //update();

}

void game::Start()
{
    score = 0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            board[i][j]=0;
    Start_restart->setText("Replay");
Start_restart->setEnabled(false);
Start_restart->setEnabled(true);


    int randi = qrand() % 4;
    int randj = qrand() % 4;
    board[randi][randj] = 2;

    state = true;

}

void game::MoveUp()
{
    //mobile
    for(int i=0;i<4;i++)
         for(int j=1;j<4;j++){
             if(board[i][j] == 0){
                 continue;//Frontist is empty
             }
            for(int p=0;p<j;p++){
                if(board[i][p] == 0){//See if there is a space in front to move into {
                    board[i][p] = board[i][j];
                    board[i][j] = 0;
                    break;
                }
            }
         }
    //Add
    for(int i=0;i<4;i++)
         for(int j=0;j<3;j++){
             if(board[i][j] == board[i][j+1]){
                 board[i][j] = board[i][j]*2;
                 board[i][j+1] = 0;
                 score += board[i][j];
                 for(int p=j+2;p<4;p++)
                     board[i][p-1] = board[i][p];
             }

         }
}

void game::MoveDown()
{
    //mobile
    for(int i=0;i<4;i++)
         for(int j=2;j>=0;j--){
             if(board[i][j] == 0){
                 continue;//Frontist is empty
             }
            for(int p=3;p>j;p--){
                if(board[i][p] == 0){//See if there is a space in front of you can move
                    board[i][p] = board[i][j];
                    board[i][j] = 0;
                    break;
                }
            }
         }
    //Add
    for(int i=0;i<4;i++)
         for(int j=3;j>0;j--){
             if(board[i][j] == board[i][j-1]){
                 board[i][j] = board[i][j]*2;
                 board[i][j-1] = 0;
                 score += board[i][j];
                 for(int p=j-2;p>=0;p--)
                     board[i][p+1] = board[i][p];
             }

         }
}

void game::MoveLeft()
{
    //mobile
    for(int j=0;j<4;j++)
         for(int i=1;i<4;i++){
             if(board[i][j] == 0){
                 continue;//Frontist is empty
             }
            for(int p=0;p<i;p++){
                if(board[p][j] == 0){//See if there is a space in front of you can move
                    board[p][j] = board[i][j];
                    board[i][j] = 0;
                    break;
                }
            }
         }
    //Add
    for(int j=0;j<4;j++)
         for(int i=0;i<3;i++){
             if(board[i][j] == board[i+1][j]){
                 board[i][j] = board[i][j]*2;
                 board[i+1][j] = 0;
                 score += board[i][j];
                 for(int p=i+2;p<4;p++)
                     board[p-1][j] = board[p][j];
             }

         }

}

void game::MoveRight()
{
    //mobile
    for(int j=0;j<4;j++)
         for(int i=2;i>=0;i--){
             if(board[i][j] == 0){
                 continue;//Frontist is empty
             }
            for(int p=3;p>i;p--){
                if(board[p][j] == 0){//See if there is a space in front of you can move
                    board[p][j] = board[i][j];
                    board[i][j] = 0;
                    break;
                }
            }
         }
    //Add
    for(int j=0;j<4;j++)
         for(int i=3;i>0;i--){
             if(board[i][j] == board[i-1][j]){
                 board[i][j] = board[i][j]*2;
                 board[i-1][j] = 0;
                 score += board[i][j];
                 for(int p=i-2;p>=0;p--)
                     board[p+1][j] = board[p][j];
             }

         }

}

void game::Randomtile()
{
    int i,j;
   struct Ns n[15];
   int ni=0;
   for(i=0;i<4;i++)
       for(j=0;j<4;j++){
           if(board[i][j] == 0)
           {
               n[ni].i=i;
               n[ni].j=j;
               ++ni;
           }
       }
   if(ni == 0){
       for(i=0;i<4;i++)
           for(j=0;j<3;j++)
               if(board[i][j] == board[i][j+1])
                  return;
       for(j=0;j<4;j++)
            for(i=0;i<3;i++)
                if(board[i][j] == board[i+1][j])
                   return;
    screen.show();

      return;
       }
   int rand = qrand() % (ni);

   board[n[rand].i][n[rand].j] = 2;

}
void game::Restart()
{
    screen.hide();
    winscreen.hide();
    score = 0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            board[i][j]=0;
    Start_restart->setText("Replay");

    int randi = qrand() % 4;
    int randj = qrand() % 4;
    board[randi][randj] = 2;
    state = true;

}
 void game::save(int board[4][4]){

     for(int i=0;i<4;i++)
         for (int j = 0; j < 4; j++) {
            grid[i][j]=board[i][j];
         }
}
 void game::load(){
     for(int i=0;i<4;i++)
         for (int j = 0; j < 4; j++) {
             if (score==0) break;
            board[i][j]=grid[i][j];
         }
}

 void game::win(){
     for(int i=0;i<4;i++)
         for (int j = 0; j < 4; j++) {
              if(board[i][j]==2048){


 winscreen.show();
 break;

              }

      }
}
