#include "engine.h"
#include "ncurses.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    Engine e(20, 78);
    
    GameObj* p = e.spawnChar(15,25,0,'o');
    e.setPlayer(p);
    Collider* c1 = e.createStopCollider(p); 
    p->setPeriod(0);

    GameObj* obstacle = e.spawnChar(18,51,0,'X');
    e.createStopCollider(obstacle);

    GameObj* bouncing = e.spawnChar(15,1,0,'M');
    bouncing->setMvmt(1, 1);
    // falling->setPeriod(20); 
    Collider* c3 = e.createBounceCollider(bouncing);
    // Mvmt* m1 = e.createAcceleration(falling, 1, 0);
// m1->setPeriod(15); // //////////////////////////////////////////// GRAVITY. STOP ON COLLIDE. 


    std::map<std::pair<int,int>, char> rect {
        {{0,0}, '='}, {{0,1}, '='}, {{0,2}, '='}, {{0,3}, '='}, {{0,4}, '='}, {{0,5}, '='},
        {{1,0}, '='}, {{1,1}, '='}, {{1,2}, '='}, {{1,3}, '='}, {{1,4}, '='}, {{1,5}, '='} };

    GameObj* top = e.spawnBmp(5, 60, 2, rect);
    e.createBounceCollider(top);
    top->setMvmt(-1, 0);

    GameObj* win = e.spawnChar(19,77,0,'W');
    Collider* winner = e.createGameEndCollider(win, true);

    GameObj* lose = e.spawnChar(0,77,0,'L');
    Collider* loser = e.createGameEndCollider(lose, false);


    std::map<std::pair<int,int>, char> b {
                  {{0,1}, '0'}, 
    {{1,0}, '0'}, {{1,1}, '0'}, {{1,2}, '0'}, 
                  {{2,1}, '0'}, 
                  {{3,1}, 'V'}
    }; 
    GameObj* bmp = e.spawnBmp(5, 50, 0, b);
    Collider* c5 = e.createBounceCollider(bmp);
    Collider* c4 = e.createDmgCollider(bmp);
    bmp->setMvmt(1, 0);

    
    Action a;
    while (e.playing) {
        a = e.getInput();
        
        GameObj* playerObj = p;
        // moveBy() sets vector of motion. tick() does the moving
        if ( UP == a ) { playerObj->moveBy(-1,0); }
        else if ( DOWN == a ) { playerObj->moveBy(1,0); }
        else if ( RIGHT == a ) { playerObj->moveBy(0,1); }
        else if ( LEFT == a ) { playerObj->moveBy(0,-1); }
        else if ( QUIT == a ) {
            e.playing = false;
            break;
        }
        

        e.tick();
    }
    

    // auto ptr = reinterpret_cast<std::uintptr_t>(c3); 
    // e.updateViews(1, std::to_string(ptr));
    // e.displayViews();
    // timeout(10000);
    // getch();
    
    // std::cout << debug << std::endl;
    

    // endwin();
}
