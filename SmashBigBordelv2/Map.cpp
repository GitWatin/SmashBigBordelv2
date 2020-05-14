#include "Map.h"


Map::Map(int plateforme)
{
	while (plateforme) 
	{
		this->plateformes.push_back(new Plateforme());// TODO créer un constructeur vide ?
		plateforme--;
	}
	this->BackGround = new Back_Ground();
	this->limiteMap.push_back(new Limite(600,0,100,1100));
	this->limiteMap.push_back(new Limite(-600,0, 100, 1100));
	this->limiteMap.push_back(new Limite(350, 0, 1800, 100));
	this->limiteMap.push_back(new Limite(-350, 0, 100, 100));

	
}

Map::~Map(void)
{
	for (int i = 0; i < plateformes.size(); i++) // suppression des plateforme
	{
		delete plateformes.back();
		plateformes.pop_back();
	}
	delete BackGround;
	for (int i = 0; i < limiteMap.size(); i++) // suppression des plateforme
	{
		delete limiteMap.back();
		limiteMap.pop_back();
	}
}

int Map::countPlatforms() {
	return this->plateformes.size();
}

Plateforme * Map::getPlatform(int pos)
{
	return this->plateformes[pos];
}

std::vector< Plateforme* > Map::GetVectorPlatefomes()
{
	return plateformes;
}

std::vector<Limite*> Map::GetlimiteMap()
{
	return limiteMap;
}

Back_Ground* Map::getBackground()
{
	return BackGround;
}

/*
void Map::GenerateurPlateformeMap(Map *mapouche)
{
    // Recupere les infos des map pour les positione et la taille  
	TextureManager *test;
	test = new TextureManager();

	test->SetTexture(mapouche->GetPathPlateforme()); // envoyer la texture de la plateforme a charger
	test->SetTexture(mapouche->GetPathBackground());

    static Plateforme *plateforme;

	plateforme->SetVectorDrawable(new Plateforme(mapouche->GetPlat1PosX(), mapouche->GetPlat1PosY(), mapouche->GetPlat1TailleX(), mapouche->GetPlat1TailleY(), mapouche->GetPathPlateforme()));//envoye la Plateforme dans le Vector d'Entite de la classe : entite_fixe
	plateforme->SetVectorDrawable(new Plateforme(mapouche->GetPlat2PosX(), mapouche->GetPlat2PosY(), mapouche->GetPlat2TailleX(), mapouche->GetPlat2TailleY(), mapouche->GetPathPlateforme()));//envoye la Plateforme dans le Vector d'Entite de la classe : entite_fixe
	plateforme->SetVectorDrawable(new Plateforme(mapouche->GetPlat3PosX(), mapouche->GetPlat3PosY(), mapouche->GetPlat3TailleX(), mapouche->GetPlat3TailleY(), mapouche->GetPathPlateforme()));//envoye la Plateforme dans le Vector d'Entite de la classe : entite_fixe
	plateforme->SetVectorDrawable(new Plateforme(mapouche->GetPlat4PosX(), mapouche->GetPlat4PosY(), mapouche->GetPlat4TailleX(), mapouche->GetPlat4TailleY(), mapouche->GetPathPlateforme()));//envoye la Plateforme dans le Vector d'Entite de la classe : entite_fixe
	plateforme->SetVectorDrawable(new Plateforme(mapouche->GetPlat5PosX(), mapouche->GetPlat5PosY(), mapouche->GetPlat5TailleX(), mapouche->GetPlat5TailleY(), mapouche->GetPathPlateforme()));//envoye la Plateforme dans le Vector d'Entite de la classe : entite_fixe
    
    
    
    //envoie la texture du background a charger

}
//----------------- Getter Texture Plateforme -----------------------
std::string Map::GetPathPlateforme()
{
	std::cout << "[Texture envoyée] :" << PathPlateforme << std::endl;
	return PathPlateforme;
}
//----------------- Getter Texture back_ground -----------------------
std::string Map::GetPathBackground()
{
	return PathBackground;
}

//----------------- Getter Plateforme 1 -----------------------

float Map::GetPlat1PosX()
{
	std::cout << "TabX:" << TabPos1[0] << std::endl;
	return TabPos1[0];
}
float Map::GetPlat1PosY()
{
	return TabPos1[1];
}
float Map::GetPlat1TailleX()
{
	return TabPos1[2];
}
float Map::GetPlat1TailleY()
{
	return TabPos1[3];
}

//----------------- Getter Plateforme 2 -----------------------

float Map::GetPlat2PosX()
{
	return TabPos2[0];
}
float Map::GetPlat2PosY()
{
	return TabPos2[1];
}
float Map::GetPlat2TailleX()
{
	return TabPos2[2];
}
float Map::GetPlat2TailleY()
{
	return TabPos2[3];
}


//----------------- Getter Plateforme 3 -----------------------

float Map::GetPlat3PosX()
{
	return TabPos3[0];
}
float Map::GetPlat3PosY()
{
	return TabPos3[1];
}
float Map::GetPlat3TailleX()
{
	return TabPos3[2];
}
float Map::GetPlat3TailleY()
{
	return TabPos3[3];
}


//----------------- Getter Plateforme 4 -----------------------

float Map::GetPlat4PosX()
{
	return TabPos4[0];
}
float Map::GetPlat4PosY()
{
	return TabPos4[1];
}
float Map::GetPlat4TailleX()
{
	return TabPos4[2];
}
float Map::GetPlat4TailleY()
{
	return TabPos4[3];
}

//----------------- Getter Plateforme 4 -----------------------

float Map::GetPlat5PosX()
{
	return TabPos5[0];
}
float Map::GetPlat5PosY()
{
	return TabPos5[1];
}
float Map::GetPlat5TailleX()
{
	return TabPos5[2];
}
float Map::GetPlat5TailleY()
{
	return TabPos5[3];
}

*/
