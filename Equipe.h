#ifndef H_EQUIPE_H
#define H_EQUIPE_H

#include <iostream>
#include "Joueur.h"
#include "Club.h"
using namespace std;

class Equipe
{
		friend ostream &operator<<(ostream &s, const Equipe &e);											//Surcharge de l'opérateur d'insertion afin d'afficher les détails d'une équipe
		friend istream &operator>>(istream &s, Equipe &e);													//Surcharge de l'opérateur d'extraction afin de pouvoir encoder les détails d'une équipe
		
		
	private:
		Club *pClub;
		char numero;
		char *division;
		Joueur *jJoueur[4]; // vecteur de 4 pointeur vers les joueurs de l'equipe
	
	public:
		Equipe();																										//Constructeur par défaut
		Equipe(Club *tmpClub, char tmpNumero,const char *tmpDivision) ;								//Constructeur d'initialisation
		Equipe(const Equipe &cpyEquipe);																			//Constructeur de copie
		~Equipe();																										//Destructeur
		Club *getClub() const;
		char getNumero() const;
		char *getDivision() const;
		Joueur *getJoueur(int nbr) const;
		int getNbrJoueur() const;
		int setClub(Club *tClub);
		int setNumero(char num);
		int setDivision(const char *div);
		int setJoueur(Joueur *tmpJoueur, int nbr);
		Equipe &operator=(const Equipe &tmpEquipe);
		int operator==(const Equipe &tmpEquipe);
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);
		void printfClubLettre()const;

};

#endif // H_EQUIPE_H
