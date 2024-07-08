
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

           //QPixmap platformPixmap(":/resources/images/platform.png");
            //platform = new Platform(platformPixmap);
            //platform->setPos(500,QWidget::height()-125);
            //scene->addItem(platform);

    QPixmap platformPixmap(":/resources/images/platform.png");
    int initialX = 200;
    int initialY = QWidget::height() - 125;
    int platformGap = 800; // فاصله بین پلتفرم‌ها

    // ایجاد چند پلتفرم
    for (int i = 0; i < 50; ++i) {
        Platform* platform = new Platform(platformPixmap);
        platform->setPos(initialX + i * platformGap, initialY);
        platforms.push_back(platform);
        scene->addItem(platform);
    }

    //QPixmap platformPixmap2(":/resources/images/platformSmallTall.png");
    //int initialX2 = 200;
    //int initialY2 = QWidget::height() - 250;
    //int platformGap2 = 1200; // فاصله بین پلتفرم‌ها

    // ایجاد چند پلتفرم
    //for (int i = 0; i < 20; ++i) {
    //    Platform* platform2 = new Platform(platformPixmap2);
    //    platform2->setPos(initialX2 + i * platformGap2, initialY2);
    //    platforms.push_back(platform2);
    //    scene->addItem(platform2);
    //}

    // تنظیم موقعیت بازیکن روی اولین پلتفرم
    player->setPos(initialX, initialY - player->boundingRect().height());

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
        background->updatePosition(background2->x() - backgroundSpeed, background->y());
        background2->updatePosition(background2->x() - backgroundSpeed, background2->y());

        // Keep the player at the middle
        player->setPos(middleX, player->y());
    }
}
