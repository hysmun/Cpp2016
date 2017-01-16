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
//Vide la fenêtre 
int cleanScreen();										

//Attend l'appui d'une touche
char WaitHit();											

//Repositionne la fenêtre
void SetCursorPos(int XPos, int YPos);				

//Récupère l'appui sur une touche (~kbhit)
int mygetch(void);										



/***********************************
*
*			fct modif
*
***********************************/
//Teste si la combinaison login + mdp existe, renvoie un code d'erreur
int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec);											

//Permet de modifier le mot de passe de la secrétaire sélectionnée, renvoie un code d'erreur
int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpasss);				



/***********************************
*
*			fct ajout
*
***********************************/
//Bidonne le fichier des logins pour permettre l'accès en tant qu'admin si le fichier n'est pas présent
void bidonnageSec();

//Permet d'ajouter le club dans la liste des clubs et de créer une secrétaire pour ce club, renvoie un code d'erreur
int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec);								

//Permet de créer une équipe dans le club sélectionné et de lui attribuer une lettre ainsi que des joueurs, renvoie un code d'erreur
int CreeEquipe(ListeTriee<Club> *listeClub, Liste<Equipe> *listeEquipe, int num);				



/***********************************
*
*			fct affichage
*
***********************************/	
//Affiche la liste des secrétaires, renvoi un code d'erreur	
int printListeSec(Liste<Secretaire> listeSec);

//Affiche les informations d'une secrétaire, renvoie un code d'erreur
int showSec(Liste<Secretaire> listeSec, bool type);

//Affiche la liste des joueurs, renvoie un code d'erreur
int printListeJoueur(ListeTriee<Joueur> listeJoueur);

//Affiche la liste des équipes, renvoie un code d'erreur
int printListeEquipe(Liste<Equipe> listeEquipe);

//Affiche les joueurs selon le classement demandé
void showJoueurWthClassement(ListeTriee<Joueur> listeJoueur,char letclass);

//Affiche les informations d'un joueur selon son numero de matricule
void showInfoJoueur(ListeTriee<Joueur> listeJoueur,int matriculeint);

//Affiche les informations d'un club via son numéro de club
void showInfoClub(ListeTriee<Club> listeClub,ListeTriee<Joueur> listeJoueur,Liste<Equipe> listeEquipe);



/***********************************
*
*			fct suppression
*
***********************************/
//Supprime un joueur choisit de l'équipe sélectionnée
int removeJoueurFromEquipe(Equipe *tmpE, Joueur *tmpJ);			

//Supprime un joueur de la liste des joueurs	
int supprimerJoueur(Matricule m, ListeTriee<Joueur> *listeJoueur);	

//Supprime une secrétaire de la liste via son nom et prénom
int supprimerSec(char* firstname,char* lastname, Liste<Secretaire> *listeSec);

//Supprime une équipe via son numéro dans la liste	
int supprimerEqu(int numero, Liste<Equipe> *listeEquipe);						



/***********************************
*
*			fct recherhe dans liste
*
***********************************/
//Permet de récupérer un club en fonction de son numéro
Club *getClubWithNum(ListeTriee<Club> *listeClub, int num);								

//Permet de récupérer un joueur en fonction de son numero de matricule
Joueur *getJoueurWithNum(ListeTriee<Joueur> *listeJoueur, int num);									

//Permet de récupérer une équipe en fonction de son club et de sa lettre
Equipe *getEquipeWithNum(Liste<Equipe> *listeEquipe, char lettre, Club tmpC);				



/***********************************
*
*			fct Save Load et fichier
*
***********************************/
//Permet d'importer un fichier .dat contenant les joueurs d'un club
int importFichierJoueur(ListeTriee<Joueur> *listeJoueur,char *nomFich, int numeroClub);	

//Sauvegarde les équipes et leurs joueurs présents dans la liste dans un fichier binaire				
int SaveJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);			

//Charge les équipes et leurs joueurs d'un fichier binaire vers la liste appropriée
int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);			



/***********************************
*
*			fct exporter resultats
*
***********************************/
//Permet d'encoder les résultats d'un match et de les exporter en fichier texte
int SimAndExportRes(Liste<Equipe> *listeEquipe,ListeTriee<Joueur> *listeJoueur,ListeTriee<Club> *listeClub);



#endif // __GESTIONMENU_H__
