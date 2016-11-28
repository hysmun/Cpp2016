#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "Joueur.h"

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cxx contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 

int main()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *****" << endl;
  {
    Joueur joueur;
    joueur.Affiche();
  }  //La presence des accolades assure que le destructeur de Joueur sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters *****" << endl;
  {
    Joueur joueur;
    joueur.setNom("Wagner");
    joueur.setPrenom("Jean-Marc");
    joueur.setNumClub(112);
    joueur.Affiche();
    cout << "Nom = " << joueur.getNom() << endl;
    cout << "Prenom = " << joueur.getPrenom() << endl;
    cout << "Numero club = " << joueur.getNumClub() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation *****" << endl;
  {
    Joueur joueur("Thiernesse","Cedric",56);
    joueur.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie *****" << endl;
  {
    Joueur joueur1("Wagner","Jean-Marc",112);
    cout << "joueur1 (AVANT) :" << endl;
    joueur1.Affiche();
    {   
      Joueur joueur2(joueur1);
      cout << "joueur2 :" << endl;
      joueur2.Affiche();
      joueur2.setPrenom("Pierre");
      joueur2.Affiche();
    } // de nouveau, les {} assurent que joueur2 sera detruit avant la suite
    cout << "joueur1 (APRES) :" << endl;
    joueur1.Affiche();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique (constructeur par defaut) *****" << endl;
  {
    Joueur *p = new Joueur();
    p->setNumClub(112);
    p->setNom("Vanlimbergen");
    p->setPrenom("David");
    p->Affiche();
    delete p;
  }

  cout << endl << "(6) ***** Test d'allocation dynamique (constructeur de copie) *****" << endl;
  {
    Joueur joueur1("Brose","Christophe",112);
    cout << "joueur1 (AVANT) :" << endl;
    joueur1.Affiche();
    Joueur* p = new Joueur(joueur1);
    cout << "La copie :" << endl;
    p->Affiche();
    cout << "Destruction de la copie..." << endl; 
    delete p;
    cout << "joueur1 (APRES) :" << endl;
    joueur1.Affiche();
  }

  return 0;
}


