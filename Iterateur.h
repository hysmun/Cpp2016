#ifndef H_ITERATEUR
#define H_ITERATEUR

#include "ListeBase.h"

template<class T>
class ListeBase;

template<class T>
struct Cellule;

template<class T>
class Iterateur 
{
	private:
		ListeBase<T> &liste;
		Cellule<T> *currentPos;
		
	public:
		Iterateur(ListeBase<T> &l) : liste(l), currentPos(l.pTete) {};
		//Iterateur(ListeBase<T> &l) {liste = &l; currentPos = l.pTete;};
		void reset();
		bool end();
		void operator++(int);
		operator T() const;
		T* operator& (void);
		T remove();
};

#endif /* H_ITERATEUR */
