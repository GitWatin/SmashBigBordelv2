#include "Map.h"
#include "Plateforme.h"
#include "Jeu.h"
#include "TextureManager.h"
#include "Entite.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

Map::Map(int plateforme)
{
	this->BackGround = new Back_Ground();
	while (plateforme+4) 
	{
		this->plateformes.push_back(new Plateforme());// TODO créer un constructeur vide ?
		plateforme--;
	}
	
	
}

Map::~Map(void)
{
	for (int i = 0; i < plateformes.size(); i++) // suppression des plateforme
	{
		delete plateformes.back();
		plateformes.pop_back();
	}
	delete BackGround;
}

int Map::countPlatforms() {
	return this->plateformes.size();
}

Plateforme * Map::getPlatform(int pos)
{
	return this->plateformes[pos];
}

std::vector< Plateforme* > Map::GetVectorPlatefomes()
{
	return plateformes;
}

Back_Ground* Map::getBackground()
{
	return BackGround;
}

