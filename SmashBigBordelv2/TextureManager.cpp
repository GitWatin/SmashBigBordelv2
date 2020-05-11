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
	
	std::cout << "[Debut du chargement de la texture] :" << std::endl;

	static sf::Texture *texture;
	
	texture = this->GetTexture(path_texture);// Mr Lerat on a un problème ici aussi ( renvoie l'erreur std::out_of_range car pas d'élément "trouvable" dans map)
	if (texture == NULL)
	{
		std::cout << "[INFO] -[] :Premier IF " << std::endl;
		texture = new sf::Texture;

		if (!texture->loadFromFile(path_texture))
		{

			// throw erreur
			std::cout << "[Error] -[] :Erreur dans le chargement de la texture " << path_texture << std::endl;
			return 0;
		}
		else
		{
			std::cout << "[Texture chargée] :" << path_texture << std::endl;
			this->map_textures.insert(std::pair<std::string, sf::Texture*>(path_texture, texture));
		}
		
	}
	return texture;

}

sf::Texture * TextureManager::GetTexture(std::string path_texture)
{// Ici on a un problème 
	std::cout << "[Path Texture Manager]:" << path_texture << std::endl;

	if (!map_textures.find(path_texture))
	{
		std::cout << "[MAP NULL]:" << path_texture << std::endl;
		return NULL;
	}
	else
	{

		std::cout << "[ELSE FOR]:" << path_texture << std::endl;
		

		for (auto itr = map_textures.find(path_texture); itr != map_textures.end(); itr++)
		{

			std::cout << "[Path Texture Manager IN FOR]:" << itr->second << std::endl;
			return itr->second;
		}
	}


		
}


TextureManager::~TextureManager()
{

	map_textures.clear();
	// Supprimer chaque pointeur
}

