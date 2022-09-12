#include "game.h"

void game::Drow() {
	window->clear();
	fild.printPlayground(window);

	window->display();
}

void game::Update(int elapsed) {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonReleased:
			MovingGems(event);
			fild.rebuild();
			break;
		}
	}
}

void game::StartGame(){
	sf::Clock clc;
	fild.buildPlayground();
	
	while (window->isOpen()) {
		int elapsed = clc.restart().asMilliseconds();
		Update(elapsed);

		Drow();
	}
}

void game::SelectFirstGem(sf::Event event) {
	if (event.mouseButton.button == sf::Mouse::Left){
		sf::Vector2i localPositionFirstGem = sf::Mouse::getPosition();
		float x_size = 50, y_size = 50;

		gemFirstX = static_cast<int>(event.mouseButton.x / x_size);
		gemFirstY = static_cast<int>(event.mouseButton.y / y_size);

		Click = true;
	}
}

void game::SelectSecondGem(sf::Event event) {
	if (event.mouseButton.button == sf::Mouse::Left){
		float x_size = 50, y_size = 50;

		gemSecondX = static_cast<int>(event.mouseButton.x / x_size);
		gemSecondY = static_cast<int>(event.mouseButton.y / y_size);

		Gems—ombination();
		
		Click = false;
	}
	if (event.mouseButton.button == sf::Mouse::Right){
		Click = false;
	}
}

void game::Gems—ombination() {
	if (isNearbyGems(gemFirstX, gemFirstY, gemSecondX, gemSecondY)) {
		fild.GemsSwap(gemFirstX, gemFirstY, gemSecondX, gemSecondY);
		fild.RemoveIdenticalNeighbors(gemFirstX, gemFirstY, gemSecondX, gemSecondY);
	}
}

void game::MovingGems(sf::Event event) {
	if (!Click) {
		SelectFirstGem(event);
	}
	else {
		SelectSecondGem(event);
	}
}

bool game::isNearbyGems(int gemFirstX, int gemFirstY, int gemSecondX, int gemSecondY) {
	return abs(gemFirstX - gemSecondX) + abs(gemFirstY - gemSecondY) == 1;
}
