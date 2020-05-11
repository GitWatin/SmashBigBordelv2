#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entite.h"
#include "Personnage.h"
#include "Jeu.h"


class HUD :
	public Jeu
{
public:
	HUD();
	~HUD();

	virtual void CallHUD();


	// Zone de texte pour le perso 1
	sf::Text *ViePerso;
	sf::Text *BouclierPerso;
	sf::Text *AtoutPerso;

	// Zone de texte pour le perso 2
	//sf::Text *ViePerso2;
	//sf::Text *BouclierPerso2;
	//sf::Text *AtoutPerso2;

	// Zone pour le timer
	sf::Text *VieTimer;

protected:


};

