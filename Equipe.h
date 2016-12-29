#ifndef H_EQUIPE_H
#define H_EQUIPE_H

#include <iostream>
#include "Joueur.h"
#include "Club.h"
using namespace std;

class Equipe
{
		friend ostream &operator<<(ostream &s, const Equipe &e);
		friend istream &operator>>(istream &s, Equipe &e);
		
		
	private:
		Club *pClub;
		char numero;
		char *division;
		Joueur *jJoueur[4]; // vecteur de 4 pointeur vers les joueurs de l'equipe
	
	public:
		//initialisateur
		Equipe();
		Equipe(Club *tmpClub, char tmpNumero,const char *tmpDivision) ;
		Equipe(const Equipe &cpyEquipe);
		~Equipe();

		//getteur
		Club *getClub() const;
		char getNumero() const;
		char *getDivision() const;
		Joueur *getJoueur(int nbr) const;
		
		//setteur
		int setClub(Club *tClub);
		int setNumero(char num);
		int setDivision(const char *div);
		int setJoueur(Joueur *tmpJoueur, int nbr);
		
		//operateur
		
		Equipe &operator=(const Equipe &tmpEquipe);
		int operator==(const Equipe &tmpEquipe);
		
		//autre
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);

};

#endif // H_EQUIPE_H
