#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "ListeBase.h"
using namespace std;

template<class T> ListeBase<T>::ListeBase() 
{
	pTete = 0;
}

template<class T> ListeBase<T>::ListeBase(const ListeBase &l) 
{
	if (l.estVide())
		return;
		
	Cellule<T> *pParc = l.pTete;
	
	pTete = new Cellule<T>;
	pTete->valeur = pParc->valeur;
	pTete->suivant = 0;
	
	pParc = pParc->suivant;
	Cellule<T> *pPrec = pTete;
	
	while (pParc != 0) 
	{
		Cellule<T> *pTr = new Cellule<T>;
		pTr->valeur = pParc->valeur;
		pTr->suivant = 0;
		
		pPrec->suivant = pTr;
		pPrec= pTr;		
		pParc = pParc->suivant;
	}
}

template<class T> ListeBase<T>::~ListeBase() 
{
	Cellule<T> *pTmp = pTete;
	while (pTmp != 0) 
	{
		Cellule<T> *pToDelete = pTmp;
		pTmp = pTmp->suivant;
		delete pToDelete;
	}
}

template<class T>
bool ListeBase<T>::estVide() const 
{
	return pTete == 0 ? true : false;
}

template<class T>
int ListeBase<T>::getNombreElements() const 
{
	int nbr = 0;
	Cellule<T> *pTmp = pTete;
	
	while (pTmp != 0) 
	{
		nbr++;
		pTmp = pTmp->suivant;
	}
	
	return nbr;
}

template<class T>
void ListeBase<T>::Affiche() const 
{
	Cellule<T> *pTmp = pTete;
	
	while (pTmp != 0) 
	{
		std::cout << pTmp->valeur << std::endl;
		pTmp = pTmp->suivant;
	}
}

template<class T> void ListeBase<T>::operator=(const ListeBase& source) 
{
	if (estVide())
		pTete = new Cellule<T>;
	else {
		//vider la liste
		Cellule<T> *pTmp = pTete;
	
		while (pTmp != 0) 
		{
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
	
	while (pParc != 0) 
	{
		Cellule<T> *pTr = new Cellule<T>;
		pTr->valeur = pParc->valeur;
		pTr->suivant = 0;
		
		pPrec->suivant = pTr;
		pPrec= pTr;		
		pParc = pParc->suivant;
	}
}

template<class T> 
int ListeBase<T>::Load(ifstream &fichier)
{
	<T> tmp;
	int i;
	for(i=0; fichier.eof() == false ;i++)
	{
		tmp.Load(fichier);
		insere(tmp);
	}
	return 1;
}

template<class T> 
int ListeBase<T>::Save(ofstream &fichier)
{
	int i;
	Cellule<T> *pParc = this->pTete;
	for(i=0; pParc != 0;i++)
	{
		pParc.valeur.Save(fichier);
		pParc=pParc->suivant;
	}
	return 1;
}




#include "Classement.h"
#include "Joueur.h"
#include "Club.h"
#include "Equipe.h"
#include "Secretaire.h"

template class ListeBase<int>;
template class ListeBase<Classement>;
template class ListeBase<Joueur>;
template class ListeBase<Equipe>;
template class ListeBase<Club>;
template class ListeBase<Secretaire>;






















