

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
#include"platform.h"
class Player :public QObject,public BodyObject,public QGraphicsPixmapItem {
Q_OBJECT

    Q_PROPERTY(qreal width READ x WRITE setX)
    Q_PROPERTY(qreal height READ y WRITE setY)
public:
    int ground{};
    int Rframe{};
    int Lframe{};
    bool RunningRight{false};
    QList<QPixmap*> moveLeftFrames{};
    QList<QPixmap*> moveRightFrames{};
    QTimer *runningrighttimer;
    QTimer *runninglefttimer;
    int sceneheight;
    QPropertyAnimation* widthAnimator;
    QPropertyAnimation* heightAnimator;
    bool running{false};

    int speed;
    Position velocity;

    Player(int, int, Position, int, Position, QGraphicsPixmapItem *image = nullptr);

    Player(int, int, QGraphicsItem *parent = nullptr);


    void handleLeftMovement();

    void handleRightMovement();

    void handleUpMovement();

    void handleDownMovement();
    ~Player();


    void draw(QGraphicsScene &scene) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent*) override ;
    void keyReleaseEvent(QKeyEvent *event) override;
    void RunRightFrame();
    void RunLeftFrame();
public slots:
    void handleGravity();
    void RunningLeft();
    void Runningright();

};



#endif //AMIN_DOPINGI_GAME_PLAYER_H

