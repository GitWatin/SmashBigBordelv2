#include "Entite.h"
#include <iostream>

Entite::Entite() : Sprite()
{
	;
}

Entite::~Entite()
{
	;
}

void Entite::CheckCollision(Entite *entite)
{
	sf::Vector2f jacquePosition = entite->getPosition();
	sf::FloatRect jacqueHitBox = entite->getGlobalBounds();
	sf::Vector2f thisPosition = this->getPosition();
	sf::FloatRect thisHitBox = this->getGlobalBounds();

	float deltaX = jacquePosition.x - thisPosition.x;
	float deltaY = jacquePosition.y - thisPosition.y;

	float intersectionX = abs(deltaX) - ((jacqueHitBox.width/2) + (thisHitBox.width/2));
	float intersectionY = abs(deltaY) - ((jacqueHitBox.height/2) + (thisHitBox.height/2));

	//if (jacqueHitBox.intersects(thisHitBox))
	//{
	//	if(jacquePosition.x < thisPosition.x + thisHitBox.width)
	//	{
	//		this->setCheckCollision(true);
	//	}
	//	
	//}
	if (intersectionX < 0.0f && intersectionY < 0.0f)
	{
		
			if (intersectionX > intersectionY)
			{
				if (deltaX > 0.0f)
				{

				}

				if (deltaY > 0.0f)
				{

				}
			}
			
			std::cout << "[Collision] : " << this->GetNom() << " et " << entite << std::endl;
		
		this->setCheckCollision(true);
	}
}

void Entite::setCollision(bool ok)
{
	this->Collision = ok;
}

bool Entite::getCollision()
{
	return this->Collision;
}

void Entite::setCheckCollision(bool ok)
{
	this->CheckColision = ok;
}

bool Entite::getCheckCollision()
{
	return this->CheckColision;
}


void Entite::SetNom(std::string nom)
{
	this->Nom = nom;
}

std::string Entite::GetNom()
{
	return Nom;
}

 /*
 void Entite::supprimer_vector()
 {
	 
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
*/



