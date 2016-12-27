#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "Equipe.h"


/***************************************
*
*			initialisateur
*
********************************/
Equipe::Equipe()
{
	pClub = NULL;
	division = NULL;
	jJoueur[0] = NULL;
	jJoueur[1] = NULL;
	jJoueur[2] = NULL;
	jJoueur[3] = NULL;
	setNumero('A');
}

Equipe::Equipe(Club &tmpClub, char tmpNumero,const char *tmpDivision)
{
	setClub(tmpClub);
	setNumero(tmpNumero);
	setDivision(tmpDivision);
}

Equipe::Equipe(const Equipe &cpyEquipe)
{
	setClub(cpyEquipe.tmpClub);
	setNumero(cpyEquipe.tmpNumero);
	setDivision(cpyEquipe.tmpDivision);
	setJoueur(cpyEquipe.jJoueur[0], 0);
	setJoueur(cpyEquipe.jJoueur[1], 1);
	setJoueur(cpyEquipe.jJoueur[2], 2);
	setJoueur(cpyEquipe.jJoueur[3], 3);
}

Equipe::~Equipe()
{
	setDivision(NULL);
}


/***************************************
*
*			getteur
*
********************************/
Club *Equipe::getClub() const
{
	return pClub;
}

char Equipe::getNumero() const
{
	return numero;
}

char *Equipe::getDivision() const
{
	return division;
}

Joueur *Equipe::getJoueur(int nbr) const
{
	if( nbr > 3 || nbr < 0)
		return NULL;
	
	return jJoueur[nbr];
}


/***************************************
*
*			Setteur
*
********************************/
int Equipe::setClub(const Club &tClub)
{
	pClub = tClub;
	return 1;
}

int Equipe::setNumero(char num)
{
	if( num < 'A' || num >'Z')
		return -1;
		
	numero = num;
}

int Equipe::setDivision(char *div)
{
	if(division != NULL)
		delete division;
	if(div != NULL)
	{
		division = new char[strlen(div)+1];
		strcpy(division, div);
	}
	
}

int Equipe::setJoueur(Joueur *tmpJoueur, int nbr)
{
	if(nbr > 3 || nbr < 0)
		return -1;

	if(tmpJoueur != NULL)
	{
		jJoueur[nbr] = tmpJoueur;
	}
}


/***************************************
*
*			operateur
*
********************************/
ostream &Equipe::operator<<(ostream &s, const Equipe &e)
{


}

istream &Equipe::operator>>(istream &s, Equipe &e)
{


}

Equipe &Equipe::operator=(const Equipe &tmpEquipe)
{


}















































