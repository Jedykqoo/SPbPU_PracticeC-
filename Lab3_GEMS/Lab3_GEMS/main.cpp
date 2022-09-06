#include "game.h"


int main() {
	//game newGame;

	//newGame.StartGame();

	sf::RenderWindow window(sf::VideoMode(500, 500), "Gems");
	sf::RenderWindow& win = window;

	std::cout << "noga" << std::endl;

	gem odin_gem(sf::Color::Blue);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		odin_gem.printGem(25, -25, win);
		window.display();

		1 + 2;
	}

	return 0;
}