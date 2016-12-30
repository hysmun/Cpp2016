#ifndef __GESTIONMENU_H__
#define __GESTIONMENU_H__

#include "Secretaire.h"
#include "ListeBase.h"
#include "Liste.h"
#include "ListeTriee.h"



int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpasss);

int showSec(Liste<Secretaire> listeSec, bool type);

int supprimerSec(char* firstname,char* lastname, Liste<Secretaire> *listeSec);



int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec);















#endif // __GESTIONMENU_H__
