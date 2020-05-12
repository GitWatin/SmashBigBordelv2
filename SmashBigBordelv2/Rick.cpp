#include "Rick.h"


Rick::Rick() : Personnage()
{
	TextureManager *t;
	t = new TextureManager();



	this->SetBouclier(50);
	this->SetPoids(100);
	this->SetPourcentages(0);
	this->SetNbre_Vies(3);
	this->SetNom("Rick " /*+ NomJoueur*/);
	this->SetAvatar("plat_tiny.png"); // Avatar de l'HUD
	this->SetDerniersAtout("Toto");

	this->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->setTextureRect(sf::IntRect(0, 0, 90, 90));
	this->setColor(sf::Color::Green);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->setPosition(100, 0);

	Dessin.push_back(this);

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