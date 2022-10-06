#pragma once

#include"Platform.h"

Paddle::Paddle(int x, int y){
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
    shape.setSize({ this->width, this->height });
    shape.setFillColor(Color::Red);
    shape.setOrigin(width / 2.f, height / 2.f);
}

void Paddle::SetDefualtWidth(){
    this->width = 150.f;
    shape.setSize({ this->width, this->height });
    shape.setOrigin(width / 2.f, height / 2.f);
}

void Paddle::IncraseWidth(){
    this->width += 40.f;
    shape.setSize({ this->width, this->height });
    shape.setOrigin(width / 2.f, height / 2.f);
}

Vector2f Paddle::getPosition(){
    return shape.getPosition();
}

void Paddle::update(float winWidth){
    this->shape.move(this->velocity);

    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0){
        velocity.x = -paddleVelocity;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < winWidth){
        velocity.x = paddleVelocity;
    }
    else{
        velocity.x = 0.f;
    }
}