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
int cleanScreen();
char WaitHit();
void SetCursorPos(int XPos, int YPos);
int mygetch(void);



/***********************************
*
*			fct modif
*
***********************************/
int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec);
int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpasss);


/***********************************
*
*			fct ajout
*
***********************************/
void bidonnageSec();
int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec);
int CreeEquipe(ListeTriee<Club> *listeClub, Liste<Equipe> *listeEquipe, int num);


/***********************************
*
*			fct affichage
*
***********************************/
int printListeSec(Liste<Secretaire> listeSec);
int showSec(Liste<Secretaire> listeSec, bool type);
int printListeJoueur(ListeTriee<Joueur> listeJoueur);
int printListeEquipe(Liste<Equipe> listeEquipe);
void showJoueurWthClassement(ListeTriee<Joueur> listeJoueur,char letclass);
void showInfoJoueur(ListeTriee<Joueur> listeJoueur,int matriculeint);


/***********************************
*
*			fct suppression
*
***********************************/
int removeJoueurFromEquipe(Equipe *tmpE, Joueur *tmpJ);
int supprimerJoueur(Matricule m, ListeTriee<Joueur> *listeJoueur);
int supprimerSec(char* firstname,char* lastname, Liste<Secretaire> *listeSec);
int supprimerEqu(int numero, Liste<Equipe> *listeEquipe);



/***********************************
*
*			fct recherhe dans liste
*
***********************************/
Club *getClubWithNum(ListeTriee<Club> *listeClub, int num);
Joueur *getJoueurWithNum(ListeTriee<Joueur> *listeJoueur, int num);
Equipe *getEquipeWithNum(Liste<Equipe> *listeEquipe, char lettre, Club tmpC);


/***********************************
*
*			fct Save Load et fichier
*
***********************************/
int importFichierJoueur(ListeTriee<Joueur> *listeJoueur,char *nomFich, int numeroClub);
int SaveJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);
int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);

/***********************************
*
*			fct exporter resultats
*
***********************************/
void SimAndExportRes(Liste<Equipe> &listeEquipe,ListeTriee<Joueur> &listeJoueur,char *clubDom,char *clubVis, char divDom,char divVis);



#endif // __GESTIONMENU_H__
