#pragma once
#include<SFML/Graphics.hpp>
class Collisionneur
{
public:
	Collisionneur(sf::Sprite &michel);
	~Collisionneur();
	void Move(float dx, float dy);
	bool CheckCollision(Collisionneur &jacque, float repoussement);
	sf::Vector2f GetPosition();
	sf::FloatRect GetHitBox();

protected:
	sf::Sprite michel;
};

