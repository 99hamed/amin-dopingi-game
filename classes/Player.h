

#ifndef AMIN_DOPINGI_GAME_PLAYER_H
#define AMIN_DOPINGI_GAME_PLAYER_H
#include"BodyObject.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include<QList>
#include<QTimer>
#include<QObject>


    class Player :public QObject,public BodyObject,public QGraphicsPixmapItem {
        Q_OBJECT
        private:
        int frame{};
        QList<QPixmap*> frames{};
        QTimer* runningtimer;
        public:
        int speed;
        Position velocity;

        Player(int,int ,Position ,int,Position, QGraphicsPixmapItem *image = nullptr);
        Player(int ,int,QGraphicsItem* parent= nullptr);



        void handleGravity();

        void handleLeftMovement();

        void handleUpMovement();


        void handleDownMovement();


        void handleMovement();


        void draw(QGraphicsScene &scene) override;
public slots:
        void handleRightMovement();


};


#endif //AMIN_DOPINGI_GAME_PLAYER_H
