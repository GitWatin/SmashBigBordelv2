#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Entite.h"
#include "Morty.h"
#include "Rick.h"
#include "Map1.h"
#include "Map2.h"



class Jeu
{

public:
	
	 Jeu ();
	 ~Jeu();
	 sf::RenderWindow* GetWindow();


	 
	 virtual void CheckInput(sf::Event event);
	

	 virtual void ChargementJeu(Map *map);
	 virtual void ChoixMap();
	 virtual void ChoixPerso();

	 Map* GetMapChoisie();
	 Personnage* GetPerso1choisi();
	 Personnage* GetPerso2choisi();

	 sf::View* GetView();
	 void SetView(float TailleX, float TailleY);
	 
	 virtual void CallModif();
	 virtual void DrawPersonnage(std::vector < Personnage* > Dessin);
	 virtual void DrawPlateforme(std::vector < Plateforme* > Dessin);
	 virtual void DrawBackGround(Back_Ground *BackGround);

	 virtual void HUD();
	 virtual void Timing();

	 // Draw HUD
	 virtual void DrawHUD();


	//Get Return_Texture_Plateforme
	//Get Return_Texture_Map
protected:
	float Timer;
	sf::RenderWindow *fenetre;
	sf::View *Vueprincipal;
	Map *mapchoisie;
	Personnage *perso1choisi;
	Personnage *perso2choisi;
	std::vector < sf::Drawable* > vectorHUD;

	const int VitesseDeplacement = 120;//  pixel/sec
	sf::Text *ViePerso;
	sf::Text *BouclierPerso;
	sf::Text *AtoutPerso;
	sf::Text *HUDTimer;

	sf::String text_timer;

	sf::Time *dureeIteration;
	sf::Clock *clock;

	// Clock timer général
	sf::Clock *clock_jeu;

	// Variable état jeu if false = jeu terminé
	bool Game_State = true;

};

