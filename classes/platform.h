#ifndef PLATFORM_H
#define PLATFORM_H

#include "BodyObject.h"

class Platform : public BodyObject {
public:
    Platform(int width, int height, Position position, QGraphicsPixmapItem* image = nullptr)
            : BodyObject(width, height, position, image) {}

    void draw(QGraphicsScene& scene) override {
        if (image) {
            image->setPos(position.x, position.y);
            scene.addItem(image);
        }
    }
};

#endif // PLATFORM_H
