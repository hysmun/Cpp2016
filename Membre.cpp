#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "Membre.h"

/***************************************
*
*			initialisateur
*
********************************/

Membre::~Membre()
{

}

/***************************************
*
*			Affiche
*
********************************/

/***************************************
*
*			Setteur
*
********************************/
int Membre::setNumClub(int n)
{
	NumClub = n;
	return 1;
}


/***************************************
*
*			Getteur
*
********************************/
const int Membre::getNumClub() const
{
	return NumClub;
}

/***********************************************
*
*		operateurs
*
**********************************/

Membre &Membre::operator=(const Membre &tmp)
{
	(Personne)*this = (Personne)tmp;
	setNumClub(tmp.getNumClub());
	
	return *this;
}

ostream &operator<<(ostream &s, const Membre &j)
{
	s << ((const Personne)j);
	s << " NumClub : " << j.getNumClub() << flush;

	return s;
}

istream &operator>>(istream &s, Membre &j)
{
	int tmp;
	Personne tmpj;
	s >> tmpj;
	(Personne)j = tmpj;
	cout << "Encodez le numclub : " << flush;
	s >> tmp;
	j.setNumClub(tmp);
	return s;
}





/*******************************************
*
*			Autre
*
********************************/

void Membre::Save(ofstream &fichier) const
{
	int tmp = getNumClub();
	
	Personne::Save(fichier);
	
	fichier.write((char *)&tmp, sizeof(int));
	return;
}

void Membre::Load(ifstream &fichier)
{
	int tmp;
	
	Personne::Load(fichier);
	
	fichier.read((char *)&tmp, sizeof(int));
	setNumClub(tmp);
	return ;
}










