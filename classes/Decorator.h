

#ifndef AMIN_DOPINGI_GAME_DECORATOR_H
#define AMIN_DOPINGI_GAME_DECORATOR_H
#include "BodyObject.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class Decorator : public BodyObject, public QGraphicsPixmapItem {

public:

    Decorator(int width, int height, Position position, QGraphicsPixmapItem *image = nullptr);
    Decorator(int width, int height, QGraphicsItem *parent = nullptr);
};

class BackgroundDecorator : public Decorator {
public:
    BackgroundDecorator(int width, int height, Position position, QGraphicsPixmapItem *image = nullptr);
    BackgroundDecorator(int width, int height, QGraphicsItem *parent = nullptr);

    void draw(QGraphicsScene &scene) override;
    void updatePosition(int x, int y);
    void setScale(float scale);
};

class HillDecorator : public Decorator {
public:
    HillDecorator(int width, int height, Position position, QGraphicsPixmapItem *image);
    HillDecorator(int width, int height, QGraphicsItem *parent = nullptr);

    void draw(QGraphicsScene &scene) override;
    void updatePosition(int x, int y);
};

#endif //AMIN_DOPINGI_GAME_DECORATOR_H
