#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QWidget>

class Platform : public QGraphicsPixmapItem {
public:
    Platform(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    static bool isOnPlatform(QGraphicsItem *object, Platform *platform);
};

#endif // PLATFORM_H