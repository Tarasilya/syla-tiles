#pragma once

#include "control_keys.h"

#include <SFML/Window.hpp>

#include <map>

class CityView;

class Player {
private:
	int id_;
	std::map<sf::Keyboard::Key, Control> controls_;
public:
	Player(std::map<sf::Keyboard::Key, Control> controls, CityView* baseView, int id);

	bool ProcessKey(sf::Keyboard::Key key);
	int GetId();
};