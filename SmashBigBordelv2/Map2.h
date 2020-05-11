#pragma once
#include "Map.h"
class Map2 :
	public Map
{
public:
	Map2();
	virtual void setPlatefomes();
	virtual void setBackground();

	virtual std::string GetPath(int taille);

	std::string GetPathBackground();
	//virtual std::string GetPathPlateforme();
	//virtual std::string GetPathBackground();
protected:
	std::string PathPlateformeTiny = "plat2_tiny.png";
	std::string PathPlateformePetite = "plat2_petite.png";
	std::string PathPlateformeGrande = "plat2_grande.png";
	std::string PathBackground = "background_map2.png";
};

