#ifndef __CLUB_H__
#define __CLUB_H__

using namespace std;

class Club
{
	friend ostream& operator<<(ostream& o, const Club& c);
	friend istream& operator>>(istream& i, Club& c);
	private:
		char* nom;
		int numClub;
		char* adresse;
	public:
		Club();
		Club(char*,int,char*);
		Club(const Club& c);
		~Club();
		void setNom(const char*);
		void setNumClub(int);
		void setAdresse(const char*);
		char* getNom()const;
		int getNumClub()const;
		char* getAdresse()const;
		Club& operator=(const Club& c);
		bool operator<(const Club& c)const;
		bool operator>(const Club& c)const;
		bool operator==(const Club& c)const;
		
		void Save(ofstream &fichier) const;
		void Load(ofstream &fichier);
};


#endif
