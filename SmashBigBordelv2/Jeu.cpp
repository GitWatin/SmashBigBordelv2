#include "Jeu.h"
Jeu::Jeu()
{
	;
}
Jeu::Jeu(sf::RenderWindow *window)
{
	this->fenetre = window;//(sf::VideoMode(1600, 900), "SmashBigBordel", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
	fenetre->setFramerateLimit(60);
}
void Jeu::DrawEntite(std::vector < sf::Drawable* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*Dessin[i]);
		std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}
void Jeu::DrawPlateforme(std::vector< Plateforme* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*Dessin[i]);
		std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

void Jeu::DrawBackGround(sf::RectangleShape *BackGround)
{
	fenetre->draw(BackGround);
}

Jeu :: ~Jeu()
{
	Entite *jeu;
	jeu = new Entite();
	jeu->supprimer_vector();
	delete jeu;
}
void Jeu::ChargementJeu(Map *map) // Chargement une fois
{
	map->setPlatefomes();
	map->setBackground();
}