

#ifndef AMIN_DOPINGI_GAME_BODYOBJECT_H
#define AMIN_DOPINGI_GAME_BODYOBJECT_H
#include"Position.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


class BodyObject {
    int width, height;
    Position position;
    QGraphicsPixmapItem *image;
public:

    BodyObject(int, int , Position , QGraphicsPixmapItem *image);
    QGraphicsPixmapItem * getimage(){
        return image;
    }

    BodyObject();
    ~BodyObject();
    virtual void draw(QGraphicsScene &scene) = 0;
    Position getpos();
    void setpos(Position);
    int getwidth();
    void setwidth(int);
    int getheight();
    void setheight(int);
};

#endif //AMIN_DOPINGI_GAME_BODYOBJECT_H
