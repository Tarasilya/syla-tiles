#include "map.h"
#include "tile.h"
#include "game_object.h"
#include "enum.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

Map::Map() {
}


const std::vector<GameObject*>& Map::GetObjects() {
	return objects_;
}

const std::vector<Tile*>& Map::GetTiles() {
	return tiles_;
}

Map::Map(std::string filename) {
	filename_ = filename;
	ReadObjects();
}

void Map::ReadObjects() {
	int count;
	std::ifstream in (filename_);

	in >> count;

	for (int i = 0; i < count; i++) {
		ReadObject(in);
	}
}

void Map::ReadObject(std::ifstream& in) {
	int type;
	in >> type;
	if (type == 0) {
		double x, y;
		int player_id;
		in >> x >> y >> player_id;
		std::cerr << "read tile " << x << " " << y << std::endl;
		Tile* tile = new Tile(objects_.size(), x, y, GRASSLAND);
		tiles_.push_back(tile);
		objects_.push_back(tile);
		neighbors.push_back(std::vector<Tile*>());
		std::cerr << neighbors.size() << " " << tiles_.size() << std::endl;
	}
	else {
		int tile1, tile2;
		in >> tile1 >> tile2;
		std::cerr << "read road " << tile1 << " " << tile2 << std::endl;
		std::cerr << neighbors.size() << " " << tiles_.size() << std::endl;
		neighbors[tile1].push_back(tiles_[tile2]);
		neighbors[tile2].push_back(tiles_[tile1]);
	}
	for (int i = 0; i < (int) neighbors.size(); i++) {
		tiles_[i]->SetNeighbors(neighbors[i]);
	}
}




void Map::AddObject(GameObject* object) {
	objects_.push_back(object);
}
