#pragma once

#include <SFML/Graphics.hpp>
#include "field.h"

using namespace sf;

class Paddle : public GameObject, public sf::Drawable{
private:
	RectangleShape shape;
	float width = 180.f;
	const float height = 16.f;
	const float paddleVelocity = 13.f;
	Vector2f velocity{ paddleVelocity, 0.f };

	void draw(RenderTarget& target, RenderStates state) const { target.draw(this->shape, state); }
public:
	Paddle(int x, int y);

	void update(float winWidth);
	void IncraseWidth();
	Vector2f getVelocity() { return this->velocity; };
	void SetDefualtWidth();

	virtual Vector2f getPosition();
	virtual float left() {	return this->shape.getPosition().x - shape.getSize().x / 2.f;	}
	virtual float right() { return this->shape.getPosition().x + shape.getSize().x / 2.f; }
	virtual float top() { return this->shape.getPosition().y - shape.getSize().y / 2.f; }
	virtual float bottom() { return this->shape.getPosition().y + shape.getSize().y / 2.f; }
};

