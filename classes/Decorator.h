
#ifndef AMIN_DOPINGI_GAME_DECORATOR_H
#define AMIN_DOPINGI_GAME_DECORATOR_H
#include"BodyObject.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class Decorator : public BodyObject,public QGraphicsPixmapItem {
public:
    Decorator(int,int,Position, QGraphicsPixmapItem *image = nullptr);

    Decorator(int,int,QGraphicsItem* parent =nullptr);

};

class BackgroundDecorator : public Decorator {
public:
    BackgroundDecorator(int, int , Position , QGraphicsPixmapItem *image = nullptr);
    BackgroundDecorator(int,int ,QGraphicsItem* parent =nullptr);

    void draw(QGraphicsScene &scene) override;

};

class HillDecorator : public Decorator {
public:
    HillDecorator(int, int , Position , QGraphicsPixmapItem *image );

    HillDecorator(int, int, QGraphicsItem *parent = nullptr);

    void draw(QGraphicsScene &scene) override;

};
#endif //AMIN_DOPINGI_GAME_DECORATOR_H
