

#ifndef AMIN_DOPINGI_GAME_PLAYER_H
#define AMIN_DOPINGI_GAME_PLAYER_H
#include"BodyObject.h"

    class Player : public BodyObject {
    public:
        int speed;
        Position velocity;

        Player(int,int ,Position ,int,Position, QGraphicsPixmapItem *image = nullptr);

        void handleGravity();

        void handleRightMovement();


        void handleLeftMovement();

        void handleUpMovement();


        void handleDownMovement();


        void handleMovement();


        void draw(QGraphicsScene &scene) override;



};


#endif //AMIN_DOPINGI_GAME_PLAYER_H
