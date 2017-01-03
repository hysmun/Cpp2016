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
#include <dirent.h>
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

char login[100];
char nomClub[100];

void menuFed();
void menuClub(char*);

Liste<Secretaire> listeSec;
ListeTriee<Club> listeClub;
ListeTriee<Joueur> listeJoueur;
Liste<Equipe> listeEquipe;

int verbose = 0;
int error = 1;

Secretaire s;
Club *clubSec = NULL;
int numeroClub;

int main(int argc, char *argv[])
{
	verbose = 0;
	error = 1;
	for(int j=1; j<argc; j++)
	{
		//cout << "mode "<<endl;
		switch(argv[j][0])
		{
			case '-':
			{
				switch(argv[j][1])
				{
					case 'v':
						verbose = 1;
						cout <<"      mode verbose        "<<endl;
						break;
					case 'e':
						error = 0;
						cout << "      mode non-affichage des erreurs  "<<endl;
						break;
					case 'h':
					{
						cout <<endl<< "-------   HELP ----------"<<endl<<endl;
						cout << "liste des options:"<<endl;
						cout << "-v   pour le mode verbose (affichage suplémentaire de ce que fait le programme)"<<endl;
						cout << "-e   pour le mode avec affichage d'aucune les erreurs généré par le programme-"<<endl;
						cout << "-h   pour le manuel d'aide des options"<<endl;
						cout << "-i   pour les informations concernant ce programme "<<endl<<endl;;
						break;
					}
					case 'i':
					{
						cout <<endl<< "------------------------------------ ------"<<endl;
						cout << "Programme de gestion du tennis "<<endl<<endl;;
						cout << "fait par :"<<endl;
						cout << "Brajkovic Antoine"<<endl;
						cout << "Mauhin Remy"<<endl<<endl;
						break;
					}
				}
					
				break;
			}
			default:
			{
				cout << "erreur "<<endl;
			}
		}
	}





	try
	{
		ifstream fichier("secretaires.dat",ios::in);
		ifstream fichierClub("clubs.dat",ios::in);
		
		char passwd[100];
		int i;
		
		// fichier club
		if(!(fichierClub.is_open()))
		{
			//fichier club inexistant ou pas ouvert
		}
		else
		{
			//fichier club.dat ouvert
			if(verbose == 1)
				cout << "chargement fichier club"<<endl;
			listeClub.Load(fichierClub);
			fichierClub.close();
		}
		
		
		//fichier Secretaire
		if(!(fichier.is_open()))
		{
			bidonnageSec();
			ifstream fichierSec("secretaires.dat", ios::in);
			listeSec.Load(fichierSec);
			fichierSec.close();
		}
		else
		{
			//cout << "chargement liste secretaire"<< endl;
			listeSec.Load(fichier);
			fichier.close();
			if(verbose == 1)
				cout <<"chargement fichier secretaire "<<endl;
			//cout << "affichage liste secretaire !!!"<< endl;
			//printListeSec(listeSec);
		}
		
		
		
		cout << "***********************************" << endl;
		cout << "********** Bienvenue !!! **********" << endl;
		cout << "***********************************" << endl << endl;
		
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
				s.setLogin(login);
				s.setPassword(passwd);
			}
			catch(InvalidPasswordException &e)
			{
				//
			}
		}
		
		numeroClub = s.getNumClub();
		if(verbose == 1)
			cout <<endl<<endl<<"Bienvenue :"<<endl<< s << endl;
			
		if(numeroClub == 0)
		{
			clubSec = NULL;
			
			
			Iterateur<Club> ItC(listeClub);
			for(ItC.reset(); ItC.end() == 0; ItC++)
			{
				if((&ItC)->getNom() != NULL)
				{
					char Nomfichier[255];
					sprintf(Nomfichier, "%s.dat", (&ItC)->getNom());
					LoadJoueurAndEquipe(Nomfichier, &listeClub, &listeJoueur, &listeEquipe);
				}
			}
			
			
			menuFed();	//lancer l'interface grand manitou
		}
		else
		{
			listeClub.Affiche();
			clubSec = getClubWithNum(&listeClub, numeroClub);
			//cout << "Club : "<<tmpC<<endl<< *tmpC;
			if(clubSec != NULL)
			{
				strcpy(nomClub, clubSec->getNom());
				char Nomfichier[255];
				sprintf(Nomfichier, "%s.dat", nomClub);
				LoadJoueurAndEquipe(Nomfichier, &listeClub, &listeJoueur, &listeEquipe);
				menuClub(nomClub);	//lancer l'interface petite bite
			}
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
	int ch=14;
	cleanScreen();
	while(ch != 0)
	{
		
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
		
		cout << "Votre choix : ";
		cin >> ch;
		cleanScreen();
		switch(ch)
		{
			case 0:
			{
				//save
				ofstream fichier("secretaires.dat",ios::out);
				listeSec.Save(fichier);
				fichier.close();
				
				ofstream fichierClub("clubs.dat",ios::out);
				listeClub.Save(fichierClub);
				fichierClub.close();
				
				exit(0);
				break;
			}
			
			case 1:
			{
				//nouveau mdp
				char newpass[100];
				cout << "Nouveau mot de passe : ";
				cin >> newpass;
				try
				{
					modifierPassword(&listeSec,&s,newpass);
				}
				catch(ExceptionMessage &e)
				{
					cerr << e.getMsg() << endl;
					break;
				}
				if(verbose == 1)
					cout << "Mot de passe changé avec succès !" << endl;
				ofstream fichier("secretaires.dat",ios::out);
				listeSec.Save(fichier);
				fichier.close();
				break;
			}			
			
			case 2:
			{
				//cree un club
				try
				{
					addClub(&listeClub, &listeSec);
					ofstream fichierClub("clubs.dat",ios::out);
					listeClub.Save(fichierClub);
					fichierClub.close();
					ofstream fichier("secretaires.dat",ios::out);
					listeSec.Save(fichier);
					fichier.close();
					if(verbose == 1)
						cout << "Club et secretaire ajouter "<<endl;
				}
				catch(InvalidPasswordException &e)
				{
					if(error || verbose)
						cout << "password incorrect !"<<endl;
				}
				catch (ExceptionMessage &e)
				{
					if(error || verbose)
						cout << e.getMsg()<<endl;
				}
				break;
			}
			
			case 3:
			{
				//afficher tout les clubs
				cout << "affichage des clubs :"<<endl;
				listeClub.Affiche();
				break;
			}
			
			case 4:
			{
				//afficher les infos et joueur d'un club
				cleanScreen();
				break;
			}
			
			case 5:
			{
				//cree nouvelle secretaire
				Secretaire s;		
				cin >> s;
				if(listeSec.SearchDoublet(s) == 0)
				{
					listeSec.insere(s);
					if(verbose == 1)
						cout << "Insertion réussie" << endl;
					ofstream fichier("secretaires.dat",ios::out);
					listeSec.Save(fichier);
					fichier.close();
				}
				else
				{
					if(error == 1)
						cout << "Erreur insertion" << endl;
				}
				break;
			}		
				
			case 6:
			{
				//afficher TOUTE les secretaire
				showSec(listeSec,0);
				break;
			}
			
			case 7:
			{
				//afficher les secretaire d'un club
				showSec(listeSec,1);
				break;
			}
			
			case 8:
			{
				//suprimer un secretaire
				char firstname[20],lastname[20];
				cout << "Nom : ";
				cin >> lastname;
				cout << "Prénom : ";
				cin >> firstname;
				if(supprimerSec(firstname,lastname,&listeSec) == 0)
				{
					if(verbose == 1)
						cout << "Secrétaire supprimé(e)" << endl;
					ofstream fichier("secretaires.dat",ios::out);
					listeSec.Save(fichier);
					fichier.close();
				}
				else
				{
					if(error == 1 || verbose==1)
						cout << "Erreur suppression" << endl;
				}
				break;
			}
			
			case 9:
			{
				//afficher tous les joueurs
				printListeJoueur(listeJoueur);
				break;
			}
			
			case 10:
			{
				//afficher tout les joueurs pour un classement de lettre donnee
				char letclass;
				cout << "Encodez une lettre de classement valide (A,B,C,D,E,F,N(non-classé)): ";
				cin >> letclass;
				letclass=toupper(letclass);
				while(letclass!='A' && letclass!='B' && letclass!='C' && letclass!='D' && letclass!='E' && letclass!='F' && letclass!='N')
				{
					cout << "Erreur de lettre. Encodez une lettre valide (A,B,C,D,E,F,N(non-classé)): ";
					cin >> letclass;
					letclass=toupper(letclass);
				}
				showJoueurWthClassement(listeJoueur,letclass);
				break;
			}
			
			case 11:
			{
				//afficher toutes les equipes
				listeEquipe.Affiche();
				break;
			}
			
			case 12:
			{
				//afficher les info d'une equipe
				break;
			}
			
			case 13:
			{
				//lancer un match + exporter resultat en .txt
				break;
			}
		}
		WaitHit();
		cleanScreen();
		//cout<<endl<<endl<<endl;
	}
}




void menuClub(char* nomClub)
{
	int ch= 14;
	char tmp[200];
	cleanScreen();
	while(ch != 0)
	{
		
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
		cout << "Votre choix : ";
		cin >> ch;
		cleanScreen();
		switch(ch)
		{
			case 0:
			{
				//save
				
				sprintf(tmp,"%s.dat", nomClub);
				if( verbose==1)
					cout << "Sauvegarde dans : "<<tmp<<endl<<endl;
				SaveJoueurAndEquipe(tmp, &listeClub, &listeJoueur, &listeEquipe);
				exit(0);
			}
			break;
			
			case 1:
			{
				char newpass[100];
				cout << "Nouveau mot de passe : ";
				cin >> newpass;
				try
				{
					modifierPassword(&listeSec,&s,newpass);
				}
				catch(ExceptionMessage &e)
				{
					cerr << e.getMsg() << endl;
				}
				if(verbose==1)
					cout << "Mot de passe changé avec succès !" << endl;
				ofstream fichier("secretaires.dat",ios::out);
				listeSec.Save(fichier);
				fichier.close();
				
				
				
				break;
			}						
			case 2:
			{
				//ajouter un joueur
				Joueur j;
				Personne tmp;
				Classement tmpc;
				Matricule tmpm;
	
	
				cin >>tmp;
				j.setNom(tmp.getNom());
				j.setPrenom(tmp.getPrenom());
				cin >> tmpm;
				j.setMatricule(tmpm);
				
				
				j.setNumClub(numeroClub);
				cout << "Encodez le classement: " << flush;
				cin >> tmpc;
				j.setClassement(&tmpc);
				
				listeJoueur.insere(j);
				if(verbose==1)
					cout << " joueur insere "<<endl;
				break;
			}
			
			case 3:
			{
				//supprimer un joueur
				Matricule m;
				
				cin >> m;
				if(supprimerJoueur(m,&listeJoueur) == 0)
				{
					if(verbose==1)
						cout << "Joueur supprimé" << endl;
				}
				else
				{
					if(error == 1 || verbose==1)
						cerr << "Erreur suppression" << endl;
				}
				break;
			}
			
			case 4:
			{
				//afficher tous les joueurs (nom, prenom, classement)
				printListeJoueur(listeJoueur);
				break;
			}
			
			case 5:
			{
				//afficher toutes les infos d'un seul joueur
				
				break;
			}
			
			case 6:
			{
				// importer un ensemble de joueur d'un fichier .txt
				DIR *pDir;
				dirent *pElementDir;
				int len;
				char nomFich[20];
				if((pDir = opendir(".")) == NULL)
				{
					//erreur
				}
				else
				{
					//dir ouvert
					cout << endl<< "Affichage des fichier  *.txt"<<endl<<endl;
					for(int i=0;(pElementDir = readdir(pDir)) != NULL; )
					{
						len = strlen(pElementDir->d_name);
						if(strcmp(".txt", &(pElementDir->d_name[len - 4])) == 0)
						{
							// c'est un fichier .txt
							printf("%d -- %s\n", i, pElementDir->d_name);
							i++;
						}
					}
					cout <<endl<<endl<< "Nom du fichier pour insertion : ";
					cin >> nomFich;
					importFichierJoueur(&listeJoueur,nomFich,numeroClub);
					
				}
				break;
			}
			
			case 7:
			{
				//cree une equipe
				int test;
				
				test = CreeEquipe(&listeClub, &listeEquipe, numeroClub);
				if(test == 1)
				{
					//insertion equipe reussi!
					if(verbose==1)
						cout << "equipe cree !!"<<endl;
				}
				break;
			}
			
			case 8:
			{
				//ajouter un joueur a une equipe
				int num, full =1;
				char lettre;
				Equipe *tmpE;
				Joueur *tmpJ;
				
				cout << "Veuillez entrer la lettre de l'equipe ou ajouter le joueur :"<<endl;
				cin >> lettre;
				
				tmpE = getEquipeWithNum(&listeEquipe, lettre, *clubSec);
				if(tmpE == NULL)
				{
					if(error == 1 || verbose==1)
						cerr << "erreur Equipe non existante!"<<endl;
					break;
				}
				
				cout << "Veuillez entrer le numero de matricule du joueur "<< endl;
				cin >> num;
				
				tmpJ = getJoueurWithNum(&listeJoueur, num);
				if(tmpJ == NULL)
				{
					if(verbose==1 || error ==1)
						cerr << "erreur joueur non existant!"<<endl;
					break;
				}
				
				for(int i=0; i<4; i++)
				{
					if(tmpE->getJoueur(i) == NULL)
					{
						tmpE->setJoueur(tmpJ, i);
						i = 4;
						full =0;
					}
				}
				if( full == 1)
				{
					if(verbose==1 || error ==1)
						cerr << "equipe plein impossible de rajouter le joueur "<<endl;
				}
				else
				{
					if(verbose==1)
						cout <<endl<< "Joueur ajouter a l'equipe !"<< endl << *tmpE<<endl;
				}
				
				break;
			}
			
			case 9:
			{
				//retirer un joueur d'une equipe
				int num;
				char lettre;
				Equipe *tmpE;
				Joueur *tmpJ;
				
				cout << "Veuillez entrer la lettre de l'equipe ou ajouter le joueur :"<<endl;
				cin >> lettre;
				
				tmpE = getEquipeWithNum(&listeEquipe, lettre, *clubSec);
				if(tmpE == NULL)
				{
					if(error == 1 || verbose==1)
						cerr << "erreur Equipe non existante!"<<endl;
					break;
				}
				cout << "Veuillez entrer le numero de matricule du joueur "<< endl;
				cin >> num;
				
				tmpJ = getJoueurWithNum(&listeJoueur, num);
				if(tmpJ == NULL)
				{
					if(error == 1 || verbose==1)
						cerr << "erreur joueur non existant!"<<endl;
					break;
				}
				
				removeJoueurFromEquipe(tmpE, tmpJ);
				
				if(verbose==1)
					cout << "joueur enlever de l'equipe"<<endl;
				
				break;
			}
			
			case 10:
			{
				//afficher detail une equipe
				char lettre;
				Equipe *tmpE;
				
				cout << "Veuillez entrer la lettre de l'equipe  :"<<endl;
				cin >> lettre;
				
				tmpE = getEquipeWithNum(&listeEquipe, lettre, *clubSec);
				if(tmpE == NULL)
				{
					if(error == 1 || verbose==1)
						cerr << "erreur Equipe non existante!"<<endl;
					if(error == 1 || verbose==1)
						cerr << *tmpE<<endl;
					break;
				}

				break;
			}
			
			case 11:
			{
				//afficher toutes les equipes
				printListeEquipe(listeEquipe);
				break;
			}
			
			case 12:
			{
				//supprimer une equipe
				break;
			}
			
		}
		
		WaitHit();
		cleanScreen();
		//cout<<endl<<endl<<endl;
	}
}

















