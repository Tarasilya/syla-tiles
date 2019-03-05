#include "tile.h"


const int index_;
const double x_;
const double y_;
const TileType tile_type_;
std::vector<Unit*> units_;
std::vector<Tile*> neighboring_tiles_;

Tile::Tile(int index, double x_coord, double y_coord, TileType tile_type){
	view_ = new TileView();
	index_ = index;
	x_ = x_coord;
	y_ = y_coord;
	tile_type_ = tile_type;
 }

void Tile::SetNeighbors(std::vector<Tile*> neighboring_tiles){
	neighboring_tiles_ = neighboring_tiles
}

double Tile::x(){
	return x_;
}

double Tile::y(){
	return y_;
}

int Tile::index(){
	return  index_;
}

const std::vector<Unit*>& Tile::GetUnits(){
	// returns mutable vector of units
	return units_;
}

const std::vector<Tile*>& Tile::GetNeighbors(){
	return neighboring_tiles_;
}

void Tile::AddUnit(Unit* incoming_unit){
	units_.push_back(incoming_unit);
}

void Tile::RemoveUnit(Unit* leaving_unit){
	units_.erase(units_.find(leaving_unit));
}


void Tile::Tick(double tick_time){
	return;
}

ObjectView* GetView(Game* game){
	throw RuntimeError("Not implemented");
}