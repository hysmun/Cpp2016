#ifndef H_UTILS_H
#define H_UTILS_H


void bidonnageSec();



int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec);

int printListeSec(Liste<Secretaire> listeSec);

int cleanScreen();


int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);


Club *getClubWithNum(ListeTriee<Club> *listeClub, int num);
Joueur *getJoueurWithNum(ListeTriee<Joueur> *listeJoueur, int num);

int printListeJoueur(ListeTriee<Joueur> listeJoueur);
int printListeEquipe(Liste<Equipe> listeEquipe);


int SaveJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);




#endif // H_UTILS_H
