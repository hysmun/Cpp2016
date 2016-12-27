#include "Iterateur.h"

template<class T>
bool Iterateur<T>::end() 
{
	return currentPos == 0;
}

template<class T>
void Iterateur<T>::reset() 
{
	currentPos = liste.pTete;
}

template<class T>
void Iterateur<T>::operator++(int) 
{
	if (currentPos != 0)
		currentPos = currentPos->suivant; 
}

template<class T>
Iterateur<T>::operator T() const 
{
	return currentPos->valeur;
}

template<class T>
T* Iterateur<T>::operator& (void) 
{
	return &(currentPos->valeur);
}

template<class T>
T Iterateur<T>::remove() 
{
	T tmp(currentPos->valeur);
	
	//recreer les bons branchements
	//parcourir la liste depuis le debut, comparer les adresses jusqu'a tomber sur la bonne...
	Cellule<T> *pParc = liste.pTete;
	Cellule<T> *pPrec = 0;
	
	while (pParc != 0 && pParc != currentPos) 
	{
		pPrec = pParc;
		pParc = pParc->suivant;
	}
	
	//retirer le premier element (tete)
	if(pPrec == 0)
		liste.pTete = liste.pTete->suivant;
	//autre element
	else
		pPrec->suivant = pParc->suivant;
	
	//delete de l element
	delete currentPos;
	
	return tmp;
}

#include "Classement.h"

template class Iterateur<int>;
template class Iterateur<Classement>;
