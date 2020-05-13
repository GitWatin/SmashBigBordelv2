#include "Collisionneur.h"

Collisionneur::Collisionneur(sf::Sprite &michel) : michel(michel)
{

}

Collisionneur::~Collisionneur( )
{
}

void Collisionneur::Move(float dx, float dy)
{
	michel.move(dx, dy);
}

bool Collisionneur::CheckCollision(Collisionneur & jacque, float repoussement)
{
	sf::Vector2f jacquePosition = jacque.GetPosition();
	sf::FloatRect jacqueHitBox= jacque.GetHitBox();
	sf::Vector2f thisPosition = GetPosition();
	sf::FloatRect thisHitBox = GetHitBox();

	float deltaX = jacquePosition.x - thisPosition.x;
	float deltaY = jacquePosition.y - thisPosition.y;

	float intersectionX = abs(deltaX) - (jacqueHitBox.width + thisHitBox.width);
	float intersectionY = abs(deltaY) - (jacqueHitBox.height + thisHitBox.height);

	if (jacquePosition.x < thisPosition.x + thisHitBox.width && thisPosition.x < jacquePosition.x + jacqueHitBox.width && jacquePosition.y < thisPosition.y + thisHitBox.height && thisPosition.y < jacquePosition.y + jacqueHitBox.height)
	{
		repoussement = std::min(std::max(repoussement, 0.0f), 1.0f);

		if (intersectionX > intersectionY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectionX * (1.0f - repoussement), 0.0f);
				jacque.Move(-intersectionX * (1.0f - repoussement), 0.0f);

			}
			else
			{
				Move(-intersectionX * (1.0f - repoussement), 0.0f);
				jacque.Move(intersectionX * (1.0f - repoussement), 0.0f);
			}
			if (deltaY > 0.0f)
			{
				Move(intersectionY * (1.0f - repoussement), 0.0f);
				jacque.Move(-intersectionY * (1.0f - repoussement), 0.0f);

			}
			else
			{
				Move(-intersectionY * (1.0f - repoussement), 0.0f);
				jacque.Move(intersectionY * (1.0f - repoussement), 0.0f);
			}
		}

		return true;
	}

	return false;
}

sf::Vector2f Collisionneur::GetPosition()
{
	return michel.getPosition();
}

sf::FloatRect Collisionneur::GetHitBox()
{
	return  michel.getGlobalBounds().contains;
}
