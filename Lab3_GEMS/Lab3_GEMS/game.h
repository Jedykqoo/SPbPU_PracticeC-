#pragma once
#include "playground.h"
#include "gems.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <time.h>

class game {
public:
	game() {
		window = new sf::RenderWindow(sf::VideoMode(500, 500), "Gems");
	}
	void StartGame();
private:
	sf::RenderWindow* window;
	playground fild;
	void Drow();
	void Update(int elapsed);
};