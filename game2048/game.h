#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QPainter>
#include <QTime>
#include <gameover.h>
#include<vector>
#include <won.h>

#include <QMediaPlayer>
#include  <QSound>


class game : public QWidget
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void win();

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void Randomtile();

    QPushButton *Start_restart;
    QPushButton *undo;
      QPushButton *scr;
QLabel *text;
    int board[4][4];
    int score;
    bool state;

    void save(int board[4][4]);

int grid [4][4];
    struct Ns{  //Save space
        int i;
        int j;
    };
 //gameover screen;
    gameover screen;
    won winscreen;

signals:

public slots:
    void Start();
    void Restart();
    void load();
};

#endif // GAME_H
