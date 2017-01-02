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
#include "gestionMenu.h"

int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpass)
{
	if(strlen(newpass) != 8)
	{
		throw ExceptionMessage("mauvais mots de pass dans modifierPassword");
	}
	Iterateur<Secretaire> itSec(*listeSec);
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		if(!strcmp((&itSec)->getLogin(), s->getLogin()) && !strcmp((&itSec)->getPassword(), s->getPassword()))
		{
			(&itSec)->setPassword(newpass);
			return 0;
		}
	}
	return -1;
}

int showSec(Liste<Secretaire> listeSec,bool type)
{
	Iterateur<Secretaire> itSec(listeSec);
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		if((&itSec)->getNumClub() == 0 && (type == 0))
		{
			cout << "******************" << endl;
			cout << "Nom : " << (&itSec)->getNom() << endl;
			cout << "Prénom : " << (&itSec)->getPrenom() << endl;
		}
		else if((&itSec)->getNumClub() != 0 && (type == 1))
		{
			cout << "******************" << endl;
			cout << "Nom : " << (&itSec)->getNom() << endl;
			cout << "Prénom : " << (&itSec)->getPrenom() << endl;
			cout << "Numéro de club : " << (&itSec)->getNumClub() << endl;
		}
	}
}

int supprimerSec(char* firstname,char* lastname,Liste<Secretaire> *listeSec)
{
	Iterateur<Secretaire> itSec(*listeSec);
	int nClub;
	for(itSec.reset();itSec.end() == 0;itSec++)
	{
		if(!strcmp((&itSec)->getPrenom(), firstname) && !strcmp((&itSec)->getNom(), lastname))
		{
			nClub = (&itSec)->getNumClub();
			//Test s'il reste une secretaire dans le club
			Iterateur<Secretaire> itTmp(*listeSec);
			for(itTmp.reset();itTmp.end() == 0;itTmp++)
			{
				if((strcmp((&itTmp)->getPrenom(), firstname) != 0) && (strcmp((&itTmp)->getNom(),lastname) != 0) && ((&itTmp)->getNumClub() == nClub))
				{
					itSec.remove();
					return 0;
				}
			}
			return -1;
		}
	}

}

int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec)
{
	Club cTmp;
	Secretaire sTmp;
	char tmp[100], pass[100];
	int tmpint, test =0;
	Personne tmpp;
	if(listeClub == NULL || listeSec == NULL)
	{
		throw ExceptionMessage("Erreur add club");
	}
	
	//encodage club
	cout << "encodage du club " << endl;
	cin >> cTmp;
	
	
	//Test s'il reste une secretaire dans le club
	Iterateur<Secretaire> itTmp(*listeSec);
	for(itTmp.reset();itTmp.end() == 0;itTmp++)
	{
		if(((&itTmp)->getNumClub() == cTmp.getNumClub()))
		{
			test = 1;
		}
	}
	if(test == 0)
	{
		//encodage Secretaire du club
		cout << endl <<"encodage de la secretaire"<< endl;
		cin >> tmpp;
		sTmp.setNom(tmpp.getNom());
		sTmp.setPrenom(tmpp.getPrenom());
	
		sTmp.setNumClub(cTmp.getNumClub());
		cout << "Encodez le login : " << flush;
		cin >> tmp;
		sTmp.setLogin(tmp);
		cout << "Encodez le password : " << flush;
		cin >> pass;
		sTmp.setPassword(pass);
	}
	
	//verifie que le club et la secretaire n'existe pas déjà
	if(!listeClub->SearchDoublet(cTmp)  &&  !listeSec->SearchDoublet(sTmp))
	{
		listeClub->insere(cTmp);
		listeSec->insere(sTmp);
	}
	else
	{
		throw ExceptionMessage("Erreur création club !!!!");
		return -1;
	}
	
	
	return 1;
}


int supprimerJoueur(Matricule m, ListeTriee<Joueur> *listeJoueur)
{
	Iterateur<Joueur> itJoueur(*listeJoueur);
	for(itJoueur.reset();itJoueur.end() == 0;itJoueur++)
	{
		
		if(!strcmp((&itJoueur)->getMatricule().getDateInscription(),m.getDateInscription()) && ((&itJoueur)->getMatricule().getNumero() == m.getNumero()))
		{
			itJoueur.remove();
			return 0;
		}
	}
	return -1;
}

int importFichierJoueur(ListeTriee<Joueur> *listejoueur, char* nomFich)
{
	int HdFich;
	if((HdFich = open(nomFich,O_RDONLY)) == -1)
	{
		cout << "Nom de fichier incorrect" << endl;
		return -1;
	}
	
}


































