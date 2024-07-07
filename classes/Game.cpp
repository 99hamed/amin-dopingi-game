
#include "Game.h"


Game::Game() {
    showFullScreen();
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto scene = new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0, 0, QWidget::width(), QWidget::height());

    scene->setBackgroundBrush(QBrush(QColor("#007786")));
//    auto playground = new QGraphicsView();
//
//    playground->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    playground->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    playground->setFrameShape(QFrame::NoFrame);
//
////    playgroundScene = new QGraphicsScene(this);
////    playground->setScene(playgroundScene);


    auto background = new BackgroundDecorator(QWidget::width(),QWidget::height());
    auto background2 = new HillDecorator(QWidget::width(),QWidget::height());
    scene->addItem(background);
    scene->addItem(background2);
    auto player = new Player( QWidget::width(),QWidget::height());
    scene->addItem(player);

//
//    QPixmap platformPixmap(":/resources/images/platform.png");
//    auto platform = new Platform(platformPixmap);
//    scene->addItem(platform);
//    platform->setPos(0, (scene->height()/2)+100);
//
//
//
//    object = new QGraphicsPixmapItem(QPixmap(":/resources/images/platform.png"));
//    object->setPos(579, (scene->height()/2)+100);
//    scene->addItem(object);

    setScene(scene);
    // Setup the view
//    view = new QGraphicsView(scene);
//    view->setFixedSize(800, 600);
//    view->show();
    //setScene(scene);
    // Setup the timer
//    timer = new QTimer();
//    connect(timer, &QTimer::timeout, this, &Game::update);
//    timer->start(16); // Approx. 60 FPS
//
//   PlatformGeneratorTimer = new QTimer();
//    PlatformGeneratorTimer->setInterval(2000);
//   connect(PlatformGeneratorTimer, &QTimer::timeout, this, &Game::addPlatform);
//  PlatformGeneratorTimer->start();

}

