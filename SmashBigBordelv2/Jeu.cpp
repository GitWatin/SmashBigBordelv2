#include "Jeu.h"
//-------------JEU-----------------------------------------

Jeu::Jeu()
{
	this->fenetre = new sf::RenderWindow(sf::VideoMode(1600, 900), "SmashBigBordel", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
	this->fenetre->setFramerateLimit(60);
}

Jeu :: ~Jeu()
{
	Entite *jeu;
	jeu = new Entite();


	jeu->supprimer_vector();


	delete jeu;
}

sf::RenderWindow* Jeu::GetWindow()
{
	return this->fenetre;
}

void Jeu::ChargementJeu(Map *map) // Chargement une fois
{
	map->setBackground();
	map->setPlatefomes();
}

void Jeu::ChoixMap()
{
	int choix;
	// a gerer avec un switch dans le menu pour les différente maps
	std::cout << "Choissez une map : \n 1. Map 1 \n 2. Map 2";
	std::cin >> choix;
	switch (choix)
	{
	case 1 :
		this->mapchoisie = new Map1();
		break;
	case 2:
		this->mapchoisie = new Map2();
		break;
	}
	
}

void Jeu::ChoixPerso()
{
	int choix1;
	int choix2;
	// a gerer avec un switch dans le menu pour les différente maps
	std::cout << "perso 1  : \n 1. Rick 1 \n 2. Morty";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:
		this->perso1choisi = new Rick();
		break;
	case 2:
		this->perso1choisi = new Morty();
		break;
	}

	std::cout << "perso 1  : \n 1. Rick 1 \n 2. Morty";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:
		this->perso2choisi = new Rick();
		break;
	case 2:
		this->perso2choisi = new Morty();
		break;
	}
}

Map* Jeu::GetMapChoisie()
{
	return this->mapchoisie;
}

sf::View * Jeu::GetView()
{
	return this->Vueprincipal;
}

void Jeu::SetView(float TailleX , float TailleY)
{
	this->Vueprincipal = new sf::View();
	this->Vueprincipal->setCenter(0 , 0);
	this->Vueprincipal->setSize(TailleX , TailleY);
}

//---------------------Entite--------------------------------------------

void Jeu::DrawEntite(std::vector < sf::Drawable* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*Dessin[i]);
		//std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

//---------------------Map--------------------------------------------

void Jeu::DrawPlateforme(std::vector< Plateforme* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*Dessin[i]);
		//std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}



void Jeu::DrawHUD(std::vector<sf::Drawable*> HUD)
{
	for (int i = 0; i < HUD.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*HUD[i]);
		//std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

void Jeu::DrawBackGround(Back_Ground *BackGround)
{
	fenetre->draw(*BackGround);


}