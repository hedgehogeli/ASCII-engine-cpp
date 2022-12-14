#include "engine.h"
#include "ncurses.h"

void spawnAliens(std::vector<GameObj*>* aliens, int r, 
  std::map<std::pair<int,int>, char> alienBmp, Engine& e);

int main(int argc, char* argv[]) {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    Engine e(20, 78);


    std::map<std::pair<int,int>, char> playerBmp {
                  {{0,1}, '_'}, {{0,2}, '/'}, {{0,3}, '^'}, {{0,4}, '\\'}, {{0,5}, '_'}, 
    {{1,0}, '/'}, {{1,1}, '-'}, {{1,2}, '-'}, {{1,3}, 'v'}, {{1,4}, '-'}, {{1,5}, '-'}, {{1,6}, '\\'}    }; 
    GameObj* player = e.spawnBmp(18,35,0,playerBmp);
    e.setPlayer(player);
    Collider* c1 = e.createStopCollider(player); 
    e.createGameEndCollider(player, false);
    // Collider* c2 = e.createCollider<stopCollider>(player);
    player->setPeriod(0); 


    std::map<std::pair<int,int>, char> alien1 {
    {{0,0}, 'V'}, {{0,1}, 'T'}, {{0,2}, 'V'},
    {{1,0}, '\\'}, {{1,1}, 'V'}, {{1,2}, '/'} };

    std::map<std::pair<int,int>, char> alien2 {
    {{0,0}, '/'}, {{0,1}, 'M'}, {{0,2}, '\\'},
    {{1,0}, '\\'}, {{1,1}, '~'}, {{1,2}, '/'} };

    std::map<std::pair<int,int>, char> alien3 {
    {{0,0}, 'd'}, {{0,1}, '0'}, {{0,2}, 'b'},
    {{1,0}, '~'}, {{1,1}, '|'}, {{1,2}, '~'} };

    std::vector<GameObj*> aliens {};
    

    aliens.reserve(27);

    spawnAliens(&aliens, 1, alien1, e);
    spawnAliens(&aliens, 4, alien2, e);
    spawnAliens(&aliens, 7, alien3, e);


    // BARRIERS

    std::map<std::pair<int,int>, char> barrier {
                      {{0,1}, '_'}, {{0,2}, '_'}, {{0,3}, '_'},
        {{1,0}, '/'}, {{1,1}, 'X'}, {{1,2}, 'X'}, {{1,3}, 'X'}, {{1,4}, '\\'},
        {{2,0}, 'Y'}, {{2,1}, 'Y'},               {{2,3}, 'Y'}, {{2,4}, 'Y'} };
    for (int c=5; c<73; c+=9) {
        GameObj* b = e.spawnBmp(13,c,0,barrier);
        Collider* collide = e.createDmgCollider(b); 
    }


    Action a;
    size_t ticks = 0;
    size_t fireCD = 0;
    while (e.playing) {
        a = e.getInput();
        
        GameObj* playerObj = player;
        if ( RIGHT == a ) { playerObj->moveBy(0,1); }
        else if ( LEFT == a ) { playerObj->moveBy(0,-1); }
        if ( SPACE == a ) {
            if ( !fireCD ) {
                GameObj* projectile = e.spawnChar(playerObj->getRow()-1, playerObj->getCol()+3, 0, '*');
                projectile->setMvmt(-1, 0);
                e.createStopCollider(projectile);
                e.createDmgCollider(projectile);
                e.createBoundDestroyCollider(projectile);
                projectile->setPeriod(1);
                fireCD = 3; // 3 is good for showcasing, 8 for actual game maybe
            }
        }
        else if ( QUIT == a ) {
            e.playing = false;
            break;
        }


        if (fireCD) --fireCD;


        int per = 470;
        bool aliensAlive = false;
        for (auto alien : aliens) {
            alien->setMvmt(0,0);
            if ( ticks && ticks%(per/2)==0 ) {
                alien->setMvmt(1,0);
                alien->setPeriod(0);
            }
            else {
                if ( (ticks%per) < (per/2) ) {
                    alien->setMvmt(0,1);
                } else {
                    alien->setMvmt(0,-1);
                }
            }

            aliensAlive = aliensAlive || alien->inPlay;
            
        }
        if (!aliensAlive) {
            e.terminate("YOU WIN!!!");
            break;
        }
// e.updateViews(0, std::to_string(ticks%per));        
// e.updateViews(1, std::to_string(ticks));
        e.tick();

        if (ticks%(per/2) == 0) {
            for (auto alien : aliens) {
                alien->setPeriod(5);
            }
        }

        ++ticks;
        
    }


}

void spawnAliens(std::vector<GameObj*>* aliens, int r, 
  std::map<std::pair<int,int>, char> alienBmp, Engine& e) {
    for (int c=3; c<35; c+=4) {
        GameObj* alien = e.spawnBmp(r,c,0,alienBmp);
        Collider* collide = e.createDmgCollider(alien); 
        e.createBoundEndCollider(alien, false);
        aliens->push_back(alien);
    }
}
