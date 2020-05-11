#pragma once
#include "Map.h"
#include <iostream>


class Map1 :
	public Map
{
 public:
		Map1();
		virtual void setPlatefomes();
		virtual std::string GetPath();
		//virtual std::string GetPathPlateforme();
		//virtual std::string GetPathBackground();
	protected:
		std::string Path = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat1.png";
};

