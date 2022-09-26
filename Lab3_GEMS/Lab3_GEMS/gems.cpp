#include "gems.h"

void gem::printGem(int x, int y, sf::RenderWindow* window) {
	sf::ConvexShape convex;

	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
	convex.setPoint(1, sf::Vector2f(static_cast<float>(x) + 50, static_cast<float>(y)));
	convex.setPoint(2, sf::Vector2f(static_cast<float>(x) + 50, static_cast<float>(y) + 50));
	convex.setPoint(3, sf::Vector2f(static_cast<float>(x), static_cast<float>(y) + 50));
	convex.setFillColor(gem::gem_color);

	window->draw(convex);
}