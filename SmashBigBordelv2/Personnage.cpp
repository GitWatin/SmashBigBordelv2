#include "Personnage.h"



Personnage::Personnage() : Entite()
{
	;
}

Personnage::~Personnage()
{
	for (int i = 0; i < Dessin.size(); i++) // suppression des Drawable mes_objets
	{
		delete Dessin.back();
		Dessin.pop_back();
	}
}

// -------------------------- Pourcentages ---------------------------------

void Personnage::SetPourcentages(double percent)
{
	this->Pourcentages = percent;
}

double Personnage::GetPourcentages()
{
	return Pourcentages;
}

// -------------------------- Poids ---------------------------------

void Personnage::SetPoids(int poids)
{
	this->Poids = poids;
}

int Personnage::GetPoids()
{
	return Poids;
}

// -------------------------- Nombres VIES ---------------------------------

void Personnage::SetNbre_Vies(int nbre_vies)
{
	this->Nbre_Vies = nbre_vies;
}

int Personnage::GetNbre_Vies()
{
	return Nbre_Vies;
}

// -------------------------- Derniers Atouts ---------------------------------

void  Personnage::SetDerniersAtout(std::string derniers_atout)
{
	this->DerniersAtout = derniers_atout;
}

std::string  Personnage::GetDerniersAtout()
{
	return DerniersAtout;
}

// -------------------------- Bouclier ---------------------------------

void Personnage::SetBouclier(int bouclier)
{
	this->Bouclier = bouclier;

}

int Personnage::GetBouclier()
{
	return Bouclier;
}

std::string Personnage::GetAvatar()
{
	return this->Path_Avatar;
}

void Personnage::SetAvatar(std::string path_avatar)
{
	this->Path_Avatar = path_avatar;
}

void Personnage::setMoveRight()
{
	this->moveRight= !this->moveRight;
}

void Personnage::setMoveLeft()
{
	this->moveLeft = !this->moveLeft;
}

void Personnage::setJump()
{
}

bool Personnage::getMoveRight()
{
	return this->moveRight;
}

bool Personnage::getMoveLeft()
{
	return this->moveLeft;
}

bool Personnage::getJump()
{
	return this->Jump;
}



std::vector<Personnage*> Personnage::GetVectorPersonnage()
{
	return Dessin;
}


