#pragma once
#include "Entite.h"
#include<iostream>


class Personnage :
	public Entite
{
    public:
	Personnage();
	~Personnage();

	virtual void Attaque(Personnage *NomCible, int TypeAttaque, float dureeIteration) = 0;
	virtual void SetPourcentages(int percent);
	virtual int GetPourcentages();
	virtual void SetPoids(float poids);
	virtual int GetPoids();
	virtual void SetNbre_Vies(int nbre_vies);
	virtual int GetNbre_Vies();
	virtual void SetDerniersAtout(std::string derniers_atout);
	virtual std::string GetDerniersAtout();
	virtual void SetBouclier(int bouclier);
	virtual int GetBouclier();

	virtual std::string GetAvatar();
	virtual void SetAvatar(std::string path_avatar);

	virtual void setMoveRight(bool ok);
	virtual void setMoveLeft(bool ok);
	virtual void setJump(bool ok);
	virtual void setAttaque(bool ok);
	virtual void setRepoussement(bool ok);
	virtual int GetLastTime();
	virtual void SetLastTime(int value);

	virtual bool getMoveRight();
	virtual bool getMoveLeft();
	virtual bool getJump();
	virtual bool getAttaque();
	virtual bool getRepoussement();

	virtual std::vector< Personnage* >GetVectorPersonnage();
	
protected:
	int Nbre_Vies;
	int Force_Attaque1;
	int Force_Attaque2;
	int Pourcentages;
	float Poids;
	int Bouclier;

	int LastTime;

	std::string NomSimple;
	std::string DerniersAtout;
	std::string TypeAttaque;
	std::string Path_Avatar;
	Personnage *perso;
	std::vector < Personnage* > Dessin;
	bool moveRight=false;
	bool moveLeft=false;
	bool Jump=false;
	bool attaque = false;
	bool repoussement = false;
};

