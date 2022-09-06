#include "game.h"

game::game(){
	1 + 5;
}

void game::StartGame(){
	sf::RenderWindow window(sf::VideoMode(500, 500), "Gems");

	std::cout << "noga" << std::endl;


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		fild.buildPlayground();
		fild.printPlayground();
		window.display();

		1 + 2;
	}
}