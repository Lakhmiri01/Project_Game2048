# Project_Game2048

# Introduction

_**This project is about 2048**_ , a single-player sliding tile puzzle video game written by Italian web developer Gabriele Cirulli . The objective of the game is to slide numbered tiles on a grid to combine them to create a tile with the number 2048; however, one can continue to play the game after reaching the goal, creating tiles with larger numbers. This article will analyze its source and implementation in detail. 

# 2048 Game

- [x] **Benzemroun Badr**
- [x] **Lakhmiri Mohammed Elias**
- [x] **Sakassa Rachid**


![img1](https://dl2.macupdate.com/images/icons256/50935.png?d=1488812134)


- ## This repport will describe 


1. [Game Interface](#game-interface)
   - [Describing the components](#describing-the-components)
   - [Starting play](#starting-play)
   - [Undo Button](#undo-button)
   - [Game Over](#game-over)
   - [You Win](#you-win)
2. [How to Play 2048](#how-to-play-2048)
   - [The game board in details](#the-game-board-in-details)

3. [Constructor](#constructor)

4. [Game logic](#game-logic)
    - [Moving tiles](#moving-tiles)
    - [Handling collisions and merging](#handling-collisions-and-merging)
    - [Randomtile Function](#randomtile-function)
    - [Start-Restart Function](#start-restart-function)
    - [Undo Button Save and Load](#undo-button-save-and-load)
    - [Game Win](#game-win)
  
    
 
 - ## Game Interface
   
   ### Describing the components
   
   1. The undo button (Type Qpushbutton) : allowing to return one move back .
   2. the score board.
   3. the replay boutton.
   4. the game board : a double dimension array [4][4] drawn with a Qpainter .
  
    
    ![image](https://user-images.githubusercontent.com/99057013/152624965-6c86025e-839a-4df6-bedb-f24197b99f9f.png)
    
   ### Starting play
   
   ![image](https://user-images.githubusercontent.com/99057013/152625094-277cc86e-4642-4c26-b0b3-ad4cc7773a88.png)
   




### Undo Button

![image](https://user-images.githubusercontent.com/99057013/152644404-2c1ae66c-88e1-4cc9-9342-e77396fffea8.png)

### Game Over

If the biggest tile <  2048 and The are no more moves possible (Game Over)

![final_61fe843b0d713c0109789731_509982](https://user-images.githubusercontent.com/99057013/152645311-4870e44f-3a3a-423a-99d9-527f5b396a7c.gif)
### You Win

If not, the game then continues until tile = 2048 (Win)

![final_61fe80f31a3a2d007788cc02_599450](https://user-images.githubusercontent.com/99057013/152645125-dc540615-142f-4e74-9668-666d6aa46e5b.gif)


- ## How to Play 2048

A game of 2048 is played on a 4×4 board. Each position on the board may be empty or may contain a tile, and each tile will have a number on it.

When we start, the board will have two tiles in random locations, each of which either has a “2” .

Moves are performed by shifting all tiles towards one edge – up, down, left, or right. When doing this, any tiles with the same value that are adjacent to each other and are moving together will merge and end up with a new tile equal to the sum of the earlier two:


![SHIFTRIGHT](https://user-images.githubusercontent.com/99057013/152644244-718ae4c7-0148-462b-8a9b-536b1f688da5.png)

 - ### The game board in details 
 In the shape of a square composed of 16 tiles , each one is a RoundedRect reprensenting a case in the double dimension array  . Notice that the colors change corresponding to    the value of the tiles ( the tiles are  by default grey with value of 0  ).
 
![image](https://user-images.githubusercontent.com/99057013/152643026-027000dd-a264-4347-88b9-a369a57e136b.png)

```c++
if(board[i][j] == 2){
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
```
   

- ## Constructor

```c++
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
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    connect(Start_restart,SIGNAL(clicked()),this,SLOT(Start()));
    connect(undo,SIGNAL(clicked()),this,SLOT(load()));
}

```

- ## Game logic

   the game starts with a random tile of value 2 popping up , after reading  the key pressed by the player ( W or Z : up / S : down / A or Q : left / D : right ) using KeyPressEvent  the tiles block move in the corresponding direction  assured by 4 movement functions.
   
```c++
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
   ```
   
 - ## Moving tiles
 
  let's examine a movement function , MoveUp() for example :
  First we iterate trough the board to find movable tiles ( value !=0) and we treat each one individually .
  Second we cross the board  searching for empty tiles in our way ( those with 0 value ),then we start moving the tiles up ( each tiles takes the value of the one beneath  it )   until we hit a full tile.
  
 ```c++
        for(int i=0;i<4;i++)
         for(int j=1;j<4;j++){
             if(board[i][j] == 0){
                 continue;
             }
            for(int p=0;p<j;p++){
                if(board[i][p] == 0)
                {
                    board[i][p] = board[i][j];
                    board[i][j] = 0;
                    break;
                }
            }
         }
```
The same logic apply to  MoveDown() the difference being iterating in the opposite way . And for moving left or right we act about the i index instead of the j one .
 ```c++
     for(int j=0;j<4;j++)
         for(int i=1;i<4;i++){
             if(board[i][j] == 0){
                 continue;//Frontist is empty
             }
            for(int p=0;p<i;p++){
                if(board[p][j] == 0){
                    board[p][j] = board[i][j];
                    board[i][j] = 0;
                    break;
                }
            }
         }
```
- ## Handling collisions and merging 

If we hit a tile with different value it stops .
In case we hit a tile with equal value , the  value of tile in front multiple by 2  and the other one takes 0 , and we continue moving . Of coursethe score increase by the tile value.
 ```c++
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
```
- ## Randomtile Function

This fuction generate a tile (2) in a rondom plaid

- ### Find out empty plaid

```c++
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
```

- ### Judging whether the game ends

```c++
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

```
- ### Start-Restart Function

```c++
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

```
- ## Undo Button Save and Load

Undo button Give to the player a second chance to Retrieve a move

to do this we need to functions (Save,Load)

- ###  Save function

This function is used to save each move in case he choose to retrieve

```C++
 void game::save(int board[4][4]){

     for(int i=0;i<4;i++)
         for (int j = 0; j < 4; j++) {
            grid[i][j]=board[i][j];
         }
}
```
- ###  Load function

When the undo button is clicked the slot load the last Save

```c++

 void game::load(){
     for(int i=0;i<4;i++)
         for (int j = 0; j < 4; j++) {
             if (score==0) break;
            board[i][j]=grid[i][j];
         }
}

```
- ### Game Win

```c++
 void game::win(){
     for(int i=0;i<4;i++)
         for (int j = 0; j < 4; j++) {
              if(board[i][j]==2048){


 winscreen.show();
 break;

              }

      }
}
```
