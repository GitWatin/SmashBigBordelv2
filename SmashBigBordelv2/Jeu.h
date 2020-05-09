#pragma once
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Entite.h"
#include "Map1.h"

class Jeu
{

public:
	 Jeu (sf::RenderWindow *window);
	 Jeu ();
	 virtual ~Jeu();

	 virtual void ChargementJeu(Map *map);
	 virtual void Draw(std::vector < sf::Drawable* > Dessin);
	//Get Return_Texture_Plateforme
	//Get Return_Texture_Map
protected:
	float Timer;
	sf::RenderWindow *fenetre;
	Map *mapouche;
	//sf::Texture Return_Texture_Plateforme;
	//sf::Texture Return_Texture_Map;

	// Attribut texture

};

