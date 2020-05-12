#include "Jeu.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

class FontManager
{
	FontManager();
	~FontManager();

	virtual sf::Font* GetFont(std::string path_font);
	virtual sf::Font* SetFont(std::string path_font);

protected:
	std::map<std::string, sf::Font*> map_font;

};

