#pragma once

#include <fstream>
#include <vector>

class GameObject;
class Tile;

class Map {
private:
	std::vector<std::vector<Tile*>> neighbors;
	std::vector<GameObject*> objects_;
	std::vector<Tile*> tiles_;
	std::string filename_;
	Map();
	void ReadObjects();
	void ReadObject(std::ifstream& in);

public:
	Map(std::string filename);
	const std::vector<GameObject*>& GetObjects();
	const std::vector<Tile*>& GetTiles();



// HUYNYA INCOMING
    void AddObject(GameObject* object);

};