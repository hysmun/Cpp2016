#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Club.h"


using namespace std;

Club::Club()
{
	setNom("Nom");
	setNumClub(0);
	setAdresse("Adresse");
}

Club::Club(char* n,int nc,char* ad)
{
	setNom(n);
	setNumClub(nc);
	setAdresse(ad);
}

Club::Club(const Club& c)
{
	if(c.nom)
	{
		if(c.adresse)
		{
			setNom(c.nom);
			setAdresse(c.adresse);
			setNumClub(c.numClub);
		}
		else
		{
			cout << "Erreur d'adresse" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "Erreur de nom" << endl;
		exit(0);
	}
}

Club::~Club()
{
	if(nom)
		delete nom;
	if(adresse)
		delete adresse;
	setNumClub(0);
}

void Club::setNom(const char* n)
{
	if(nom)
		delete nom;
	nom = new char[strlen(n)+1];
	strcpy(nom,n);
}

void Club::setNumClub(int nc)
{
	numClub = nc;
}

void Club::setAdresse(const char* ad)
{
	if(adresse)
		delete adresse;
	adresse = new char[strlen(ad)+1];
	strcpy(adresse,ad);
}

char* Club::getNom()const
{
	return nom;
}

int Club::getNumClub()const
{
	return numClub;
}

char* Club::getAdresse()const
{
	return adresse;
}

ostream& operator<<(ostream& o,const Club& c)
{
	o << "Nom du club : " << c.nom << endl << "Numero du club : " << c.numClub << endl << "Adresse du club : " << c.adresse << endl;
	return o;
}

istream& operator>>(istream& i, Club& c)
{
	cout << "Nom du club : ";
	i >> c.nom;
	cout << "Numero du club : ";
	i >> c.numClub;
	cout << "Adresse du club : ";
	i >> c.adresse;
	return i;
}

Club& Club::operator=(const Club& c)
{
	if(c.nom)
	{
		if(c.adresse)
		{
			setNom(c.nom);
			setAdresse(c.adresse);
			setNumClub(c.numClub);
		}
		else
		{
			cout << "Erreur d'adresse" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "Erreur de nom" << endl;
		exit(0);
	}
	return *this;
}

bool Club::operator<(const Club& c)const
{
	if(strcmp(nom,c.nom) < 0)
		return true;
	else
		return false;
}


bool Club::operator>(const Club& c)const
{
	if(strcmp(nom,c.nom) > 0)
		return true;
	else
		return false;
}


bool Club::operator==(const Club& c)const
{
	if(strcmp(nom,c.nom) == 0)
		return true;
	else
		return false;
}















