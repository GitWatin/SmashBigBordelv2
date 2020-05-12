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
	// a gerer avec un switch dans le menu pour les diff�rente maps
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
	// a gerer avec un switch dans le menu pour les diff�rente maps
	std::cout << "perso 1  : \n 1. Rick 1 \n 2. Morty";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:
		Rick *rick;
		rick = new Rick();
		rick->SetPersonnage();
		this->perso1choisi = rick;
		this->perso1choisi->SetVectorPersonnages(perso1choisi);
		std::cout << "J1 : Rick "<<std::endl;
		//delete rick;
		break;
	case 2:
		Morty *morty;
		morty = new Morty;
		morty->SetPersonnage();
		this->perso1choisi = morty;
		this->perso1choisi->SetVectorPersonnages(perso1choisi);
		std::cout << "J1 : Morty " << std::endl;

		//delete morty;
		break;
	}
	
	std::cout << "perso 2  : \n 1. Rick 1 \n 2. Morty";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:
		Rick *rick;
		rick = new Rick();
		rick->SetPersonnage();
		this->perso2choisi = rick;
		this->perso2choisi->SetVectorPersonnages(this->perso2choisi);
		//delete rick;
		std::cout << "J2 : Rick " << std::endl;
		break;
	case 2:
		Morty *morty;
		morty = new Morty;
		morty->SetPersonnage();
		this->perso2choisi = morty;
		this->perso2choisi->SetVectorPersonnages(this->perso2choisi);
		std::cout << "J2 : Morty " << std::endl;
		//delete morty;
		break;
	}
	
}

Map* Jeu::GetMapChoisie()
{
	return this->mapchoisie;
}

Personnage * Jeu::GetPersochoisi()
{
	return this->perso1choisi;
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

void Jeu::DrawPersonnage(std::vector < Personnage* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de cr�ation[1][2]
	{
		fenetre->draw(*Dessin[i]);
		//std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

//---------------------Map--------------------------------------------

void Jeu::DrawPlateforme(std::vector< Plateforme* > Dessin)
{
	for (int i = 0; i < Dessin.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de cr�ation[1][2]
	{
		fenetre->draw(*Dessin[i]);
		//std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}



void Jeu::DrawHUD()
{
	for (int i = 0; i < vectorHUD.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de cr�ation[1][2]
	{
		fenetre->draw(*vectorHUD[i]);
		//std::cout << "[Info]:Return dessin " << Dessin[i] << std::endl;
	}
}

void Jeu::DrawBackGround(Back_Ground *BackGround)
{
	fenetre->draw(*BackGround);


}