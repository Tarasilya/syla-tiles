#pragma once

#include <SFML/Window.hpp>
#include <vector>

class GameObject;
class ObjectView;
class Player;
class Painter;
class Map;
class GameConfig;
class City;

class Game {
private:
	Painter* painter_;
	Map* map_;
	int seconds_;

	std::vector<ObjectView*> views_;
	std::vector<Player*> players_;

	void InitMap();
	void InitViews();
	
public: 
	Game(Painter* painter, GameConfig& config);
	void Run();
	void Draw();
	void ProcessKey(sf::Keyboard::Key key);
	void Tick(double dt);
};
