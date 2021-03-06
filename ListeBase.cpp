#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "ListeBase.h"
#include "ExceptionMessage.h"
using namespace std;

template<class T> ListeBase<T>::ListeBase() 
{
	pTete = NULL;
}

template<class T> ListeBase<T>::ListeBase(const ListeBase &l) 
{
	if (l.estVide())
	{
		pTete =NULL;
		return;
	}
		
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
	return pTete == NULL ? true : false;
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
	Cellule<T> *tmp = new Cellule<T>;
	int i;
	char c;

	//cout << "load liste "<< endl;

	if(!fichier)
	{
		//cout << "Erreur fichier dans listeBase.Load" << endl;
		throw ExceptionMessage("Erreur fichier  dans le load ListeBase");
	}
	fichier.get(c);
	for(i=0; !fichier.eof();i++)
	{
		fichier.seekg(-1, ios::cur);
		tmp->valeur.Load(fichier);
		//cout << (tmp->valeur)<< endl;
		insere((tmp->valeur));
		fichier.get(c);
	}
	//cout << " fin load liste : " << i << endl;
	return 1;
}

template<class T> 
int ListeBase<T>::Save(ofstream &fichier)
{
	int i;
	Cellule<T> *pParc = this->pTete;
	//cout <<"begin"<<endl;
	for(i=0; pParc != NULL;i++)
	{
		//cout <<i<<" "<<endl;
		pParc->valeur.Save(fichier);
		pParc=pParc->suivant;
	}
	//cout <<endl;
	return 1;
}



template<class T>
int ListeBase<T>::SearchDoublet(const T &tmp)
{
	int i;
	Cellule<T> *pParc = this->pTete;
	for(i=0; pParc != NULL;i++)
	{
		if( pParc->valeur == tmp)
		{
			return 1;
		}
		pParc=pParc->suivant;
	}
	return 0;
}


template<class T>
int ListeBase<T>::DeleteElem(const T &tmp)
{
	int i;
	Cellule<T> *pParc = this->pTete;
	Cellule<T> *pPrec = NULL;
	for(i=0; pParc != NULL;i++)
	{
		if( pParc->valeur == tmp)
		{
			if(pPrec == NULL)
			{
				this->pTete = pParc->suivant;
			}
			else
			{
				pPrec->suivant = pParc->suivant;
			}
			return 1;
		}
		pPrec = pParc;
		pParc=pParc->suivant;
	}
	return 0;
}



#include "Classement.h"
#include "Joueur.h"
#include "Club.h"
#include "Equipe.h"
#include "Secretaire.h"

//template class ListeBase<int>;
template class ListeBase<Classement>;
template class ListeBase<Joueur>;
template class ListeBase<Equipe>;
template class ListeBase<Club>;
template class ListeBase<Secretaire>;




















