#include "mvmt.h"

Mvmt::~Mvmt() {}

Mvmt::Mvmt(GameObj* obj): obj{obj}, waitPeriod{20}, waitTicks{20} {}

void Mvmt::affectMvmt() { 
    if (waitTicks) { // check if there are ticks to wait until mvmt
        --waitTicks;
        affect();
    } else { waitTicks = waitPeriod; } // reset ticks
}
