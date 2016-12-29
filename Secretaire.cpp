#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <fstream>
#include <cstring>
using namespace std;
#include "Membre.h"
#include "Personne.h"
#include "Secretaire.h"
#include "InvalidPasswordException.h"
#include "ExceptionMessage.h"

/***************************************
*
*			initialisateur
*
********************************/
Secretaire::Secretaire() : Membre()
{
	setNumClub(0);
}

Secretaire::Secretaire(const Secretaire &tmp) : Membre(tmp)
{
	setLogin(tmp.getLogin()); 
	setPassword(tmp.getPassword());
}

Secretaire::~Secretaire()
{

}

/***************************************
*
*			Affiche
*
********************************/

int Secretaire::Affiche(void)
{
	if(Nom != NULL) cout << Nom << " ";
	if(Prenom != NULL) cout << Prenom << " ";
	if(NumClub != -1) cout << NumClub << " ";
	return 1;
}

/***************************************
*
*			Setteur
*
********************************/
int Secretaire::setLogin(const char *tmp)
{
	int i, lenght = strlen(tmp);
	if(tmp != NULL && lenght<9)
	{
		
		strcpy(login, tmp);
		/*if(lenght<8)
		{
			for(i=lenght; i==8; i++)
			{
				login[i]='\0';
			}
		}*/
	}
	else
	{
		char temp[100];
		sprintf(temp, "mauvis login car taille = %d --- %s", lenght, tmp);
		//throw ExceptionMessage(temp);
	}
}
int Secretaire::setPassword(const char *tmp)
{
	unsigned int i, digit=0, alpha=0, lenght;
	char temp[100];
	lenght = strlen(tmp);
	//cout << endl << tmp << endl;
	if(lenght != 8)
	{
		throw InvalidPasswordException(InvalidPasswordException::BAD_LENGTH_ERROR, temp);
	}
	for(i=0; i < lenght; i++)
	{
		if(tmp[i] <= '9' && tmp[i] >= '0') 
			digit = 1;
		
		if(isalpha(tmp[i])) 
			alpha = 1;
	}
	//cout << endl << "fin analise : "<< digit << " - " << alpha<< endl;
	if(digit == 0)
		throw InvalidPasswordException(InvalidPasswordException::MISSING_DIGIT_ERROR, "erreur digit manquant");
	
	if(alpha == 0)
		throw InvalidPasswordException(InvalidPasswordException::MISSING_ALPHA_ERROR, "erreur alphha manquant");
	

	strcpy(password, tmp);
}

/***************************************
*
*			Getteur
*
********************************/
const char *Secretaire::getLogin() const
{
	return login;
}
const char *Secretaire::getPassword() const
{
	return password;
}


/***********************************************
*
*		operateurs
*
**********************************/

Secretaire &Secretaire::operator=(const Secretaire &tmp)
{
	setNom(tmp.getNom());
	setPrenom(tmp.getPrenom());
	setNumClub(tmp.NumClub);
	setPassword(tmp.password);
	setLogin(tmp.login);
	
	return *this;
}


ostream &operator<<(ostream &s, const Secretaire &j)
{
	s << (Personne)j << endl;
	s << "num : " << j.getNumClub()<< endl;
	s << "login : " << j.getLogin() << " password : " << j.getPassword()<< endl;
	return s;
}

istream &operator>>(istream &s, Secretaire &j)
{
	char tmp[100], pass[100];
	int tmpint;
	Personne tmpp;
	s >> tmpp;
	j.setNom(tmpp.getNom());
	j.setPrenom(tmpp.getPrenom());
	
	cout << "Encodez le numero de club : " << flush;
	s >> tmpint;
	j.setNumClub(tmpint);
	cout << " Encodez le login : " << flush;
	s >> tmp;
	j.setLogin(tmp);
	cout << " Encodez le password : " << flush;
	s >> pass;
	j.setPassword(pass);
	return s;
}

int Secretaire::operator==(const Secretaire &tmpSecretaire)
{
	
	return 1;
}



/*******************************************
*
*			Autre
*
********************************/

void Secretaire::Save(ofstream &fichier) const
{
	char buf[9];
	// save login
	Membre::Save(fichier);
	fichier.write(getLogin(),9);
	
	//save password
	
	fichier.write(getPassword(),9);
	return;
}

void Secretaire::Load(ifstream &fichier)
{
	char buf[9];
	//cout<< "load secretaire "<< endl;
	Membre::Load(fichier);
	
	//lecture login
	//cout << (Personne )*this<<endl;
	fichier.read(buf,9);
	setLogin(buf);
	//cout << "log : " << buf<< endl;
	//lecture password
	
	fichier.read(buf,9);
	//cout << "pass : " << buf<< endl;
	setPassword(buf);
	return;
}























