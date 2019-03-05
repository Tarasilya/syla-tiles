#include "tile_view.h"
#include "game_config.h"


TileView::TileView(Tile* tile){
	config = GameConfig.getInstance();
	tile_ = tile;
	tile_radius_ = config.GetFloat("TILE_RADIUS"); // ADD IT
}

void TileView::Draw(Painter* painter) const{
	Color tile_color = TILE_COLOR; // ADD IT
	Circle tile_image;
	tile_image = {tile_->x(), tile_->y(), tile_radius_, TILE_COLOR}; 
	painter->Draw(tile_image);
}