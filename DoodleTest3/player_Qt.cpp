//#include <QImage>
//#include <QPoint>

//#include "ItemFactory.h"
//#include "player_Qt.h"
//#include "preferences.h"

//Player_Qt::Player_Qt() : p(":/player/images/NinjaPlayer400x400.png")
//{
//    this->setPixmap(p);
//    double model_width = double(PLAYER_HITBOX_WIDTH) / HITBOX_RATIO;
//    this->setScale(model_width / p.width());
//    this->setZValue(PLAYER_Z);
//    this->setPos(HITBOX_X_LT_OFFSET_RATIO * model_width,
//                 HITBOX_Y_LT_OFFSET_RATIO * model_width);
//}

//namespace
//{
//    ItemFactoryRegistration<Player_Qt> p(ID);
//}


// width = 600  ==> 100
// width = 1200 ==> 200
// width = 2400 ==> 400

#include "ItemFactory.h"
#include "player.h"
#include "player_Qt.h"
#include "preferences.h"

Player_Qt::Player_Qt() : DrawingItem(PLAYER_Z,
                                     PLAYER_HITBOX_WIDTH, PLAYER_HITBOX_HEIGHT,
                                     0.48, 0.78, 0.2, 0.11,
                                     ":/player/images/NinjaPlayer400x400.png")
{}

namespace
{
    ItemFactoryRegistration <Player_Qt> p(PLAYER_ID);
}
