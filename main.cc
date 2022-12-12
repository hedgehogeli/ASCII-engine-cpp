#include "engine.h"
#include "ncurses.h"
#include <string>
#include <iostream>

#include <fstream>

class Engine;

int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    Engine e(20, 78);
    
    GameObj* p = e.spawnChar(5,5,0,'o');
    e.setPlayer(*p);
    Collider* c1 = e.createStopCollider(p); // it should return the collider 
    p->setPeriod(0);

    GameObj* obstacle = e.spawnChar(10,20,0,'X');
    e.createStopCollider(obstacle);

    GameObj* falling = e.spawnChar(3,3,0,'M');
    falling->setMvmt(1, 1);
    // falling->setPeriod(1); 
    Collider* c3 = e.createBounceCollider(falling);
    

    GameObj* win = e.spawnChar(19,77,0,'W');
    Collider* winner = e.createGameEndCollider(win, true);

    GameObj* lose = e.spawnChar(0,77,0,'L');
    Collider* loser = e.createGameEndCollider(lose, false);


    e.play();

    // auto ptr = reinterpret_cast<std::uintptr_t>(c3); 
    // e.updateViews(1, std::to_string(ptr));
    // e.displayViews();
    // timeout(10000);
    // getch();
    
    // std::cout << debug << std::endl;
    

    endwin();
}