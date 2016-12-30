#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Club.h"
#include "ExceptionMessage.h"


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
			setNom(c.getNom());
			setAdresse(c.getAdresse());
			setNumClub(c.getNumClub());
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
	o << "Nom du club : " << c.getNom() << endl;
	o << "Numero du club : " << c.getNumClub() << endl;
	o << "Adresse du club : " << c.getAdresse() << endl;
	return o;
}

istream& operator>>(istream& i, Club& c)
{

	char tmp[100];
	int itmp;
	cout << "Nom du club : ";
	i >> tmp;
	c.setNom(tmp);
	
	cout << endl <<"Numero du club : ";
	i >> itmp;
	c.setNumClub(itmp);
	
	cout << endl << "Adresse du club : ";
	i >> tmp;
	c.setAdresse(tmp);
	
	
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

void Club::Save(ofstream &fichier) const
{
	int len;
	
	len = strlen(getNom())+1;
	fichier.write((char *)&len,sizeof(int));
	fichier.write(getNom(), len);
	
	len = getNumClub();
	fichier.write((char *)&len, sizeof(int));
	
	len = strlen(getAdresse())+1;
	fichier.write((char *)&len,sizeof(int));
	fichier.write(getAdresse(), len);
	
	return;
}

void Club::Load(ifstream &fichier)
{
	char cTmp[255];
	int iTmp, len;
	
	fichier.read((char *)&len, sizeof(int));
	fichier.read(cTmp, len);
	setNom(cTmp);
	
	fichier.read((char *)&iTmp, sizeof(int));
	setNumClub(iTmp);
	
	fichier.read((char *)&len, sizeof(int));
	fichier.read(cTmp, len);
	setAdresse(cTmp);
	
	
	return;
}


































