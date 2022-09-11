#include "playground.h"

void playground::buildPlayground(){
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < gem_amount_x; i++) {
		std::vector <gem> temporary_vector;
		for (int j = 0; j < gem_amount_y; j++) {
			// передавать кол-во цветов 6
			switch (static_cast<int>(rand() / (static_cast<double>(RAND_MAX) + 1.0) * 6)) {
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
			x = gem_size * i;
			y = gem_size * j;
			playground_matrix[i][j].printGem(x, y, window);
		}
	}
}

void playground::GemsSwap(int x1, int y1, int x2, int y2) {
	sf::Color color_1, color_2;
	
	color_1 = playground_matrix[x1][y1].GetColor();
	color_2 = playground_matrix[x2][y2].GetColor();

	playground_matrix[x1][y1].SetColor(color_2);
	playground_matrix[x2][y2].SetColor(color_1);
}

void playground::RemoveIdenticalNeighbors(int x1, int y1, int x2, int y2) {
	sf::Color Color1 = playground_matrix[x1][y1].GetColor(), Color2 = playground_matrix[x2][y2].GetColor();
	int left1, right1, up1, down1; // number 1 matching item
	int left2, right2, up2, down2;
	left1 = right1 = up1 = down1 = left2 = right2 = up2 = down2 = 0;

	int i = x1;
	int j = y1;

	while (i >= 0) {
		if (playground_matrix[i][y1].GetColor() == Color1){
			left1 = i;
			i--;
		}
		else {
			left1 = i + 1;
			break;
		}
	}
	i = x1;
	while (i < 10) {
		if (playground_matrix[i][y1].GetColor() == Color1){
			right1 = i;
			i++;
		}
		else {
			right1 = i - 1;
			break;
		}
	}
	while (j >= 0) {
		if (playground_matrix[x1][j].GetColor() == Color1){
			up1 = j;
			j--;
		}
		else {
			up1 = j + 1;
			break;
		}
	}
	j = y1;
	while (j < 10) {
		if (playground_matrix[x1][j].GetColor() == Color1){
			down1 = j;
			j++;
		}
		else {
			down1 = j - 1;
			break;
		}
	}

	i = x2;
	while (i >= 0) {
		if (playground_matrix[i][y2].GetColor() == Color2){
			left2 = i;
			i--;
		}
		else {
			left2 = i + 1;
			break;
		}
	}
	i = x2;
	while (i < 10) {
		if (playground_matrix[i][y2].GetColor() == Color2) {
			right2 = i;
			i++;
		}
		else {
			right2 = i - 1;
			break;
		}
	}
	j = y2;
	while (j >= 0) {
		if (playground_matrix[x2][j].GetColor() == Color2) {
			up2 = j;
			j--;
		}
		else {
			up2 = j + 1;
			break;
		}
	}
	j = y2;
	while (j < 10) {
		if (playground_matrix[x2][j].GetColor() == Color2){
			down2 = j;
			j++;
		}
		else {
			down2 = j - 1;
			break;
		}
	}
	if ((abs(left1 - right1) + abs(up1 - down1)) > 0)
		removeGem(x1, y1, left1, right1, up1, down1);

	if ((abs(left2 - right2) + abs(up2 - down2)) > 0)
		removeGem(x2, y2, left2, right2, up2, down2);
}

void playground::removeGem(int x, int y, int from_x, int to_x, int from_y, int to_y) {
	for (int i = from_x; i <= to_x; i++) {
		playground_matrix[i][y].SetColor(sf::Color::Black);
	}
	for (int j = from_y; j <= to_y; j++) {
		playground_matrix[x][j].SetColor(sf::Color::Black);
	}
}
