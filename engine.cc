#include "engine.h"
#include "curseView.h"
#include "textView.h"
#include "curseControl.h"
#include <iostream>

Engine::Engine(size_t r, size_t c): rows{r}, cols{c} {
    for (size_t i=0; i<r; ++i) {
        std::vector<Cell> row;
        for (size_t j=0; j<c; ++j) {
            row.emplace_back(Cell(i, j)); // ??????
        }
        grid.emplace_back(row);
    }

    addView(std::move(std::make_unique<curseView>(r, c, *this)));
    addView(std::move(std::make_unique<textView>(r, c, *this)));
    addController(std::move(std::make_unique<curseControl>()));
}

void Engine::play() {
    Action a;
    while(std::cin) {
        renderCells();

        timeout(50);
        a = getAction();
        if ( UP == a ) {
            updateViews(3, 7, 'u');
            // std::cout << "hallooo" << std::endl;
        }
        else if ( DOWN == a ) updateViews(5, 7, 'd'); 
        else if ( QUIT == a ) break;

        // handle automated 
        // tick(); handle all auto things, not the user input bit
        displayViews();
    }
    
}


void Engine::renderCells() {
    for (int r=0; r<rows; ++r) {
        for (int c=0; c<cols; ++c) {
            updateViews(r, c, grid[r][c].getChar());
        }
    }
}
