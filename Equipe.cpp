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
}

Equipe::Equipe(Club *tmpClub, char tmpNumero,const char *tmpDivision)
{
	pClub = NULL;
	division = NULL;
	jJoueur[0] = NULL;
	jJoueur[1] = NULL;
	jJoueur[2] = NULL;
	jJoueur[3] = NULL;
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

int Equipe::getNbrJoueur() const
{
	int cpt=0;
	for(int i=0; i<4; i++)
	{
		if(getJoueur(0) != NULL)
		{
			cpt++;
		}
	}
	return cpt;
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
		s << (e.getClub()->getNom()) << " ";
	s << e.getNumero() <<endl;
	if(e.getDivision() != NULL)
		s << e.getDivision() << endl<<endl;
	for(i=0; i<4; i++)
	{
		if(e.getJoueur(i) != NULL)
		{
			s<<"joueur " << i << endl<< *(e.getJoueur(i))<<endl<<endl;;
		}
		else
		{
			s<< " pas de joueur " << i<<endl;
		}
	}
}

istream &operator>>(istream &s, Equipe &e)
{
	Joueur tmpJoueur;
	char nbr;
	char tmpDiv[100];
	//Club tmpClub;
	int i;

	//s >> tmpClub;
	//e.setClub(&tmpClub);
	
	cout << "veuillez entrez le numero de l'equipe (A, B, C, D, ...)"<<endl;
	s>> nbr;
	e.setNumero(nbr);
	
	cout << "Veuillez entrez la division de l'equipe"<<endl;
	s>> tmpDiv;
	e.setDivision(tmpDiv);
	
	/*for(i=0; i<4; i++)
	{
		cout << " joueur "<< i<< endl;
		s>>tmpJoueur;
		e.setJoueur(&tmpJoueur,i);
	}*/
	
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

int Equipe::operator==(const Equipe &tmpEquipe)
{

	return 1;
}


/***************************************
*
*			Autre
*
********************************/

void Equipe::Save(ofstream &fichier) const
{
	int len, tmp, i;
	char ctmp;
	tmp = getClub()->getNumClub();
	fichier.write((char *)&tmp, sizeof(int));
	
	ctmp = getNumero();
	fichier.write(&ctmp, sizeof(char));
	
	len = strlen(getDivision())+1;
	fichier.write((char *)&len, sizeof(int));
	fichier.write(getDivision(), sizeof(len));
	
	for(i=0; i<4; i++)
	{
		if(getJoueur(i) == NULL)
			tmp = 0;
		else
			tmp = getJoueur(i)->getMatricule().getNumero();
		fichier.write((char *)&tmp, sizeof(int));
	}
	
	return;
}



void Equipe::Load(ifstream &fichier)
{
	int len, tmp, i;
	char ctmp;
	
	/*
	
	fichier.read((char *)&tmp, sizeof(int));
	
	ctmp = getNumero();
	fichier.write(&ctmp, sizeof(char));
	
	len = strlen(getDivision())+1;
	fichier.write((char *)&len, sizeof(int));
	fichier.write(getDivision(), sizeof(len));
	
	for(i=0; i<4; i++)
	{
		if(getJoueur() == NULL)
			tmp = 0;
		else
			tmp = getJoueur()->getNumero();
		fichier.write((char *)&tmp, sizeof(int));
	}
	*/
	
	
	return;
}










































