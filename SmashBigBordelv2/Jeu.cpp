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
	// a gerer avec un switch dans le menu pour les diff�rente maps

	Map1 map;
	this->mapchoisie = &map;
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
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de cr�ation[1][2]
	{
		fenetre->draw(*Dessin[i]);
		std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

//---------------------Map--------------------------------------------

void Jeu::DrawPlateforme(std::vector< Plateforme* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de cr�ation[1][2]
	{
		fenetre->draw(*Dessin[i]);
		std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

void Jeu::DrawBackGround(Back_Ground *BackGround)
{
	fenetre->draw(*BackGround);


}