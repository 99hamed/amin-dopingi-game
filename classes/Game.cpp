#include "Game.h"

Game::Game() {
    showFullScreen();

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0, 0, QWidget::width(), QWidget::height());
    scene->setBackgroundBrush(QBrush(QColor("#007786")));

    background = new BackgroundDecorator(QWidget::width(), QWidget::height());
    background2 = new HillDecorator(QWidget::width(), QWidget::height());
    scene->addItem(background);
    scene->addItem(background2);

    player = new Player(QWidget::width(), QWidget::height());
    player->speed = 30; // player speed
    scene->addItem(player);

    setScene(scene);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::updateScene);
    timer->start(16); // 60 FPS
}

void Game::updateScene() {
    int middleX = scene->width() / 2;
    int playerX = player->x();

    int dx = 0;
    if (playerX > middleX) {
        dx = playerX - middleX;
    } else if (playerX < middleX && scene->sceneRect().x() > 0) {
        dx = playerX - middleX;
    }

    if (dx != 0) {
        int backgroundSpeed = dx / 4; // scroll speed

        scene->setSceneRect(scene->sceneRect().x() + dx, 0, scene->width(), scene->height());
        background->updatePosition(background->x() - backgroundSpeed, background->y());
        background2->updatePosition(background2->x() - backgroundSpeed, background2->y());

        // Keep the player at the middle
        player->setPos(middleX, player->y());
    }
}
