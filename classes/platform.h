#ifndef PLATFORM_H
#define PLATFORM_H

#include "BodyObject.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QObject>

class Platform : public BodyObject , public QGraphicsPixmapItem , public QObject {
    Q_OBJECT
    Q_PROPERTY(greal x READ x WRITE setX)


private:
    QPropertyAnimation* moveAnimator;

public:
    platform(int SceneWidth , int SceneHeight);
    ~platform();

public slots:

    void removePlatform();


};

#endif // PLATFORM_H