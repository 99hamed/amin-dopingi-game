
#include <QApplication>
#include <QPushButton>
#include "classes/Game.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto game= new Game();
    game->show();




    return QApplication::exec();
}
