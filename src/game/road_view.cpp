#include "road_view.h"
#include "road.h"
#include "city.h"

#include "painter/painter.h"
#include "painter/sizes.h"

#include <cmath>

RoadView::RoadView(Road* road) : road_(road), selected_cities_(2) {}


void RoadView::SelectFromCity(int city_id) {
	for (int i = 0; i < 2; i++) {
		if (road_->GetCities()[i]->GetIndex() == city_id) {
			selected_cities_[i] = true;
		}
	}
}

void RoadView::DeselectFromCity(int city_id) {
	for (int i = 0; i < 2; i++) {
		if (road_->GetCities()[i]->GetIndex() == city_id) {
			selected_cities_[i] = false;
		}
	}
}

Road* RoadView::GetRoad() {
    return road_;
}