#pragma once
#include "playground.h"
#include "gems.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <time.h>
#include <cmath>

class game {
public:
	game() {
		window = new sf::RenderWindow(sf::VideoMode(500, 500), "Gems");
		Click = false;
		gemFirstX = gemFirstY = gemSecondX = gemSecondY = 0;
	}
	void StartGame();
private:
	sf::RenderWindow* window;
	playground fild;

	void Drow();
	void Update(int elapsed);
	void SelectFirstGem(sf::Event event);
	void SelectSecondGem(sf::Event event);
	void Gems—ombination();
	void MovingGems(sf::Event event);
	bool isNearbyGems(int gemFirstX, int gemFirstY, int gemSecondX, int gemSecondY);

	int gemFirstX, gemFirstY, gemSecondX, gemSecondY;

	bool Click;
};