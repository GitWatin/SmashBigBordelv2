#include "Map2.h"
#include "TextureManager.h"

Map2::Map2() : Map(1)
{
}
void Map2::setPlatefomes()
{
	TextureManager *t;
	t = new TextureManager();

	// Taille Plateforme : 
	// 1 : Grande : 1193*120
	// 2 : Petite : 448*90
	// 3 : Tiny : 268*90 

	// Plateforme principale dans le bas fr�re
	this->getPlatform(0)->setPosition(0, +350);
	this->getPlatform(0)->setTexture(*t->SetTexture(this->GetPath(1)));
	this->getPlatform(0)->setTextureRect(sf::IntRect(0, 0, 1123, 115));
	this->getPlatform(0)->setOrigin(this->getPlatform(0)->getGlobalBounds().width / 2, this->getPlatform(0)->getGlobalBounds().height / 2);


	delete t;

}
void Map2::setBackground()
{
	TextureManager *t;
	t = new TextureManager();

	this->getBackground()->setTexture(*t->SetTexture(this->GetPathBackground()));
	this->getBackground()->setOrigin(this->getBackground()->getGlobalBounds().width/2, this->getBackground()->getGlobalBounds().height/2);
	// Image en 1920*1080 donc scale la texture pour adapter
	this->getBackground()->setScale(0.834, 0.834);

	delete t;
}

sf::Vector2f *Map2::getVue()
{
	size = new sf::Vector2f(Sx, Sy);
	return this->size;
}
std::string Map2::GetPath(int taille)
{
	if(taille == 1)
	{
		std::cout << "[GRANDE]:" << std::endl;
		return PathPlateformeGrande;


	}
	else if (taille == 2)
	{
		std::cout << "[HAN OUAIS]:" << std::endl;
		return PathPlateformePetite;

	}
	else if (taille == 3)
	{
		return PathPlateformeTiny;
	}
	else
	{
		return PathPlateformePetite; // return plateforme par defaut ( a changer si jamais ) 
	}

}
std::string Map2::GetPathBackground()
{
	return PathBackground;
}
