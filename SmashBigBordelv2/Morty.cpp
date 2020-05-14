#include "Morty.h"


Morty::Morty(int x, int y) : Personnage()
{
	TextureManager *t;
	t = new TextureManager();

	this->SetBouclier(50);
	this->SetPoids(60);
	this->SetPourcentages(0);
	this->SetNbre_Vies(1);
	this->SetNom("Morty");
	this->SetAvatar("morty"); // Avatar de l'HUD
	this->SetPathTexture("morty0.png");
	this->SetDerniersAtout("Han ouais");
	this->LastTime = 2;
	
	this->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->setTextureRect(sf::IntRect(0, 0, 78, 110));
	//this->setColor(sf::Color::Black);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->setPosition(x , y);
	Dessin.push_back(this);

	delete t;
}


void Morty::Attaque(Personnage *NomCible, std::string TypeAttaque)
{
}

std::string Morty::GetPathTexture()
{
	return PathTexture;
}



void Morty::SetPathTexture(std::string path_perso)
{
	this->PathTexture = path_perso;
}




