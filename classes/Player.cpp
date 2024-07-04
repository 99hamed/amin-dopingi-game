
#include "Player.h"

Player::Player(int width, int height, Position position, int speed, Position velocity, QGraphicsPixmapItem *image)
        : BodyObject(width, height, position, image), speed(speed), velocity(velocity) {}


Player::Player(int width,int height,QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setFlags(GraphicsItemFlag::ItemIsFocusable );
    setFocus();

    auto pixmap =new QPixmap (":/resources/images/spriteStandRight.png");
    auto scaledpixmap=pixmap->scaled(89.5,196.5);

    setPixmap(scaledpixmap);

//    frames.append(new QPixmap(scaledpixmap));
//    pixmap=new QPixmap(":/resources/images/spriteRunRight.png");
//    scaledpixmap=pixmap->scaled(5000,200);
//
//    scaledpixmap = scaledpixmap.copy(0, 0, pixmap->width() - 10050 , pixmap->height());
//    frames.append(new QPixmap(scaledpixmap));
    mSpriteSheet = QPixmap(":/resources/images/spriteRunRight.png");
   mSpriteSheet=mSpriteSheet.scaled(5000,196.5);
    mFrameWidth = mSpriteSheet.width() / 29.9; // Assuming 10 frames
    mFrameHeight = mSpriteSheet.height();

    // Initial frame
    setPixmap(mSpriteSheet.copy(0, 0, mFrameWidth, mFrameHeight));

    runningTimer = new QTimer(this);
    runningTimer->setInterval(100);
    connect(runningTimer, &QTimer::timeout, this, &Player::updateFrame);
    runningTimer->start();

    //setPixmap(scaledpixmap);



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

//    auto pixmap =new QPixmap (":/resources/images/spriteStandRight.png");
//    auto scaledpixmap=pixmap->scaled(89.5,196.5);
//    setPixmap(scaledpixmap);
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x()+20);
    widthAnimator->setDuration(50);
    widthAnimator->start();

}
void Player::handleLeftMovement() {
//    auto pixmap =new QPixmap (":/resources/images/spriteStandLeft.png");
//    auto scaledpixmap=pixmap->scaled(89.5,196.5);
//    setPixmap(scaledpixmap);
    widthAnimator->stop();
    widthAnimator->setStartValue(x());
    widthAnimator->setEndValue(x()-20);
    widthAnimator->setDuration(50);
    widthAnimator->start();

}
void Player::handleUpMovement() {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(y()-200);
    heightAnimator->setDuration(500);
    heightAnimator->start();

}
void Player::updateFrame(){

    mCurrentFrame = (mCurrentFrame + 1) % 30; // Assuming 10 frames
    int x = mCurrentFrame * mFrameWidth;
    setPixmap(mSpriteSheet.copy(x, 0, mFrameWidth, mFrameHeight));
}
void Player::handleGravity() {

    heightAnimator->stop();
    heightAnimator->setStartValue(y());
    heightAnimator->setEndValue(ground);
    heightAnimator->setDuration(1000);
    heightAnimator->setEasingCurve(QEasingCurve::InOutCubic);
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

    if (event->key() == Qt::Key::Key_Up || event->key() == Qt::Key::Key_Space) {
        handleUpMovement();
    }

}
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_Left) {
        QPixmap standingPixmap(":/resources/images/spriteStandRight.png");
        setPixmap(standingPixmap.scaled(89.5, 196.5)); // ;
    }
    if ( event->key() == Qt::Key_Left) {
        QPixmap standingPixmap(":/resources/images/spriteStandLeft.png");
        setPixmap(standingPixmap.scaled(89.5, 196.5)); // ;
    }
    QGraphicsItem::keyReleaseEvent(event);
}

