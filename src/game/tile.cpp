#include "tile.h"

#include "tile_view.h"

Tile::Tile(int index, double x, double y, TileType tile_type) : index_(index), x_(x), y_(y), tile_type_(tile_type) {
	view_ = new TileView(this);
 }

void Tile::SetNeighbors(std::vector<Tile*> neighboring_tiles) {
	neighboring_tiles_ = neighboring_tiles;
}

double Tile::x() const {
	return x_;
}

double Tile::y() const {
	return y_;
}

int Tile::index() const {
	return index_;
}

const std::vector<Unit*>& Tile::GetUnits() const {
	return units_;
}

const std::vector<Tile*>& Tile::GetNeighbors() const {
	return neighboring_tiles_;
}

void Tile::AddUnit(Unit* incoming_unit) {
	units_.push_back(incoming_unit);
}

void Tile::RemoveUnit(Unit* leaving_unit) {
	units_.erase(std::find(units_.begin(), units_.end(), leaving_unit));
}

void Tile::Tick(double tick_time) {
	return;
}
