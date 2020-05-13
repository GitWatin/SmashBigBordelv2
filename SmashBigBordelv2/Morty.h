#pragma once
#include "Personnage.h"
#include "TextureManager.h"
class Morty :
	public Personnage
{
public:
	Morty(int x, int y);
	void SetPersonnage();
	void Attaque(Personnage *NomCible, std::string TypeAttaque);
	std::string GetPathTexture();


	virtual void SetPathTexture(std::string path_perso);

protected:
	
	std::string PathTexture;

};

