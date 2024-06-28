
#include "BodyObject.h"


BodyObject::BodyObject(int width, int height, Position position, QGraphicsPixmapItem *image = nullptr)
        : width(width), height(height), position(position), image(image) {}
