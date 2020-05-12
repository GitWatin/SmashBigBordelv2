#include "Morty.h"


Morty::Morty() : Personnage()
{
	;
}

void Morty::SetPersonnage()
{
	TextureManager *t;
	t = new TextureManager();

	this->perso = new Morty();

	this->perso->SetBouclier(50);
	this->perso->SetPoids(80);
	this->perso->SetPourcentages(0);
	this->perso->SetNbre_Vies(3);
	this->perso->SetNom("Rick : " /*+ NomJoueur*/);


	this->perso->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->perso->setTextureRect(sf::IntRect(0, 0, 90, 90));
	this->perso->setColor(sf::Color::Black);
	this->perso->setOrigin(this->perso->getGlobalBounds().width / 2, this->perso->getGlobalBounds().height / 2);
	this->perso->setPosition(-100, 0);

	Dessin.push_back(this->perso);
	delete t;
}

void Morty::Attaque(Personnage *NomCible, std::string TypeAttaque)
{
}

std::string Morty::GetPathTexture()
{
	return PathTexture;
}


