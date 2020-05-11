#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entite : public sf::Sprite
{
public: // A voir pour les d�claration a cause de sfml
	Entite();

	virtual std::vector< sf::Drawable* >GetVectorDrawable();
	

	virtual void supprimer_vector();

	virtual void SetVectorPersonnages(Entite *drawable);
	

	virtual void SetPositionX(float position_x);
	virtual float GetPositionX();

	virtual void SetPositionY(float position_y);
	virtual float GetPositionY();

	virtual void SetNom(std::string nom);
	virtual std::string GetNom();

	virtual void SetTexture(std::string nom_texture);//pas la bonne d�claration tkt fr�re c'est regl�
	virtual std::string GetTexture();//pas la bonne d�claration tkt fr�re c'est regl�

	virtual void SetTailleX(float taille_x);
	virtual float GetTailleX();

	virtual void SetTailleY(float taille_y);
	virtual float GetTailleY();

protected:

	std::string Nom;
	float Position_X;
	float Position_Y;
	std::string nom_texture;
	float Taille_X;
	float Taille_Y;
	std::vector < sf::Drawable* > Dessin;
};


