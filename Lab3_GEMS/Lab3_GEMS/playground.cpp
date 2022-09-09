#include "playground.h"


void playground::buildPlayground(){
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < gem_amount_x; i++) {
		std::vector <gem> temporary_vector;
		for (int j = 0; j < gem_amount_y; j++) {
			std::cout << "buildPlayground()\ni = " << i << "\nj = " << j << std::endl;////////
			// передавать кол-во цветов 7
			switch (static_cast<int>(rand() / (static_cast<double>(RAND_MAX) + 1.0) * 7)) {
			case 0:
				temporary_vector.push_back(sf::Color::Yellow);
				std::cout << "Color is Yellow\n"<< std::endl;
				break;
			case 1:
				temporary_vector.push_back(sf::Color::Blue);
				std::cout << "Color is Blue\n" << std::endl;
				break;
			case 2:
				temporary_vector.push_back(sf::Color::White);
				std::cout << "Color is White\n" << std::endl;
				break;
			case 3:
				temporary_vector.push_back(sf::Color::Green);
				std::cout << "Color is Green\n" << std::endl;
				break;
			case 4:
				temporary_vector.push_back(sf::Color::Magenta);
				std::cout << "Color is Magenta\n" << std::endl;
				break;
			case 5:
				temporary_vector.push_back(sf::Color::Cyan);
				std::cout << "Color is Cyan\n" << std::endl;
				break;
			case 6:
				temporary_vector.push_back(sf::Color::Black);
				std::cout << "Color is Black\n" << std::endl;
				break;
			}
		}
		playground_matrix.push_back(temporary_vector);
		temporary_vector.clear();
	}
}

void playground::printPlayground(sf::RenderWindow* window) {
	int x, y;
	for (int i = 0; i < gem_amount_x; i++) {
		for (int j = 0; j < gem_amount_y; j++) {
			std::cout << "printPlayground()\ni = " << i << "\nj = " << j << std::endl;////////
			x = gem_size * i;
			y = gem_size * j;
			playground_matrix[i][j].printGem(x, y, window);
		}
	}
}