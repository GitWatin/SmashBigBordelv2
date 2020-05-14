#include "Rick.h"


Rick::Rick(int x,int y) : Personnage()
{
	TextureManager *t;
	t = new TextureManager();



	this->SetBouclier(50);
	this->SetPoids(100);
	this->SetPourcentages(0);
	this->SetNbre_Vies(3);
	this->SetNom("Rick");
	this->SetAvatar("rick"); // Avatar de l'HUD
	this->SetDerniersAtout("");
	this->SetPathTexture("rick0.png");
	this->SetLastTime(2);

	this->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->setTextureRect(sf::IntRect(0, 0, 85, 124));
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->setPosition(x, y);
	*t->SetTexture(this->GetAvatar() + "victory.png");
	Dessin.push_back(this);

	delete t;
}



void Rick::Attaque(Personnage *NomCible, int TypeAttaque)
{
	
	if (TypeAttaque = 1)//droite
	{
		NomCible->SetPourcentages(NomCible->GetPourcentages() + 10);
	}
	if (TypeAttaque = 2)//gauche
	{
		NomCible->SetPourcentages(NomCible->GetPourcentages() + 10);

	}

}

void Rick::SetPathTexture(std::string path_texture_rick)
{
	this->PathTexture = path_texture_rick;
}



std::string Rick::GetPathTexture()
{
	return PathTexture;
}