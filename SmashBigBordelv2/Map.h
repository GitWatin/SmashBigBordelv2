#pragma once
#include "Plateforme.h"
#include "Back_Ground.h"
#include"Collisionneur.h"
#include <iostream>
class Map
{
public:

	Map(int plateforme);
	~Map(void);
	virtual void setBackground() = 0;
	virtual void setPlatefomes() = 0;
	virtual sf::Vector2f* getVue() = 0;
	int countPlatforms();
	Plateforme* getPlatform(int pos);
	virtual std::vector< Plateforme* >GetVectorPlatefomes();
	Back_Ground* getBackground();


protected:

	std::vector < Plateforme* > plateformes;
	sf::Vector2f *size;
	Back_Ground *BackGround;

};
