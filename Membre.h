#ifndef	__Membre_H__
#define	__Membre_H__
#include "Personne.h"

class Membre : public Personne
{
	protected:
		int	NumClub;

	public:
		//initialisateur
		Membre() : Personne()
		{setNumClub(-1);};
		
		Membre(const char *name, const char *sdname, int n) : Personne(name, sdname)
		{setNumClub(n);};
		
		Membre(const Membre &tmp) : Personne(tmp)
		{setNumClub(tmp.getNumClub());};
		
		virtual  ~Membre();
		
		//affiche
		virtual int Affiche(void) = 0;
		
		//setteur
		int setNumClub(int n);
		
		// getteur
		const int getNumClub() const;

		
		//operateurs
		Membre &operator=(const Membre &tmp);
		friend ostream &operator<<(ostream &s, const Membre &j);
		friend istream &operator>>(istream &s, Membre &j);

		
};

#endif
