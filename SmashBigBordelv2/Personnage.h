#pragma once
#include "Entite.h"
#include<iostream>


class Personnage :
	public Entite
{
    public:
	Personnage();
	~Personnage();
	virtual void SetPersonnage() = 0;
	virtual void Attaque(Personnage *NomCible, std::string TypeAttaque) = 0;
	virtual void SetPourcentages(double percent);
	virtual double GetPourcentages();
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

	virtual void setMoveRight();
	virtual void setMoveLeft();
	virtual void setJump();

	virtual bool getMoveRight();
	virtual bool getMoveLeft();
	virtual bool getJump();
	
	virtual std::vector< Personnage* >GetVectorPersonnage();
	
protected:
	int Nbre_Vies;
	int Force_Attaque1;
	int Force_Attaque2;
	double Pourcentages;
	float Poids;
	int Bouclier;
	std::string DerniersAtout;
	std::string TypeAttaque;
	std::string Path_Avatar;
	Personnage *perso;
	std::vector < Personnage* > Dessin;
	bool moveRight=false;
	bool moveLeft=false;
	bool Jump=false;
};

