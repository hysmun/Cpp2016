#ifndef H_UTILS_H
#define H_UTILS_H


void bidonnageSec();



int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec);

int printListeSec(Liste<Secretaire> listeSec);

int cleanScreen();


int LoadJoueurAndEquipe(char *nomClub, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe);


char *getNomClubWithNum(ListeTriee<Club> listeClub, int num);

int printListeJoueur(ListeTriee<T> listeJoueur)




#endif // H_UTILS_H
