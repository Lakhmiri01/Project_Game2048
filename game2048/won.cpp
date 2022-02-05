#include "won.h"

#include "game.h"
#include "QMovie"




won::won(QWidget *parent) : QWidget(parent)
{
    setStyleSheet(" background: rgb(237,224,200); ");
    setFixedSize(545,385);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
 QLabel* cong = new QLabel(this);


    QLabel* win = new QLabel( this);

    win->setFixedSize(545,385);
    QMovie *movie = new QMovie(":/new/prefix1/win.gif");
    win->setMovie(movie);
    movie->start();


   layout->addWidget(cong);
   QSound::play(":/new/prefix1/youwin.mp3");


}
void won::keyPressEvent(QKeyEvent *event)
{

   if(event->key()==Qt::Key_Space)

     this->close();


}


