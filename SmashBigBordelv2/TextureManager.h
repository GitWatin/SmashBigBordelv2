#pragma once
#include "Jeu.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
class TextureManager
{
public :
	TextureManager();
	~TextureManager();
	virtual sf::Texture* GetTexture(std::string path_texture);
	virtual sf::Texture* SetTexture(std::string path_texture);

protected :
	std::map<std::string, sf::Texture*> map_textures;

};

