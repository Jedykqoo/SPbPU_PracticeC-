#include"Blocks.h"

Rectangle::Rectangle(int x, int y, float blockWidth, float blockHeight){
	shape.setPosition(static_cast<float>(x), static_cast<float>(y));
	shape.setSize(Vector2f{ blockWidth, blockHeight });
	shape.setFillColor(Color(169, 169, 169));
	shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
}

void Block::SetColor(int type){
    this->type = type;
    switch (type){
    case NOT_DESTROYED:
        shape.setFillColor(Color(105, 105, 105));
        break;
    case ORDINARY:
        shape.setFillColor(Color::Yellow);
        break;
    case WITH_BONUS:
        shape.setFillColor(Color(255, 105, 180));
        break;
    case INCREASE_SPEED:
        shape.setFillColor(Color(0, 255, 255));
        break;
    case WITH_HEALTH:
        shape.setFillColor(withHealth.color[withHealth.lvl]);
        break;
    default:
        break;
    }
}