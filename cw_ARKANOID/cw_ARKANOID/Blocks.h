#pragma once

#include"field.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Rectangle : public GameObject, public Drawable {
public:
	virtual void draw(RenderTarget& targer, RenderStates states) const {
		targer.draw(this->shape, states);
	}

	RectangleShape shape;
	bool destroyed = false;
public:
	Rectangle(int x, int y, float blockWidth, float blockHeight);

	virtual  Vector2f getPosition() { return shape.getPosition(); };
	virtual float left() {return this->shape.getPosition().x - shape.getSize().x / 2.0f;};
	virtual float right() { return this->shape.getPosition().x + shape.getSize().x / 2.0f; };
	virtual float top() { return this->shape.getPosition().y - shape.getSize().y / 2.0f; };
	virtual float bottom() { return this->shape.getPosition().y + shape.getSize().y / 2.0f; };

	bool isDestroyed() { return this->destroyed; };
	void destroy() { this->destroyed = true; };
	Vector2f getSize() { return shape.getSize(); };
};

enum BLOCK_TYPES {
	NOT_DESTROYED,
	ORDINARY,
	WITH_BONUS,
	INCREASE_SPEED,
	WITH_HEALTH
};

class Block : public Rectangle {
public:
	Block(int x, int y, float blockWidth, float blockHeight) : Rectangle(x, y, blockWidth, blockHeight) {}
	struct {
		Color color[3] = { Color(255, 127, 80), Color(255, 99, 71), Color(255, 69, 0) };
		int lvl = 2;
	} withHealth;

	int type = ORDINARY;

	void SetColor(int type);
};