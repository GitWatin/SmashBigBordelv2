#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entite : public sf::Sprite
{
    public: // A voir pour les déclaration a cause de sfml
	 Entite();
	 Entite(float position_x, float position_y, float taille_x, float taille_y, std::string path_texture);

	 virtual std::vector< sf::Drawable* >GetVectorDrawable();
	 virtual std::vector < Entite* > GetVectorEntiteFixe();

	 virtual void supprimer_vector();

	 virtual void SetVectorDrawable(Entite *drawable);
	 virtual void SetVectorEntiteFixe(Entite *entite);
	 
	virtual void SetPositionX(float position_x);
	virtual float GetPositionX();
	
	virtual void SetPositionY(float position_y);
	virtual float GetPositionY();


	virtual void SetNom(std::string nom);
	virtual std::string GetNom();
	
	virtual void SetTexture(std::string nom_texture);//pas la bonne déclaration tkt frère c'est reglé
	virtual std::string GetTexture();//pas la bonne déclaration tkt frère c'est reglé

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
	std::vector < Entite* > entite_fixe;
};

