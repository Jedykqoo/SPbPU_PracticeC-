#pragma once
#include <vector>
#include <iostream>
#include "gems.h"
#include "SFML\Graphics.hpp"


class playground{
public:
	playground() {	};
	void buildPlayground();
	void printPlayground();

private:
	sf::RenderWindow window;
	std::vector< std::vector<gem>> playground_matrix;
	std::vector<gem> gems;
	std::vector<sf::Color> colors = { sf::Color::Yellow, sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan , sf::Color::Black};
	int gem_size = 50;
	int window_size_x = 500;
	int window_size_y = 500;
	int gem_amount_x = window_size_x / gem_size;
	int gem_amount_y = window_size_y / gem_size;
};
