
#include "Game.h"
#include "Platform.h"
#include <QTimer>
#include <QMetaObject>



Game::Game(QObject *parent) : QGraphicsScene(parent), QGraphicsView(parent){
    showFullScreen();


    auto scene = new QGraphicsScene();

    scene->setSceneRect(0,0,QWidget::width(),QWidget::height());

    scene->setBackgroundBrush(QBrush(QColor("#007786")));

    auto background = new BackgroundDecorator(QWidget::width(), QWidget::height());
    auto background2 = new HillDecorator(QWidget::width(), QWidget::height());

    scene->addItem(background);
    scene->addItem(background2);
    background->setPos(10,10);
    background2->setPos(10,10);
    setScene(scene);

    PlatformGeneratorTimer = new QTimer();
    PlatformGeneratorTimer->setInterval(2000);
    connect(PlatformGeneratorTimer, &QTimer::timeout, this, &Game::addPlatform);
    PlatformGeneratorTimer->start();

}

void Game::addPlatform() {
    auto platform = new Platform(width(), height(), this);
    playgroundScene->addItem(platform);
}