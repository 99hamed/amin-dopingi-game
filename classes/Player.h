

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
    private:
        int frame{};
        QList<QPixmap *> frames{};
        QTimer *runningtimer;
        QPropertyAnimation* widthAnimator;
    public:
        int speed;
        Position velocity;

        Player(int, int, Position, int, Position, QGraphicsPixmapItem *image = nullptr);

        Player(int, int, QGraphicsItem *parent = nullptr);


        void handleGravity();

        void handleLeftMovement();

        void handleRightMovement();

        void handleUpMovement();


        void handleDownMovement();


        void handleMovement();

        void Running();

        void draw(QGraphicsScene &scene) override;

    protected:
        void keyPressEvent(QKeyEvent *event) override;





    };



#endif //AMIN_DOPINGI_GAME_PLAYER_H
