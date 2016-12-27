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
#include "Matricule.h"
#include "Iterateur.h"


void bidonnageSec()
{
	ofstream fichier("secretaires.dat",ios::out);
	Secretaire s("admin","admin",0,"admin","admin111");
	s.Load(fichier);
	fichier.close();
}
