#include "Platform.h"

Platform::Platform(int SceneWidth, int SceneHeight, QObject *parent)
        : BodyObject(), QGraphicsPixmapItem(), QObject(parent){
    QPixmap pixmap(":/images/platform");
    pixmap = pixmap.scaled(pixmap.width() , SceneHeight , Qt::KeepAspectRatioByExpanding);

    auto bottomPlatformHeight = pixmap.height() - (0);
    auto bottomPlatform = pixmap.copy(0 , 0 , pixmap.width() , bottomPlatformHeight);


    setPixmap(pixmap);
    setPos(SceneWidth , 0);

    moveAnimator = new QPropertyAnimation(this , "x");
    moveAnimator->setStartValue(SceneWidth);
    moveAnimator->setEndValue(-1 * pixmap.width());
    moveAnimator->setDuration(3000);
    moveAnimator->start();
}

void Platform::removePlatform(){

}

Platform::~Platform() {
    delete moveAnimator;
}
