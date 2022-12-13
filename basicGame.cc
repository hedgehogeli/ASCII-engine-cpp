// #include "engine.h"
// #include "ncurses.h"
// #include <string>
// #include <iostream>

// int main(int argc, char* argv[]) {
//     initscr();
//     noecho();
//     curs_set(0);
//     refresh();

//     Engine e(20, 78);
    
//     GameObj* p = e.spawnChar(15,5,0,'o');
//     e.setPlayer(p);
//     Collider* c1 = e.createStopCollider(p); 
//     p->setPeriod(0);

//     GameObj* obstacle = e.spawnChar(18,51,0,'X');
//     e.createStopCollider(obstacle);

//     GameObj* falling = e.spawnChar(0,0,0,'M');
//     falling->setMvmt(1, 1);
//     // falling->setPeriod(1); 
//     Collider* c3 = e.createBounceCollider(falling);
//     Mvmt* m1 = e.createAcceleration(falling, 0, 1);
//     m1->setPeriod(30);

//     GameObj* win = e.spawnChar(19,77,0,'W');
//     Collider* winner = e.createGameEndCollider(win, true);

//     GameObj* lose = e.spawnChar(0,77,0,'L');
//     Collider* loser = e.createGameEndCollider(lose, false);


//     std::map<std::pair<int,int>, char> b {
//                   {{0,1}, '0'}, 
//     {{1,0}, '0'}, {{1,1}, '0'}, {{1,2}, '0'}, 
//                   {{2,1}, '0'}, 
//                   {{3,1}, 'V'}
//     }; 
//     GameObj* bmp = e.spawnBmp(5, 50, 0, b);
//     Collider* c5 = e.createBounceCollider(bmp);
//     Collider* c4 = e.createDmgCollider(bmp);
//     bmp->setMvmt(1, 0);

    
//     Action a;
//     while (e.playing) {
//         a = e.getInput();
        
//         GameObj* playerObj = p;
//         // moveBy() sets vector of motion. tick() does the moving
//         if ( UP == a ) { playerObj->moveBy(-1,0); }
//         else if ( DOWN == a ) { playerObj->moveBy(1,0); }
//         else if ( RIGHT == a ) { playerObj->moveBy(0,1); }
//         else if ( LEFT == a ) { playerObj->moveBy(0,-1); }
//         else if ( QUIT == a ) {
//             e.playing = false;
//             break;
//         }
        

//         e.tick();
//     }
    

//     // auto ptr = reinterpret_cast<std::uintptr_t>(c3); 
//     // e.updateViews(1, std::to_string(ptr));
//     // e.displayViews();
//     // timeout(10000);
//     // getch();
    
//     // std::cout << debug << std::endl;
    

//     // endwin();
// }