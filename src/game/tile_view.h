#pragma once

#include "object_view.h"

class Painter;
class Tile;

class TileView : public ObjectView{
private:
	Tile* tile_;
	double tile_radius_;
public:
	TileView(Tile* tile_);
	void Draw(Painter* painter) const;
}