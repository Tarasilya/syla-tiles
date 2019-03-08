#include "game_config.h"

#include "utils/utils.h"

#include <iostream>
#include <fstream>

GameConfig::GameConfig() {
	std::ifstream in("config.txt");
	std::string name, value;
	while (in >> name) {
		in >> value;
		std::cerr << "read " << name << " " << value << std::endl;
		params_[name] = value;
	}
}

std::string GameConfig::GetString(std::string name) {
	return params_[name];
}

int GameConfig::GetInt(std::string name) {
	return std::stoi(params_[name]);
}

float GameConfig::GetFloat(std::string name) {
	return std::stof(params_[name]);
}

std::map<sf::Keyboard::Key, Control> GameConfig::GetControls(int player_index) {
	std::map<sf::Keyboard::Key, Control> controls_;
	std::string ids = utils::ToStr(player_index);
	controls_[GetKey("MOVE" + ids)] = MOVE;
	return controls_;
}

sf::Keyboard::Key GameConfig::GetKey(std::string name) {
	std::cerr << "converting " << params_[name] << std::endl;
	return ToSfKey(params_[name]);
}