#pragma once
#include "Map1.h"
#include "TextureManager.h"
#include "Map.h"
#include <iostream>


Map1::Map1(): Map(5)
{
}
void Map1::setPlatefomes()
{
	TextureManager *t;
	t = new TextureManager();

	this->getPlatform(0)->setPosition(0, 0);
	this->getPlatform(0)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(0)->setTextureRect(sf::IntRect(0, 0, 100, 20));

	
	this->getPlatform(1)->setPosition(100, 300);
	this->getPlatform(1)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(1)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(2)->setPosition(-100, 200);
	this->getPlatform(2)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(2)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(3)->setPosition(50, 20);
	this->getPlatform(3)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(3)->setTextureRect(sf::IntRect(0, 0, 100, 20));


	this->getPlatform(4)->setPosition(-500, 900);
	this->getPlatform(4)->setTexture(*t->SetTexture(this->GetPath()));
	this->getPlatform(4)->setTextureRect(sf::IntRect(0, 0, 1000, 50));

	delete t;

}
void Map1::setBackground()
{
	TextureManager *t;
	t = new TextureManager();

	this->getBackground()->setTexture(*t->SetTexture(this->GetPathBackground()));
	this->getBackground()->setOrigin(800, 450);
	this->getBackground()->scale(1.6, 1.6);


	delete t;
}
std::string Map1::GetPath()
{
	return Path;
}
std::string Map1::GetPathBackground()
{
	return PathBackground;
}

// Han ouais 




