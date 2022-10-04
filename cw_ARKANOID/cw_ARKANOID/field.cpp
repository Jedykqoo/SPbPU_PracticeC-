#include "field.h"

Playground::Playground(int x, int y, float blockWidth, float blockHeight) {
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
    shape.setSize(Vector2f{ blockWidth, blockHeight });
    shape.setFillColor(Color(169, 169, 169));
    shape.setOrigin(blockWidth / 2, blockHeight / 2);
}

void Playground::draw(RenderTarget& target, RenderStates state) const {
    target.draw(this->shape, state);
}

float Playground::left() {
    return this->shape.getPosition().x - shape.getSize().x / 2;
}

float Playground::right() {
    return this->shape.getPosition().x + shape.getSize().x / 2;
}

float Playground::top() {
    return this->shape.getPosition().y - shape.getSize().y / 2;
}

float Playground::bottom() {
    return this->shape.getPosition().y + shape.getSize().y / 2;
}

Vector2f Playground::getPosition() {
    return shape.getPosition();
}
