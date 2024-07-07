
#include "Decorator.h"
#include<QGraphicsScene>


Decorator::Decorator(int width,int height,QGraphicsItem* parent){}

Decorator::Decorator(int width, int height, Position position, QGraphicsPixmapItem *image ): BodyObject(width, height, position, image) {}

BackgroundDecorator::BackgroundDecorator(int width, int height, Position position, QGraphicsPixmapItem *image ): Decorator(width, height, position, image) {}

BackgroundDecorator::BackgroundDecorator(int width,int height,QGraphicsItem* parent)
:Decorator(width,height, parent ){

    QPixmap pixmap(":/resources/images/background.png");

    pixmap =pixmap.scaled(pixmap.width(),height);

    setPixmap(pixmap);

    setPos(0,0);
}

void BackgroundDecorator::draw(QGraphicsScene &scene)  {
if (getimage()) {
getimage()->setPos(getpos().getx(), getpos().gety());
scene.addItem(getimage());
void draw(QGraphicsScene &scene);
}
}

HillDecorator::HillDecorator(int width,int height ,QGraphicsItem* parent ):Decorator(width,height, parent ){
    QPixmap pixmap(":/resources/images/hills.png");

    pixmap =pixmap.scaled(pixmap.width(),height);

    setPixmap(pixmap);

    setPos(0,0);
}
HillDecorator::HillDecorator(int width, int height, Position position, QGraphicsPixmapItem *image)
        : Decorator(width, height, position, image) {}
void HillDecorator::draw(QGraphicsScene &scene)  {
if (getimage()) {
getimage()->setPos(getpos().getx(), getpos().gety());
scene.addItem(getimage());
}
}