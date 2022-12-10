#include "curseControl.h"
#include <string>
#include <iostream>

curseControl::curseControl() {
    setlocale(LC_ALL, "");
    mapping['w'] = Action::UP;
    mapping['d'] = Action::RIGHT;
    mapping['s'] = Action::DOWN;
    mapping['a'] = Action::LEFT;
    mapping[KEY_UP] = Action::UP;
    mapping[KEY_RIGHT] = Action::RIGHT;
    mapping[KEY_DOWN] = Action::DOWN;
    mapping[KEY_LEFT] = Action::LEFT;
    mapping[' '] = Action::SPACE;
    mapping['\033'] = Action::QUIT;
}

Action curseControl::action() {
    char n;
    while ( (n = getch()) == ERR ) continue;

    if ( mapping.find(n) != mapping.end() ) {
        return mapping[n];
    }
    return Action::INVALID;
}
