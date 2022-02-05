# Project_Game2048
_**This project is about 2048**_ , a single-player sliding tile puzzle video game written by Italian web developer Gabriele Cirulli . The objective of the game is to slide numbered tiles on a grid to combine them to create a tile with the number 2048; however, one can continue to play the game after reaching the goal, creating tiles with larger numbers. This article will analyze its source and implementation in detail. 

# 2048 Game

- [x] **Benzemroun Badr**
- [x] **Lakhmiri Mohammed Elias**
- [x] **Sakassa Rachid**


![img1](https://dl2.macupdate.com/images/icons256/50935.png?d=1488812134)

list
- ## This repport will describe 


1. Game Interface
2. Game logic

    - [Moving tiles](#moving-tiles)
    - Handling collisions and merging 
    - setting score and next move 
    
3. Game outcome  



   ### game interface
   
   Describing the components :
   
   1. The undo button (Type Qpushbutton) : allowing to return one move back .
   
   2. the score board.
   3. the replay boutton.
   4. the game board : a double dimension array [4][4] drawn with a Qpainter .
  
    
    ![image](https://user-images.githubusercontent.com/99057013/152624965-6c86025e-839a-4df6-bedb-f24197b99f9f.png)
    
   ### Starting play
   
   ![image](https://user-images.githubusercontent.com/99057013/152625094-277cc86e-4642-4c26-b0b3-ad4cc7773a88.png)
   
 the game board in details : 
 In the shape of a square composed of 16 tiles , each one is a RoundedRect reprensenting a case in the double dimension array  . Notice that the colors change corresponding to    the value of the tiles ( the tiles are  by default grey with value of 0  ).
 
 ![image](https://user-images.githubusercontent.com/99057013/152626177-a40293e9-b37c-43ec-8c65-f9e1fb4c1baa.png)
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
   
   the game logic . 
   the game starts with a random tile of value 2 popping up , after reading  the key pressed by the player ( Z : up S : down A : left D : right ) using KeyPressEvent  the tiles block move in the corresponding direction  assured by 4 movement functions.
   ```c++
   
   void game::keyPressEvent(QKeyEvent *event)
{
    if(!state)
       return;



   switch(event->key())
   {
    case Qt::Key_Z:
       save(board);
       PressUp();
       win();
         break;
    case Qt::Key_S:
       save(board);
       PressDown();
       win();
         break;
    case Qt::Key_Q:
       save(board);
       PressLeft();
       win();
       break;
    case Qt::Key_D:
       save(board);
       PressRight();
       win();
         break;

    default:return;//Ignore other Starts
   }
   ```
   
   

