#pragma once
#include "Entite.h"
#include "TextureManager.h"
class Limite :
	public Entite
{

public:
	Limite(float x, float y, float width, float height);
	virtual std::string GetPathTexture();
	~Limite();
protected:
	std::string PathTexture = "morty0.png";
};

