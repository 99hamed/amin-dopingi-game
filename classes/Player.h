
#ifndef AMIN_DOPINGI_GAME_PLAYER_H
#define AMIN_DOPINGI_GAME_PLAYER_H
#include"BodyObject.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include<QList>
#include<QTimer>
#include<QObject>
#include<QPropertyAnimation>
#include<QKeyEvent>

class Player :public QObject,public BodyObject,public QGraphicsPixmapItem {
Q_OBJECT

    Q_PROPERTY(qreal width READ x WRITE setX)
    Q_PROPERTY(qreal height READ y WRITE setY)
private:
    int ground{};
    int frame{};
    QList<QPixmap *> frames{};
    QTimer *runningtimer;

    QPropertyAnimation* widthAnimator;
    QPropertyAnimation* heightAnimator;
public:
    int speed;
    Position velocity;

    Player(int, int, Position, int, Position, QGraphicsPixmapItem *image = nullptr);

    Player(int, int, QGraphicsItem *parent = nullptr);


    void handleLeftMovement();

    void handleRightMovement();

    void handleUpMovement();

    void handleDownMovement();



    void draw(QGraphicsScene &scene) override;



    void keyPressEvent(QKeyEvent*) override ;


public slots:
    void handleGravity();
    void Running();

};



#endif //AMIN_DOPINGI_GAME_PLAYER_H
