#ifndef	__CLASSEMENT_H__
#define	__CLASSEMENT_H__

class Classement
{
	friend ostream &operator<<(ostream &s, const Classement &c);
	friend istream &operator>>(istream &s, Classement &c);
	
	
	private:
		char lettre;
		short nombre;
		
	public:
	static Classement A1, F2, F1;
	//initialisateur
	Classement();
	Classement(char sd, short n);
	Classement(const Classement &c);
	Classement(const char *sd);
	~Classement();
	
	//getteur
	char getLettre() const;
	short getNombre() const;
	
	//setteur
	void setLettre(char n);
	void setNombre(short n);
	void setValeur(int x);
	
	//affiche
	void Affiche()const;
	
	//operateur
	int operator-(Classement c);
	int operator==(Classement c);
	int operator<(Classement c);
	int operator>(Classement c);
	
	Classement &operator++();
	Classement operator++(int x);
	Classement &operator--();
	Classement operator--(int x);
	
	//autre
	int getValeur() const;
	void setCl(char n , int x);
};

#endif
