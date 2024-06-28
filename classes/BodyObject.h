

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
    virtual void draw(QGraphicsScene &scene) = 0;
};

#endif //AMIN_DOPINGI_GAME_BODYOBJECT_H
