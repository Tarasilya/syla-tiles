#pragma once

#include "control_keys.h"

#include <SFML/Window.hpp>

#include <map>

class CityView;
class Unit;

class Player {
private:
	int id_;
	std::map<sf::Keyboard::Key, Control> controls_;
    Unit* focusedUnit_;
public:
	Player(std::map<sf::Keyboard::Key, Control> controls, int id);

	bool ProcessKey(sf::Keyboard::Key key);
	int GetId();

    void SetUnit(Unit* unit);
};