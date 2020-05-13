#pragma once
#include<SFML/Graphics.hpp>

class Collider
{
	
public:
	Collider(sf::Sprite *michel);
	~Collider();
	void Move(float dx, float dy);
	bool CheckCollision(Collider *jacque, float repoussement);
	sf::Vector2f GetPosition();
	sf::FloatRect GetHitBox();

protected:
	sf::Sprite *michel;
};


