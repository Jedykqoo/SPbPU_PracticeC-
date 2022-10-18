#include "Controller.h"

void StartGame() {
	GameController game;
	game.SetBlocksToDefualt();

	while (game.window.isOpen()){
		sf::Event event;
		game.window.pollEvent(event);

		if (event.type == sf::Event::Closed){
			game.window.close();
		}

		game.window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			break;
		}

		game.RunGame();
		game.DrawField();
	}
}

int main() {
	StartGame();
	return 0;
}