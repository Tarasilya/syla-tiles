#pragma once

#include <SFML/Window.hpp>

#include <string>

enum Control {
	NOTHING = 0,
	MOVE, 
};

sf::Keyboard::Key ToSfKey(std::string);
