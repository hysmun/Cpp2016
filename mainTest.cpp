/*
*
*
*
*
*		main pour test personnel !!!
*
*
*/

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
#include "utils.h"


int main()
{
	try
	{
		ifstream fichier("secretaires.dat",ios::in);
		//ifstream fichier2("clubs.dat",ios::in);
		Liste<Secretaire> listeSec;
		//ListeTriee<Club> listeClub;
		cout << "***********************************" << endl;
		cout << "********** Bienvenue !!! **********" << endl;
		cout << "***********************************" << endl << endl << endl;
		char login[9],passwd[9];
		int numeroClub;
		if(!(fichier.is_open()))
		{
			bidonnageSec();
			fichier.open("secretaires.dat", ios::in);
		}
		//throw ExceptionMessage(" message");
		cout << "chargement liste secretaire"<< endl;
		listeSec.Load(fichier);
		fichier.close();
		cout << "affichage liste secretaire !!!"<< endl;
		printListeSec(listeSec);
		cout << "Login : ";
		cin >> login;
		//Test si login OK
		cout << "Password : ";
		cin >> passwd;
		//Test si password OK


		if(numeroClub == 0)
		{
			//lancer l'interface grand manitou
		}
		else
		{
			//lancer l'interface petite bite
		}
	}
	catch(ExceptionMessage &e)
	{
		cerr << e.getMsg()<< endl;
	}
	catch(InvalidClassementException &e)
	{
		cerr << "mauvais classement "<< endl;
	}
	catch(InvalidPasswordException &e)
	{
		cerr << "mauvais password main()"<< e.getMsg() << " --- "<< e.getCode()<<endl;
	}
	catch(...)
	{
		cerr << "Erreur inconue" << endl;
	}
}




















