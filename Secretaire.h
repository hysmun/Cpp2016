#ifndef	__SECRETAIRE_H__
#define	__SECRETAIRE_H__
#include "Membre.h"
#include "Personne.h"

class Secretaire : public Membre
{
	protected:
		char login[9];
		char password[9];
		
		
	public:
		//initialisateur
		Secretaire();
		
		Secretaire(const char *name, const char *sdname, int n) : Membre(name, sdname, n)
		{};
		
		Secretaire(const char *name, const char *sdname, int n, const char *log, const char *pass) : Membre(name, sdname, n)
		{setLogin(log); setPassword(pass);};
		
		Secretaire(const Secretaire &tmp);
		
		virtual ~Secretaire();
		
		//affiche
		virtual int Affiche(void);
		
		//setteur
		int setLogin(const char *tmp);
		int setPassword(const char *tmp);
		
		// getteur
		const char *getLogin() const;
		const char *getPassword() const;
		
		//operateurs
		Secretaire &operator=(const Secretaire &tmp);
		friend ostream &operator<<(ostream &s, const Secretaire &j);
		friend istream &operator>>(istream &s, Secretaire &j);
		
};

#endif
