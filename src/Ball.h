#pragma once
#include<SFML/Graphics.hpp>
#include "Paddle.h"

class Ball {

private:
	sf::CircleShape ball;
	const int windowHeight;
	int dx;
	int dy;

public:
	Ball(float x, const int windowHeight, float baseBallSpeed);

	const sf::CircleShape& get() const;

	void move(float dt);

	void collisionDetection(Paddle& leftPaddle, Paddle& rightPaddle);
};

