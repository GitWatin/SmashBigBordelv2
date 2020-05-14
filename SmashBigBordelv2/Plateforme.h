#pragma once
#include "Entite.h"
#include <iostream>

class Plateforme :
	public Entite
{
	public:
		Plateforme(float position_x, float position_y, float taille_x, float taille_y);
		Plateforme();
		~Plateforme();
	protected:

};

