#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entite.h"
#include "Personnage.h"
#include "Jeu.h"


class HUD: public Jeu
{
public:
	HUD();
	~HUD();

	virtual void CallHUD();

protected:

	sf::Text *ViePerso;
	sf::Text *BouclierPerso;
	sf::Text *AtoutPerso;
	sf::Text *VieTimer;

};

