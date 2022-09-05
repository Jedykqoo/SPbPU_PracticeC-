#include "playground.h"

void playground::buildPlayground(){
	srand(static_cast<unsigned int>(time(0)));
	playground a;
	for (int i = 0; i < gem_amount_x; i++) {
		std::vector <gem> temporary_vector;
		for (int j = 0; j < gem_amount_y; j++) {
			// передавать кол-во цветов 7
			switch (static_cast<int>(rand() / (static_cast<double>(RAND_MAX) + 1.0) * 7)) {
			case 0:
				temporary_vector.push_back(sf::Color::Yellow);
				break;
			case 1:
				temporary_vector.push_back(sf::Color::Blue);
				break;
			case 2:
				temporary_vector.push_back(sf::Color::White);
				break;
			case 3:
				temporary_vector.push_back(sf::Color::Green);
				break;
			case 4:
				temporary_vector.push_back(sf::Color::Magenta);
				break;
			case 5:
				temporary_vector.push_back(sf::Color::Cyan);
				break;
			case 6:
				temporary_vector.push_back(sf::Color::Black);
				break;
			}
		}
		playground_matrix.push_back(temporary_vector);
		temporary_vector.clear();
	}
}