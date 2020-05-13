#include "Plateforme.h"
#include "Map.h"
#include "Entite.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>


Plateforme::Plateforme()
{
	;
}


/*Plateforme::Plateforme(float position_x, float position_y, float taille_x, float taille_y, std::string path_texture) : Entite(position_x,  position_y, taille_x, taille_y, path_texture)//envoyer (pos x , pos y , taille_x , taille_y , *pointeur de texture)
{	
	sf::Sprite *plateforme;
	TextureManager *tl;
    tl=new TextureManager;
	plateforme = new sf::Sprite;
	sf::Texture *texture ;
    texture=new sf::Texture;
	std::cout << "[Path Plateforme.cpp]:" << path_texture << std::endl;
    texture = tl->SetTexture(path_texture);
	plateforme->setTexture(*texture);
	plateforme->setTextureRect(sf::IntRect(0, 0, Taille_X, Taille_Y));
	plateforme->setPosition(Position_X,Position_Y);
	plateforme->setColor(sf::Color::Red);
	std::cout << "Plateforme cree" << std::endl;
}*/


Plateforme::~Plateforme()
{
	;
}


