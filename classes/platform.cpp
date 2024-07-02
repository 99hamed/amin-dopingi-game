#include "Platform.h"

Platform::Platform(int width, int height, Position position, QGraphicsPixmapItem* image)
        : BodyObject(width, height, position, image) {}

void Platform::draw(QGraphicsScene& scene) {
    if (image) {
        image->setPos(position.x, position.y);
        scene.addItem(image);
    }
}
