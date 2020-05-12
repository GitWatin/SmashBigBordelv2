#include "Personnage.h"



Personnage::Personnage() : Entite()
{
	
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

void Personnage::SetVectorPersonnages(Personnage * drawable)
{
	Dessin.push_back(drawable);
}

std::vector<Personnage*> Personnage::GetVectorDrawable()
{
	return Dessin;
}


