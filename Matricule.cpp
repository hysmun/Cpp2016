#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "Joueur.h"
#include "Matricule.h"
#include "Classement.h"

/***************************************
*
*			Initialisateur
*
********************************/





Matricule::Matricule()
{
	strcpy(dateInscription, "00/00/0000");
	numero = -1;
}

Matricule::Matricule(const char *sd, const int n)
{
	strcpy(dateInscription, "00/00/0000");
	setDateInscription(sd);
	setNumero(n);
}

Matricule::Matricule(const Matricule &m)
{
	strcpy(dateInscription, "00/00/0000");
	setDateInscription(m.dateInscription);
	setNumero(m.numero);
}

Matricule::~Matricule()
{

}

/***************************************
*
*			Getteur
*
********************************/

int Matricule::getNumero() const
{
	return numero;
}

const char *Matricule::getDateInscription() const
{
	return dateInscription;
}

/***************************************
*
*			Setteur
*
********************************/

void Matricule::setNumero(int n)
{
	numero = n;
}

void Matricule::setDateInscription(const char *sd)
{
	if(sd != NULL)
		strcpy(dateInscription, sd);
}

/***************************************
*
*			affiche
*
********************************/

void Matricule::Affiche() const
{
	if(dateInscription != NULL) cout << dateInscription << " ";
	cout << numero;
}


//operateurs

ostream &operator<<(ostream &s, const Matricule &j)
{

	s << j.getDateInscription() << " " << flush;;
	s << j.getNumero() << " " << flush;
	return s;
}

istream &operator>>(istream &s, Matricule &j)
{
	char tmp1[20];
	int tmp2;
	cout << "Entrez la date d inscription : " << flush;
	s >> tmp1;
	j.setDateInscription(tmp1);
	cout << "Encodez le numero d inscription :" << flush;
	s >> tmp2;
	j.setNumero(tmp2);
	return s;
}













