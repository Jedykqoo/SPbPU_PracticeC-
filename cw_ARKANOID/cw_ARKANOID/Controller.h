#pragma once
#include "field.h"
#include "Ball.h"
#include "Platform.h"
#include "Blocks.h"
#include "Bonus.h"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class GameController{
private:
	int blocksX = 8, blocksY = 7, blockWidth = 80, blockHeight = 20;
	int windowWidth = 800, windowHeight = 600, frameLimit = 60;
	Clock Clock;
	Sprite gamePlayBackground, gameOverBackground, gameWinnerBackground;
	Texture gamePlayBackgroundTexture, gameOverBackgroundTexture, gameWinnerBackgroundTexture;
	Font font;
	Text tScore, esc, tHealth;
	string printScore = "Score : ";
	string printHealth = "Health : ";

	bool IsCollisionBlock(Block& block, Ball& ball);
	bool IsCollisionPaddle(GameObject& paddle, Ball& ball);
	bool IsIntersecting(GameObject& obj1, GameObject& obj2);
	bool testCollision(Paddle& racket, Bonus& bonus);
	void testCollision(Ball& white, Ball& red);
	void HandleCollisionBlock(Block& block, Ball& ball);

	int health = 0;
public:
	int score = 0;
	RenderWindow window{ VideoMode(windowWidth, windowHeight), "Arkanoid", Style::Titlebar | Style::Close };
	Bonus bonus{ 400, 300 };
	vector<Ball> balls;
	Paddle paddle{ static_cast<int>(windowWidth / 2.f), static_cast<int>(windowHeight - 20.f) };
	vector<Block> blocks;

	void RunGame();
	void SetBlocksToDefualt();
	void DrawField();
	void StartBonus(int it);

	GameController() {
		tScore.setString(printScore + to_string(score));
		tScore.setPosition(Vector2f(0, 0));
		tScore.setCharacterSize(16);
		tScore.setFillColor(Color::White);

		tHealth.setString(printHealth + to_string(3 - health));
		tHealth.setPosition(Vector2f(100, 0));
		tHealth.setCharacterSize(16);
		tHealth.setFillColor(Color::White);

		esc.setCharacterSize(15);
		esc.setPosition(7, static_cast<float>(windowHeight - 20));
		esc.setString("Press Esc for exit");
		esc.setFillColor({ 255,255,255,150 });

		window.setFramerateLimit(frameLimit);
		balls.emplace_back(300, 300);
	}
};