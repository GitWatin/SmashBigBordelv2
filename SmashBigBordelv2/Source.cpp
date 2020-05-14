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


void main(int argc,char** argv[])
{
	// Objet temps machine
	
	//---------------------------- Création de la fenêtre -----------------------------------------
	
	Jeu Game;

	//------------------------Création des Sprite ---------------------------------------------

	Game.ChoixMap();
	Game.ChargementJeu(Game.GetMapChoisie()); // Chargement une fois 
	Game.ChoixPerso();
	Game.CreateHUD(); // Création de l'interface HUD

	//----------------------------- Boucle du jeu --------------------------------------------------
	while (Game.GetWindow()->isOpen())
	{
		
		Game.setDureeIteration();

		sf::Event event;
		//------------------------------- Gestion des évènements -------------------------------
		while (Game.GetWindow()->pollEvent(event))
		{
			Game.CheckInput(event);
			
			if (event.type == sf::Event::Closed)
				Game.GetWindow()->close();
		}
		//-------------------------------- Modification des états des objets--------------------
		Game.SetView(Game.GetMapChoisie()->getVue());//center les coordoné 2D de la window au centre de la vue  // Taille de la vue si x=1600 ; y = 900 => vue 16:9
		Game.CheckModif();
		Game.CheckCollision(Game.GetPerso1choisi());
		Game.CheckCollision(Game.GetPerso2choisi());
		Game.CallModif();
		 //center les coordoné 2D de la window au centre de la vue  // Taille de la vue si x=1600 ; y = 900 => vue 16:9
		


		//-------------------------------- Effacer le contenu de la fenêtre----------------------

		Game.GetWindow()->clear();

		//-------------------------------- Liaison des objets graphiques à la fenêtre------------

		Game.GetWindow()->setView(*Game.GetView());
		Game.DrawBackGround(Game.GetMapChoisie()->getBackground());
		//Game.DrawLimite(Game.GetMapChoisie()->GetlimiteMap());
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


		