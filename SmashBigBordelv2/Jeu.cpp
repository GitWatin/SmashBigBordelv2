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
			perso1choisi->setJump(false);
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
	if (Game_State = true)
	{
		if (perso1choisi->getMoveRight()) //check si le bool est actif
		{
			Animate(perso1choisi, "droite");
			perso1choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso1choisi->getMoveLeft()) //check si le bool est actif
		{
			Animate(perso1choisi, "gauche");
			perso1choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso1choisi->getJump()/*&& perso1choisi->getCollision()*/)
		{
			perso1choisi->move(0, (-dureeIteration.asSeconds()*((VitesseSaut / perso1choisi->GetPoids()) * VitesseSaut)));
		}
		if (!perso1choisi->getCollision() && !perso1choisi->getJump())
		{
			perso1choisi->move(0, (dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * Gravity)));
		}
		//----------J2--------------------------------
		if (perso2choisi->getMoveRight()) //check si le bool est actif
		{
			Animate(perso2choisi, "droite");
			perso2choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso2choisi->getMoveLeft()) //check si le bool est actif
		{
			Animate(perso2choisi, "gauche");
			perso2choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso2choisi->getJump() /*&& perso2choisi->getCollision()*/)
		{
			perso2choisi->move(0, (-dureeIteration.asSeconds()*((VitesseSaut / perso2choisi->GetPoids()) * VitesseSaut)));
		}
		if (!perso2choisi->getCollision() && !perso2choisi->getJump())
		{
			perso2choisi->move(0, (dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * Gravity)));
		}
	}
}

void Jeu::Animate(Personnage *perso, std::string direction)
{
	TextureManager *texture_move;
	texture_move= new TextureManager();

	NomTextureMove = perso->GetAvatar();
	sf::Time timer_Move = clock_Move->getElapsedTime();

	if (timer_Move.asSeconds() >= 0.2 && direction=="droite")
	{
		std::cout << sens << std::endl;
		if (sens == 2)
		{
			perso->setScale(-1, 1);
			this->sens = 1;
		}
		perso->setTexture(*texture_move->SetTexture(NomTextureMove+std::to_string(Iteration)+".png"));
		//perso->setScale(-1, 1);

		clock_Move->restart();
		this->Iteration = Iteration + 1;
		this->sens = 1;//Droite
	}


	if (timer_Move.asSeconds() >= 0.2 && direction == "gauche")
	{
		std::cout << sens << std::endl;
		if (sens == 1)
		{
			std::cout << "Coucou_gauche" << std::endl;
			perso->setScale(1, 1);
			this->sens = 2;
		}
		perso->setTexture(*texture_move->SetTexture(NomTextureMove + std::to_string(Iteration) + ".png"));
		clock_Move->restart();
		this->Iteration = Iteration + 1;
		this->sens = 2;//Gauche
	}
	else if(this->Iteration == 4)
	{
		this->Iteration = 0;
	}


	delete texture_move;

}
void Jeu::CheckCollisionPlat(Personnage *jacque)
{
	for (int i = 0; i < (mapchoisie->GetVectorPlatefomes()).size(); i++)
	{
		this->CheckCollision(jacque, mapchoisie->getPlatform(i), 0);
	}
	
}

void Jeu::CheckCollision(Entite *michel,Entite *plateforme,float repoussement)
{
	sf::Vector2f plateformePosition = plateforme->getPosition();
	sf::FloatRect plateformeHitBox = plateforme->getGlobalBounds();
	sf::Vector2f michelPosition = michel->getPosition();
	sf::FloatRect michelHitBox = michel->getGlobalBounds();

	float deltaX = plateformePosition.x - michelPosition.x;
	float deltaY = plateformePosition.y - michelPosition.y;

	float intersectionX = abs(deltaX) - (plateformeHitBox.width + michelHitBox.width);
	float intersectionY = abs(deltaY) - (plateformeHitBox.height + michelHitBox.height);

	if (plateformePosition.x < michelPosition.x + michelHitBox.width && michelPosition.x < plateformePosition.x + plateformeHitBox.width && plateformePosition.y < michelPosition.y + michelHitBox.height && michelPosition.y < plateformePosition.y + plateformeHitBox.height)
	{
		repoussement = std::min(std::max(repoussement, 0.0f), 1.0f);

		if (intersectionX > intersectionY)
		{
			if (deltaX > 0.0f)
			{
				michel->move(intersectionX * (1.0f - repoussement), 0.0f);
				plateforme->move(-intersectionX * (1.0f - repoussement), 0.0f);

			}
			else
			{
				michel->move(-intersectionX * (1.0f - repoussement), 0.0f);
				plateforme->move(intersectionX * (1.0f - repoussement), 0.0f);
			}
			if (deltaY > 0.0f)
			{
				michel->move(intersectionY * (1.0f - repoussement), 0.0f);
				plateforme->move(-intersectionY * (1.0f - repoussement), 0.0f);

			}
			else
			{
				michel->move(-intersectionY * (1.0f - repoussement), 0.0f);
				plateforme->move(intersectionY * (1.0f - repoussement), 0.0f);
			}
		}

		michel->setCollision(true);
	}

	michel->setCollision(false);
	


	/* permier jet collisioneur
	for (int i=0; i<(mapchoisie->GetVectorPlatefomes()).size() ;i++)
	{
		if(michel->getGlobalBounds().intersects(mapchoisie->getPlatform(i)->getGlobalBounds()))
		{
			michel->setCollision(true);
			//std::cout << "[Collision] : " << michel->GetNom() << " et " << mapchoisie->getPlatform(i) << std::endl;
			break;
		}
		if(!michel->getGlobalBounds().intersects(mapchoisie->getPlatform(i)->getGlobalBounds()))
		{
			//std::cout << "[Fin Collision] : " << michel->GetNom() << " et " << mapchoisie->getPlatform(i) << std::endl;
			michel->setCollision(false);
		}
	}*/	
}

void Jeu::CallModif()
{
	// Call HUD Function 

	SetHUD();
	CountDown();

	if (Game_State == true)
	{
		Timing();
	}

	
}

void Jeu::ChargementJeu(Map *map) // Chargement une fois
{
	// demmarage du Timer du jeu (5min )
	this->clock_jeu = new sf::Clock; //  
	this->clock_HUD = new sf::Clock; 
	this->clock_Move = new sf::Clock;
	temporary_time = 60;
	CountDownInt = 5;
	Game_State = false;

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
		this->TempsDeJeu = 15;
		break;
	case 2:
		this->mapchoisie = new Map2();
		this->TempsDeJeu = 90;
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
		
		perso1choisi = new Rick(Spawn_x1,Spawn_y1);
		std::cout << "J1 : Rick \n"<<std::endl;
		

		break;
	case 2:
		
		perso1choisi = new Morty(Spawn_x1, Spawn_y1);
		std::cout << "J1 : Morty \n" << std::endl;
		break;
	}

	
	std::cout << "perso 2 : \n 1. Rick 1 \n 2. Morty \n";
	std::cin >> choix2;
	switch (choix2)
	{
	case 1:

		perso2choisi = new Rick(Spawn_x2, Spawn_y2);
		perso2choisi->SetPersonnage();
		
		std::cout << "J2 : Rick  \n " << std::endl;
		break;
	case 2:

		perso2choisi = new Morty(Spawn_x2, Spawn_y2);
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
	this->clock_Depart = new sf::Clock; // Demarrage count down depart
	

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
	avatar1->setTexture(*texture_hud->SetTexture(perso1choisi->GetAvatar()+".png"));
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

	AtoutPerso1->setString("");
	AtoutPerso1->setFont(*font->SetFont("quicksand.ttf"));
	AtoutPerso1->setFillColor(sf::Color::Red);
	AtoutPerso1->setCharacterSize(24);
	AtoutPerso1->setPosition(-480, -360);
	vectorHUD.push_back(AtoutPerso1);


	// --------------- Perso 2 ----------------------

	avatar2->setTextureRect(sf::IntRect(0, 0, 80, 80));
	avatar2->setTexture(*texture_hud->SetTexture(perso2choisi->GetAvatar() + ".png"));
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

	AtoutPerso2->setString("");
	AtoutPerso2->setFont(*font->SetFont("quicksand.ttf"));
	AtoutPerso2->setFillColor(sf::Color::Blue);
	AtoutPerso2->setCharacterSize(24);
	AtoutPerso2->setOrigin(AtoutPerso2->getGlobalBounds().width, 0);
	AtoutPerso2->setPosition(+480, -360);
	vectorHUD.push_back(AtoutPerso2);


	HUDTimer->setString("");
	HUDTimer->setFont(*font->SetFont("quicksand.ttf"));
	HUDTimer->setFillColor(sf::Color::Black);
	HUDTimer->setCharacterSize(50);
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

	//std::cout << "[Info]: " << perso2choisi->GetDerniersAtout() << std::endl;

	NomPerso1->setString(perso1choisi->GetNom());
	NomPerso2->setString(perso2choisi->GetNom());

	ViePerso1->setString("Vies restantes :" + std::to_string(perso1choisi->GetNbre_Vies()));
	ViePerso2->setString("Vies restantes :" + std::to_string(perso2choisi->GetNbre_Vies()));
	ViePerso2->setOrigin(ViePerso2->getGlobalBounds().width,0);

	BouclierPerso1->setString("Bouclier :" + std::to_string(perso1choisi->GetBouclier()));
	BouclierPerso2->setString("Bouclier :" + std::to_string(perso2choisi->GetBouclier()));
	BouclierPerso2->setOrigin(BouclierPerso2->getGlobalBounds().width, 0);

	if (perso1choisi->GetDerniersAtout() != "")
	{
		AtoutPerso1->setString("Atout :" + perso1choisi->GetDerniersAtout());
	}
	if (perso1choisi->GetDerniersAtout() != "" && perso2choisi->GetDerniersAtout() != "")
	{
		AtoutPerso1->setString("Atout :" + perso1choisi->GetDerniersAtout());
		AtoutPerso2->setString("Atout :" + perso2choisi->GetDerniersAtout());
		AtoutPerso2->setOrigin(AtoutPerso2->getGlobalBounds().width, 0);
	}
	if (perso2choisi->GetDerniersAtout() != "")
	{
		AtoutPerso2->setString("Atout :" + perso2choisi->GetDerniersAtout());
		AtoutPerso2->setOrigin(AtoutPerso2->getGlobalBounds().width, 0);
	}

	

}

// Fonction pour gerer le timer
void Jeu::Timing()
{
	sf::Time timer_jeu = clock_jeu->getElapsedTime();
	sf::Time timer_HUD = clock_HUD->getElapsedTime();
	
	if (timer_jeu.asSeconds() > TempsDeJeu ) // Fin du jeu 
	{
		this->HUDTimer->setString(" Fin du jeu");
		this->HUDTimer->setOrigin(HUDTimer->getGlobalBounds().width / 2, HUDTimer->getGlobalBounds().height / 2);
		//std::cout << "[Info]: Fin du jeu (Time done)" << std::endl;
		Game_State = false;
	}
	else // Continue � incrementer
	{
		this->secondes = timer_HUD.asSeconds();
		
		if (secondes < 10) // Permet d'afficher un 0 devant les secondes 
		{
			this->HUDTimer->setString(std::to_string(this->minute) + ":" + "0"+ std::to_string(this->secondes));	
		}
		else
		{
			this->HUDTimer->setString(std::to_string(this->minute) + ":" + std::to_string(this->secondes));
		}


		if (timer_HUD.asSeconds() >= temporary_time) // Incremente les minutes et restart le clock HUD
		{
			this->minute++;
			clock_HUD->restart();
			this->temporary_time = temporary_time+ 60;
			
		}
		
		this->HUDTimer->setOrigin(HUDTimer->getGlobalBounds().width / 2, HUDTimer->getGlobalBounds().height / 2);
		
		//Game_State = true;
	}

	

}

void Jeu::CountDown()
{
	
	sf::Time timer_Depart = clock_Depart->getElapsedTime();
	
	if (timer_Depart.asSeconds() >= 1 && Game_State==false)
	{
		this->CountDownInt = CountDownInt - 1;
		this->HUDTimer->setString( "D�but dans :" + std::to_string(this->CountDownInt));
		this->HUDTimer->setOrigin(HUDTimer->getGlobalBounds().width / 2, HUDTimer->getGlobalBounds().height / 2);
		clock_Depart->restart();
		Game_State = false;
		clock_HUD->restart();
			
	}
	else if(CountDownInt==0)
	{
		std::cout << "J suis la" << std::endl;
		Game_State = true;
		

	}



}

