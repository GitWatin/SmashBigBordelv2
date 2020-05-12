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

protected:
	
	std::string PathTexture = "plat_tiny.png";
};

