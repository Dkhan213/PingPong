#include "Ball.h"

Ball::Ball(float x, const int windowHeight, const float baseBallVelocity) : windowHeight(windowHeight) {
	ball.setRadius(10);
	ball.setPosition(x, windowHeight / 2 - 50);
	ball.setFillColor(sf::Color::White);
	dx = baseBallVelocity;
	dy = baseBallVelocity;
}

const sf::CircleShape& Ball::get() const {
	return ball;
}

void Ball::move() {
	ball.move(dx, dy);
}
void Ball::collisionDetection(Paddle& leftPaddle, Paddle& rightPaddle) {
	if (ball.getGlobalBounds().intersects(leftPaddle.get().getGlobalBounds()) ||
		ball.getGlobalBounds().intersects(rightPaddle.get().getGlobalBounds())) {
		dx = -dx;
	}

	if (ball.getPosition().y <= 0 || ball.getPosition().y >= windowHeight - 20)
		dy = -dy;
}
