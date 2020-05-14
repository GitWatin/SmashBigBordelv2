#include "TextureManager.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>



TextureManager::TextureManager()
{
	;
}

sf::Texture* TextureManager::SetTexture(std::string path_texture)
{

	static sf::Texture *texture;
	
	texture = this->GetTexture(path_texture);
	if (texture == NULL)
	{
		
		texture = new sf::Texture;

		if (!texture->loadFromFile(path_texture))
		{
			// throw erreur
			std::cout << "[Error] -[] :Erreur dans le chargement de la texture " << path_texture << std::endl;
			return 0;
		}
		else
		{
			std::cout << "[Texture chargee] :" << path_texture << std::endl;
			this->map_textures.insert(std::pair<std::string, sf::Texture*>(path_texture, texture));
		}
		
	}
	return texture;

}

sf::Texture * TextureManager::GetTexture(std::string path_texture)
{

	if (map_textures.find(path_texture) == map_textures.end())
	{
		
		return NULL;
	}
	else
	{
		std::cout << "[J'ai trouve une texture] :" << path_texture << std::endl;
		
		return  map_textures.find(path_texture)->second;
	}

}


TextureManager::~TextureManager()
{

	map_textures.clear();
	
}

