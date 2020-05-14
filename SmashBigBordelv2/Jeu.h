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
#include "Collisionneur.h"


class Jeu
{

public:
	
	// Constructeur et destructeur
	 Jeu ();
	 ~Jeu();

	 // Fenetre de jeu
	 sf::RenderWindow* GetWindow();

	 // --------------- Fonctions -----------------
	 virtual void setDureeIteration();
	 virtual void CheckInput(sf::Event event);
	 virtual void CheckModif();
	 virtual void ChargementJeu(Map *map);
	 virtual void ChoixMap();
	 virtual void ChoixPerso();
	 virtual void Animate(Personnage *perso, std::string direction);
	 virtual void CheckVictory();
	 void PersoGagne(Personnage * perso1choisi, Personnage * perso2choisi);
	 void CheckCollision(Personnage *michel);
	 void CheckAttaque(Personnage *michel);
	 virtual void CallModif();
	 virtual void DrawPersonnage(std::vector < Personnage* > Dessin);
	 virtual void DrawPlateforme(std::vector < Plateforme* > Dessin);
	 virtual void DrawBackGround(Back_Ground *BackGround);
	 void SetView(sf::Vector2f* size);
	 virtual sf::Time GetdureeIteration();
	 virtual void CreateHUD();
	 void SetHUD();
	 virtual void Timing();
	 virtual void CountDown();
	 Map* GetMapChoisie();
	 Personnage* GetPerso1choisi();
	 Personnage* GetPerso2choisi();
	 sf::View* GetView();
	 virtual void DrawHUD();
	 virtual void StartMenu();
	

protected:

	// ----------------- Attributs ---------------

	float Timer;
	sf::RenderWindow *fenetre;
	sf::View *Vueprincipal;
	Map *mapchoisie;
	Personnage *perso1choisi;
	Personnage *perso2choisi;
	std::vector < sf::Drawable* > vectorHUD;
	std::vector < sf::Drawable* > Menu;

	// Constante
	const int VitesseDeplacement = 150;//  pixel/sec
	const int VitesseSaut = 300;
	const int Gravity = 10;
	const float Spawn_x1 = -100;
	const float Spawn_y1 = -300;
	const float Spawn_x2 = 100;
	const float Spawn_y2 = -300;

	// Label HUD
	sf::Sprite *avatar1;
	sf::Text *NomPerso1;
	sf::Text *ViePerso1;
	sf::Text *BouclierPerso1;
	sf::Text *AtoutPerso1;
	sf::Text *PourcentPerso1;
	sf::Text *Perso1;
	sf::Text *Perso2;
	sf::Text *HUDTimer;
	sf::Sprite *Winner;
	sf::Sprite *avatar2;
	sf::Text *NomPerso2;
	sf::Text *ViePerso2;
	sf::Text *BouclierPerso2;
	sf::Text *AtoutPerso2;
	sf::Text *PourcentPerso2;
	int minute;
	int secondes;
	float temporary_time;
	float TempsDeJeu;


	// Sprite pour le menu
	sf::Sprite *MenuMap1;
	sf::Sprite *MenuMap2;
	sf::Text *Joueur1;
	sf::Text *Joueur2;
	sf::Text *SelectedMap;
	sf::Sprite *MenuJ1Rick;
	sf::Sprite *MenuJ1Morty;
	sf::Sprite *MenuJ2Rick;
	sf::Sprite *MenuJ2Morty;
	sf::Sprite *Play;
	int choix;
	int choix1;
	int choix2;

	sf::Time dureeIteration;

	sf::Clock *clock;

	// Clock timer général
	sf::Clock *clock_jeu;
	sf::Time timer_jeu;

	sf::Clock *clock_HUD;
	sf::Time timer_HUD;

	sf::Clock *clock_Depart;
	sf::Time timer_Depart;

	// Attribut pour la gestion des mouvements
	sf::Clock *clock_Move;
	sf::Time timer_Move;
	int Iteration;
	int Iteration2;
	int sens;

	int LastTimePerso1;
	int LastTimePerso2;

	std::string NomTextureMove;
	// Variable état jeu if false = jeu terminé
	bool Game_State = true;
	bool Game_State_Final;
	bool Perso1Bord;
	bool Perso2Bord;
	bool CountDownDone;
	int CountDownInt;

};

