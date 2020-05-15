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
	delete Vueprincipal;
	delete clock_Depart;
	delete clock_HUD;
	delete clock_jeu;
	delete clock_Move;
	delete clock_Att;
	
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
		case sf::Keyboard::RControl:
			if (!perso1choisi->getAttaque())perso1choisi->setAttaque(true);
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
		case sf::Keyboard::Space:
			if (!perso2choisi->getAttaque())perso2choisi->setAttaque(true);
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
		case sf::Keyboard::RControl:	
			perso1choisi->setAttaque(false);
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
		case sf::Keyboard::Space:
			perso2choisi->setAttaque(false);
			break;
		}
		break;
	}
}

void Jeu::CheckModif()
{


	// decommenter ca pour avoir le countdown
	//if(true)
	if (Game_State == true && Game_State_Final == true)
	{
		//---------J1--------------------------------

		if (perso1choisi->getMoveRight() && perso1choisi->getVersdroite() && !perso1choisi->getAttaque()) //check si le bool est actif
		{
			Animate(perso1choisi, "droite");
			perso1choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso1choisi->getMoveLeft() && perso1choisi->getVersgauche() && !perso1choisi->getAttaque()) //check si le bool est actif
		{
			Animate(perso1choisi, "gauche");
			perso1choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso1choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso1choisi->getJump() && perso1choisi->getVershaut() && !perso1choisi->getAttaque()/*&& !perso2choisi->getVersbas()*/)
		{
			Animate(perso1choisi, "jump");
			
			perso1choisi->move(0, (-dureeIteration.asSeconds()*((VitesseSaut/perso1choisi->GetPoids()) * Gravity*50)));

			//perso1choisi->move(0, (-dureeIteration.asSeconds()*((perso1choisi->GetPoids()/Gravity) * VitesseSaut)));
			
		}
		if (!perso1choisi->getCollision() && perso1choisi->getVersbas() && !perso1choisi->getAttaque())
		{
			perso1choisi->move(0, (dureeIteration.asSeconds()*(perso1choisi->GetPoids() * Gravity)));
		}
		if (perso1choisi->getAttaque())
		{
			if (perso1choisi->CheckAttaque(perso2choisi))
			{
				{			
					perso1choisi->Attaque(perso2choisi, perso1choisi->GetLastTime());
				}
				if (perso1choisi->GetLastTime() == 1)//droite
				{
					perso2choisi->move(perso2choisi->GetPourcentages()*dureeIteration.asSeconds()*VitesseDeplacement, 0);
				}
				if (perso1choisi->GetLastTime() == 2)//gauche
				{
					perso2choisi->move(-perso2choisi->GetPourcentages()*dureeIteration.asSeconds()*VitesseDeplacement, 0);
				}
			}
		}
		//----------J2--------------------------------
		if (perso2choisi->getMoveRight() && perso2choisi->getVersdroite() && !perso2choisi->getAttaque())//check si le bool est actif
		{
			Animate(perso2choisi, "droite");
			perso2choisi->move(dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso2choisi->getMoveLeft() && perso1choisi->getVersgauche() && !perso2choisi->getAttaque()) //check si le bool est actif
		{
			Animate(perso2choisi, "gauche");
			perso2choisi->move(-dureeIteration.asSeconds()*((VitesseDeplacement / perso2choisi->GetPoids()) * VitesseDeplacement), 0);
		}
		if (perso2choisi->getJump() && perso2choisi->getVershaut() && !perso2choisi->getAttaque() /*&& !perso2choisi->getVersbas()*/)
		{
			Animate(perso2choisi, "jump");
			perso2choisi->move(0, (-dureeIteration.asSeconds()*((VitesseSaut / perso2choisi->GetPoids()) * Gravity*50)));
			//perso2choisi->move(0, (-dureeIteration.asSeconds()*((perso2choisi->GetPoids()/ Gravity) * VitesseSaut)));
		}
		if (!perso2choisi->getCollision() &&  perso1choisi->getVersbas() && !perso2choisi->getAttaque())
		{
			perso2choisi->move(0, (dureeIteration.asSeconds()*((perso2choisi->GetPoids()) * Gravity)));
		}
		if (perso2choisi->getAttaque())
		{
			if (perso2choisi->CheckAttaque(perso1choisi))
			{
				{
					perso2choisi->Attaque(perso1choisi, perso2choisi->GetLastTime());
				}
				if (perso2choisi->GetLastTime() == 1)//droite
				{
					perso1choisi->move(perso1choisi->GetPourcentages()*dureeIteration.asSeconds()*VitesseDeplacement, 0);
				}
				if (perso2choisi->GetLastTime() == 2)//gauche
				{
					perso1choisi->move(-perso1choisi->GetPourcentages()*dureeIteration.asSeconds()*VitesseDeplacement, 0);
				}
			}
		}
	} 
}



void Jeu::CheckCollision(Personnage *michel)
{	
	for (int i = 0; i < (mapchoisie->GetVectorPlatefomes()).size(); i++)
	{
		michel->CheckCollision(mapchoisie->getPlatform(i),0,this->dureeIteration);
		//mapchoisie->getPlatform(i)->CheckCollision(michel, 0.0f);
	}
	if (michel->getCheckCollision())
	{
		michel->setCollision(true);
	}
	if (!michel->getCheckCollision())
	{
		michel->setCollision(false);
		michel->setVersbas(true);
		michel->setVershaut(true);
		michel->setVersgauche(true);
		michel->setVersdroite(true);
	}
	michel->setCheckCollision(false);
	
}

void Jeu::CheckAttaque(Personnage * michel)
{
}



void Jeu::Animate(Personnage *perso, std::string direction)
{
	
	TextureManager *texture_move;
	texture_move= new TextureManager();
	NomTextureMove = perso->GetAvatar();
	sf::Time timer_Move = clock_Move->getElapsedTime();

	std::cout << dureeIteration.asSeconds() << std::endl;

	if (timer_Move.asSeconds() >= 0.2 && direction == "droite")
	{
		if (perso->GetLastTime() == 2)
		{
			perso->setScale(-1, 1);
			perso->SetLastTime(1);
		}
		perso->setTexture(*texture_move->SetTexture(NomTextureMove + std::to_string(Iteration) + ".png"));
		//perso->setScale(-1, 1);

		clock_Move->restart();
		this->Iteration = Iteration + 1;
		perso->SetLastTime(1);//Droite
	}
	if (timer_Move.asSeconds() >= 0.2 && direction == "gauche")
	{
		std::cout << sens << std::endl;
		if (perso->GetLastTime() == 1)
		{	
			perso->setScale(1, 1);
			perso->SetLastTime(2);
		}
		perso->setTexture(*texture_move->SetTexture(NomTextureMove + std::to_string(Iteration) + ".png"));
		clock_Move->restart();
		this->Iteration = Iteration + 1;
		perso->SetLastTime(2);//Gauche
	}
	if (timer_Move.asSeconds() >= 0.2 && direction == "jump")
	{
		perso->setTexture(*texture_move->SetTexture(NomTextureMove + "jump.png"));
		clock_Move->restart();
	}
	else if (this->Iteration == 4)
	{
		this->Iteration = 0;
	}
	delete texture_move;
	
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
	this->clock_Att = new sf::Clock;
	temporary_time = 60;
	CountDownInt = 5;
	Game_State = false;

	
	map->setBackground();
	map->setPlatefomes();
}

void Jeu::ChoixMap()
{
	

	switch (choix)
	{
	case 1 :
		this->mapchoisie = new Map1();
		this->TempsDeJeu = 95;
		break;
	case 2:
		this->mapchoisie = new Map2();
		this->TempsDeJeu = 95;
		break;
	}
}

void Jeu::ChoixPerso()
{


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

	
	switch (choix2)
	{
	case 1:

		perso2choisi = new Rick(Spawn_x2, Spawn_y2);
		
		std::cout << "J2 : Rick  \n " << std::endl;
		break;
	case 2:

		perso2choisi = new Morty(Spawn_x2, Spawn_y2);
	
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

void Jeu::SetView(sf::Vector2f* size)
{
	this->Vueprincipal = new sf::View();
	this->Vueprincipal->setCenter(0 , 0);
	this->Vueprincipal->setSize(*size);
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
	
	for (int i = 0; i < vectorHUD.size(); i++) // dessin successif des Drawable mes_objets dans leurs ordre de création[1][2]
	{
		fenetre->draw(*vectorHUD[i]);
	}
}



void Jeu::DrawBackGround(Back_Ground *BackGround)
{
	fenetre->draw(*BackGround);

}

sf::Time Jeu::GetdureeIteration()
{
	return dureeIteration;
}


// Fonction pour recuperer les informations des personnages et les ajouters au vector vectorHUD
void Jeu::CreateHUD()
{
	this->clock_Depart = new sf::Clock; // Demarrage count down depart
	

	NomPerso1 = new sf::Text;
	NomPerso2 = new sf::Text;

	Perso1 = new sf::Text;
	Perso2 = new sf::Text;
	ViePerso1 = new sf::Text;
	ViePerso2 = new sf::Text;
	BouclierPerso1 = new sf::Text;
	BouclierPerso2 = new sf::Text;
	AtoutPerso1 = new sf::Text;
	AtoutPerso2 = new sf::Text;
	PourcentPerso1 = new sf::Text;
	PourcentPerso2 = new sf::Text;
	HUDTimer = new sf::Text;
	
	avatar1 = new sf::Sprite;
	avatar2 = new sf::Sprite;


	FontManager *font;
	font = new FontManager();
	TextureManager *texture_hud;
	texture_hud = new TextureManager();


	// Creation de l' HUD
	avatar1->setTextureRect(sf::IntRect(0, 0, 80, 80));
	avatar1->setTexture(*texture_hud->SetTexture(perso1choisi->GetAvatar()+".png"));
	avatar1->setPosition(-720, -370);
	avatar1->setOrigin(avatar1->getGlobalBounds().width / 2, avatar1->getGlobalBounds().height / 2);

	vectorHUD.push_back(avatar1);

	Perso1->setString("Morty");
	Perso1->setFont(*font->SetFont("quicksand.ttf"));
	Perso1->setFillColor(sf::Color::Green);
	Perso1->setPosition(perso1choisi->getPosition().x, perso1choisi->getPosition().y-85);
	Perso1->setOrigin(Perso1->getGlobalBounds().width / 2, Perso1->getGlobalBounds().height / 2);
	vectorHUD.push_back(Perso1);

	NomPerso1->setString("Morty");
	NomPerso1->setFont(*font->SetFont("quicksand.ttf"));
	NomPerso1->setFillColor(sf::Color::Green);
	NomPerso1->setPosition(-670, -410);
	vectorHUD.push_back(NomPerso1);

	ViePerso1->setString("Vie restante : 3");
	ViePerso1->setFont(*font->SetFont("quicksand.ttf"));
	ViePerso1->setFillColor(sf::Color::Green);
	ViePerso1->setCharacterSize(24);
	ViePerso1->setPosition(-670, -360);
	vectorHUD.push_back(ViePerso1);

	BouclierPerso1->setString("Bouclier : 100%");
	BouclierPerso1->setFont(*font->SetFont("quicksand.ttf"));
	BouclierPerso1->setFillColor(sf::Color::Green);
	BouclierPerso1->setCharacterSize(24);
	BouclierPerso1->setPosition(-480, -410);
	vectorHUD.push_back(BouclierPerso1);

	AtoutPerso1->setString("");
	AtoutPerso1->setFont(*font->SetFont("quicksand.ttf"));
	AtoutPerso1->setFillColor(sf::Color::Green);
	AtoutPerso1->setCharacterSize(24);
	AtoutPerso1->setPosition(-480, -360);
	vectorHUD.push_back(AtoutPerso1);


	PourcentPerso1->setString("");
	PourcentPerso1->setFont(*font->SetFont("quicksand.ttf"));
	PourcentPerso1->setFillColor(sf::Color::Green);
	PourcentPerso1->setCharacterSize(50);
	PourcentPerso1->setPosition(-740, +360);
	vectorHUD.push_back(PourcentPerso1);


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

	PourcentPerso2->setString("");
	PourcentPerso2->setFont(*font->SetFont("quicksand.ttf"));
	PourcentPerso2->setFillColor(sf::Color::Blue);
	PourcentPerso2->setCharacterSize(50);
	PourcentPerso2->setOrigin(PourcentPerso2->getGlobalBounds().width, 0);
	PourcentPerso2->setPosition(+740, +360);
	vectorHUD.push_back(PourcentPerso2);

	Perso2->setString(perso2choisi->GetNom());
	Perso2->setFont(*font->SetFont("quicksand.ttf"));
	Perso2->setFillColor(sf::Color::Blue);
	Perso2->setPosition(perso2choisi->getPosition().x, perso2choisi->getPosition().y - 85);
	Perso2->setOrigin(Perso2->getGlobalBounds().width / 2, Perso2->getGlobalBounds().height / 2);
	vectorHUD.push_back(Perso2);

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

	Perso1->setString(perso1choisi->GetNom());
	Perso1->setOrigin(Perso1->getGlobalBounds().width / 2, Perso1->getGlobalBounds().height / 2);
	Perso1->setPosition(perso1choisi->getPosition().x, perso1choisi->getPosition().y + -85);

	Perso2->setString(perso2choisi->GetNom());
	Perso2->setOrigin(Perso2->getGlobalBounds().width / 2, Perso2->getGlobalBounds().height / 2);
	Perso2->setPosition(perso2choisi->getPosition().x, perso2choisi->getPosition().y + -85);
	
	

	NomPerso1->setString(perso1choisi->GetNom());
	NomPerso2->setString(perso2choisi->GetNom());

	ViePerso1->setString("Vies restantes :" + std::to_string(perso1choisi->GetNbre_Vies()));
	ViePerso2->setString("Vies restantes :" + std::to_string(perso2choisi->GetNbre_Vies()));
	ViePerso2->setOrigin(ViePerso2->getGlobalBounds().width,0);

	BouclierPerso1->setString("Bouclier :" + std::to_string(perso1choisi->GetBouclier()));
	BouclierPerso2->setString("Bouclier :" + std::to_string(perso2choisi->GetBouclier()));
	BouclierPerso2->setOrigin(BouclierPerso2->getGlobalBounds().width, 0);

	PourcentPerso1->setString(std::to_string(perso1choisi->GetPourcentages()) + "%");
	PourcentPerso2->setString(std::to_string(perso2choisi->GetPourcentages()) + "%");
	PourcentPerso2->setOrigin(PourcentPerso2->getGlobalBounds().width, 0);

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
		Game_State_Final = false;
	}
	else // Continue à incrementer
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
		
		Game_State_Final = true;
	}

}

void Jeu::CountDown()
{
	
	sf::Time timer_Depart = clock_Depart->getElapsedTime();
	
	if (timer_Depart.asSeconds() >= 1 && Game_State==false)
	{
		this->CountDownInt = CountDownInt - 1;
		this->HUDTimer->setString( "Start du game dans :" + std::to_string(this->CountDownInt));
		this->HUDTimer->setOrigin(HUDTimer->getGlobalBounds().width / 2, HUDTimer->getGlobalBounds().height / 2);
		clock_Depart->restart();
		Game_State = false;
		clock_HUD->restart();
			
	}
	else if(CountDownInt==0)
	{
		Game_State = true;
	}
}

void Jeu::CheckVictory()
{

	// Function to test if game is done
	Winner = new sf::Sprite;

	//std::cout<< perso1choisi.GetN <<std::endl;
	if (perso1choisi->GetBouclier() <= 0 || Perso1Bord == true || !perso1choisi->CheckZone(this->GetMapChoisie()->getBackground()))
	{
		if (perso1choisi->GetNbre_Vies()<=0)
		{
			PersoGagne(perso1choisi,perso2choisi);
		}
		else
		{
			perso1choisi->SetPourcentages(0);
			perso1choisi->SetNbre_Vies(perso1choisi->GetNbre_Vies()-1);
			perso1choisi->setPosition(Spawn_x1, Spawn_y1);
		}
		
	}

	if (perso2choisi->GetBouclier() <= 0 || Perso2Bord == true || !perso2choisi->CheckZone(this->GetMapChoisie()->getBackground())) // Rick Gagne
	{
		if (perso2choisi->GetNbre_Vies() <= 0)
		{
			PersoGagne(perso2choisi, perso1choisi);
		}
		else
		{
			perso2choisi->SetPourcentages(0);
			perso2choisi->SetNbre_Vies(perso2choisi->GetNbre_Vies() -1);
			perso2choisi->setPosition(Spawn_x1, Spawn_y1);
		}
	}
	if (Game_State_Final == false && Game_State==true)// Si le timer arrive à 0
	{
		std::cout << " Time's UP " << std::endl;

		if (perso2choisi->GetNbre_Vies() < perso1choisi->GetNbre_Vies())
		{
			PersoGagne(perso2choisi, perso1choisi); // Perso 1 Gagne
		}
		if (perso1choisi->GetNbre_Vies() < perso2choisi->GetNbre_Vies())
		{
			PersoGagne(perso1choisi, perso2choisi); // Perso 2 Gagne
		}

	}

	//delete texture_hud;

}

void Jeu::PersoGagne(Personnage *perso1,Personnage *perso2)
{
	TextureManager *texture_Rick;
	texture_Rick = new TextureManager();
	
	perso1->setTexture(*texture_Rick->SetTexture(perso1->GetAvatar() + "victory.png"));
	perso2->setTexture(*texture_Rick->SetTexture(perso2->GetAvatar() + "victory.png"));

	Game_State_Final = false;

	this->HUDTimer->setString(perso1->GetNom() + " Winner ");
	this->HUDTimer->setOrigin(HUDTimer->getGlobalBounds().width / 2, HUDTimer->getGlobalBounds().height / 2);
	delete texture_Rick;
}

void Jeu::StartMenu()
{

	sf::RenderWindow Menu(sf::VideoMode(800, 600), "Menu");
	std::string NomJoueur1="";
	std::string NomJoueur2="";
	std::string MAP = "";
	choix = 1;

	while (Menu.isOpen())
	{
		FontManager *font;
		font = new FontManager();
		TextureManager *texture_menu;
		texture_menu= new TextureManager();
		MenuMap1 = new sf::Sprite;
		MenuMap1->setTextureRect(sf::IntRect(0, 0, 1600, 900));
		MenuMap1->setTexture(*texture_menu->SetTexture("background_map1.png"));
		MenuMap1->setScale(0.1, 0.1);
		MenuMap1->setPosition(200, 100);

		MenuMap2 = new sf::Sprite;
		MenuMap2->setTextureRect(sf::IntRect(0, 0, 1600, 900));
		MenuMap2->setTexture(*texture_menu->SetTexture("background_map2.png"));
		MenuMap2->setScale(0.1, 0.1);
		MenuMap2->setPosition(400, 100);

		Joueur1 = new sf::Text;
		Joueur1->setPosition(200, 300);
		Joueur1-> setFont(*font->SetFont("quicksand.ttf"));
		Joueur1->setString("Joueur 1:" + NomJoueur1);
		Joueur1->setFillColor(sf::Color::Green);


		Joueur2 = new sf::Text;
		Joueur2->setPosition(500, 300);
		Joueur2->setFont(*font->SetFont("quicksand.ttf"));
		Joueur2->setString("Joueur 2 :"+NomJoueur2);
		Joueur2->setFillColor(sf::Color::Green);

		SelectedMap = new sf::Text;
		SelectedMap->setPosition(300, 50);
		SelectedMap->setFont(*font->SetFont("quicksand.ttf"));
		SelectedMap->setString("MAP :" + MAP);
		SelectedMap->setFillColor(sf::Color::Green);

		MenuJ1Morty = new sf::Sprite;
		MenuJ1Morty->setTextureRect(sf::IntRect(0, 0,80,80));
		MenuJ1Morty->setTexture(*texture_menu->SetTexture("morty.png"));
		MenuJ1Morty->setPosition(150, 400);

		MenuJ1Rick = new sf::Sprite;
		MenuJ1Rick->setTextureRect(sf::IntRect(0, 0, 80, 80));
		MenuJ1Rick->setTexture(*texture_menu->SetTexture("rick.png"));
		MenuJ1Rick->setPosition(250, 400);

		MenuJ2Morty = new sf::Sprite;
		MenuJ2Morty->setTextureRect(sf::IntRect(0, 0, 80, 80));
		MenuJ2Morty->setTexture(*texture_menu->SetTexture("morty.png"));
		MenuJ2Morty->setPosition(450, 400);

		MenuJ2Rick = new sf::Sprite;
		MenuJ2Rick->setTextureRect(sf::IntRect(0, 0, 80, 80));
		MenuJ2Rick->setTexture(*texture_menu->SetTexture("rick.png"));
		MenuJ2Rick->setPosition(550, 400);

		Play = new sf::Sprite;
		Play->setTextureRect(sf::IntRect(0, 0, 1024, 1024));
		Play->setScale(0.0781, 0.0781);
		Play->setTexture(*texture_menu->SetTexture("play.png"));
		Play->setPosition(600, 500);
	   	  

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (Menu.pollEvent(event))
		{


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (Play->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					Menu.close();
				}
				if (MenuMap1->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					std::cout << "MAp 1 Map : " << choix << std::endl;
					this->choix = 1;
					MAP = "SF";
				}
				if (MenuMap2->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					std::cout << "MAp2 Map : " << choix << std::endl;
					this->choix = 2;
					MAP = "Desert";
				}

				if (MenuJ1Morty->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					std::cout << "Choix 1 : " << choix << std::endl;
					this->choix1 = 1;
					NomJoueur1 = "Morty";
				}
				if (MenuJ1Rick->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					std::cout << "Choix 1 : " << choix << std::endl;
					this->choix1 = 2;
					NomJoueur1 = "Rick";
				}
				if (MenuJ2Morty->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					std::cout << "Choix 1 : " << choix << std::endl;
					this->choix2 = 1;
					NomJoueur2 = "Morty";
				}
				if (MenuJ2Rick->getGlobalBounds().contains(Menu.mapPixelToCoords(sf::Mouse::getPosition(Menu))))
				{
					std::cout << "Choix 1 : " << choix << std::endl;
					this->choix2 = 2;
					NomJoueur2 = "Rick";
				}
			}

			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				Menu.close();
		}

		Menu.clear();
		Menu.draw(*MenuMap1);
		Menu.draw(*MenuMap2);
		Menu.draw(*Joueur1);
		Menu.draw(*Joueur2);
		Menu.draw(*MenuJ1Morty);
		Menu.draw(*MenuJ1Rick);
		Menu.draw(*MenuJ2Morty);
		Menu.draw(*MenuJ2Rick);
		Menu.draw(*Play);
		Menu.draw(*SelectedMap);
		Menu.display();


		delete texture_menu;
		delete font;
	}


	
	Menu.close();


}

