#pragma once
#include "Map1.h"
#include "TextureManager.h"
#include "Map.h"
#include <iostream>


Map1::Map1(): Map(3) // PAS OUBLIE DE MODIFIER CE CHIFFRE PUT***
{
}
void Map1::setPlatefomes()
{
	TextureManager *t;
	t = new TextureManager();

	// Taille Plateforme : 
	// 1 : Grande : 1193*120
	// 2 : Petite : 448*90
	// 3 : Tiny : 268*90 

	// Plateforme principale dans le bas frère
	this->getPlatform(0)->setPosition(0, +350);
	this->getPlatform(0)->setTexture(*t->SetTexture(this->GetPath(1)));
	this->getPlatform(0)->setTextureRect(sf::IntRect(0, 0, 1193, 120));
	this->getPlatform(0)->setOrigin(this->getPlatform(0)->getGlobalBounds().width/2, this->getPlatform(0)->getGlobalBounds().height /2);


	// Plateforme 1 en haut à gauche

	this->getPlatform(1)->setPosition(-400, 0);
	this->getPlatform(1)->setTexture(*t->SetTexture(this->GetPath(2)));
	this->getPlatform(1)->setTextureRect(sf::IntRect(0, 0, 448, 90));
	this->getPlatform(1)->setOrigin(this->getPlatform(1)->getGlobalBounds().width/2, this->getPlatform(1)->getGlobalBounds().height/2);

	// Plateforme 2 
	this->getPlatform(2)->setPosition(+500, 0);
	this->getPlatform(2)->setTexture(*t->SetTexture(this->GetPath(3)));
	this->getPlatform(2)->setTextureRect(sf::IntRect(0, 0, 268, 90));
	this->getPlatform(2)->setOrigin(this->getPlatform(2)->getGlobalBounds().width/2, this->getPlatform(2)->getGlobalBounds().height/2);

	
	delete t;

}
void Map1::setBackground()
{
	TextureManager *t;
	t = new TextureManager();

	this->getBackground()->setTexture(*t->SetTexture(this->GetPathBackground()));
	this->getBackground()->setOrigin(Sx/2, Sy/2);

	delete t;
}
sf::Vector2f* Map1::getVue()
{
	size = new sf::Vector2f(Sx, Sy);
	return this->size;
}
std::string Map1::GetPath(int taille)
{
	if (taille == 1)
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
std::string Map1::GetPathBackground()
{
	return PathBackground;
}

// Han ouais 




