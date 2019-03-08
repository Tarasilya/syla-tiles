#include "unit_view.h"

#include "unit.h"
#include "tile.h"

#include "painter/painter.h"

#include <ctime>

UnitView::UnitView(Unit* unit) : unit_(unit) {
    srand(clock());
    color_ = {255 * (rand()%2), 255 * (rand()%2), 255 * (rand()%2)};
}

void UnitView::Draw(Painter* painter) const {
    Tile* tile = unit_->GetTile();
    double x = tile->x();
    double y = tile->y();
    double sz = 0.02;
    painter->Draw(Rectangle(x - 3*sz, y - sz, x + 3*sz, y + sz, color_));
    painter->Draw(Rectangle(x - sz, y - 3*sz, x + sz, y + 3*sz, color_));
}