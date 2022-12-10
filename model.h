#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include "action.h"
#include "controller.h"
#include "view.h"

enum Action;

class Model {
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> control;
  protected:
    void addView(std::unique_ptr<View> v);
    void addController(std::unique_ptr<Controller> v);
    Action getAction();
  public:
    virtual ~Model() = default;
    void updateViews(int row, int col, char c);
    void updateViews(int row, const std::string& s);
    void displayViews();

    // tick() // step fwd 1 tick
};

#endif