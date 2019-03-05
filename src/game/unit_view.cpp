#include "unit_view.h"

#include "painter/painter.h"

UnitView::UnitView(Unit* unit) : unit_(unit) {
    color_ = {255 * (rand()%2), 255 * (rand()%2), 255 * (rand()%2)};
}

void UnitView::Draw(Painter* painter) {
    Tile* tile = unit_->GetTile();
    double x = tile->x();
    double y = tile->y();
    double sz = 0.05;
    painter->Draw(Rectangle(x - 3*sz, y - sz, x + 3*sz, y + sz, color_));
    painter->Draw(Rectangle(x - sz, y - 3*sz, x + sz, y + 3*sz, color_));
}