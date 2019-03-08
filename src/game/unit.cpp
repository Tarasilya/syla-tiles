#include "unit.h"

#include "tile.h"
#include "unit_view.h"

Unit::Unit(Tile* homie) : homie_(homie) {
    view_ = new UnitView(this);
}

void Unit::Move() {
    const std::vector<Tile*>& vars = homie_->GetNeighbors();
    homie_ = vars[rand() % vars.size()];
}

void Unit::Tick(double /*tick_time*/) {}

Tile* Unit::GetTile() const {
    return homie_;
}