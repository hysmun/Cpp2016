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
		cerr << "password icorecte "<< e.getMsg() << endl;
	}
	catch(...)
	{
		cerr << "erreur inconue"<< endl;
	}
}



int testSecLogin(Liste<Secretaire> listeSec, const Secretaire &sec)
{
	
	
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











































