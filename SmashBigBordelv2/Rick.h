#pragma once
#include "Personnage.h"
class Rick :
	public Personnage
{
public:
	Rick();
	void SetPersonnage();
	void Attaque(Personnage *NomCible, std::string TypeAttaque);

	std::string GetPathTexture();

protected:

	std::string PathTexture = "  ";// rajouter le path
};

