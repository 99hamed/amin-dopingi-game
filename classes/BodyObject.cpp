
#include "BodyObject.h"


BodyObject::BodyObject(int width, int height, Position position, QGraphicsPixmapItem *image = nullptr)
        : width(width), height(height), position(position), image(image) {}
BodyObject::BodyObject() {}

Position BodyObject::getpos(){return position;}
void BodyObject::setpos(Position a){position=a;}

int BodyObject::getwidth(){return width;}
void BodyObject::setwidth( int w){width =w;}
int BodyObject::getheight(){return height;}
void BodyObject::setheight(int h){ height =h;}
