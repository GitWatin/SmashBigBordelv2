#include "Limite.h"

Limite::Limite(float x,float y,float width,float height)
{
	TextureManager *t;
	t = new TextureManager();
	this->setTexture(*t->SetTexture(this->GetPathTexture()));
	this->setTextureRect(sf::IntRect(0, 0, width, height));
	this->setColor(sf::Color::Red);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->setPosition(x, y);
	delete t;
}

std::string Limite::GetPathTexture()
{
	return PathTexture;
}

Limite::~Limite()
{
}
