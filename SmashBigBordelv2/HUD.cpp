#include "HUD.h"


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

	return 

	//this->vectorHUD.push_back();

}




