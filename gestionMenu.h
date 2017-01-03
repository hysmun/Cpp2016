#ifndef __GESTIONMENU_H__
#define __GESTIONMENU_H__

#include "Secretaire.h"
#include "ListeBase.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Club.h"
#include "Joueur.h"

int mygetch ( void );

int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpasss);

int showSec(Liste<Secretaire> listeSec, bool type);

int supprimerSec(char* firstname,char* lastname, Liste<Secretaire> *listeSec);



int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec);

int supprimerJoueur(Matricule m, ListeTriee<Joueur> *listeJoueur);

int importFichierJoueur(ListeTriee<Joueur> *listeJoueur,char *nomFich, int numeroClub);

int CreeEquipe(ListeTriee<Club> *listeClub, Liste<Equipe> *listeEquipe, int num);



void bidonnageSec();



int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec);

int printListeSec(Liste<Secretaire> listeSec);

int cleanScreen();
char WaitHit();


int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);


Club *getClubWithNum(ListeTriee<Club> *listeClub, int num);
Joueur *getJoueurWithNum(ListeTriee<Joueur> *listeJoueur, int num);
Equipe *getEquipeWithNum(Liste<Equipe> *listeEquipe, char lettre, Club tmpC);

int printListeJoueur(ListeTriee<Joueur> listeJoueur);
int printListeEquipe(Liste<Equipe> listeEquipe);


int SaveJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);


int removeJoueurFromEquipe(Equipe *tmpE, Joueur *tmpJ);

int showJoueurWthClassement(ListeTriee<Joueur> listeJoueur,char letclass);




#endif // __GESTIONMENU_H__
