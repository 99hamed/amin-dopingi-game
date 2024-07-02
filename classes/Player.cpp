
#include "Player.h"

Player::Player(int width, int height, Position position, int speed, Position velocity, QGraphicsPixmapItem *image)
        : BodyObject(width, height, position, image), speed(speed), velocity(velocity) {}


Player::Player(int width,int height,QGraphicsItem* parent): QGraphicsPixmapItem(parent)
        {

    auto pixmap =new QPixmap (":/resources/images/spriteStandRight.png");
    auto scaledpixmap=pixmap->scaled(89.5,196.5);

    setPixmap(scaledpixmap);

    frames.append(new QPixmap(scaledpixmap));
    pixmap=new QPixmap(":/resources/images/spriteRunRight.png");
    scaledpixmap=pixmap->scaled(5000,200);

    scaledpixmap = scaledpixmap.copy(0, 0, pixmap->width() - 10050 , pixmap->height());
    frames.append(new QPixmap(scaledpixmap));

    runningtimer= new QTimer();
    runningtimer->setInterval(300);
    connect(runningtimer,&QTimer::timeout,this,&Player::handleRightMovement);
    runningtimer->start();

    setPos(100,height/2-pixmap->height()/2);


}
void Player::draw(QGraphicsScene &scene)  {
    if (getimage()) {
        getimage()->setPos(getpos().getx(), getpos().gety());
        scene.addItem(getimage());
    }
}

void Player::handleRightMovement(){
    setPixmap(*frames.at(frame));
    frame=(frame+1)%2;
}