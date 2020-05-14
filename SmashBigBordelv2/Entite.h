#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include <iostream>


class Entite : public sf::Sprite
{
public: // A voir pour les déclaration a cause de sfml
	Entite();
	~Entite();
	bool CheckZone(Entite * background);
	bool CheckAttaque(Entite * background);
	virtual void CheckCollision(Entite *entite, float repoussement, sf::Time dureeIteration);
	virtual void setCollision(bool ok);
	virtual bool getCollision();

	virtual void setCheckCollision(bool ok);
	virtual bool getCheckCollision();
	
	virtual void setVersdroite(bool ok);
	virtual bool getVersdroite();

	virtual void setVersgauche(bool ok);
	virtual bool getVersgauche();

	virtual void setVershaut(bool ok);
	virtual bool getVershaut();

	virtual void setVersbas(bool ok);
	virtual bool getVersbas();

	virtual void SetNom(std::string nom);
	virtual std::string GetNom();



protected:
	bool Collision = false;
	bool Versgauche = true;
	bool Versdroite = true;
	bool Vershaut = true;
	bool Versbas = true;
	bool CheckColision = false;
	Collider *collider;
	std::string Nom;

};


