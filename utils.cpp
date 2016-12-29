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
		char pass[9] = "adminaa1";
		ifstream fichier("secretaires.dat",ios::in);
		Secretaire s("admin","admin",0);
		s.setLogin("admin");
		cout << "password "<< endl;
		s.setPassword(pass);
		s.Load(fichier);
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
