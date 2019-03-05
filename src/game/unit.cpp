#include "unit.h"

Unit::Unit(Tile* homie) : homie_(homie) {
    view_ = new UnitView(this);
}

void Unit::Move() {
    const vector<Tiles*>& vars = homie_->GetNeighbours();
    homie_ = vars[rand() % vars.size()];
}

void Unit::Tick(double /*tick_time*/) {}