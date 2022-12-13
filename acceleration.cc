#include "acceleration.h"
#include "gameObj.h"

Acceleration::Acceleration(GameObj *obj, int ddY, int ddX): Mvmt{obj}, ddY{ddY}, ddX{ddX} {}

void Acceleration::affect() {
    obj->addMvmt(ddY, ddX);
}