#include "Limite.h"

Limite::Limite(float x,float y,float width,float height)
{
	TextureManager *t;
	t = new TextureManager();

	delete t;
}

std::string Limite::GetPathTexture()
{
	return PathTexture;
}

Limite::~Limite()
{
}
