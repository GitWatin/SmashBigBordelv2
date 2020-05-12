#include "FontManager.h"

FontManager::FontManager()
{
	;
}

FontManager::~FontManager()
{
	map_font.clear();
}


sf::Font * FontManager::SetFont(std::string path_font)
{
	std::cout << "[Debut du chargement de la texture] :" << std::endl;

	static sf::Font *font;

	font = this->GetFont(path_font);// Mr Lerat on a un problème ici aussi ( renvoie l'erreur std::out_of_range car pas d'élément "trouvable" dans map)
	if (font == NULL)
	{
		std::cout << "[INFO] -[] :Premier IF " << std::endl;
		font = new sf::Font;

		if (!font->loadFromFile(path_font))
		{

			// throw erreur
			std::cout << "[Error] -[] :Erreur dans le chargement de la Font " << path_font << std::endl;
			return 0;
		}
		else
		{
			std::cout << "[Font chargée] :" << path_font << std::endl;
			this->map_font.insert(std::pair<std::string, sf::Font*>(path_font, font));
		}

	}
	return font;
}


sf::Font * FontManager::GetFont(std::string path_font)
{
	std::cout << "[Path Texture Manager]:" << path_font << std::endl;


	if (map_font.find(path_font) == map_font.end())
	{
		// Ca n'existe pas 
		return NULL;
	}
	else
	{
		// Du coup ca existe MDR hg
		return  map_font.find(path_font)->second;
	}
}

