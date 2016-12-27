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


int main()
{
	ifstream fichier("secretaires.dat",ios::in);
	Liste<Secretaire> listeSec;
	cout << "***********************************" << endl;
	cout << "********** Bienvenue !!! **********" << endl;
	cout << "***********************************" << endl << endl << endl;
	char login[20],passwd[20];
	cout << "Login : ";
	cin >> login;
	//Test si login OK
	cout << "Password : ":
	cin >> passwd;
	//Test si password OK
}
