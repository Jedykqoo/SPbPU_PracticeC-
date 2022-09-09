#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

class gem {
public:
	gem(sf::Color color) {
		gem_color = color;
	}
	int GetSizeGem(){
		return gem_size;
	}
	void printGem(int x, int y, sf::RenderWindow* window);
private:
	int gem_size = 50;
	sf::Color gem_color;
};

