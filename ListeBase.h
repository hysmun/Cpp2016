#ifndef H_LISTEBASE
#define H_LISTEBASE

#include "Iterateur.h"

template<class T>
class Iterateur;

template<class T>
struct Cellule 
{
	T valeur ;
	Cellule<T> *suivant ;
};

template<class T>
class ListeBase 
{
	protected:
		Cellule<T> *pTete;
	
	public:
		ListeBase();
		ListeBase(const ListeBase&);
		virtual ~ListeBase() = 0;
		bool estVide() const;
		int getNombreElements() const;
		void Affiche() const;
		virtual T* insere(const T&) = 0;
		void operator=(const ListeBase&);
		friend class Iterateur<T>;
};

#endif /* H_LISTEBASE */
