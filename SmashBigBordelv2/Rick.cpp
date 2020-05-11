#include "Rick.h"
#include "TextureManager.h"

Rick::Rick() : Personnage()
{
	TextureManager *t;
	t = new TextureManager();

	this->perso = new Rick();
	this->perso->SetBouclier(50);
	this->perso->SetNbre_Vies(3);
	this->perso->SetNom("Rick : " /*+ NomJoueur*/);
	this->perso->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->perso->setPosition(0, 0);

	this->perso->SetVectorPersonnages(perso);

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