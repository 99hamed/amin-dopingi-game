

#include "Player.h"
Player::Player(int width, int height, Position position, int speed, Position velocity, QGraphicsPixmapItem *image)
        : BodyObject(width, height, position, image), speed(speed), velocity(velocity) {}

void Player::draw(QGraphicsScene &scene)  {
    if (getimage()) {
        getimage()->setPos(getpos().getx(), getpos().gety());
        scene.addItem(getimage());
    }
}