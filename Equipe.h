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
		Joueur *jJoueur[4]; //Vecteur de 4 pointeurs vers les joueurs de l'equipe
	
	public:
		Equipe();																										//Constructeur par défaut
		Equipe(Club *tmpClub, char tmpNumero,const char *tmpDivision) ;								//Constructeur d'initialisation
		Equipe(const Equipe &cpyEquipe);																			//Constructeur de copie
		~Equipe();																										//Destructeur
		Club *getClub() const;																						//Permet de récupérer l'objet club associé a l'équipe
		char getNumero() const;																						//Permet de récupérer le numero de l'équipe (la lettre)
		char *getDivision() const;																					//Permet de récupérer la division de l'équipe (Provinciale,...)
		Joueur *getJoueur(int nbr) const;																		//Permet de récupérer l'objet joueur en fonction de son indice dans le tableau
		int getNbrJoueur() const;																					//Permet de récupérer le nombre de joueur faisant partie de l'équipe
		int setClub(Club *tClub);																					//Permet de modifier la variable membre privée pointée par *pClub
		int setNumero(char num);																					//Permet de modifier la variable membre privée numero (la lettre)
		int setDivision(const char *div);																		//Permet de modifier la variable membre privée division
		int setJoueur(Joueur *tmpJoueur, int nbr);															//Permet de modifier la variable membre privée pointée par un indice du tableau de joueur
		Equipe &operator=(const Equipe &tmpEquipe);															//Surcharge de l'opérateur d'affectation afin de pouvoir copier un objet équipe
		int operator==(const Equipe &tmpEquipe);																//Surcharge de l'opérateur de comparaison d'égalité afin de pouvoir comaparer 2 équipes, renvoie true ou false
		void Save(ofstream &fichier) const;																		//Permet de sauvegarder une équipe dans un fichier
		void Load(ifstream &fichier);																				//Permet de charger une équipe d'un fichier
		void printfClubLettre()const;																				//Permet d'afficher le nom du club lié suivit de la lettre de l'équipe

};

#endif // H_EQUIPE_H
