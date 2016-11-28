#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Joueur.h"
#include "Matricule.h"
#include "Classement.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

//*******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 2 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Matricule" << endl;
  cout << " 2. Tests de la classe Classement" << endl;
  cout << " 3. Tests de la classe Joueur (avec agregations par valeur et par reference)" << endl;
  cout << " 4. Tests des variables statiques utiles" << endl;
  cout << " 5. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

//*******************************************************************************************************
//*** Tests de la classe Matricule **********************************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << "(1) ***** Test des constructeurs de Matricule *****" << endl;
  {
    Matricule m1, m2("01/09/2016",25369), m3(m2);
    cout << "Defaut : "; m1.Affiche();
    cout << "Initialisation : "; m2.Affiche();
    cout << "Copie : "; m3.Affiche();
    cout << endl;
  }

  cout << endl << "(2) **** Test des setters/getters *****" << endl;
  {
    Matricule m;
    cout << "Defaut : "; m.Affiche();
    m.setDateInscription("15/10/2012");
    m.setNumero(14817);
    cout << "Apres setters : "; m.Affiche();
    cout << endl << "Date inscription : " << m.getDateInscription() << endl;
    cout << "Numero : " << m.getNumero() << endl;
  }
}

//*******************************************************************************************************
//*** Tests de la classe Classement *********************************************************************
//*******************************************************************************************************
void Essai2()
{
  cout << "(1) ***** Test des constructeurs de Classement *****" << endl;
  {
    Classement c1, c2('D',2), c3(c2), c4("E1");
    cout << "Defaut : "; c1.Affiche();
    cout << "Initialisation Version 1 : "; c2.Affiche();
    cout << "Copie : "; c3.Affiche();
    cout << "Initialisation Version 2 : "; c4.Affiche();
    cout << endl;
  }

  cout << endl << "(2) **** Test des setters/getters *****" << endl;
  {
    Classement c1;
    cout << "Defaut : "; c1.Affiche();
    c1.setLettre('C');
    c1.setNombre(4);
    cout << "Apres setters : "; c1.Affiche();
    cout << endl;

    Classement c2("A10");
    c2.Affiche();
    cout << "Lettre : " << c2.getLettre() << endl;
    cout << "Nombre : " << c2.getNombre() << endl;
  }
}

//*************************************************************************************************
//*** Tests de la classe Joueur (Agregation)                                                    *** 
//***               - par valeur avec Matricule                                                 ***
//***               - par reference avec Classement                                             ***
//*************************************************************************************************
void Essai3()
{
  cout << "(1) ***** Test du constructeur par defaut de Joueur *****" << endl;
  { // Par defaut, un joueur ne possede pas de classement (NULL)
    // Par defaut, un joueur possede un matricule construit par defaut
    Joueur j;
    j.Affiche();
    cout << endl;
  }

  cout << endl << "(2) ***** Test du constructeur d'initialisation de Joueur *****" << endl;
  { // Un nouveau joueur ne possede pas de classement (NULL)
    Matricule m("01/09/2015",28000);
    Joueur j("Mercenier","Denys",112,m);
    j.Affiche();
    cout << endl;
  }

  cout << endl << "(3) **** Test des setters/getters *****" << endl;
  {
    Joueur j("Wagner","Jean-Marc",112);
    j.setMatricule(Matricule("01/09/2014",14817));
    Classement *pC = new Classement("D2");
    j.setClassement(pC);
    delete pC;
    j.Affiche();

    cout << endl << "Matricule : " << endl;
    j.getMatricule().Affiche();
    cout << "Classement : ";
    j.getClassement()->Affiche();
    cout << endl;
  }

  cout << endl << "(4) ***** Test du constructeur de copie de Joueur *****" << endl;
  {
    Joueur *pJ = new Joueur("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
    Classement *pC = new Classement("D2");
    pJ->setClassement(pC);
    delete pC;
    cout << "--- Objet de base ---" << endl;
    pJ->Affiche();

    Joueur j(*pJ);
    cout << "--- Destruction objet de base ---" << endl;
    delete pJ;
    cout << "--- Copie ---" << endl;
    j.Affiche(); 
  }
}

//*******************************************************************************************************
//*** Tests des variables statiques utiles **************************************************************
//*******************************************************************************************************
void Essai4()
{
  cout << "(1) ***** Tests de base *****" << endl;
  Classement::F1.Affiche(); // F1 est un objet de la classe Classement, il possede donc la methode Affiche()
  Classement::A1.Affiche();

  // Classement::F1.setLettre('E'); // --> ne compile pas car l'objet F1 est un objet constant (voir enonce) !!!

  cout << endl << "(2) ***** Copie des objets statiques *****" << endl;
  Classement c(Classement::F1);
  c.Affiche();
  c.setLettre('E');   // compile car c n'est pas un objet constant
  c.Affiche();

  cout << endl << "(3) ***** Creation de joueur avec classement *****" << endl;
  Joueur j("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
  j.setClassement(&Classement::A1);  // Dommage...
  j.Affiche();
}

