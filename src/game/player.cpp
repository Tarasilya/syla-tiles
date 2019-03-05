#include "enum.h"
#include "city.h"
#include "road.h"
#include "player.h"
#include "control_keys.h"
#include "road_view.h"
#include "city_view.h"

#include <iostream>

Player::Player(std::map<sf::Keyboard::Key, Control> controls, int id) 
	: focusedUnit_(0), 
	controls_(controls),
	id_(id) 
{
}

int Player::GetId() {
	return id_;
}

bool Player::ProcessKey(sf::Keyboard::Key key) {
	if (controls_[key] == 0){
		return false;
	}
	switch (controls_[key]){

	case MOVE: 
		if (focusedUnit_) {
			focusedUnit_->Move();
		}
		return true;
	}


	return false;

}
