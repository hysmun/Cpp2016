#ifndef __GESTIONMENU_H__
#define __GESTIONMENU_H__

#include "Secretaire.h"
#include "ListeBase.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Club.h"
#include "Joueur.h"


/***********************************
*
*			fct generale
*
***********************************/
int cleanScreen();										//Vide la fenêtre 
char WaitHit();											//Attend l'appui d'une touche
void SetCursorPos(int XPos, int YPos);				//Repositionne la fenêtre
int mygetch(void);										//Récupère l'appui sur une touche (~kbhit)



/***********************************
*
*			fct modif
*
***********************************/
int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec);											//Teste si la combinaison login + mdp existe, renvoie un code d'erreur
int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpasss);				//Permet de modifier le mot de passe de la secrétaire sélectionnée, renvoie un code d'erreur


/***********************************
*
*			fct ajout
*
***********************************/
void bidonnageSec();																									//Bidonne le fichier des logins pour permettre l'accès en tant qu'admin si le fichier n'est pas présent
int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec);								//Permet d'ajouter le club dans la liste des clubs et de créer une secrétaire pour ce club, renvoie un code d'erreur
int CreeEquipe(ListeTriee<Club> *listeClub, Liste<Equipe> *listeEquipe, int num);				//Permet de créer une équipe dans le club sélectionné et de lui attribuer une lettre ainsi que des joueurs, renvoie un code d'erreur


/***********************************
*
*			fct affichage
*
***********************************/		
int printListeSec(Liste<Secretaire> listeSec);																					//Affiche la liste des secrétaires, renvoi un code d'erreur
int showSec(Liste<Secretaire> listeSec, bool type);																			//Affiche les informations d'une secrétaire, renvoie un code d'erreur
int printListeJoueur(ListeTriee<Joueur> listeJoueur);																			//Affiche la liste des joueurs, renvoie un code d'erreur
int printListeEquipe(Liste<Equipe> listeEquipe);																				//Affiche la liste des équipes, renvoie un code d'erreur
void showJoueurWthClassement(ListeTriee<Joueur> listeJoueur,char letclass);											//Affiche les joueurs selon le classement demandé
void showInfoJoueur(ListeTriee<Joueur> listeJoueur,int matriculeint);													//Affiche les informations d'un joueur selon son numero de matricule
void showInfoClub(ListeTriee<Club> listeClub,ListeTriee<Joueur> listeJoueur,Liste<Equipe> listeEquipe);		//Affiche les informations d'un club via son numéro de club


/***********************************
*
*			fct suppression
*
***********************************/
int removeJoueurFromEquipe(Equipe *tmpE, Joueur *tmpJ);																		//Supprime un joueur choisit de l'équipe sélectionnée
int supprimerJoueur(Matricule m, ListeTriee<Joueur> *listeJoueur);														//Supprime un joueur de la liste des joueurs
int supprimerSec(char* firstname,char* lastname, Liste<Secretaire> *listeSec);										//Supprime une secrétaire de la liste via son nom et prénom
int supprimerEqu(int numero, Liste<Equipe> *listeEquipe);																	//Supprime une équipe via son numéro dans la liste



/***********************************
*
*			fct recherhe dans liste
*
***********************************/
Club *getClubWithNum(ListeTriee<Club> *listeClub, int num);																	//Permet de récupérer un club en fonction de son numéro
Joueur *getJoueurWithNum(ListeTriee<Joueur> *listeJoueur, int num);														//Permet de récupérer un joueur en fonction de son numero de matricule
Equipe *getEquipeWithNum(Liste<Equipe> *listeEquipe, char lettre, Club tmpC);											//Permet de récupérer une équipe en fonction de son club et de sa lettre


/***********************************
*
*			fct Save Load et fichier
*
***********************************/
int importFichierJoueur(ListeTriee<Joueur> *listeJoueur,char *nomFich, int numeroClub);																	//Permet d'importer un fichier .dat contenant les joueurs d'un club
int SaveJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);			//Sauvegarde les équipes et leurs joueurs présents dans la liste dans un fichier binaire
int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);			//Charge les équipes et leurs joueurs d'un fichier binaire vers la liste appropriée

/***********************************
*
*			fct exporter resultats
*
***********************************/
int SimAndExportRes(Liste<Equipe> *listeEquipe,ListeTriee<Joueur> *listeJoueur,ListeTriee<Club> *listeClub);				//Permet d'encoder les résultats d'un match et de les exporter en fichier texte



#endif // __GESTIONMENU_H__
