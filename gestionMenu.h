#ifndef __GESTIONMENU_H__
#define __GESTIONMENU_H__

int modifierPassword(Liste<Secretaire> *listeSec,Secretaire *s,char newpasss[9]);
int showSec(Liste<Secretaire> listeSec, bool type);
int supprimerSec(char* firstname,char* lastname, Liste<Secretaire> *listeSec);



















#endif // __GESTIONMENU_H__
