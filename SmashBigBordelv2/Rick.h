#pragma once
#include "Personnage.h"
#include "TextureManager.h"
class Rick :
	public Personnage
{
public:
	Rick(int x, int y);
	void Attaque(Personnage *NomCible, int TypeAttaque);
	virtual void SetPathTexture(std::string path_texture_rick);

	std::string GetPathTexture();
	
protected:

	std::string PathTexture;


};

