#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "Equipe.h"
#include "Club.h"
#include "ExceptionMessage.h"


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

Equipe::Equipe(Club *tmpClub, char tmpNumero,const char *tmpDivision)
{
	pClub = NULL;
	division = NULL;
	jJoueur[0] = NULL;
	jJoueur[1] = NULL;
	jJoueur[2] = NULL;
	jJoueur[3] = NULL;
	setNumero('A');
	setClub(tmpClub);
	setNumero(tmpNumero);
	setDivision(tmpDivision);
}

Equipe::Equipe(const Equipe &cpyEquipe)
{
	pClub = NULL;
	division = NULL;
	jJoueur[0] = NULL;
	jJoueur[1] = NULL;
	jJoueur[2] = NULL;
	jJoueur[3] = NULL;
	setNumero('A');
	setClub(cpyEquipe.getClub());
	setNumero(cpyEquipe.getNumero());
	setDivision(cpyEquipe.getDivision());
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
int Equipe::setClub(Club *tClub)
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

int Equipe::setDivision(const char *div)
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
	
	
	jJoueur[nbr] = tmpJoueur;
	
}


/***************************************
*
*			operateur
*
********************************/
ostream &operator<<(ostream &s, const Equipe &e)
{
	int i;
	if(e.getClub() != NULL)
		s << e.getClub() << " ";
	s << e.getNumero() << " ";
	if(e.getDivision() != NULL)
		s << e.getDivision() << endl;
	for(i=0; i<4; i++)
	{
		if(e.getJoueur(i) != NULL)
		{
			s<<"joueur " << i << endl<< e.getJoueur(i)<<endl;
		}
	}
}

istream &operator>>(istream &s, Equipe &e)
{
	Joueur tmpJoueur;
	char nbr;
	char tmpDiv[100];
	Club tmpClub;
	int i;

	s >> tmpClub;
	e.setClub(&tmpClub);
	
	cout << "veuillez entrez le numero de l'equipe (A, B, C, D, ...)"<<endl;
	s>> nbr;
	e.setNumero(nbr);
	
	cout << "Veuillez entrez la division de l'equipe"<<endl;
	s>> tmpDiv;
	e.setDivision(tmpDiv);
	
	for(i=0; i<4; i++)
	{
		cout << " joueur "<< i<< endl;
		s>>tmpJoueur;
		e.setJoueur(&tmpJoueur,i);
	}
	
}

Equipe &Equipe::operator=(const Equipe &tmpEquipe)
{
	setClub(tmpEquipe.getClub());
	setNumero(tmpEquipe.getNumero());
	setDivision(tmpEquipe.getDivision());
	setJoueur(tmpEquipe.jJoueur[0], 0);
	setJoueur(tmpEquipe.jJoueur[1], 1);
	setJoueur(tmpEquipe.jJoueur[2], 2);
	setJoueur(tmpEquipe.jJoueur[3], 3);
	return *this;
}


/***************************************
*
*			Autre
*
********************************/

void Equipe::Save(ofstream &fichier) const
{

	return;
}



void Equipe::Load(ifstream &fichier)
{

	return;
}










































