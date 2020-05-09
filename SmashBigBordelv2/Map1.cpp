#pragma once
#include "Map1.h"
#include "Map.h"
#include <iostream>


Map1::Map1(): Map()
{
	
	this->NomMap = "Map du Turfu";


	//--------------POSTION------------------------

		//Plateforme 1 : 
		
		this->TabPos1[0] = {100.0};// Position X
		this->TabPos1[1] = {200.0};// Position Y 
		this->TabPos1[2] = {600.0};// Taille X
		this->TabPos1[3] = {400.0};// Taille Y


		//Plateforme 2 : 

		this->TabPos2[0] = { -20.0 };// Position X
		this->TabPos2[1] = { -20.0 };// Position Y 
		this->TabPos2[2] = { 20.0 };// Taille X
		this->TabPos2[3] = { 20.0 };// Taille Y


		//Plateforme 3 : 

		this->TabPos3[0] = { 20.0 };// Position X
		this->TabPos3[1] = { 20.0 };// Position Y 
		this->TabPos3[2] = { 20.0 };// Taille X
		this->TabPos3[3] = { 20.0 };// Taille Y


		//Plateforme 4 : 

		this->TabPos4[0] = { 20.0 };// Position X
		this->TabPos4[1] = { 20.0 };// Position Y 
		this->TabPos4[2] = { 20.0 };// Taille X
		this->TabPos4[3] = { 20.0 };// Taille Y



		//Plateforme 5 : 

		this->TabPos5[0] = { 20.0 };// Position X
		this->TabPos5[1] = { 20.0 };// Position Y 
		this->TabPos5[2] = { 20.0 };// Taille X
		this->TabPos5[3] = { 20.0 };// Taille Y	
	//--------------TEXTURE-------------------------
	this->PathPlateforme = "plat1.png";
	this->PathBackground = "mario.png";

	//this->PathPlateforme = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\plat1.png";
	//this->PathBackground = "D:\\projet_cpp\\SmashBigBordelv2\\SmashBigBordelv2\\Textures\\mario.png";
	std::cout << "donnée map envoyer" << std::endl;
	//linux c'est qd même de la merde

}





