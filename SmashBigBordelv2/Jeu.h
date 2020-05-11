#pragma once
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Entite.h"
#include "Map1.h"

class Jeu
{

public:
	
	 Jeu ();
	 virtual ~Jeu();
	 sf::RenderWindow* GetWindow();

	 virtual void ChargementJeu(Map *map);
	 virtual void ChoixMap();
	 Map* GetMapChoisie();

	 sf::View* GetView();
	 void SetView(float TailleX, float TailleY);
	 


	 virtual void DrawEntite(std::vector < sf::Drawable* > Dessin);
	 virtual void DrawPlateforme(std::vector < Plateforme* > Dessin);
	 virtual void DrawBackGround(Back_Ground *BackGround);

	//Get Return_Texture_Plateforme
	//Get Return_Texture_Map
protected:
	float Timer;
	sf::RenderWindow *fenetre;
	sf::View *Vueprincipal;
	Map *mapchoisie;
	//sf::Texture Return_Texture_Plateforme;
	//sf::Texture Return_Texture_Map;

	// Attribut texture

};

