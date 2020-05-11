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
		virtual std::string GetPath();
		std::string GetPathBackground();
		//virtual std::string GetPathPlateforme();
		//virtual std::string GetPathBackground();
	protected:
		std::string Path = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat1.png";
		std::string PathBackground = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat1.png";
};

