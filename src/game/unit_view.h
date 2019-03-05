#include "object_view.h"

#include "painter/shapes.h"

class Unit;
class Painter;

class UnitView : public ObjectView {
    Unit* unit_;
    Color color_;
public:
    UnitView(Unit* unit);
    void Draw(Painter* painter) const override;
};