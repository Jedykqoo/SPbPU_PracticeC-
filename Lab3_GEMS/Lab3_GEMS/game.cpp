#include "game.h"

void game::Drow() {
	window->clear();
	fild.printPlayground(window);

	window->display();
}

void game::Update(int elapsed) {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
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