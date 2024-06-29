
#include "Game.h"

Game::Game(){
    showFullScreen();

    auto scene = new QGraphicsScene();

    scene->setSceneRect(0,0,QWidget::width(),QWidget::height());

   scene->setBackgroundBrush(QBrush(QImage(":/images/background.png")));
//    auto background= new Decorator();
//    scene->addItem(background);
    setScene(scene);

}