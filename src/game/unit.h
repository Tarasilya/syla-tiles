#include "game_object.h"

class Tile;

class Unit : public GameObject {
private:
    Tile* homie_;

public:
    Unit(Tile* homie);
    void Move();
    void Tick(double tick_time) override;
};