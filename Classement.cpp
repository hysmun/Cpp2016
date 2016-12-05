#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "Joueur.h"
#include "Matricule.h"
#include "Classement.h"
#include "InvalidClassementException.h"

Classement Classement::A1("A1");
Classement Classement::F1("F1");
Classement Classement::F2("F2");


/***************************************
*
*		Initialisateur
*
********************************/

Classement::Classement()
{
	lettre = 'F';
	nombre = 2;
}

Classement::Classement(char sd, short n)
{
	setCl(sd, n);
}

Classement::Classement(const Classement &c)
{
	setCl(c.getLettre(), c.getNombre());
}

Classement::Classement(const char *sd)
{
	setCl(sd[0], atoi(&sd[1]));
}

Classement::~Classement()
{
	
}

/***************************************
*
*			Getteur
*
********************************/

char Classement::getLettre() const
{
	return lettre;
}

short Classement::getNombre() const
{
	return nombre;
}

int Classement::getValeur() const
{
	int val = 0;
	if(this != NULL)
	{
		switch(lettre)
		{
			case 'F': val = 3-nombre; break;
			case 'E': val = 9-nombre; break;
			case 'D': val = 15-nombre; break;
			case 'C': val = 21-nombre; break;
			case 'B': val = 27-nombre ; break;
			case 'A': val = 37-nombre; break;
			default: val = 0;
		}
	}
	
	return val;
}

/***************************************
*
*			Setteur
*
********************************/

void Classement::setLettre(char n)
{
	if(n < 'A' || n > 'F')
		throw InvalidClassementException("Lettre invalide !");
	
	lettre = n;
}

void Classement::setNombre(short n)
{
	if(n > 10 || n < 1)
		throw InvalidClassementException("Nombre invalide !");
	
	nombre = n;
}

void Classement::setCl(char n , int x)
{
	switch(n)
	{
		case 'A':
			break;
		case 'B':
		case 'C':
		case 'D':
		case 'E':
			if(x > 6)
			throw InvalidClassementException("Nombre invalide !");
			break;
		case 'F':
			if(x > 2)
			throw InvalidClassementException("Nombre invalide !");
			break;
		default:
			throw InvalidClassementException("Lettre invalide !");
	}
	setLettre(n);
	setNombre(x);
}

void Classement::setValeur(int x)
{

	// 0x41 'A'	
	
	int tmp;
	if(x <= 0 || x >= 37)
	{
		throw InvalidClassementException("Classement invalide !");
	}
	else
	{
		if(x < 3)
		{
			setLettre('F');
			setNombre(3-x);
			return;
		}
		if(x < 27)
		{
			x= x-3;
			
			setLettre(3-(x/6)+0x42);
			setNombre(6-(x%6));
			return;
		}
		if( x < 37)
		{
			setLettre('A');
			setNombre(10-(x - 27));
			return;
		}
	}
}

/***************************************
*
*			Affiche
*
********************************/

void Classement::Affiche() const
{
	cout << lettre << " " << nombre << endl;
}


/*********************************************
*
*		operateur
*
************************************************/

int Classement::operator-(Classement c)
{	
	return this->getValeur() - c.getValeur();
}

int Classement::operator==(Classement c)
{
	return this->getValeur() == c.getValeur();
}

int Classement::operator<(Classement c)
{
	return this->getValeur() < c.getValeur();
}

int Classement::operator>(Classement c)
{
	return this->getValeur() > c.getValeur();
}

ostream &operator<<(ostream &s, const Classement &c)
{
	s << c.getLettre() << c.getNombre();
	return s;
}

istream &operator>>(istream &s, Classement &c)
{
	char l;
	int i;
	s >> l;
	s >> i;
	
	c.setCl(l, i);
	return s;
}

Classement &Classement::operator++()
{
	setValeur((getValeur())+1);
	return *this;
}

Classement Classement::operator++(int)
{
	Classement tmp(*this);
	setValeur((getValeur())+1);
	return tmp;
}

Classement &Classement::operator--()
{
	setValeur((getValeur())-1);
	return *this;
}

Classement Classement::operator--(int)
{
	Classement tmp(*this);
	setValeur((getValeur())-1);
	return tmp;
}


/*******************************************
*
*			Autre
*
********************************/

void Classement::Save(ofstream &fichier) const
{
	fichier.write(&lettre, sizeof(char));
	fichier.write((char*)&nombre, sizeof(int));
	return;
}

void Classement::Load(ifstream &fichier)
{
	char tmpc;
	int tmpi;
	fichier.read(&tmpc, sizeof(char));
	fichier.read((char *)&tmpi, sizeof(int));
	setCl(tmpc, tmpi);
	return ;
}























