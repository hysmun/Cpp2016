#ifndef	__JOUEUR_H__
#define	__JOUEUR_H__
#include "Matricule.h"
#include "Classement.h"
#include "Membre.h"

class Joueur : public Membre
{
	protected:
		int	Points;
		Matricule jMatricule;
		Classement *jClassement;
	public:
		//initialisateur
		Joueur();
		Joueur(const char *name, const char *sdname, int n);
		Joueur(const char *name, const char *sdname, int n, Matricule m);
		
		Joueur(const Joueur &tmp);
		
		~Joueur();
		
		//affiche
		virtual int Affiche(void);
		
		//setteur
		int setPoints(int n);
		int setMatricule(Matricule m);
		int setClassement(Classement *c);
		
		// getteur
		const int getPoints() const;
		const Matricule getMatricule() const;
		Classement *getClassement() const;
		
		//operateurs
		Joueur &operator=(const Joueur &tmp);
		int operator==(const Joueur &tmp);
		int operator<(const Joueur &tmp);
		int operator>(const Joueur &tmp);
		friend ostream &operator<<(ostream &s, const Joueur &j);
		friend istream &operator>>(istream &s, Joueur &j);
		Joueur &operator++();
		Joueur operator++(int x);
		Joueur &operator--();
		Joueur operator--(int x);
		Joueur operator+(int x);
		Joueur operator-(int x);
		
		//autre
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);
		
};

#endif
