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
void Jeu::Draw(std::vector < sf::Drawable* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*Dessin[i]);
		std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
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
	
	map->GenerateurPlateformeMap(map); // Voir CLasse Map : Charge Les texture Back_ground et Plateforme contenu dans la map choisi  // Cree les plateforme et les envoie dans le vetor d'entite

}