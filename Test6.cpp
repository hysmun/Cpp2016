#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"

#include "Classement.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Liste avec des entiers" << endl;
  cout << " 2. Test du template Liste avec des objets de la classe Classement" << endl;
  cout << " 3. Test du template ListeTriee avec des entiers" << endl;
  cout << " 4. Test du template ListeTriee avec des objets de la classe Classement" << endl;
  cout << " 5. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une Liste de Classements" << endl;
  cout << " 7. Test de l'iterateur avec une Liste triee d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec une Liste triee de Classements" << endl;
  cout << " 9. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
void Essai1()
{
  cout << "----- 1. Test du template Liste avec des entiers ------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'une Liste -------------------------------" << endl;
  Liste<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  int *pI = liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (3 -2 5 -1 0)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << "On modifie le 3eme element :" << endl;
  *pI = 100;
  liste.Affiche();

  cout << "----- 1.2 Test du constructeur de copie ----------------------------------" << endl;
  {
    Liste<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    liste2.insere(50);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------" << endl;
  {
    Liste<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 50 dans la nouvelle liste :" << endl; 
    liste3.insere(50);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

//*********************************************************************************************
void Essai2()
{
  cout << "----- 2. Test du template Liste avec des objets de la classe Classement --------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Classement> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere D2..." << endl;
  liste.insere(Classement('D',2));
  liste.Affiche();

  cout << "On insere E6..." << endl;
  Classement c("E6");
  liste.insere(c);
  liste.Affiche();

  cout << "On insere A10..." << endl;
  Classement *ptr = new Classement('A',10);
  Classement *pC = liste.insere(*ptr);
  delete ptr;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << "On modifie le dernier element de la liste :" << endl;
  pC->setNombre(5);
  liste.Affiche();

  cout << endl;
}

//*******************************************************************************************************
void Essai3()
{
  cout << "----- 3. Test du template ListeTriee avec des entiers ------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Liste triee ------------------------------" << endl;
  ListeTriee<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et -8..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(-8);
  liste.Affiche();                                       // --> (-8 -2 -1 0 3 5)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;

  cout << "----- 1.2 Test du constructeur de copie ----------------------------------" << endl;
  {
    ListeTriee<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 4 dans la copie :" << endl; 
    liste2.insere(4);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------" << endl;
  {
    ListeTriee<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 6 dans la nouvelle liste :" << endl; 
    liste3.insere(6);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai4()
{
  cout << "----- 4. Test du template ListeTriee avec des objets de la classe Classement -----------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<Classement> liste;
  liste.Affiche();                                       
  cout << endl;

  cout << "On insere quelques classements..." << endl;
  liste.insere(Classement("D1"));
  liste.insere(Classement::F1);
  liste.insere(Classement('B',3));
  liste.insere(Classement("E2"));
  liste.insere(Classement::A1);
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai5()
{
  cout << "----- 5. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (5 --> 20)..." << endl;
  it.reset();  // on est sur 3
  it++;        // on est sur -2
  it++;        // on est sur 5;
  *(&it) = 20;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 4eme element de la liste (-1)..." << endl;
  it++;        // on est sur -1
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai6()
{
  cout << "----- 6. Test de l'iterateur avec une Liste de Classement ---------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Classement> liste;
  Iterateur<Classement> it(liste);

  cout << "On insere quelques classements..." << endl;
  liste.insere(Classement("C2"));
  liste.insere(Classement('B',5));
  liste.insere(Classement("E3"));

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Classement)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (E3 --> F1)..." << endl;
  it.reset();  // on est sur C2
  it++;        // on est sur B5
  it++;        // on est sur E3
  *(&it) = Classement::F1;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 1er element de la liste (C2)..." << endl;
  it.reset();        // on est sur C2
  Classement valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai7()
{
  cout << "----- 7. Test de l'iterateur avec une Liste triee d'entiers ------------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl; // --> (-2 -1 0 3 5)
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime le 2eme element de la liste (-1)..." << endl;
  it.reset();  // on est sur -2
  it++;        // on est sur -1
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai8()
{
  cout << "----- 8. Test de l'iterateur avec une Liste triee de Classements --------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<Classement> liste;
  Iterateur<Classement> it(liste);

  cout << "On insere quelques classements..." << endl;
  liste.insere(Classement("C5"));
  liste.insere(Classement::A1);
  liste.insere(Classement('B',2));
  liste.insere(Classement("E4"));
  liste.insere(Classement('E',1));

  cout << "On affiche grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Classement)it << endl;
  cout << endl;

  cout << "On supprime le 2eme element de la liste..." << endl;
  it.reset();  
  it++;        
  Classement valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}


