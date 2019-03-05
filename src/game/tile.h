#pragma once

#include "enum.h"
#include "game_object.h"
#include "player.h"
#include "object_view.h"

#include<vector>

class Unit;

class Tile : public GameObject
{
private:
	const int index_;
	const double x_;
	const double y_;
	const TileType tile_type_;
	std::vector<Unit*> units_;
	std::vector<Tile*> neighboring_tiles_;
public:
	Tile(int index, double x_coord, double y_coord, TileType tile_type);
	void SetNeighbors(std::vector<Tile*> neighboring_tiles);

    double x() const;
    double y() const;
    int index() const;
    const std::vector<Unit*>& GetUnits() const;
    const std::vector<Tile*>& GetNeighbors() const;

    void AddUnit(Unit* incoming_unit);
    void RemoveUnit(Unit* leaving_unit);


    void Tick(double tick_time) override;
    ObjectView* GetView(Game* game) override;
};