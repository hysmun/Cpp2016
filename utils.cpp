#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "Equipe.h"
#include "Club.h"
#include "Classement.h"
#include "Joueur.h"
#include "Membre.h"
#include "Personne.h"
#include "Secretaire.h"
#include "ListeBase.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "InvalidClassementException.h"
#include "InvalidPasswordException.h"
#include "ExceptionMessage.h"
#include "Matricule.h"
#include "Iterateur.h"


void bidonnageSec()
{
	try
	{
		ofstream fichier("secretaires.dat",ios::out);
		Secretaire s("admin","admin",0, "admin", "admin111");
		s.Save(fichier);
		fichier.close();
	}
	catch(ExceptionMessage &e)
	{
		cerr << "erreur : "<< e.getMsg()<<endl;
	}
	catch(InvalidPasswordException &e)
	{
		cerr << "password incorect "<< e.getMsg() << endl;
	}
	catch(...)
	{
		cerr << "erreur inconnue"<< endl;
	}
}



int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec)
{
	Iterateur<Secretaire> itSec(listeSec);
	cout << "test des secretaire login + mdp"<<endl;
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		cout << (&itSec)->getLogin() << " == "<< sec->getLogin()<<endl;
		cout << (&itSec)->getPassword() << " == "<< sec->getPassword()<<endl<<endl;
		if(strcmp((&itSec)->getLogin(), sec->getLogin()) && strcmp((&itSec)->getPassword(), sec->getPassword()))
		{
			sec = (&itSec);
			cout << "trouver !"<< endl;
			return (&itSec)->getNumClub();
		}
	}
	return -1;
}

int printListeSec(Liste<Secretaire> listeSec)
{
	int i;
	Iterateur<Secretaire> pParc(listeSec);
	cout<< endl;
	for(i=0; pParc.end() != 0; i++)
	{
		cout << "secretaire "<< i<<endl;
		cout << &pParc <<endl;
		pParc++;
	}
	
}











































