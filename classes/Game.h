

#ifndef AMIN_DOPINGI_GAME_GAME_H
#define AMIN_DOPINGI_GAME_GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class Game:public QGraphicsScene,public QGraphicsView {
Q_OBJECT

private:
    QTimer* PlatformGeneratorTimer;

public:
    explicit Game(QObject *parent = nullptr);

public slots:
    void addPlatform();

};


#endif //AMIN_DOPINGI_GAME_GAME_H
