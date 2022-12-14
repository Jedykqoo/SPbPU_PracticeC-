#include "Bonus.h"

void Bonus::SetColor() {
	switch (type) {
	case CHANGE_WIDTH_PADDLE:
		shape.setFillColor(Color::Red);
		break;
	case DECREASE_SPEEDBALL:
		shape.setFillColor(Color::Cyan);
		break;
	case BALL_STICKING:
		shape.setFillColor(Color::Yellow);
		break;
	case CHANGE_TRAJECTORY:
		shape.setFillColor(Color::Magenta);
		break;
	case SET_FLOOR:
		shape.setFillColor(Color::Green);
		break;
	case SECOND_BALL:
		shape.setFillColor(Color::White);
		break;
	default:
		break;
	}
}