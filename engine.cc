#include "engine.h"
#include "curseView.h"
#include "textView.h"
// #include "curseKeyboard.h"

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
    // addController(std::move(std::make_unique<curseKeyboard>()));
}



void Engine::render() {
    updateViews(0, "hey there");
    getch();
    displayViews(); 
    // views[0]->render();
    // views[1]->update("hey there");
}
