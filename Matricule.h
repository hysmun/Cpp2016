#ifndef	__MATRICULE_H__
#define	__MATRICULE_H__

class Matricule
{
	private:
		int numero;
		char dateInscription[11];
	public:
	//initialisateur
	Matricule();
	Matricule(const char *sd, const int n);
	Matricule(const Matricule &m);
	~Matricule();
	
	//getteur
	int getNumero() const;
	const char *getDateInscription() const;
	
	//setteur
	void setNumero(int n);
	void setDateInscription(const char *sd);
	
	//affiche
	void Affiche()const;
	
	//operateur
	friend ostream &operator<<(ostream &s, const Matricule &j);

	friend istream &operator>>(istream &s, Matricule &j);
	
};

#endif
