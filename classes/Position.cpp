

#include "Position.h"

Position::Position():x(0),y(0){}
Position::Position(int X , int Y) : x(X), y(Y) {}
int Position::getx(){return x;}
void Position::setx(int a){x=a; }
int Position::gety(){return y;}
void Position::sety(int b){y=b;}