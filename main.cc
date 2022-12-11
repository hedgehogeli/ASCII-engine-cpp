#include "engine.h"
#include <string>
#include <iostream>

class Engine;

int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    Engine e(20, 78);
    
    CharGameObj o = e.spawnChar(3,3,0,'X');
    e.setPlayer(o);

    e.play();


    endwin();

  
}