#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entite : public sf::Sprite
{
public: // A voir pour les déclaration a cause de sfml
	Entite();
	~Entite();
	
	

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

	std::string Nom;
	//float Position_X;
	//float Position_Y;
	//std::string nom_texture;
	//float Taille_X;
	//float Taille_Y;
	
};


