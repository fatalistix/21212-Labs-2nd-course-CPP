//#include <QImage>
//#include <QPoint>

//#include "ItemFactory.h"
//#include "defaultstep_Qt.h"
//#include "preferences.h"

//DefaultStep_Qt::DefaultStep_Qt() : p(":/surround/images/green.png")
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
//    ItemFactoryRegistration<DefaultStep_Qt> p(ID);
//}


#include "ItemFactory.h"
#include "defaultstep.h"
#include "defaultstep_Qt.h"
#include "preferences.h"

DefaultStep_Qt::DefaultStep_Qt() : DrawingItem(STEPS_Z,
                                               DEFAULT_STEP_HITBOX_WIDTH, DEFAULT_STEP_HITBOX_HEIGHT,
                                               1, 1, 0, 0,
                                               ":/surround/images/green.png")
{}

namespace
{
    ItemFactoryRegistration <DefaultStep_Qt> p(DEFAULT_STEP_ID);
}
