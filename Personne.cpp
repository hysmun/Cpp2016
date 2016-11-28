#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "Personne.h"


/***************************************
*
*			initialisateur
*
********************************/

Personne::Personne()
{
	Nom = NULL;
	Prenom = NULL;
}
Personne::Personne(const char *name, const char *sdname)
{
// attention NULL
	Nom = NULL;
	Prenom = NULL;
	setNom(name);
	setPrenom(sdname);
}

Personne::Personne(const Personne &tmp)
{
	Nom = NULL;
	Prenom = NULL;
	setNom(tmp.getNom());
	setPrenom(tmp.getPrenom());
}


Personne::~Personne()
{
	if(Nom != NULL) delete Nom;
	if(Prenom != NULL) delete Prenom;
}

/***************************************
*
*			Affiche
*
********************************/

int Personne::Affiche(void) const
{
	if(Nom != NULL) cout << Nom << " ";
	if(Prenom != NULL) cout << Prenom << " ";
	return 1;
}

/***************************************
*
*			Setteur
*
********************************/

int Personne::setNom(const char *tmp)
{
	if(Nom != NULL) delete Nom;
	if(tmp != NULL)
	{
		Nom = new char[strlen(tmp)+1]	;
		strcpy(Nom, tmp);
	}
	return 1;
}

int Personne::setPrenom(const char *tmp)
{
	if(Prenom != NULL) delete Prenom;
	if(tmp != NULL)
	{
		Prenom = new char[strlen(tmp)+1];
		strcpy(Prenom, tmp);
	}
	return 1;
}


/***************************************
*
*			Getteur
*
********************************/
const char *Personne::getNom() const
{
	return Nom;
}

const char *Personne::getPrenom() const
{
	return Prenom;
}



/***********************************************
*
*		operateurs
*
**********************************/

Personne &Personne::operator=(const Personne &tmp)
{
	setNom(tmp.getNom());
	setPrenom(tmp.getPrenom());
	
	return *this;
}

ostream &operator<<(ostream &s, const Personne &j)
{
	if( j.getNom() != NULL)
		s << j.getNom() << " " << flush;
	if( j.getPrenom() != NULL)
		s << j.getPrenom() << " " << flush;
	
	return s;
}

istream &operator>>(istream &s, Personne &j)
{
	char tmp[100];
	cout << "Encodez le nom : " << flush;
	s >> tmp;
	j.setNom(tmp);
	cout << "Encodez le prenom : " << flush;
	s >> tmp;
	j.setPrenom(tmp);
	return s;
}




















