#pragma once

#include <fstream>
#include "SFML\Graphics.hpp"

using namespace sf;

class GameObject {
public:
	virtual sf::Vector2f getPosition() = 0;

	virtual float left() = 0;
	virtual float right() = 0;
	virtual float top() = 0;
	virtual float bottom() = 0;
};

class Playground : public GameObject, public sf::Drawable {
public:
	virtual void draw(sf::RenderTarget& targer, sf::RenderStates states) const;

	RectangleShape shape;
	bool destroyed = false;
public:
	Playground(int x, int y, float blockWidth, float blockHeight);

	virtual  Vector2f getPosition();
	virtual float left();
	virtual float right();
	virtual float top();
	virtual float bottom();

	bool isDestroyed() { return this->destroyed; }
	void destroy() { this->destroyed = true; }
	Vector2f getSize() { return shape.getSize(); }
};