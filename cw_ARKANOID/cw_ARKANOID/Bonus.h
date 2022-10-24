#pragma once
#include "Ball.h"
#include "Blocks.h"
#include <SFML\Graphics.hpp>

enum BONUS_TYPES{
	CHANGE_WIDTH_PADDLE,
	DECREASE_SPEEDBALL,
	BALL_STICKING,
	SET_FLOOR,
	CHANGE_TRAJECTORY,
	SECOND_BALL
};

class Bonus : public Circle{
private:
	void SetColor();
public:
	bool isActive = false;

	struct{
		Rectangle rect{ 800 / 2, 600, 800, 16 };
		bool active = false;
	}floor;

	int type = 5;

	Bonus(int x, int y) : Circle(x, y){
		ballRadius = 5.f;
		ballVelocity = 14.f;
		shape.setRadius(this->ballRadius);
		velocity = { 0, ballVelocity };
	}

	void SetType(int type){
		this->type = type;
		SetColor();
	}

	void SetPosition(Vector2f position){
		shape.setPosition(position);
	}

	virtual  Vector2f getPosition() { return shape.getPosition(); };
	virtual float left() { return this->shape.getPosition().x - shape.getRadius(); };
	virtual float right() { return this->shape.getPosition().x + shape.getRadius(); };
	virtual float top() { return this->shape.getPosition().y - shape.getRadius(); };
	virtual float bottom() { return this->shape.getPosition().y + shape.getRadius(); };
};