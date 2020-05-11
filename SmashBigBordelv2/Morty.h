#pragma once
#include "Personnage.h"
class Morty :
	public Personnage
{
public:
	Morty();
	void SetPersonnage();
	void Attaque(Personnage *NomCible, std::string TypeAttaque);

protected:
	Morty *perso;
};

