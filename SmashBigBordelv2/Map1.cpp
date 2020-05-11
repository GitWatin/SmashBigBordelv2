#pragma once
#include "Map1.h"
#include "TextureManager.h"
#include "Map.h"
#include <iostream>


Map1::Map1(): Map(1)
{
}
void Map1::setPlatefomes()
{
	TextureManager *t;
	t = new TextureManager();

	this->getPlatform(0)->setPosition(0, 0);
	this->getPlatform(0)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(0)->setTextureRect(sf::IntRect(0, 0, 100, 20));

	/*
	this->getPlatform(1)->setPosition(0, 0);
	this->getPlatform(1)->setLargeur(100);
	this->getPlatform(1)->setHauteur(20);
	this->getPlatform(1)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(1)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(2)->setPosition(0, 0);
	this->getPlatform(2)->setLargeur(100);
	this->getPlatform(2)->setHauteur(20);
	this->getPlatform(2)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(2)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(3)->setPosition(0, 0);
	this->getPlatform(3)->setLargeur(100);
	this->getPlatform(3)->setHauteur(20);
	this->getPlatform(3)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(3)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(4)->setPosition(0, 0);
	this->getPlatform(4)->setLargeur(100);
	this->getPlatform(4)->setHauteur(20);
	this->getPlatform(4)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(4)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(5)->setPosition(0, 0);
	this->getPlatform(5)->setLargeur(100);
	this->getPlatform(5)->setHauteur(20);
	this->getPlatform(5)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(5)->setTextureRect(sf::IntRect(0, 0, 100, 20));

	*/
}
std::string Map1::GetPath()
{
	return Path;
}
// Han ouais 




