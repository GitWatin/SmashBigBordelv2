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
	std::string PathPlateformeTiny = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat_tiny.png";
	std::string PathPlateformePetite = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat_petite.png";
	std::string PathPlateformeGrande = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat_grande.png";
	std::string PathBackground = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\background.png";
};

