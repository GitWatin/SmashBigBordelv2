#include "Morty.h"
#include "TextureManager.h"

Morty::Morty() : Personnage()
{
	TextureManager *t;
	t = new TextureManager();

	this->perso = new Morty();
	this->perso->SetBouclier(50);
	this->perso->SetNbre_Vies(3);
	this->perso->SetNom("Rick : " /*+ NomJoueur*/);
	this->perso->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->perso->setPosition(0, 0);

	this->perso->SetVectorPersonnages(perso);
}

void Morty::SetPersonnage()
{
}

void Morty::Attaque(Personnage *NomCible, std::string TypeAttaque)
{
}
