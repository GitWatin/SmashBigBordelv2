#include "Entite.h"
#include <iostream>
Entite::Entite(float position_x, float position_y, float taille_x, float taille_y, std::string path_texture) : Sprite()
{
	this->Position_X = position_x;
	this->Position_Y = position_y;
	this->Taille_X = taille_x;
	this->Taille_Y = taille_y;
	this->nom_texture = path_texture;
	std::cout << "Entite cree" << std::endl;

}
Entite::Entite() : Sprite()
{
	;
}

void Entite::SetVectorEntiteFixe(Entite *entite)
{
	entite_fixe.push_back(entite);
}

std::vector < Entite* > Entite::GetVectorEntiteFixe()
{
	return entite_fixe;
}
void Entite::SetVectorDrawable(Entite *drawable)
{
	Dessin.push_back(drawable);
}

 std::vector< sf::Drawable* > Entite::GetVectorDrawable()
{
	
		return Dessin;
		std::cout << "[Info]:Return vector dessin "  << std::endl;
	
}

 void Entite::supprimer_vector()
 {
	 
	 for (int i = 0; i < entite_fixe.size(); i++) // suppression des Drawable mes_objets
	 {
		 delete entite_fixe.back();
		 entite_fixe.pop_back();
	 }
	 for (int i = 0; i < Dessin.size(); i++) // suppression des Drawable mes_objets
	 {
		 delete Dessin.back();
		 Dessin.pop_back();
	 }
	 
 }

// -------------------------- Position  X---------------------------------
void Entite::SetPositionX(float position_x)
{
	this->Position_X = position_x;
}

float Entite::GetPositionX()
{
	return Position_X;
}

// -------------------------- Position  Y ---------------------------------
void Entite::SetPositionY(float position_y)
{
	this->Position_Y = position_y;
}

float Entite::GetPositionY()
{
	return Position_Y;
}

// -------------------------- Nom entité---------------------------------
void Entite::SetNom(std::string nom)
{
	this->Nom = nom;
}

std::string Entite::GetNom()
{
	return Nom;
}

// -------------------------- Texture ---------------------------------

void Entite::SetTexture(std::string nom_texture)
{
	this->nom_texture = nom_texture;
}

std::string Entite::GetTexture()
{
	return nom_texture;
}

// -------------------------- Taille Axe X ---------------------------------

void Entite::SetTailleX(float taille_x)
{
	this->Taille_X = taille_x;
}

float Entite::GetTailleX()
{
	return Taille_X;
}

// -------------------------- Taille Axe Y ---------------------------------

void Entite::SetTailleY(float taille_y)
{
	this->Taille_Y = taille_y;
}

float Entite::GetTailleY()
{
	return Taille_Y;
}




