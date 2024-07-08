

#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Decorator.h"
#include "Player.h"
#include "platform.h"

class Game : public QGraphicsView {
Q_OBJECT

    QTimer* PlatformGeneratorTimer;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* object;
    QTimer* timer;
    Player* player;
    BackgroundDecorator* background;
    HillDecorator* background2;
    //Platform *platform;
    std::vector<Platform*> platforms;


public:
    Game();

public slots:
    void updateScene();
};

#endif // GAME_H

