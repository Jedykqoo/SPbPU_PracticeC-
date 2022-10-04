#pragma once

#include"Ball.h"

bool Circle::update(unsigned int winWidth, unsigned int winHeight) {
    shape.move(this->velocity);

    if (this->left() < 0) {
        velocity.x = ballVelocity;
    }
    else if (this->right() > winWidth) {
        velocity.x = -ballVelocity;
    }
    else if (this->top() < 0) {
        velocity.y = ballVelocity;
    }
    else if (this->bottom() > winHeight) {
        return false;
    }

    return true;
}

Circle::Circle(int x, int y) {
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
    shape.setRadius(this->ballRadius);
    shape.setFillColor(color);
    shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::SpeedDown() {
    ballVelocity -= 1.5f;
    velocity = { ballVelocity, ballVelocity };
}

Ball::Ball(int x, int y) : Circle(x, y){

}