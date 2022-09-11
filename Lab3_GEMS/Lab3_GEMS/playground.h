#pragma once
#include <vector>
#include <iostream>
#include "gems.h"
#include "SFML\Graphics.hpp"


class playground{
public:
	void buildPlayground();
	void printPlayground(sf::RenderWindow* window);
	void GemsSwap(int x1, int y1, int x2, int y2);
	void RemoveIdenticalNeighbors(int x1, int y1, int x2, int y2);
	void removeGem(int x, int y, int from_x, int to_x, int from_y, int to_y);
private:
	std::vector< std::vector<gem>> playground_matrix;
	std::vector<gem> gems;
	std::vector<sf::Color> colors = { sf::Color::Yellow, sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan};
	int gem_size = 50;
	int window_size_x = 500;
	int window_size_y = 500;
	int gem_amount_x = window_size_x / gem_size;
	int gem_amount_y = window_size_y / gem_size;
};
