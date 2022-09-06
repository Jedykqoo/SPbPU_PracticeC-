#include "gems.h"

void gem::printGem(int x, int y, sf::RenderWindow& window) {
	std::cout << "printGem()\nx = " << x << "\ny = " << y << std::endl;////////
	sf::CircleShape gem(50,0);
	gem.setPosition(static_cast<float>(x), static_cast<float>(y));
	gem.setFillColor(gem::gem_color);
	window.draw(gem);
}