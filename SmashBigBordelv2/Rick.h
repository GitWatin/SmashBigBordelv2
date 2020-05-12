#pragma once
#include "Personnage.h"
#include "TextureManager.h"
class Rick :
	public Personnage
{
public:
	Rick();
	void SetPersonnage();
	void Attaque(Personnage *NomCible, std::string TypeAttaque);

	std::string GetPathTexture();

protected:

	std::string PathTexture = "plat_tiny.png";// rajouter le path
};

