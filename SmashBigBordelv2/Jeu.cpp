#include "Jeu.h"
#include "FontManager.h"
#include "TextureManager.h"

//-------------JEU-----------------------------------------

Jeu::Jeu()
{
	this->fenetre = new sf::RenderWindow(sf::VideoMode(1600, 900), "SmashBigBordel", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
	this->fenetre->setFramerateLimit(60);
	this->clock = new sf::Clock;
	this->dureeIteration = sf::Time::Zero;

	// Timer du jeu (5min )
	this->clock_jeu = new sf::Clock;
	
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

void Jeu::setDureeIteration()
{
	dureeIteration = clock->restart();
}

void Jeu::CheckInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
			fenetre->close();
		break;
	case sf::Event::EventType :: KeyPressed :
		switch (event.key.code)
		{
		case sf::Keyboard::Right :
			perso1choisi->setMoveRight();
			break;
		case sf::Keyboard::Left:
			perso1choisi->setMoveLeft();
			break;
		case sf::Keyboard::D:
			perso2choisi->setMoveRight();
			break;
		case sf::Keyboard::Q:
			perso2choisi->setMoveLeft();
			break;
		}
		break;
	case sf::Event::EventType::KeyReleased :
		switch (event.key.code)
		{
		case sf::Keyboard::Right:
			perso1choisi->setMoveRight();
			break;
		case sf::Keyboard::Left:
			perso1choisi->setMoveLeft();
			break;
		case sf::Keyboard::D:
			perso2choisi->setMoveRight();
			break;
		case sf::Keyboard::Q:
			perso2choisi->setMoveLeft();
			break;
		}
		break;
	}
}

void Jeu::CheckModif()
{
	if (perso1choisi->getMoveRight()) //check si le bool est actif
	{
		std::cout << " [Check Modif] : right perso1" << perso1choisi->GetPoids()<< std::endl;
		perso1choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * 100), 0);
	}
	if (perso1choisi->getMoveLeft()) //check si le bool est actif
	{
		perso1choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * 100), 0);
	}
	if (perso2choisi->getMoveRight()) //check si le bool est actif
	{
		std::cout << " [Check Modif] : right perso2" << std::endl;
		perso2choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement /perso2choisi->GetPoids()) * 100), 0);
	}
	if (perso2choisi->getMoveLeft()) //check si le bool est actif
	{
		perso2choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * 100), 0);
	}
}

void Jeu::CallModif()
{
	// Call HUD Function 
	SetHUD();
	Timing();
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
		
		perso1choisi = new Rick();
		std::cout << "J1 : Rick \n"<<std::endl;
		

		break;
	case 2:
		
		perso1choisi = new Morty();
		std::cout << "J1 : Morty \n" << std::endl;
		break;
	}

	
	std::cout << "perso 2 : \n 1. Rick 1 \n 2. Morty \n";
	std::cin >> choix1;
	switch (choix1)
	{
	case 1:

		perso2choisi = new Rick();
		perso2choisi->SetPersonnage();
		
		std::cout << "J2 : Rick  \n " << std::endl;
		break;
	case 2:

		perso2choisi = new Morty();
		perso2choisi->SetPersonnage();

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
		
		//std::cout << "[Info]:Return dessin " << vectorHUD[i] << std::endl;
	}
}

void Jeu::DrawBackGround(Back_Ground *BackGround)
{
	fenetre->draw(*BackGround);


}


// Fonction pour recuperer les informations des personnages et les ajouters au vector vectorHUD
void Jeu::CreateHUD()
{
	NomPerso1 = new sf::Text;
	NomPerso2 = new sf::Text;
	ViePerso1 = new sf::Text;
	ViePerso2 = new sf::Text;
	BouclierPerso1 = new sf::Text;
	BouclierPerso2 = new sf::Text;
	AtoutPerso1 = new sf::Text;
	AtoutPerso2 = new sf::Text;
	
	avatar1 = new sf::Sprite;
	avatar2 = new sf::Sprite;


	FontManager *font;
	font = new FontManager();
	TextureManager *texture_hud;
	texture_hud = new TextureManager();



	// Creation de l'avatar perso 1: 
	avatar1->setTextureRect(sf::IntRect(0, 0, 50, 50));
	avatar1->setTexture(*texture_hud->SetTexture("plat_tiny.png"));
	avatar1->setPosition(+200, -450);
	vectorHUD.push_back(avatar1);
	
	NomPerso1->setString("N/A");
	NomPerso1->setFont(*font->SetFont("quicksand.ttf"));
	NomPerso1->setFillColor(sf::Color::Red);
	NomPerso1->setPosition(-500, -450);
	vectorHUD.push_back(NomPerso1);
	
	delete font;
	delete texture_hud;
}


void Jeu::SetHUD()
{

	FontManager *font;
	font = new FontManager();

	TextureManager *texture_hud;
	texture_hud = new TextureManager();

	avatar1 = new sf::Sprite;
	avatar2 = new sf::Sprite;

	// Set Label pour le perso 1

	// Affichage de l'avatar : 

	NomPerso1->setString("Joueur : " + perso1choisi->GetNom());
}
// Fonction pour gerer le timer
void Jeu::Timing()
{
	
	sf::Time timer_jeu = clock_jeu->getElapsedTime();

	std::cout << "[Info]: " << timer_jeu.asSeconds() << std::endl;
	
	/*if (timer_jeu.asSeconds >= 300.f)
	{
		this->text_timer = " Fin du jeu";
		Game_State = false;
	}
	else
	{
		text_timer = std::to_string(timer_jeu.asSeconds());
		Game_State = true;
	}

	//clock_jeu->getElapsedTime*/
}
