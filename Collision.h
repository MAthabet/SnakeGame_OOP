#pragma once
class Collision
{
	bool collided;
public:
	bool checkCollision();
	void handleCollision();
private:
	bool checkCollisionWithWindow();
	bool checkSelfCollision();
	bool checkCollisionWithCollectable();
	bool checkCollisionWithBoundry();
};