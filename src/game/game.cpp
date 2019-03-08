#include "game.h"
#include "game_object.h"
#include "player.h"
#include "map.h"
#include "game_config.h"
#include "unit.h"
#include "object_view.h"

#include "painter/painter.h"

#include <iostream>
#include <cmath>
#include <sstream>

Game::Game(Painter* painter, GameConfig& config) {
	painter_ = painter;
	InitMap();
	InitViews();
	for (int i = 0; i < 2; i++) {
		players_.push_back(new Player(config.GetControls(i), i));
	}
	for (int i = 0; i < 2; i++) {
		Tile* homich = map_->GetTiles()[i * (map_->GetTiles().size() - 1)];
		Unit* unit = new Unit(homich);
		players_[i]->SetUnit(unit);
		map_->AddObject(unit);
		views_.push_back(unit->GetView());
	}
}

void Game::InitMap() {
	map_ = new Map(GameConfig::getInstance().GetString("MAP"));
}

void Game::InitViews() {
	for (auto object: map_->GetObjects()) {
		views_.push_back(object->GetView());
	}
}

void Game::Draw() {
	for (auto view: views_) {
		view->Draw(painter_);
	}
}

void Game::ProcessKey(sf::Keyboard::Key key)
{
	for (auto player : players_) {
		if (player->ProcessKey(key)) {
			break;
		}
	}
}

void Game::Tick(double dt)
{
	for (auto object: map_->GetObjects())
	{
		object->Tick(dt);
	}
}
