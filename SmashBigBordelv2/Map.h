#pragma once
#include "Plateforme.h"
#include "Back_Ground.h"
#include "Limite.h"
#include "Jeu.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
class Map
{
public:

	Map(int plateforme);
	~Map(void);
	virtual void setBackground() = 0;
	virtual void setPlatefomes() = 0;
	int countPlatforms();

	Plateforme* getPlatform(int pos);
	virtual std::vector< Plateforme* >GetVectorPlatefomes();
	virtual std::vector< Limite* >GetlimiteMap();
	Back_Ground* getBackground();


protected:
	std::vector < Limite* > limiteMap;
	std::vector < Plateforme* > plateformes;
	Back_Ground *BackGround;
};
