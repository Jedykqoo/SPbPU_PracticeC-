#pragma once
#include "playground.h"
#include "gems.h"
#include "SFML\Graphics.hpp"
#include <iostream>

class game {
public:
	game();
	void StartGame();
private:
	playground fild;
};