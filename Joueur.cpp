#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "Joueur.h"
#include "Matricule.h"
#include "Classement.h"

/***************************************
*
*			initialisateur
*
********************************/

Joueur::Joueur()
{
	Nom = NULL;
	Prenom = NULL;
	jClassement = NULL;
	setNumClub(-1);
	setPoints(0);
}
Joueur::Joueur(const char *name, const char *sdname, int n)
{
// attention NULL
	Nom = NULL;
	Prenom = NULL;
	jClassement = NULL;
	setNumClub(-1);
	setNom(name);
	setPrenom(sdname);
	setNumClub(n);
	setPoints(0);
}

Joueur::Joueur(const Joueur &tmp) : Membre(tmp)
{
	jClassement = NULL;
	setPoints(tmp.getPoints());
	setMatricule(tmp.getMatricule());
	setClassement(tmp.getClassement());
}

Joueur::Joueur(const char *name, const char *sdname, int n, Matricule m)
{
	Nom = NULL;
	Prenom = NULL;
	jClassement = NULL;
	setNumClub(-1);
	setPoints(0);
	setNom(name);
	setPrenom(sdname);
	setNumClub(n);
	setMatricule(m);
}

Joueur::~Joueur()
{
	if(jClassement != NULL) delete jClassement;
}

/***************************************
*
*			Affiche
*
********************************/

int Joueur::Affiche(void)
{
	if(Nom != NULL) cout << Nom << " ";
	if(Prenom != NULL) cout << Prenom << " ";
	if(NumClub != -1) cout << NumClub << " ";
	if(jClassement != NULL) jClassement->Affiche();
	jMatricule.Affiche();
	return 1;
}

/***************************************
*
*			Setteur
*
********************************/

int Joueur::setPoints(int n)
{
	Points = n;
	return 1;
}

int Joueur::setMatricule(Matricule m)
{
	jMatricule.setDateInscription(m.getDateInscription());
	jMatricule.setNumero(m.getNumero());
	return 1;
}

int Joueur::setClassement(Classement *c)
{
	if(jClassement != NULL) delete jClassement;
	if( c != NULL)
		jClassement = new Classement(*c);
	else jClassement = NULL; 
	return 1;
}

/***************************************
*
*			Getteur
*
********************************/
const int Joueur::getPoints() const
{
	return Points;
}

const Matricule Joueur::getMatricule() const
{
	return jMatricule;
}

Classement *Joueur::getClassement() const
{
	if(jClassement != NULL)
		return jClassement;
	else
		return NULL;
}

/***********************************************
*
*		operateurs
*
**********************************/

Joueur &Joueur::operator=(const Joueur &tmp)
{
	setNom(tmp.Nom);
	setPrenom(tmp.Prenom);
	setNumClub(tmp.NumClub);
	setPoints(tmp.getPoints());
	setMatricule(tmp.jMatricule);
	setClassement(tmp.jClassement);
	
	return *this;
}

int Joueur::operator==(const Joueur &tmp)
{
	return this->jClassement->getValeur() == tmp.jClassement->getValeur();
}

int Joueur::operator<(const Joueur &tmp)
{
	return this->jClassement->getValeur() < tmp.jClassement->getValeur();
}

int Joueur::operator>(const Joueur &tmp)
{
	return this->jClassement->getValeur() > tmp.jClassement->getValeur();
}

ostream &operator<<(ostream &s, const Joueur &j)
{
	s << (Personne)j << flush;
	s << " Matricule : " << j.getMatricule() << flush;
	s<< " Numclub : " << j.getNumClub() << flush;
	if( j.getClassement() != NULL)
		s << " Classement = " << *(j.getClassement()) << flush;
	s << " Points = " << j.Points << flush;
	return s;
}

istream &operator>>(istream &s, Joueur &j)
{
	Personne tmp;
	int tmpint;
	Classement tmpc;
	Matricule tmpm;
	
	
	s >> tmp;
	j.setNom(tmp.getNom());
	j.setPrenom(tmp.getPrenom());
	s >> tmpm;
	j.setMatricule(tmpm);
	cout << "Encodez le numclub: " << flush;
	s >> tmpint;
	j.setNumClub(tmpint);
	cout << "Encodez le classement: " << flush;
	s >> tmpc;
	j.setClassement(&tmpc);
	cout << "Encodez les points du joueur :" << flush;
	s >> tmpint;
	j.setPoints(tmpint);
	return s;
}

Joueur &Joueur::operator++()
{
	setPoints(getPoints()+1);
	if(getPoints() == 20)
	{
		if(jClassement == &Classement::A1)
		{
		
		}
		else
		{
			++(*jClassement);
			setPoints(0);
		}
	}
	return *this;
}

Joueur Joueur::operator++(int x)
{
	Joueur tmp(*this);
	setPoints(getPoints()+1);
	if(getPoints() == 20)
	{
		if(getClassement() == &Classement::A1)
		{
		
		}
		else
		{
			++(*jClassement);
			setPoints(0);
		}
	}
	return tmp;
}

Joueur &Joueur::operator--()
{
	setPoints(getPoints()-1);
	if(getPoints() == -20)
	{
		if(getClassement() == &Classement::F2)
		{
		
		}
		else
		{
			--(*jClassement);
			setPoints(0);
		}
	}
	return *this;
}

Joueur Joueur::operator--(int x)
{
	Joueur tmp(*this);
	setPoints(getPoints()-1);
	if(getPoints() == -20)
	{
		if(getClassement() == &Classement::F2)
		{
		
		}
		else
		{
			--(*jClassement);
			setPoints(0);
		}
	}
	return tmp;
}

Joueur Joueur::operator+(int x)
{
   Joueur tmp(*this);
	int i;
	for(i = 0; i < x; i++)
	{
		++tmp;
	}
	return tmp;
}

Joueur Joueur::operator-(int x)
{
	Joueur tmp(*this);
	int i;
	for(i = 0; i < x; i++)
	{
		--tmp;
	}
	return tmp;
}



/*******************************************
*
*			Autre
*
********************************/

void Joueur::Save(ofstream &fichier) const
{
	int tmp;
	
	Membre::Save(fichier);
	
	//save points
	tmp = getPoints();
	fichier.write((char *)&tmp, sizeof(int));
	
	//save matricule
	jMatricule.Save(fichier);
	
	//save classements
	jClassement->Save(fichier);
	
	return;
}

void Joueur::Load(ifstream &fichier)
{
	int tmp;
	Matricule tmpM;
	Classement tmpC;
	
	Membre::Load(fichier);
	
	//load points
	fichier.read((char *)&tmp, sizeof(int));
	setPoints(tmp);
	
	//load matricule
	tmpM.Load(fichier);
	setMatricule(tmpM);
	
	//load classement
	tmpC.Load(fichier);
	setClassement(&tmpC);
	
	return ;
}
















