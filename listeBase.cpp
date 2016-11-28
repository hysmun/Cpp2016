#include <iostream>
#include "listeBase.h"

template<class T>
listeBase<T>::listeBase() {
	pTete = 0;
}

template<class T>
listeBase<T>::listeBase(const listeBase &l) {
	if (l.estVide())
		return;
		
	Cellule<T> *pParc = l.pTete;
	
	pTete = new Cellule<T>;
	pTete->valeur = pParc->valeur;
	pTete->suivant = 0;
	
	pParc = pParc->suivant;
	Cellule<T> *pPrec = pTete;
	
	while (pParc != 0) {
		Cellule<T> *pTr = new Cellule<T>;
		pTr->valeur = pParc->valeur;
		pTr->suivant = 0;
		
		pPrec->suivant = pTr;
		pPrec= pTr;		
		pParc = pParc->suivant;
	}
}

template<class T>
listeBase<T>::~listeBase() {
	Cellule<T> *pTmp = pTete;
	while (pTmp != 0) {
		Cellule<T> *pToDelete = pTmp;
		pTmp = pTmp->suivant;
		delete pToDelete;
	}
}

template<class T>
bool listeBase<T>::estVide() const {
	return pTete == 0 ? true : false;
}

template<class T>
int listeBase<T>::getNombreElements() const {
	int nbr = 0;
	Cellule<T> *pTmp = pTete;
	
	while (pTmp != 0) {
		nbr++;
		pTmp = pTmp->suivant;
	}
	
	return nbr;
}

template<class T>
void listeBase<T>::Affiche() const {
	Cellule<T> *pTmp = pTete;
	
	while (pTmp != 0) {
		std::cout << pTmp->valeur << std::endl;
		pTmp = pTmp->suivant;
	}
}

template<class T>
void listeBase<T>::operator=(const listeBase& source) {
	if (estVide())
		pTete = new Cellule<T>;
	else {
		//vider la liste
		Cellule<T> *pTmp = pTete;
	
		while (pTmp != 0) {
			std::cout << pTmp->valeur << std::endl;
			pTmp = pTmp->suivant;
		}
	}
	
	//la recreer par copie de la source
	Cellule<T> *pParc = source.pTete;
	
	pTete = new Cellule<T>;
	pTete->valeur = pParc->valeur;
	pTete->suivant = 0;
	
	pParc = pParc->suivant;
	Cellule<T> *pPrec = pTete;
	
	while (pParc != 0) {
		Cellule<T> *pTr = new Cellule<T>;
		pTr->valeur = pParc->valeur;
		pTr->suivant = 0;
		
		pPrec->suivant = pTr;
		pPrec= pTr;		
		pParc = pParc->suivant;
	}
}

#include "Classement.h"

template class listeBase<int>;
template class listeBase<Classement>;
