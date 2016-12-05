#ifndef	__PERSONNE_H__
#define	__PERSONNE_H__

class Personne
{
	protected:
		char	*Nom;
		char	*Prenom;

	public:
		//initialisateur
		Personne();
		Personne(const char *name, const char *sdname);
		Personne(const Personne &tmp);
		virtual  ~Personne();
		
		//affiche
		virtual int Affiche(void) const;
		
		//setteur
		int setNom(const char *tmp);
		int setPrenom(const char *tmp);
		
		// getteur
		const char *getNom() const;
		const char *getPrenom() const;
		
		//operateurs
		Personne &operator=(const Personne &tmp);
		friend ostream &operator<<(ostream &s, const Personne &j);
		friend istream &operator>>(istream &s, Personne &j);
		
		//autre
		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);	
			
};

#endif
