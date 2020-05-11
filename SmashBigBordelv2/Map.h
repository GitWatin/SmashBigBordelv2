#pragma once
#include "Plateforme.h"
#include <iostream>
class Map
{
    public:

    Map(int plateforme);
	~Map(void);
	virtual void setBackground() = 0;
	virtual void setPlatefomes()= 0;
	int countPlatforms();

	Plateforme* getPlatform(int pos);
	
	virtual std::vector< Plateforme* >GetVectorPlatefomes();
	
	/*
    virtual std::string GetPathPlateforme();
	virtual std::string GetPathBackground();

	virtual float GetPlat1PosX();
	virtual float GetPlat1PosY();
	virtual float GetPlat1TailleX();
	virtual float GetPlat1TailleY();

	virtual float GetPlat2PosX();
	virtual float GetPlat2PosY();
	virtual float GetPlat2TailleX();
	virtual float GetPlat2TailleY();

	virtual float GetPlat3PosX();
	virtual float GetPlat3PosY();
	virtual float GetPlat3TailleX();
	virtual float GetPlat3TailleY();

	virtual float GetPlat4PosX();
	virtual float GetPlat4PosY();
	virtual float GetPlat4TailleX();
	virtual float GetPlat4TailleY();

	virtual float GetPlat5PosX();
	virtual float GetPlat5PosY();
	virtual float GetPlat5TailleX();
	virtual float GetPlat5TailleY();
	*/

protected:

	std::vector < Plateforme* > plateformes;
	sf::RectangleShape *BackGround;

	// Nom de la carte
	//std::string NomMap;

	// Position plateforme
	//float TabPos1[4];
	//float TabPos2[4];
	//float TabPos3[4];
	//float TabPos4[4];
	//float TabPos5[4];

	// Chemin accès background 
	//std::string PathBackground;
	
	// Path Plateforme
	//std::string PathPlateforme;
};

