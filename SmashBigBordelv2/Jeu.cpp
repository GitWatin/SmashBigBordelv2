#include "Jeu.h"
#include "FontManager.h"
//-------------JEU-----------------------------------------

Jeu::Jeu()
{
	this->fenetre = new sf::RenderWindow(sf::VideoMode(1600, 900), "SmashBigBordel", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
	this->fenetre->setFramerateLimit(60);
	this->clock = new sf::Clock;
	this->dureeIteration = sf::Time::Zero;
}

Jeu :: ~Jeu()
{
	Entite *jeu;
	jeu = new Entite();


	delete jeu;

	// Destructeur HUD
	for (int i = 0; i < vectorHUD.size(); i++)
	{
		delete vectorHUD.back();
		vectorHUD.pop_back();
	}
}

sf::RenderWindow* Jeu::GetWindow()
{
	return this->fenetre;
}

void Jeu::CheckInput(sf::Event event)
{
	switch (event.key.code)
	{
		de
		break;
	}
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
	std::cout << "Choissez une map : \n 1. Map 1 \n 2. Map 2 \n";
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
	std::cout << "perso 1  : \n 1. Rick 1 \n 2. Morty \n";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:
		
		this->perso1choisi = new Rick();
		this->perso1choisi->SetPersonnage();
		
		std::cout << "J1 : Rick \n"<<std::endl;
		

		break;
	case 2:
		
		this->perso1choisi = new Morty();
		this->perso1choisi->SetPersonnage();

		std::cout << "J1 : Morty \n" << std::endl;
		break;
	}

	
	std::cout << "perso 2 : \n 1. Rick 1 \n 2. Morty \n";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:

		this->perso2choisi = new Rick();
		this->perso2choisi->SetPersonnage();
		
		std::cout << "J2 : Rick  \n " << std::endl;
		break;
	case 2:

		this->perso2choisi = new Morty();
		this->perso2choisi->SetPersonnage();

		std::cout << "J2 : Morty \n " << std::endl;
		
		break;
	}

	
}

Map* Jeu::GetMapChoisie()
{
	return this->mapchoisie;
}

Personnage * Jeu::GetPerso1choisi()
{
	return this->perso1choisi;
}

Personnage * Jeu::GetPerso2choisi()
{
	return this->perso2choisi;
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

void Jeu::CallModif()
{
	FontManager *font;
	font = new FontManager();

	ViePerso = new sf::Text;

	// Set Label pour le perso 1

	//ViePerso->setString(std::to_string(perso1choisi->GetNbre_Vies()));
	ViePerso->setString("HAN OUAIS");
	ViePerso->setFont(*font->SetFont("quicksand.ttf"));
	ViePerso->setPosition(0, 0);
	vectorHUD.push_back(ViePerso);
	/*
	BouclierPerso->setString(std::to_string(perso1choisi->GetBouclier()));
	BouclierPerso->setPosition(0, 0);
	vectorHUD.push_back(BouclierPerso);

	AtoutPerso->setString(perso1choisi->GetDerniersAtout());
	AtoutPerso->setPosition(0, 0);
	vectorHUD.push_back(AtoutPerso);

	// Set Label pour le perso 2

	ViePerso->setString(std::to_string(perso2choisi->GetNbre_Vies()));
	ViePerso->setPosition(0, 0);
	vectorHUD.push_back(ViePerso);

	BouclierPerso->setString(std::to_string(perso2choisi->GetBouclier()));
	BouclierPerso->setPosition(0, 0);
	vectorHUD.push_back(BouclierPerso);

	AtoutPerso->setString(perso2choisi->GetDerniersAtout());
	AtoutPerso->setPosition(0, 0);
	vectorHUD.push_back(AtoutPerso);*/

	delete font;

}

void Jeu::DrawPersonnage(std::vector < Personnage* > Dessin)
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


// Draw les elements de l'HUD
void Jeu::DrawHUD()
{
	std::cout << "[HUD] :" << vectorHUD.size() << std::endl;
	for (int i = 0; i < vectorHUD.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*vectorHUD[i]);
		std::cout << "[Info]:Return dessin " << vectorHUD[i] << std::endl;
	}
}

void Jeu::DrawBackGround(Back_Ground *BackGround)
{
	fenetre->draw(*BackGround);


}