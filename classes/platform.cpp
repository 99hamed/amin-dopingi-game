#include "Platform.h"

platform::platform(int SceneWidth , int SceneHeight){
     Qpixmap pixmap(":/images/platform");
     pixmap = pixmap,scaled(pixmap.width() , sceneHeight , Qt::KeepAspectRatioByExpanding);

     auto bottomPlatformHeight = pixmap.height - (0);
     auto bottomPlatform = pixmap.copy(0 , 0 , pixmap.width() , bottomPlatformHeight);


     setPixmap(pixmap);
     setPos(sceneWidth , 0);

    moveAnimator = new QPropertyAnimation(this , "x");
    moveAnimator->setStartValue(sceneWidth);
    moveAnimator.setEndValue(-1 * pixmap,width());
    moveAnimator->setDuration(3000);
    moveAnimator->start();
}

void Platform::removePlatform(){

}

Platform::~platform() {
    delete moveAnimator;
}
