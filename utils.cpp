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
#include "gestionMenu.h"


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
	//cout << "test des secretaire login + mdp"<<endl;
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		//cout << (&itSec)->getLogin() << " == "<< sec->getLogin()<<endl;
		//cout << (&itSec)->getPassword() << " == "<< sec->getPassword()<<endl<<endl;
		if(!strcmp((&itSec)->getLogin(), sec->getLogin()) && !strcmp((&itSec)->getPassword(), sec->getPassword()))
		{
			//cout << "AAAA"<< *(&itSec)<<endl<<sec;
			*sec = *(&itSec);
			//cout << "AAAA"<< *(&itSec) << endl << *sec << endl;
			//cout << "trouver !"<< endl;
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


int cleanScreen()
{
	for(int i =0; i<100; i++)
	{
		cout << endl;
	}
	return 1;
}



int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe)
{
	
	
	if(nomClub == NULL)
	{
		//erreur !!!
	}
	else
	{
		// on veut les jouers et equipe que de 1 seul clubs portant le nom : nomClub
		ifstream fichier(nomClub,ios::in);
		
		
		
	}
	return 1;
}

char *getNomClubWithNum(ListeTriee<Club> listeClub, int num)
{
	Iterateur<Club> ItClub(listeClub);
	cout << "recheche num club "<<endl;
	for(ItClub.reset(); ItClub.end() != 0; ItClub++)
	{
		cout << endl << "premier essais : "<< num << " == "<<(&ItClub)->getNumClub()<<endl;
		if((&ItClub)->getNumClub() == num)
		{
			return (&ItClub)->getNom();
		}
	}
	throw ExceptionMessage("nom de club pas trouver !");
	return NULL;
}



































