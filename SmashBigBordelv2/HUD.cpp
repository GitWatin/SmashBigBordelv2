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
	ViePerso = new sf::Text;

	// Set Label pour le perso 1

	ViePerso->setString(std::to_string(perso1choisi->GetNbre_Vies()));
	ViePerso->setPosition(0, 0);
	vectorHUD.push_back(ViePerso);

	BouclierPerso->setString(std::to_string(perso1choisi->GetBouclier()));
	BouclierPerso->setPosition(0, 0);
	vectorHUD.push_back(BouclierPerso);

	AtoutPerso->setString(perso1choisi->GetDerniersAtout());
	AtoutPerso->setPosition(0, 0);
	vectorHUD.push_back(AtoutPerso);

	// Set Label pour le perso 2

	ViePerso->setString(std::to_string(perso2choisi->GetNbre_Vies()));
	ViePerso->setPosition(0, 0);
	vectorHUD.push_back(ViePerso);

	BouclierPerso->setString(std::to_string(perso2choisi->GetBouclier()));
	BouclierPerso->setPosition(0, 0);
	vectorHUD.push_back(BouclierPerso);
	
	AtoutPerso->setString(perso2choisi->GetDerniersAtout());
	AtoutPerso->setPosition(0, 0);
	vectorHUD.push_back(AtoutPerso);

}




