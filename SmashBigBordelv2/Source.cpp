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

void VerifPosition(Entite *Plat);
Entite J;

//void GenerateurPlateforme();
//void GenerateurMap(Map mapouche);
//void GenerateurEntiteFixe(Entite *entite_fixe);

//création vector contenant tous les Entite
//std::vector < sf::Drawable* > mes_objets;		:	 Contenu dans Entite
//std::vector < Entite* > entite_fixe;			:	Contenu dans Entite
//sf::RectangleShape *back_ground;
//sf::CircleShape *point_reference;
//Taille de la vue si x=1600 ; y = 900 => vue 16:9
float x=1600;
float y=900;
//Rayon cercle reference
float Rshape=10;
// Taille view
float rect_game_x = x;
float rect_game_y = y;

// Chargement de la texture (View totale)




int main()
{
	// Objet temps machine
	
	//---------------------------- Création de la fenêtre -----------------------------------------
	sf::RenderWindow *window;
	window = new sf::RenderWindow (sf::VideoMode(1600, 900), "SmashBigBordel", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
	window->setFramerateLimit(60);
	sf::View view;

	//------------------------Création des Sprite ---------------------------------------------
	// rect defini pour la plage de jeu
	//back_ground = new sf::RectangleShape (sf::Vector2f(rect_game_x,rect_game_y));
	//mes_objets.push_back(back_ground);
	//point_reference = new sf::CircleShape(Rshape);
	//point_reference->setFillColor(sf::Color::Green);
	

	
	Map1 map;
	
	// Chargement des textures

	Jeu Game(window);
	Game.ChargementJeu(&map);

	//----------------------------- Boucle du jeu --------------------------------------------------
	while (window->isOpen())
	{
		sf::Event event;
		//------------------------------- Gestion des évènements -------------------------------
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		//-------------------------------- Modification des états des objets--------------------
		

		view.setCenter(0, 0); //center les coordoné 2D de la window au centre de la vue
		view.setSize(x, y); // Taille de la vue si x=1600 ; y = 900 => vue 16:9

		//back_ground->setPosition((-rect_game_x/2),(-rect_game_y/2)); //Rectangle de fond positionner au milieur de la vue
		//point_reference->setPosition((-Rshape / 2), (-Rshape / 2));//Cercle vert positionner au milieur de la vue Référence

		//-------------------------------- Effacer le contenu de la fenêtre----------------------

		window->clear();

		//-------------------------------- Liaison des objets graphiques à la fenêtre------------

		window->setView(view);
		Game.DrawBackGround(map.getBackground());
		Game.DrawPlateforme(map.GetVectorPlatefomes());
		window->display();

	}
	
	

	delete window;
	/*for (int i = 0; i < entite_fixe.size(); i++) // suppression des Drawable mes_objets
	{
		delete entite_fixe.back();
		entite_fixe.pop_back();
	}*/

	return 0;


	
}
			// Fonction pour regenerer les plateformes à chaque itération de la fenetre

/*
void GenerateurEntiteFixe(Entite *entite_fixe)
{

	if (!texture.create(500, 500)) {}
	texture.clear(sf::Color::Red);
	texture.getTexture();

	std::cout << "[Error]:Generateur entite debut \"Games\"";
	entite_fixe->setPosition(entite_fixe->GetPositionX(), entite_fixe->GetPositionY());
	entite_fixe->setScale(entite_fixe->GetTailleX(), entite_fixe->GetTailleY());
	entite_fixe->setTextureRect(sf::IntRect(10, 10, 32, 32));
	//entite_fixe->setColor(sf::Color::Red);//replacer par texture
	entite_fixe->setTexture(texture.getTexture());
	//mes_objets.push_back(entite_fixe);
	std::cout << "[Error]:Generateur entite fin \"Games\"";
}

void GenerateurMap(Map mapouche)  Voir Classe map et AtStartup + Entite
{	
	Plateforme *Plat;
	Plat = new Plateforme(mapouche.GetPlat1PosX(), mapouche.GetPlat1PosY(), mapouche.GetPlat1TailleX(), mapouche.GetPlat1TailleY(), "j");
	entite_fixe.push_back(Plat);
	Plat = new Plateforme(mapouche.GetPlat2PosX(), mapouche.GetPlat2PosY(), mapouche.GetPlat2TailleX(), mapouche.GetPlat2TailleY(), "j");
	entite_fixe.push_back(Plat);
	Plat = new Plateforme(mapouche.GetPlat3PosX(), mapouche.GetPlat3PosY(), mapouche.GetPlat3TailleX(), mapouche.GetPlat3TailleY(), "j");
	entite_fixe.push_back(Plat);
	Plat = new Plateforme(mapouche.GetPlat4PosX(), mapouche.GetPlat4PosY(), mapouche.GetPlat4TailleX(), mapouche.GetPlat4TailleY(), "j");
	entite_fixe.push_back(Plat);
	Plat = new Plateforme(mapouche.GetPlat5PosX(), mapouche.GetPlat5PosY(), mapouche.GetPlat5TailleX(), mapouche.GetPlat5TailleY(), "j");
	entite_fixe.push_back(Plat);
}*/

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


		