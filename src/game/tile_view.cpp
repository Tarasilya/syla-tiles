#include "tile_view.h"

#include "game_config.h"
#include "tile.h"

#include "painter/painter.h"

TileView::TileView(Tile* tile){
	tile_ = tile;
	tile_radius_ = GameConfig::getInstance().GetFloat("TILE_RADIUS");
}

void TileView::Draw(Painter* painter) const{
	Color tile_color = TILE_COLOR; // ADD IT
	Circle tile_image;
	tile_image = {tile_->x(), tile_->y(), tile_radius_, TILE_COLOR}; 
	painter->Draw(tile_image);
}