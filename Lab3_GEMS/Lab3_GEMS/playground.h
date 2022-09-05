#pragma once
#include <vector>
#include "gems.h"
#include "SFML\Graphics.hpp"

class playground{
public:
	void buildPlayground();
	int GetAmountX() {
		return gem_amount_x;
	}
private:
	std::vector< std::vector<gem>> playground_matrix;
	std::vector<gem> gems;
	std::vector<sf::Color> colors = { sf::Color::Yellow, sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan , sf::Color::Black};
	int window_size_x = 500;
	int window_size_y = 500;
	int gem_amount_x = window_size_x / gems[0].GetSizeGem();
	int gem_amount_y = window_size_y / gems[0].GetSizeGem();
};
