// Ceci est un test github
//class---------------------------------------------

#include "Personnage.h"
//#include "AtoutPoids.h"
//#include "AtoutForce.h"
//#include "AtoutBouclier.h"
//#include "AtoutPourcentage.h"
//#include "HUD.h"
#include "Plateforme.h"
#include "Jeu.h"
#include "Map1.h"
#include "Map.h"


//Lib-----------------------------------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

void main(int argc, char ** argv[]);

void VerifPosition(Entite *Plat);

//Entite J;

//void GenerateurPlateforme();
//void GenerateurMap(Map mapouche);
//void GenerateurEntiteFixe(Entite *entite_fixe);

//cr�ation vector contenant tous les Entite
//std::vector < sf::Drawable* > mes_objets;		:	 Contenu dans Entite
//std::vector < Entite* > entite_fixe;			:	Contenu dans Entite
//sf::RectangleShape *back_ground;
//sf::CircleShape *point_reference;
//Taille de la vue si x=1600 ; y = 900 => vue 16:9
//float x=1600;
//float y=900;
//Rayon cercle reference
//float Rshape=10;
// Taille view
//float rect_game_x = x;
//float rect_game_y = y;

// Chargement de la texture (View totale)




void main(int argc,char** argv[])
{
	// Objet temps machine
	
	//---------------------------- Cr�ation de la fen�tre -----------------------------------------
	

	Jeu Game;
	
	//window = new sf::RenderWindow (sf::VideoMode(1600, 900), "SmashBigBordel", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
	//window->setFramerateLimit(60);
	
	//------------------------Cr�ation des Sprite ---------------------------------------------
	// rect defini pour la plage de jeu
	//back_ground = new sf::RectangleShape (sf::Vector2f(rect_game_x,rect_game_y));
	//mes_objets.push_back(back_ground);
	//point_reference = new sf::CircleShape(Rshape);
	//point_reference->setFillColor(sf::Color::Green);
	
	Game.StartMenu();

	Game.ChoixMap();
	Game.ChargementJeu(Game.GetMapChoisie()); // Chargement une fois 
	Game.ChoixPerso();
	Game.CreateHUD(); // Cr�ation de l'interface HUD

	//----------------------------- Boucle du jeu --------------------------------------------------
	while (Game.GetWindow()->isOpen())
	{
		
		Game.setDureeIteration();

		sf::Event event;
		//------------------------------- Gestion des �v�nements -------------------------------
		while (Game.GetWindow()->pollEvent(event))
		{
			Game.CheckInput(event);
			
			if (event.type == sf::Event::Closed)
				Game.GetWindow()->close();
		}
		//-------------------------------- Modification des �tats des objets--------------------
		Game.SetView(Game.GetMapChoisie()->getVue());
		Game.CheckModif();
		Game.CheckCollision(Game.GetPerso1choisi());
		Game.CheckCollision(Game.GetPerso2choisi());
		Game.CallModif();
		Game.CheckVictory();
			//center les coordon� 2D de la window au centre de la vue  // Taille de la vue si x=1600 ; y = 900 => vue 16:9
		

		//back_ground->setPosition((-rect_game_x/2),(-rect_game_y/2)); //Rectangle de fond positionner au milieur de la vue
		//point_reference->setPosition((-Rshape / 2), (-Rshape / 2));//Cercle vert positionner au milieur de la vue R�f�rence

		//-------------------------------- Effacer le contenu de la fen�tre----------------------

		Game.GetWindow()->clear();

		//-------------------------------- Liaison des objets graphiques � la fen�tre------------

		Game.GetWindow()->setView(*Game.GetView());
		Game.DrawBackGround(Game.GetMapChoisie()->getBackground());
		Game.DrawPlateforme(Game.GetMapChoisie()->GetVectorPlatefomes());
		Game.DrawPersonnage(Game.GetPerso1choisi()->GetVectorPersonnage());
		Game.DrawPersonnage(Game.GetPerso2choisi()->GetVectorPersonnage());
		Game.DrawHUD();
		Game.GetWindow()->display();

	}
	
}

void VerifPosition(Entite *Plat)
{
	float X = Plat->getPosition().x;
	float Y = Plat->getPosition().y;

	float tx = Plat->getScale().x;
	float ty = Plat->getScale().y;

	std::cout << "[Valeur de la position de l'objet]:"<< X << std::endl;
	std::cout << "[Valeur de la position de l'objet]:" << Y << std::endl;
	
	std::cout << "[Valeur de la Taille de l'objet]:" << tx << std::endl;
	std::cout << "[Valeur de la Taille de l'objet]:" << ty << std::endl;

}


		