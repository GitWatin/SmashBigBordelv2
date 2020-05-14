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

	/*
	virtual void supprimer_vector();
	virtual void SetPositionX(float position_x);
	virtual float GetPositionX();

	virtual void SetPositionY(float position_y);
	virtual float GetPositionY();

	

	virtual void SetTexture(std::string nom_texture);//pas la bonne déclaration tkt frère c'est reglé
	virtual std::string GetTexture();//pas la bonne déclaration tkt frère c'est reglé

	virtual void SetTailleX(float taille_x);
	virtual float GetTailleX();

	virtual void SetTailleY(float taille_y);
	virtual float GetTailleY();
	*/

protected:
	bool Collision = false;
	bool Versgauche = true;
	bool Versdroite = true;
	bool Vershaut = true;
	bool Versbas = true;
	bool CheckColision = false;
	Collider *collider;
	std::string Nom;
	//float Position_X;
	//float Position_Y;
	//std::string nom_texture;
	//float Taille_X;
	//float Taille_Y;
	
};


