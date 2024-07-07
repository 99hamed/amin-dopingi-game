/*
#include "Player.h"

Player::Player(int width, int height, Position position, int speed, Position velocity, QGraphicsPixmapItem *image)
        : BodyObject(width, height, position, image), speed(speed), velocity(velocity) {}


Player::Player(int width,int height,QGraphicsItem* parent): QGraphicsPixmapItem (parent)
        {
    setFlags(GraphicsItemFlag::ItemIsFocusable );
    setFocus();

    auto pixmap =new QPixmap (":/resources/images/spriteStandRight.png");
    auto scaledpixmap=pixmap->scaled(89.5,196.5);

    setPixmap(scaledpixmap);




    auto x=100;
    auto y=height/2-pixmap->height()/2;
    ground=height-200;
    widthAnimator= new QPropertyAnimation(this,"width",this);
    heightAnimator= new QPropertyAnimation(this,"height",this);

    heightAnimator->setStartValue(ground);
    heightAnimator->setEndValue(ground);
    heightAnimator->setDuration(200);
    heightAnimator->start();
    connect(heightAnimator,&QPropertyAnimation::finished,this,&Player::handleGravity);

    setPos(x,y);


}
void Player::draw(QGraphicsScene &scene)  {
    if (getimage()) {
        getimage()->setPos(getpos().getx(), getpos().gety());
        scene.addItem(getimage());
    }
}

void Player::handleRightMovement(){

    auto pixmap =new QPixmap (":/resources/images/spriteStandRight.png");
    auto scaledpixmap=pixmap->scaled(89.5,196.5);
    setPixmap(scaledpixmap);
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x()+25);
    widthAnimator->setDuration(50);
    widthAnimator->start();

}
void Player::handleLeftMovement() {
    auto pixmap =new QPixmap (":/resources/images/spriteStandLeft.png");
    auto scaledpixmap=pixmap->scaled(89.5,196.5);
    setPixmap(scaledpixmap);
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x()-25);
    widthAnimator->setDuration(50);
    widthAnimator->start();

}
void Player::handleUpMovement() {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(y()-250);
    heightAnimator->setDuration(500);
    heightAnimator->start();

}

void Player::handleGravity() {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(ground);
    heightAnimator->setDuration(800);
    heightAnimator->setEasingCurve(QEasingCurve::InOutQuart);
    heightAnimator->start();



}
void Player::keyPressEvent(QKeyEvent *event){
    QGraphicsItem::keyPressEvent(event);

    if (event->key() == Qt::Key::Key_Right) {
        handleRightMovement();
    }

    if (event->key() == Qt::Key::Key_Left) {
        handleLeftMovement();
    }

    if(y()>ground-100) {
        if (event->key() == Qt::Key::Key_Up || event->key() == Qt::Key::Key_Space) {
            handleUpMovement();
        }
    }

}
void Player::keyReleaseEvent(QKeyEvent *event){
    QGraphicsItem::keyPressEvent(event);

    if (event->key() == Qt::Key::Key_Right) {
        auto pixmap =new QPixmap (":/resources/images/spriteStandRight.png");
        auto scaledpixmap=pixmap->scaled(89.5,196.5);
        setPixmap(scaledpixmap);
    }
    if (event->key() == Qt::Key::Key_Left) {
        auto pixmap =new QPixmap (":/resources/images/spriteStandLeft.png");
        auto scaledpixmap=pixmap->scaled(89.5,196.5);
        setPixmap(scaledpixmap);
    }


}
*/
#include "Player.h"

Player::Player(int width, int height, Position position, int speed, Position velocity, QGraphicsPixmapItem *image)
        : BodyObject(width, height, position, image), speed(speed), velocity(velocity) {}

Player::Player(int width, int height, QGraphicsItem* parent) :sceneheight(height), QGraphicsPixmapItem(parent) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();

      auto pixmap=new  QPixmap (":/resources/images/spriteStandRight.png");
      auto scaledpixmap =pixmap->scaled(89.5, 196.5);

    setPixmap(scaledpixmap);
    RunRightFrame();
    RunLeftFrame();
    runningrighttimer= new QTimer();
    runningrighttimer->setInterval(20);
    runninglefttimer= new QTimer();
    runninglefttimer->setInterval(20);
    connect(runningrighttimer,&QTimer::timeout,this,&Player::Runningright);
    connect(runninglefttimer,&QTimer::timeout,this,&Player::RunningLeft);



    auto x = 100;
    auto y = height / 2 - scaledpixmap.height() / 2;
    ground = height - 200;
    widthAnimator = new QPropertyAnimation(this, "width", this);
    heightAnimator = new QPropertyAnimation(this, "height", this);


    heightAnimator->setStartValue(ground);
    heightAnimator->setEndValue(ground);
    heightAnimator->setDuration(5);
    heightAnimator->start();

    connect(heightAnimator, &QPropertyAnimation::finished, this, &Player::handleGravity);


    setPos(x, y);


}

void Player::draw(QGraphicsScene &scene) {
    if (getimage()) {
        getimage()->setPos(getpos().getx(), getpos().gety());
        scene.addItem(getimage());
    }
}

void Player::handleRightMovement() {
    auto pixmap = new QPixmap(":/resources/images/spriteStandRight.png");
    auto scaledpixmap = pixmap->scaled(89.5, 196.5);
    setPixmap(scaledpixmap);
//    runningtimer->start();
    Runningright();
    running=true;
    RunningRight=true;
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x() + speed); // player speed +
    widthAnimator->setDuration(50);
    widthAnimator->start();
}

void Player::handleLeftMovement() {
    auto pixmap = new QPixmap(":/resources/images/spriteStandLeft.png");
    auto scaledpixmap = pixmap->scaled(89.5, 196.5);
    setPixmap(scaledpixmap);
    RunningLeft();
    RunningRight=false;
    running=true;
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x() - speed); // player speed +
    widthAnimator->setDuration(50);
    widthAnimator->start();
}

void Player::handleUpMovement() {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(y() - 200);
    heightAnimator->setDuration(500);
    heightAnimator->start();
}



void Player::handleGravity() {
    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(ground);
    heightAnimator->setDuration(1000);
    heightAnimator->setEasingCurve(QEasingCurve::InOutCubic);
    heightAnimator->start();
}
void Player::Runningright() {
    if(!running){
    runningrighttimer->start();
    setPixmap(*moveRightFrames.at(Rframe));
    Rframe = (Rframe + 1) % 30;}
}
void Player::RunningLeft() {
    if(!running){
        runninglefttimer->start();
        setPixmap(*moveLeftFrames.at(Lframe));
        Lframe = (Lframe + 1) % 30;}
}
void Player::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);

    if (event->key() == Qt::Key_Right) {

        handleRightMovement();
    }
    if(x()>10){

        if (event->key() == Qt::Key_Left) {

            handleLeftMovement();
    }}
    if(y()>sceneheight-400){
        if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Space) {
        handleUpMovement();
    }}
}
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter, option, widget);
    for (QGraphicsItem *item: collidingItems()) {
        Platform *p = dynamic_cast<Platform *>(item);
        if (p != nullptr) {

            ground = sceneheight - 320;
            setPos(x(), sceneheight - 320);
            return;
        }
        if (p == nullptr) {
            ground = sceneheight - 200;
            heightAnimator->start();

        }

    }
}
void Player::keyReleaseEvent(QKeyEvent *event) {
    QGraphicsItem::keyReleaseEvent(event);

    if (event->key() == Qt::Key::Key_Right) {
        auto pixmap = new QPixmap(":/resources/images/spriteStandRight.png");
        auto scaledpixmap = pixmap->scaled(89.5, 196.5);
        setPixmap(scaledpixmap);
        running=false;
        runningrighttimer->stop();
    }
    if (event->key() == Qt::Key::Key_Left) {
        auto pixmap = new QPixmap(":/resources/images/spriteStandLeft.png");
        auto scaledpixmap = pixmap->scaled(89.5, 196.5);
        setPixmap(scaledpixmap);
        running=false;
        runninglefttimer->stop();
    }
}
void Player::RunLeftFrame() {
    auto pixmap =new QPixmap(":/resources/images/spriteRunLeft.png");
    auto scaledpixmap =pixmap->scaled(5000, 200);
    auto L1 =scaledpixmap.copy((scaledpixmap.width()/29.9)*0,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L1));
    auto L2=scaledpixmap.copy((scaledpixmap.width()/29.9)*1,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L2));
    auto L3=scaledpixmap.copy((scaledpixmap.width()/29.9)*2,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L3));
    auto L4=scaledpixmap.copy((scaledpixmap.width()/29.9)*3,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L4));
    auto L5=scaledpixmap.copy((scaledpixmap.width()/29.9)*4,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L5));
    auto L6=scaledpixmap.copy((scaledpixmap.width()/29.9)*5,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L6));
    auto L7=scaledpixmap.copy((scaledpixmap.width()/29.9)*6,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L7));
    auto L8=scaledpixmap.copy((scaledpixmap.width()/29.9)*7,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L8));
    auto L9=scaledpixmap.copy((scaledpixmap.width()/29.9)*8,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L9));
    auto L10=scaledpixmap.copy((scaledpixmap.width()/29.9)*9,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L10));
    auto L11=scaledpixmap.copy((scaledpixmap.width()/29.9)*10,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L11));
    auto L12=scaledpixmap.copy((scaledpixmap.width()/29.9)*11,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L12));
    auto L13=scaledpixmap.copy((scaledpixmap.width()/29.9)*12,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L13));
    auto L14=scaledpixmap.copy((scaledpixmap.width()/29.9)*13,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L14));
    auto L15=scaledpixmap.copy((scaledpixmap.width()/29.9)*14,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L15));
    auto L16=scaledpixmap.copy((scaledpixmap.width()/29.9)*15,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L16));
    auto L17=scaledpixmap.copy((scaledpixmap.width()/29.9)*16,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L17));
    auto L18=scaledpixmap.copy((scaledpixmap.width()/29.9)*17,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L18));
    auto L19=scaledpixmap.copy((scaledpixmap.width()/29.9)*18,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L19));
    auto L20=scaledpixmap.copy((scaledpixmap.width()/29.9)*19,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L20));
    auto L21=scaledpixmap.copy((scaledpixmap.width()/29.9)*20,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L21));
    auto L22=scaledpixmap.copy((scaledpixmap.width()/29.9)*21,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L22));
    auto L23=scaledpixmap.copy((scaledpixmap.width()/29.9)*22,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L23));
    auto L24=scaledpixmap.copy((scaledpixmap.width()/29.9)*23,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L24));
    auto L25=scaledpixmap.copy((scaledpixmap.width()/29.9)*24,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L25));
    auto L26=scaledpixmap.copy((scaledpixmap.width()/29.9)*25,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L26));
    auto L27=scaledpixmap.copy((scaledpixmap.width()/29.9)*26,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L27));
    auto L28=scaledpixmap.copy((scaledpixmap.width()/29.9)*27,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L28));
    auto L29=scaledpixmap.copy((scaledpixmap.width()/29.9)*28,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L29));
    auto L30=scaledpixmap.copy((scaledpixmap.width()/29.9)*29,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveLeftFrames.append(new QPixmap(L30));
}
void Player::RunRightFrame() {
    auto pixmap =new QPixmap(":/resources/images/spriteRunRight.png");
    auto scaledpixmap =pixmap->scaled(5000, 200);
    auto R1 =scaledpixmap.copy((scaledpixmap.width()/29.9)*0,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R1));
    auto R2=scaledpixmap.copy((scaledpixmap.width()/29.9)*1,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R2));
    auto R3=scaledpixmap.copy((scaledpixmap.width()/29.9)*2,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R3));
    auto R4=scaledpixmap.copy((scaledpixmap.width()/29.9)*3,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R4));
    auto R5=scaledpixmap.copy((scaledpixmap.width()/29.9)*4,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R5));
    auto R6=scaledpixmap.copy((scaledpixmap.width()/29.9)*5,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R6));
    auto R7=scaledpixmap.copy((scaledpixmap.width()/29.9)*6,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R7));
    auto R8=scaledpixmap.copy((scaledpixmap.width()/29.9)*7,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R8));
    auto R9=scaledpixmap.copy((scaledpixmap.width()/29.9)*8,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R9));
    auto R10=scaledpixmap.copy((scaledpixmap.width()/29.9)*9,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R10));
    auto R11=scaledpixmap.copy((scaledpixmap.width()/29.9)*10,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R11));
    auto R12=scaledpixmap.copy((scaledpixmap.width()/29.9)*11,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R12));
    auto R13=scaledpixmap.copy((scaledpixmap.width()/29.9)*12,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R13));
    auto R14=scaledpixmap.copy((scaledpixmap.width()/29.9)*13,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R14));
    auto R15=scaledpixmap.copy((scaledpixmap.width()/29.9)*14,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R15));
    auto R16=scaledpixmap.copy((scaledpixmap.width()/29.9)*15,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R16));
    auto R17=scaledpixmap.copy((scaledpixmap.width()/29.9)*16,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R17));
    auto R18=scaledpixmap.copy((scaledpixmap.width()/29.9)*17,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R18));
    auto R19=scaledpixmap.copy((scaledpixmap.width()/29.9)*18,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R19));
    auto R20=scaledpixmap.copy((scaledpixmap.width()/29.9)*19,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R20));
    auto R21=scaledpixmap.copy((scaledpixmap.width()/29.9)*20,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R21));
    auto R22=scaledpixmap.copy((scaledpixmap.width()/29.9)*21,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R22));
    auto R23=scaledpixmap.copy((scaledpixmap.width()/29.9)*22,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R23));
    auto R24=scaledpixmap.copy((scaledpixmap.width()/29.9)*23,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R24));
    auto R25=scaledpixmap.copy((scaledpixmap.width()/29.9)*24,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R25));
    auto R26=scaledpixmap.copy((scaledpixmap.width()/29.9)*25,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R26));
    auto R27=scaledpixmap.copy((scaledpixmap.width()/29.9)*26,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R27));
    auto R28=scaledpixmap.copy((scaledpixmap.width()/29.9)*27,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R28));
    auto R29=scaledpixmap.copy((scaledpixmap.width()/29.9)*28,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R29));
    auto R30=scaledpixmap.copy((scaledpixmap.width()/29.9)*29,0,scaledpixmap.width()/29.9,scaledpixmap.height());
    moveRightFrames.append(new QPixmap(R30));
}