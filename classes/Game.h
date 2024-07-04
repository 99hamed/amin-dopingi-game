

#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include"Decorator.h"
#include"Player.h"

class Game:public QGraphicsView{
Q_OBJECT


    QTimer* PlatformGeneratorTimer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    //Platform *platform;
    QGraphicsPixmapItem *object;
    QTimer *timer;
public:
    public:
    Game();


};


#endif //AMIN_DOPINGI_GAME_GAME_H
