#include "Plateforme.h"
#include "Map.h"
#include "Entite.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>


Plateforme::Plateforme(float position_x, float position_y, float taille_x, float taille_y)
{
	TextureManager *t;
	t = new TextureManager();

	this->setTexture(*t->SetTexture("plat2_tiny.png"));
	this->setTextureRect(sf::IntRect(0, 0, taille_x, taille_y));
	this->setOrigin(taille_x / 2, taille_y / 2);
	this->setPosition(position_x, position_y);
	std::cout << "[Plateforme]: bordure" << std::endl;
	delete t;
}

Plateforme::Plateforme()
{
	;
}

Plateforme::~Plateforme()
{
	;
}


