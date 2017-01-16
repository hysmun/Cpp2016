#ifndef __CLUB_H__
#define __CLUB_H__

using namespace std;

class Club
{
	friend ostream& operator<<(ostream& o, const Club& c);					//Surcharge l'opérateur d'insertion afin d'afficher les détails d'un club
	friend istream& operator>>(istream& i, Club& c);							//Surcharge l'opérateur d'extraction afin de pouvoir encoder tous les détails d'un club
	private:
		char* nom;
		int numClub;
		char* adresse;
	public:
		Club();																				//Constructeur par défaut
		Club(char*,int,char*);															//Constructeur d'initialisation
		Club(const Club& c);																//Constructeur de copie
		~Club();																				//Destructeur
		void setNom(const char*);														//Permet d'accéder a la variable membre privée "nom"
		void setNumClub(int);															//Permet d'accéder a la variable membre privée "numClub"
		void setAdresse(const char*);													//Permet d'accéder a la variable membre privée "adresse"
		char* getNom()const;																//Permet de récupérer la valeur de nom
		int getNumClub()const;															//Permet de récupérer la valeur de numClub
		char* getAdresse()const;														//Permet de récupérer la valeur d'adresse
		Club& operator=(const Club& c);												//Surcharge de l'opérateur d'affectation afin de pouvoir utiliser pour copier un objet
		bool operator<(const Club& c)const;											//Surcharge de l'opérateur inférieur afin de pouvoir comparer deux clubs, renvoi true ou false
		bool operator>(const Club& c)const;											//Surcharge de l'opérateur supérieur afin de pouvoir comparer deux clubs, renvoi true ou false
		bool operator==(const Club& c)const;										//Surcharge de l'opérateur de comparaison d'égalité afin de pouvoir comparer deux clubs, renvoi true ou false
		
		void Save(ofstream &fichier) const;											//Permet de sauvegarder les clubs dans un fichier
		void Load(ifstream &fichier);													//Permet de charger les clubs dans un fichier
};


#endif
