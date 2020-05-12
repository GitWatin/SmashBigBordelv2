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
	return this->Pourcentages;
}

// -------------------------- Poids ---------------------------------

void Personnage::SetPoids(int poids)
{
	this->Poids = poids;
	std::cout << "Poids Envoye� : "<< poids << " Poids perso :" << Poids << std::endl;
}

int Personnage::GetPoids()
{
	return this->Poids;
}

// -------------------------- Nombres VIES ---------------------------------

void Personnage::SetNbre_Vies(int nbre_vies)
{
	this->Nbre_Vies = nbre_vies;
}

int Personnage::GetNbre_Vies()
{
	return this->Nbre_Vies;
}

// -------------------------- Derniers Atouts ---------------------------------

void  Personnage::SetDerniersAtout(std::string derniers_atout)
{
	this->DerniersAtout = derniers_atout;
}

std::string  Personnage::GetDerniersAtout()
{
	return this->DerniersAtout;
}

// -------------------------- Bouclier ---------------------------------

void Personnage::SetBouclier(int bouclier)
{
	this->Bouclier = bouclier;

}

int Personnage::GetBouclier()
{
	return this->Bouclier;
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
	return this->Dessin;
}


