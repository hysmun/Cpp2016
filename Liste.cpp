#include "ListeBase.h"
#include "Liste.h"

template<class T> T* Liste<T>::insere(const T &elm) 
{
	if (this->estVide()) 
	{
		this->pTete = new Cellule<T>;
		this->pTete->valeur = elm;
		this->pTete->suivant = 0;
		return &(this->pTete->valeur);
	}
	else 
	{
		Cellule<T> *pParc = this->pTete;
	
		while (pParc->suivant != 0) 
		{
			pParc = pParc->suivant;
		}
		
		Cellule<T> *pNew = new Cellule<T>;
		pNew->valeur = elm;
		pNew->suivant = 0;
		pParc->suivant = pNew;
		return &(pNew->valeur);
	}
}

#include "Classement.h"
#include "Joueur.h"
#include "Club.h"
#include "Equipe.h"
#include "Secretaire.h"

template class Liste<int>;
template class Liste<Classement>;
template class Liste<Secretaire>;
template class Liste<Equipe>;










