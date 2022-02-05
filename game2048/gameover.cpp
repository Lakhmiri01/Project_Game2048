#include "gameover.h"
#include "game.h"
#include <QMovie>
gameover::gameover(QWidget *parent) : QWidget(parent)
{
    setStyleSheet(" background: rgb(0,0,0); ");
    setFixedSize(800,400);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
     QLabel* over = new QLabel();
    QLabel* cong = new QLabel(this);

    QMovie *movie = new QMovie(":/new/prefix1/glitch.gif");
    over->setMovie(movie);
    movie->start();

    layout->addWidget(over);

    QSound::play(":/new/prefix1/oversound.mp3");

}

