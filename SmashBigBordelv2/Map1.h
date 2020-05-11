#pragma once
#include "Map.h"
#include <iostream>


class Map1 :
	public Map
{
 public:
		Map1();
		virtual void setPlatefomes();
		virtual void setBackground();
		virtual std::string GetPath(int taille);
		std::string GetPathBackground();

	protected:
		
		std::string PathPlateformeTiny = "plat_tiny.png";
		std::string PathPlateformePetite = "plat_petite.png";
		std::string PathPlateformeGrande = "plat_grande.png";
		std::string PathBackground = "background_map1.png";
};


