#ifndef H_ITERATEUR
#define H_ITERATEUR

#include "ListeBase.h"

template<class T>
class listeBase;

template<class T>
struct Cellule;

template<class T>
class Iterateur {
	private:
		listeBase<T> &liste;
		Cellule<T> *currentPos;
		
	public:
		Iterateur(listeBase<T> &l) : liste(l), currentPos(l.pTete) {};
		void reset();
		bool end();
		void operator++(int);
		operator T() const;
		T* operator& (void);
		T remove();
};

#endif /* H_ITERATEUR */
