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
	 //float Pos_X;
	 //float Pos_Y;
	 //float Taille_X;
	 //float Taille_Y;
	 //Plateforme *NTMPlateforme; // Pas besoin du destructeur s
};

