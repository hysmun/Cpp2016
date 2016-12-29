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

int modifierPassword(Liste<Secretaire> *listeSec,Secretaire *s,char newpass[9])
{
	Iterateur<Secretaire> itSec(*listeSec);
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		if(!strcmp((&itSec)->getLogin(), s->getLogin()) && !strcmp((&itSec)->getPassword(), s->getPassword()))
		{
			(&itSec)->setPassword(newpass);
			return 0;
		}
		else
			throw ExceptionMessage("Secretaire introuvable dans le container !");
	}
	return -1;
}

int showSec(const Liste<Secretaire> listeSec,bool type)
{
	Iterateur<Secretaire> itSec(listeSec);
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		cout << "***********************" << endl;
		if((&itSec)->getNumClub() == 0 && (type == 0))
		{
			cout << "Nom : " << (&itSec)->getNom() << endl;
			cout << "Prénom : " << (&itSec)->getPrenom() << endl;
		}
		else if((&itSec)->getNumClub() != 0 && (type == 1))
		{
			cout << "Nom : " << (&itSec)->getNom() << endl;
			cout << "Prénom : " << (&itSec)->getPrenom() << endl;
		}
	}
}
