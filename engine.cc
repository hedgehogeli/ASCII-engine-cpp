#include "engine.h"
#include "curseView.h"
#include "curseKeyboard.h"

Engine::Engine(size_t r, size_t c): rows{r}, cols{c} {
    for (int i=0; i < r; ++i){
        std::vector<Cell> row;
        for (int j=0; j < c; ++j){
            row.emplace_back(Cell(i, j));
        }
        grid.emplace_back(row);
    }

    addView(std::move(std::make_unique<curseView>(r, c, *this)));
    addView(std::move(std::make_unique<textView>(r, c, *this)));
    // addController(std::move(std::make_unique<curseKeyboard>()));
}

/*
initscr();
    noecho();
    curs_set(0);
    */

void Engine::render() {
    views[0].render();
}
