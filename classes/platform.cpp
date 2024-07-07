#include "platform.h"

Platform::Platform(const QPixmap &pixmap, QGraphicsItem *parent)
        : QGraphicsPixmapItem(pixmap, parent) {}

bool Platform::isOnPlatform(QGraphicsItem *object, Platform *platform) {
    qreal gravity = 9.8;

    QRectF objectRect = object->boundingRect();
    QRectF platformRect = platform->boundingRect();

    qreal objectBottom = object->pos().y() + objectRect.height();
    qreal platformTop = platform->pos().y();

    if (objectBottom <= platformTop &&
        objectBottom + gravity >= platformTop &&
        object->pos().x() + objectRect.width() >= platform->pos().x() &&
        object->pos().x() <= platform->pos().x() + platformRect.width()) {
        return true;
    }

    return false;
}
