#include "Entite.h"
#include "Jeu.h"
#include <iostream>

Entite::Entite() : Sprite()
{
	;
}

Entite::~Entite()
{
	;
}
bool Entite::CheckZone(Entite *background)
{
	float CenterX = background->getOrigin().x ;
	float CenterY = background->getOrigin().y;
	float CoteDroit = (this->getPosition().x) - ((this->getGlobalBounds().width) / 2);//droite
	float CoteGauche = (this->getPosition().x) + ((this->getGlobalBounds().width) / 2); //gauche
	float CoteHaut = (this->getPosition().y) + ((this->getGlobalBounds().height) / 2); //haut
	float CoteBas = (this->getPosition().x) - ((this->getGlobalBounds().width) / 2); //bas
	{
		if (background->getGlobalBounds().intersects(this->getGlobalBounds()))
		{
			if ((CenterX + ((background->getGlobalBounds().width) / 2)) < CoteDroit || (CenterX - ((background->getGlobalBounds().width) / 2)) < CoteGauche || (CenterY + ((background->getGlobalBounds().height) / 2)) < CoteBas || (CenterY - ((background->getGlobalBounds().height) / 2)) < CoteHaut)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

}
bool Entite::CheckAttaque(Entite *entite)
{
	float CenterX = entite->getOrigin().x;
	float CenterY = entite->getOrigin().y;
	float CoteDroit = (this->getPosition().x) + ((this->getGlobalBounds().width) / 2);//droite
	float CoteGauche = (this->getPosition().x) - ((this->getGlobalBounds().width) / 2); //gauche
	float CoteHaut = (this->getPosition().y) - ((this->getGlobalBounds().height) / 2); //haut
	float CoteBas = (this->getPosition().x) + ((this->getGlobalBounds().width) / 2); //bas
	{
		if (entite->getGlobalBounds().intersects(this->getGlobalBounds()))
		{
			if ((CenterX + ((entite->getGlobalBounds().width) / 2)) < CoteDroit || (CenterX - ((entite->getGlobalBounds().width) / 2)) < CoteGauche || (CenterY + ((entite->getGlobalBounds().height) / 2)) < CoteBas || (CenterY - ((entite->getGlobalBounds().height) / 2)) < CoteHaut)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

}
void Entite::CheckCollision(Entite *entite, float repoussement, sf::Time dureeIteration)
{
	sf::Vector2f jacquePosition = entite->getPosition();
	sf::FloatRect jacqueHitBox = entite->getGlobalBounds();
	sf::Vector2f thisPosition = this->getPosition();
	sf::FloatRect thisHitBox = this->getGlobalBounds();

	float deltaX = jacquePosition.x - thisPosition.x;
	float deltaY = jacquePosition.y - thisPosition.y;

	float intersectionX = abs(deltaX) - ((jacqueHitBox.width/2) + (thisHitBox.width/2));
	float intersectionY = abs(deltaY) - ((jacqueHitBox.height/2) + (thisHitBox.height/2));

	if (intersectionX < 0.0f && intersectionY < 0.0f)
	{
		//repoussement = std::min(std::max(repoussement, 0.0f), 1.0f);
		if (intersectionX > intersectionY)
		{
			if (deltaX > 0.0f)
			{
				this->move((intersectionX *dureeIteration.asSeconds()) * (dureeIteration.asSeconds() - repoussement), 0.0f);
				this->setVersdroite(false);//vers la droite
				
			}
			else if (deltaX < 0.0f)
			{
				this->move(-(intersectionX *dureeIteration.asSeconds())  * (dureeIteration.asSeconds() - repoussement), 0.0f);//vers la gauche
				this->setVersgauche(false);
				
			}
		
		else if(intersectionX < intersectionY)
		
			if (deltaY > 0.0f)
			{
				this->move(0.0f, (intersectionX *dureeIteration.asSeconds())  * (dureeIteration.asSeconds() - repoussement));//vers le bas
				this->setVersbas(false);
				
			}
			else if (deltaY < 0.0f)
			{
				this->move(0.0f ,-(intersectionX *dureeIteration.asSeconds()) * (dureeIteration.asSeconds() - repoussement));//vers le haut
				this->setVershaut(false);
				
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

void Entite::setVersdroite(bool ok)
{
	this->Versdroite = ok;
}

bool Entite::getVersdroite()
{
	return this->Versdroite;
}

void Entite::setVersgauche(bool ok)
{
	this->Versgauche = ok;
}

bool Entite::getVersgauche()
{
	return this->Versgauche;
}

void Entite::setVershaut(bool ok)
{
	this->Vershaut = ok;
}

bool Entite::getVershaut()
{
	return this->Vershaut;
}

void Entite::setVersbas(bool ok)
{
	this->Versbas = ok;
}

bool Entite::getVersbas()
{
	return this->Versbas;
}

void Entite::SetNom(std::string nom)
{
	this->Nom = nom;
}

std::string Entite::GetNom()
{
	return Nom;
}

 



