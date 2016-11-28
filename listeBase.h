#ifndef H_LISTEBASE
#define H_LISTEBASE

#include "Iterateur.h"

template<class T>
class Iterateur;

template<class T>
struct Cellule {
	T valeur ;
	Cellule<T> *suivant ;
};

template<class T>
class listeBase {
	protected:
		Cellule<T> *pTete;
	
	public:
		listeBase();
		listeBase(const listeBase&);
		virtual ~listeBase() = 0;
		bool estVide() const;
		int getNombreElements() const;
		void Affiche() const;
		virtual T* insere(const T&) = 0;
		void operator=(const listeBase&);
		friend class Iterateur<T>;
};

#endif /* H_LISTEBASE */
