#pragma once
#include "SFML\Graphics.hpp"

class gem {
public:
	gem(sf::Color color) {
		gem_color = color;
	}
	int GetSizeGem(){
		return gem_size;
	}
private:
	int gem_size = 50;
	sf::Color gem_color;
};

