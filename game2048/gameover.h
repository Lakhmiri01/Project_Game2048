#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>



class gameover : public QWidget
{


    Q_OBJECT
public:
    explicit gameover(QWidget *parent = nullptr);

    QPushButton *reset =nullptr;
QLabel *over=nullptr;

 //QLabel* cong =nullptr;
signals:

};

#endif // GAMEOVER_H
