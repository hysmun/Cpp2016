#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>

#include "Personne.h"
#include "Joueur.h"
#include "Secretaire.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 4 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test de la classe Personne" << endl;
  cout << " 2. Test de la classe Joueur (Personne --> Membre --> Joueur)" << endl;
  cout << " 3. Test de la classe Secretaire (Personne --> Membre --> Secretaire)" << endl;
  cout << " 4. Heritage et virtualite : Test de la methode virtuelle Affiche()" << endl;
  cout << " 5. Test du downcasting et du dynamic-cast" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//***********************************************************************************************
// A FAIRE : la classe Personne qui possede
//           - un nom (char*) et un prenom (char*)
//           - les constructeurs habituels et destructeurs
//           - les getXXX() et setXXX() correspondants
//           - une methode Affiche()
//           - les operateurs << >> et =
//***********************************************************************************************
//*** Tests de la classe Personne ***************************************************************
//***********************************************************************************************
void Essai1()
{
  cout << "----- 1.1 Test des constructeurs de Personne -----------------------------------" << endl;
  Personne p1, p2("Wagner","Jean-Marc"), p3(p2);
  cout << "--> Voici p1 (defaut) : "; p1.Affiche();
  cout << "--> Voici p2 (initialisation) : "; p2.Affiche();
  cout << "--> Voici p3 (copie de p2) : "; p3.Affiche();
  cout << endl;
 
  cout << "----- 1.2 Test des getXXX() et setXXX() de Personne --------------------------" << endl;
  p1.setNom("Mercenier");
  p1.setPrenom("Denys");
  cout << "--> Voici p1 : "; p1.Affiche();
  cout << "Nom : " << p1.getNom() << endl;
  cout << "Prenom : " << p1.getPrenom() << endl;
  cout << endl;

  cout << "----- 1.3 Test des operateurs <<, >> et = de Personne ------------------------" << endl;
  cout << "Encodez une personne :" << endl;
  Personne p;
  {
	cout << "1";
    Personne p2;
    cout << "2";
    cin >> p2;
    cout << "3";
    p = p2;
    cout << "4";
  }
  cout << "Voici la personne encodee : " << p << endl;
  cout << endl;
}

//***********************************************************************************************
// A FAIRE D'ABORD: la classe ABSTRAITE Membre qui
//                      - herite de Personne
//                      - possede en plus un numero de club (int)
//                      - possede la methode VIRTUELLE PURE Affiche()
//
// A MODIFIER ENSUITE: la classe Joueur qui
//                      - herite a present de la classe Membre
//                      - surcharge la methode Affiche() afin d'afficher tous les details
//                        du joueur
//                      - possede toutes les caracteristiques et surcharges definies precedemment  
//***********************************************************************************************
//*** Tests de la classe Joueur *****************************************************************
//***********************************************************************************************
void Essai2()
{
  cout << "(2.1) ***** Test du constructeur par defaut de Joueur *****" << endl;
  { 
    Joueur j;
    cout << j << endl; // Pour rappel, n'affiche que le nom, prenom, numero de club, classement et points (sur une seule ligne)
  }

  cout << endl << "(2.2) ***** Test du constructeur d'initialisation de Joueur *****" << endl;
  { 
    Joueur j("Mercenier","Denys",112,Matricule("01/09/2015",28000));
    cout << j << endl;
  }

  cout << endl << "(2.3) **** Test des setters/getters *****" << endl;
  {
    Joueur j("Wagner","Jean-Marc",112);
    j.setMatricule(Matricule("01/09/2014",14817));
    j.setClassement(&Classement::F1);
    j.setPoints(10);
    cout << j << endl;

    cout << "Matricule : " << endl;
    j.getMatricule().Affiche();
    cout << "Classement : " << *(j.getClassement()) << endl;
  }

  cout << endl << "(2.4) ***** Test du constructeur de copie de Joueur *****" << endl;
  {
    Joueur *pJ = new Joueur("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
    pJ->setClassement(&Classement::A1);
    cout << "--- Objet de base ---" << endl;
    cout << *pJ << endl;

    Joueur j(*pJ);
    cout << "--- Destruction objet de base ---" << endl;
    delete pJ;
    cout << "--- Copie ---" << endl;
    cout << j << endl; 
  }
}

//***********************************************************************************************
// A FAIRE : la classe Secretaire qui
//                      - herite a present de la classe Membre
//                      - possede en plus un login (char[9]) et un password (char[9])
//                      - surcharge la methode Affiche() afin d'afficher tous les details
//                        d'un secretaire de club ou de la federation  
//***********************************************************************************************
//*** Tests de la classe Secretaire *************************************************************
//***********************************************************************************************
void Essai3()
{
  cout << "(3.1) ***** Test du constructeur par defaut de Secretaire *****" << endl;
  { 
    Secretaire s;
    cout << s << endl; // Par defaut, un secretaire a un numero de club egal à 0 --> secretaire federal et non de club
  }

  cout << endl << "(3.2) ***** Test du constructeur d'initialisation de Secretaire *****" << endl;
  { 
    Secretaire s("Deresteau","Olivier",0,"dereoliv","aaaa1111");
    cout << s << endl;
  }

  cout << endl << "(3.3) **** Test des setters/getters *****" << endl;
  {
    Secretaire s;
    s.setNom("Coptere");
    s.setPrenom("Eli");
    s.setNumClub(112);
    s.setLogin("copteli");
    s.setPassword("bbbb2222");
    cout << s << endl;
    cout << "Login : " << s.getLogin() << endl;
    cout << "Password : " << s.getPassword() << endl;
  }

  cout << endl << "(3.4) ***** Test du constructeur de copie, << et >> de Secretaire *****" << endl;
  {
    Secretaire s1;
    {
      cin >> s1;
      cout << endl << "Secretaire encode : " << s1 << endl;
      Secretaire s2(s1);
      cout << "Copie : " << s2 << endl;
      cout << "--- Destruction de la copie ---" << endl;
    }
    cout << "Secretaire encode : " << s1 << endl;
  }
}

//***********************************************************************************************
// A FAIRE : normalement rien...
//           juste comprendre et tester le code ci-dessous
//***********************************************************************************************
//*** Tests de la virtualite ********************************************************************
//***********************************************************************************************
void Essai4()
{
  srand((unsigned)time(NULL));

  cout << "----- 4.1 Allocation dynamique de Membres --------------------------------" << endl;
  Membre* membre[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "membre[" << i << "] : ";
    int n = rand()%2;
    switch(n)
    {
      case 0 : membre[i] = new Joueur("Wagner","Jean-Marc",112);
               cout << "Joueur" << endl;
               break;

      case 1 : membre[i] = new Secretaire("Mercenier","Denys",100,"MerceD","xxxx1111");
               cout << "Secretaire" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 4.2 Test de la methode VIRTUELLE Affiche() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "membre[" << i << "] : ";
    membre[i]->Affiche();
    cout << endl;
  }
  cout << endl;

  
  cout << "----- 4.4 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete membre[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

//***********************************************************************************************
// A FAIRE : normalement rien dans vos classes...
//           juste comprendre et tester le code ci-dessous
//***********************************************************************************************
//*** Tests du downcasting et dynamic-cast ******************************************************
//***********************************************************************************************
void Essai5()
{
  srand((unsigned)time(NULL));

  cout << "----- 5.1 Allocation dynamique de Membres --------------------------------" << endl;
  Membre* membre[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "membre[" << i << "] : ";
    int n = rand()%2;
    switch(n)
    {
      case 0 : membre[i] = new Joueur("Wagner","Jean-Marc",112);
               cout << "Joueur" << endl;
               break;

      case 1 : membre[i] = new Secretaire("Mercenier","Denys",100,"MerceD","xxxx1111");
               cout << "Secretaire" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 5.2 Test du downcasting et dynamic-cast ------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "membre[" << i << "] ";
    Joueur* pj = dynamic_cast<Joueur*>(membre[i]);
    if (pj != NULL) cout << pj->getNom() << " " << pj->getPrenom() << " est un Joueur" << endl;
    Secretaire* ps = dynamic_cast<Secretaire*>(membre[i]);
    if (ps != NULL) cout << ps->getNom() << " " << ps->getPrenom() << " est un Secretaire" << endl;
  }
  cout << endl;

  cout << "----- 5.3 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete membre[i];
}

