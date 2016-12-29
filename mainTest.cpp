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

char login[9];
char nomClub[9];

void menuFed();
void menuClub(char*);


Secretaire s;
int numeroClub;

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
		cout << "***********************************" << endl << endl;
		char passwd[9];
		int i;
		
		
		if(!(fichier.is_open()))
		{
			bidonnageSec();
			fichier.open("secretaires.dat", ios::in);
		}
		
		//cout << "chargement liste secretaire"<< endl;
		listeSec.Load(fichier);
		fichier.close();
		//cout << "affichage liste secretaire !!!"<< endl;
		//printListeSec(listeSec);
		
		try
		{
			cout << "Login : ";
			cin >> login;
			//Test si login OK
			cout << "Password : ";
			cin >> passwd;
			//Test si password OK
			
			s.setLogin(login);
			s.setPassword(passwd);
		}
		catch(InvalidPasswordException &e)
		{}
		for(i=0; (numeroClub = testSecLogin(listeSec, &s)) == -1; i++)
		{
			try
			{
				cout << "Login et/ou password incorrecte !"<<endl;
				cout << "Login : ";
				cin >> login;
				//Test si login OK
				cout << "Password : ";
				cin >> passwd;
				//Test si password OK
				Secretaire s;
				s.setLogin(login);
				s.setPassword(passwd);
			}
			catch(InvalidPasswordException &e)
			{}
		}
		
		
		//cout << s << endl;
		if(numeroClub == 0)
		{
			menuFed();	//lancer l'interface grand manitou
		}
		else
		{
			menuClub(nomClub);	//lancer l'interface petite bite
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

void menuFed()
{
		cleanScreen();
		cout << "********************************************************************" << endl;
		cout << "********* Gestion de la Fédération de Tennis de Table **************" << endl;
		cout << "********************************************************************" << endl << endl;
		cout << "	0. Quitter" << endl;
		cout << "	1. Changer de mot de passe" << endl;
		cout << "Gestion des Clubs **************************************************" << endl;
		cout << "	2. Créer un nouveau Club" << endl;
		cout << "	3. Afficher tous les Clubs" << endl;
		cout << "	4. Afficher toutes les informations et les joueurs d’un Club" << endl;
		cout << "Gestion des Secretaires ********************************************" << endl;
		cout << "	5. Ajouter un Secretaire" << endl;
		cout << "	6. Afficher tous les Secretaires de federation" << endl;
		cout << "	7. Afficher tous les Secretaires de club" << endl;
		cout << "	8. Supprimer un Secretaire" << endl;
		cout << "Gestion des Joueurs ************************************************" << endl;
		cout << "	9. Afficher tous les Joueurs" << endl;
		cout << "	10. Afficher tous les Joueurs pour un classement de lettre donnee"<<  endl;
		cout << "Gestion des équipes ************************************************" << endl;
		cout << "	11. Afficher toutes les équipes" << endl;
		cout << "	12. Afficher toutes les informations d’une équipe" << endl;
		cout << "	13. Lancer un match de championnat inter-club et exporter les résultats au format txt" << endl << endl;
		int ch;
		cout << "Votre choix : ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				//save
				exit(0);
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			case 6:
			break;
			
			case 7:
			break;
			
			case 8:
			break;
			
			case 9:
			break;
			
			case 10:
			break;
			
			case 11:
			break;
			
			case 12:
			break;
			
			case 13:
			break;
			
		}
	
}




void menuClub(char* nomClub)
{
		cleanScreen();
		cout << "********************************************************************" << endl;
		cout << "*********** Club de Tennis de Table : " << nomClub << " *********************" << endl;
		cout << "********************************************************************" << endl << endl;
		cout << "	0. Quitter" << endl;
		cout << "	1. Changer de mot de passe" << endl;
		cout << "Gestion des Joueurs ************************************************" << endl;
		cout << "	2. Ajouter un Joueur" << endl;
		cout << "	3. Supprimer un Joueur" << endl;
		cout << "	4. Afficher tous les Joueurs (nom, prénom, classement)" << endl;
		cout << "	5. Afficher toutes les informations d’un Joueur" << endl;
		cout << "	6. Importer un ensemble de joueurs à partir d’un fichier texte" << endl;
		cout << "Gestion des équipes ************************************************" << endl;
		cout << "	7. Créer une équipe" << endl;
		cout << "	8. Ajouter un joueur à une équipe" << endl;
		cout << "	9. Retirer un joueur d’une équipe" << endl;
		cout << "	10. Afficher tous les détails d’une équipe" << endl;
		cout << "	11. Afficher toutes les équipes" << endl;
		cout << "	12. Supprimer une équipe" << endl << endl;
		int ch;
		cout << "Votre choix : ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				//save
				exit(0);
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			case 6:
			break;
			
			case 7:
			break;
			
			case 8:
			break;
			
			case 9:
			break;
			
			case 10:
			break;
			
			case 11:
			break;
			
			case 12:
			break;
			
		}
		
}











