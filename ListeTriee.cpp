#include "listeBase.h"
#include "ListeTriee.h"

template<class T>
T* ListeTriee<T>::insere(const T &elm) {
	Cellule<T> *pNew = new Cellule<T>;
	pNew->valeur = elm;
	pNew->suivant = 0;
	
	Cellule<T> *pParc = this->pTete;
	Cellule<T> *pPrec = 0;
	
	if (pParc == 0) {
		this->pTete = pNew;
		return &(this->pTete->valeur);
	}
	
	while (pParc != 0 && pParc->valeur < elm) {
		pPrec = pParc;
		pParc = pParc->suivant;
	}
	
	//cas ou il va en tete de liste?
	if (pPrec == 0) {
		pNew->suivant = this->pTete;
		this->pTete = pNew;
	}
	//autre cas
	else {
		pPrec->suivant = pNew;
		pNew->suivant = pParc;
	}
	
	return &(pNew->valeur);
}

#include "Classement.h"

template class ListeTriee<int>;
template class ListeTriee<Classement>;
