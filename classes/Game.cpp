
#include "Game.h"

Game::Game(){
    showFullScreen();

    auto scene = new QGraphicsScene();

    scene->setSceneRect(0,0,QWidget::width(),QWidget::height());

   scene->setBackgroundBrush(QBrush(QColor("#007786")));


    auto background= new BackgroundDecorator(QWidget::width(),QWidget::height());
    auto background2= new HillDecorator(QWidget::width(),QWidget::height());
    scene->addItem(background);
    scene->addItem(background2);
    background->setPos(10,10);
    background2->setPos(10,10);
    setScene(scene);

}