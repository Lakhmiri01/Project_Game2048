#ifndef WON_H
#define WON_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QSound>



class won : public QWidget
{


    Q_OBJECT
public:
    explicit won(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);

   // QPushButton *reset=nullptr ;
QLabel *win=nullptr;


signals:

};



#endif // WON_H
