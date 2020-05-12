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
			//---------J1--------------------------------

		case sf::Keyboard::Right :
			perso1choisi->setMoveRight(true);
			break;
		case sf::Keyboard::Left:
			perso1choisi->setMoveLeft(true);
			break;
		case sf::Keyboard::Up:
			perso1choisi->setJump(true);
			break;

			//---------J2--------------------------------

		case sf::Keyboard::D:
			perso2choisi->setMoveRight(true);
			break;
		case sf::Keyboard::Q:
			perso2choisi->setMoveLeft(true);
			break;
		case sf::Keyboard::Z:
			perso2choisi->setJump(true);
			break;
		}
		break;
	case sf::Event::EventType::KeyReleased :
		switch (event.key.code)
		{
			//---------J1--------------------------------

		case sf::Keyboard::Right:
			perso1choisi->setMoveRight(false);
			break;
		case sf::Keyboard::Left:
			perso1choisi->setMoveLeft(false);
			break;
		case sf::Keyboard::Up:
			perso1choisi->setJump(true);
			break;


			//---------J2--------------------------------

		case sf::Keyboard::D:
			perso2choisi->setMoveRight(false);
			break;
		case sf::Keyboard::Q:
			perso2choisi->setMoveLeft(false);
			break;
		case sf::Keyboard::Z:
			perso2choisi->setJump(false);
			break;
		}
		break;
	}
}

void Jeu::CheckModif()
{
	//---------J1--------------------------------

	if (perso1choisi->getMoveRight()) //check si le bool est actif
	{	
		perso1choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * 150), 0);
	}
	if (perso1choisi->getMoveLeft()) //check si le bool est actif
	{
		perso1choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * 150), 0);
	}
	if (perso1choisi->getJump())
	{
		perso1choisi->move(0 ,(-dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * 150)));
	}

	//----------J2--------------------------------
	if (perso2choisi->getMoveRight()) //check si le bool est actif
	{
		perso2choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement /perso2choisi->GetPoids()) * 150), 0);
	}
	if (perso2choisi->getMoveLeft()) //check si le bool est actif
	{
		perso2choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * 150), 0);
	}
	if (perso2choisi->getJump())
	{
		perso2choisi->move(0, (-dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * 150)));
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
	// a gerer avec un switch dans le menu pour les diff�rente maps
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
	// a gerer avec un switch dans le menu pour les diff�rente maps
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


// Draw les elements de l'HUD
void Jeu::DrawHUD()
{
	
	for (int i = 0; i < vectorHUD.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de cr�ation[1][2]
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
	HUDTimer = new sf::Text;
	
	avatar1 = new sf::Sprite;
	avatar2 = new sf::Sprite;


	FontManager *font;
	font = new FontManager();
	TextureManager *texture_hud;
	texture_hud = new TextureManager();



	// Creation de l'avatar perso 1: 
	avatar1->setTextureRect(sf::IntRect(0, 0, 80, 80));
	avatar1->setTexture(*texture_hud->SetTexture("plat_tiny.png"));
	avatar1->setPosition(-720, -370);
	avatar1->setOrigin(avatar1->getGlobalBounds().width / 2, avatar1->getGlobalBounds().height / 2);

	vectorHUD.push_back(avatar1);
	
	NomPerso1->setString("Morty");
	NomPerso1->setFont(*font->SetFont("quicksand.ttf"));
	NomPerso1->setFillColor(sf::Color::Red);
	NomPerso1->setPosition(-670, -410);
	vectorHUD.push_back(NomPerso1);

	ViePerso1->setString("Vie restante : 3");
	ViePerso1->setFont(*font->SetFont("quicksand.ttf"));
	ViePerso1->setFillColor(sf::Color::Red);
	ViePerso1->setCharacterSize(24);
	ViePerso1->setPosition(-670, -360);
	vectorHUD.push_back(ViePerso1);

	BouclierPerso1->setString("Bouclier : 100%");
	BouclierPerso1->setFont(*font->SetFont("quicksand.ttf"));
	BouclierPerso1->setFillColor(sf::Color::Red);
	BouclierPerso1->setCharacterSize(24);
	BouclierPerso1->setPosition(-480, -410);
	vectorHUD.push_back(BouclierPerso1);

	AtoutPerso1->setString("Atout : Weight Watcher");
	AtoutPerso1->setFont(*font->SetFont("quicksand.ttf"));
	AtoutPerso1->setFillColor(sf::Color::Red);
	AtoutPerso1->setCharacterSize(24);
	AtoutPerso1->setPosition(-480, -360);
	vectorHUD.push_back(AtoutPerso1);


	// --------------- Perso 2 ----------------------

	avatar2->setTextureRect(sf::IntRect(0, 0, 80, 80));
	avatar2->setTexture(*texture_hud->SetTexture("plat_tiny.png"));
	avatar2->setPosition(+720, -370);
	avatar2->setOrigin(avatar1->getGlobalBounds().width / 2, avatar1->getGlobalBounds().height / 2);
	vectorHUD.push_back(avatar2);

	NomPerso2->setString("Rickyky");
	NomPerso2->setFont(*font->SetFont("quicksand.ttf"));
	NomPerso2->setFillColor(sf::Color::Blue);
	NomPerso2->setPosition(+670, -410);
	NomPerso2->setOrigin(NomPerso2->getGlobalBounds().width, 0);
	vectorHUD.push_back(NomPerso2);

	ViePerso2->setString("Vie restante : 3");
	ViePerso2->setFont(*font->SetFont("quicksand.ttf"));
	ViePerso2->setFillColor(sf::Color::Blue);
	ViePerso2->setCharacterSize(24);
	ViePerso2->setOrigin(ViePerso2->getGlobalBounds().width, 0);
	ViePerso2->setPosition(+670, -360);
	vectorHUD.push_back(ViePerso2);

	BouclierPerso2->setString("Bouclier : 100%");
	BouclierPerso2->setFont(*font->SetFont("quicksand.ttf"));
	BouclierPerso2->setFillColor(sf::Color::Blue);
	BouclierPerso2->setCharacterSize(24);
	BouclierPerso2->setOrigin(BouclierPerso2->getGlobalBounds().width, 0);
	BouclierPerso2->setPosition(+480, -410);
	vectorHUD.push_back(BouclierPerso2);

	AtoutPerso2->setString("Atout : Weight Watcher");
	AtoutPerso2->setFont(*font->SetFont("quicksand.ttf"));
	AtoutPerso2->setFillColor(sf::Color::Blue);
	AtoutPerso2->setCharacterSize(24);
	AtoutPerso2->setOrigin(AtoutPerso2->getGlobalBounds().width, 0);
	AtoutPerso2->setPosition(+480, -360);
	vectorHUD.push_back(AtoutPerso2);


	HUDTimer->setString("0000");
	HUDTimer->setFont(*font->SetFont("quicksand.ttf"));
	HUDTimer->setFillColor(sf::Color::Black);
	HUDTimer->setCharacterSize(30);
	HUDTimer->setOrigin(HUDTimer->getGlobalBounds().width/2, HUDTimer->getGlobalBounds().height/2);
	HUDTimer->setPosition(0, -410);
	vectorHUD.push_back(HUDTimer);




	
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

	//NomPerso1->setString("Joueur : " + perso1choisi->GetNom());
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
