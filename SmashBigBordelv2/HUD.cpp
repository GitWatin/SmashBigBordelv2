#include "HUD.h"
#include <string>


HUD::HUD()
{
	

}



HUD::~HUD()
{

	for (int i = 0; i < vectorHUD.size(); i++)
	{
		delete vectorHUD.back();
		vectorHUD.pop_back();
	}

}

std::vector<sf::Drawable*> HUD::GetVectorHUD()
{
	//return std::vector<sf::Drawable*>();
	return vectorHUD;
}

void HUD::CallHUD()
{

	this->ViePerso1.setString(std::to_string(perso1choisi->GetNbre_Vies));
	this->ViePerso1.setPosition(0, 0);

	this->ViePerso1.setString(std::to_string(perso1choisi->GetNbre_Vies));
	this->ViePerso1.setPosition(0, 0);



	vectorHUD.push_back(ViePerso1);

}




