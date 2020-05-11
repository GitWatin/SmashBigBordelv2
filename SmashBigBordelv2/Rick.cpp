#include "Rick.h"
#include "TextureManager.h"

Rick::Rick() : Personnage()
{
	TextureManager *t;
	t = new TextureManager();

	this->perso = new Rick();

	this->perso->SetBouclier(50);
	this->perso->SetPoids(80);
	this->perso->SetPourcentages(0);
	this->perso->SetNbre_Vies(3);
	this->perso->SetNom("Rick : " /*+ NomJoueur*/);


	//this->perso->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->perso->setTextureRect(sf::IntRect(0, 0, 268, 90));
	this->perso->setColor(sf::Color::Green);
	this->perso->setOrigin(this->perso->getGlobalBounds().width / 2, this->perso->getGlobalBounds().height / 2);

	this->perso->setPosition(0, 0);

	this->perso->SetVectorPersonnages(perso);

	delete t;

}

void Rick::SetPersonnage()
{

}

void Rick::Attaque(Personnage *NomCible, std::string TypeAttaque)
{

}

std::string Rick::GetPathTexture()
{
	return PathTexture;
}