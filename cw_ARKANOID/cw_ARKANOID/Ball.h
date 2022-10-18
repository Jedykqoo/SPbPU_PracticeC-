#pragma once

#include "field.h"
#include "SFML\Graphics.hpp"

class Circle : public GameObject, public Drawable {
protected:
    CircleShape shape;
    float ballRadius = 8.f;

    Color color = Color::White;

    void draw(RenderTarget& target, RenderStates state) const { target.draw(this->shape, state); }
public:
    float ballVelocity = 5.f;
    Vector2f velocity = { ballVelocity, ballVelocity };
    Circle(int x, int y);

    bool update(unsigned int winWidth, unsigned int winHeight);
    void updatePosition(float x, float y) { shape.setPosition(x, y); }
    void setPosition(Vector2f position) { shape.setPosition({ position.x, position.y - shape.getRadius() + 5.f }); }

    virtual Vector2f getPosition() { return shape.getPosition(); }
    virtual float left() { return this->shape.getPosition().x - shape.getRadius(); }
    virtual float right() { return this->shape.getPosition().x + shape.getRadius(); }
    virtual float top() { return this->shape.getPosition().y - shape.getRadius(); }
    virtual float bottom() { return this->shape.getPosition().y + shape.getRadius(); }
};

class Ball : public Circle {
public:
    Ball(int x, int y);

    void moveUp() { this->velocity.y = -ballVelocity; };
    void moveDown() { this->velocity.y = ballVelocity; };
    void moveRight(){ this->velocity.x = ballVelocity; };
    void moveLeft() { this->velocity.x = -ballVelocity; };

    void SpeedUp() { ballVelocity += 1.f; }
    void SetSpeedDefualt() { ballVelocity = 5.f; }
    void SpeedDown();
    void FollowPaddle(Vector2f vec) {shape.move(this->velocity);}
    void setPosition(Vector2f position) { shape.setPosition({ position.x, position.y - shape.getRadius() + 5.f });}
    void ReflectX() { velocity.x = -velocity.x; };
};