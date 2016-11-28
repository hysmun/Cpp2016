#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
#include "Classement.h"
#include "Secretaire.h"
#include "InvalidClassementException.h"
#include "InvalidPasswordException.h"

using namespace std;

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
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des setXXX() de la classe Classement" << endl;
  cout << " 2. Test des constructeurs de la classe Classement" << endl;
  cout << " 3. Test des operateurs >> ++ et -- de la classe Classement" << endl;
  cout << " 4. Test du mot de passe de la classe Secretaire" << endl;
  cout << " 5. Gestion de plusieurs exceptions simultanement" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//**********************************************************************************************
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch 
//**********************************************************************************************
void Essai1()
{
  cout << "----- 1. Test des setXXX() de la classe Classement --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ...
	 try
  {
    char lettre;
    short nombre;
    Classement cl;
    cout << "Encodez un classement :" << endl;
    cout << "Lettre : "; cin >> lettre; cin.ignore();
    cl.setLettre(lettre);
    cout << "Nombre : "; cin >> nombre; cin.ignore();
    cl.setNombre(nombre);
    cout << "Classement encode = " << cl << endl << endl;

    cout << "On modifie le classement encode : " << endl;
    cout << "Lettre : "; cin >> lettre; cin.ignore();
    cl.setLettre(lettre);
    cout << "Nombre : "; cin >> nombre; cin.ignore();
    cl.setNombre(nombre);
    cout << "Classement modifie = " << cl << endl << endl;
  }
  // ...
  catch	(InvalidClassementException tmp)
  {
 	 cout << "erreur" << tmp.getMsg() << endl;
  }
  
  cout << endl;
}

//**********************************************************************************************
void Essai2()
{
  cout << "----- 2. Test des constructeurs de la classe Classement --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ...
  try
  {
    char lettre;
    short nombre;
    cout << "Encodez un classement :" << endl;
    cout << "Lettre : "; cin >> lettre; cin.ignore();
    cout << "Nombre : "; cin >> nombre; cin.ignore();
    Classement c1(lettre,nombre);
    cout << "Classement cree = " << c1 << endl << endl;

    char txt[80];
    cout << "Encodez un classement sous forme de chaine : "; cin.getline(txt,80);
    Classement c2(txt);
    cout << "Classement cree = " << c2 << endl << endl;
  }
  // ...
  catch	(InvalidClassementException tmp)
  {
 	 cout << "erreur" << tmp.getMsg() << endl;
  }
  
  cout << endl;
}

//**********************************************************************************************
void Essai3()
{
  cout << "----- 3. Test des operateurs >> ++ et -- de la classe Classement --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ...
  try
  {
    Classement c1;
    cout << "Encodez un classement : "; cin >> c1;
    cout << "Classement encode : " << c1 << endl << endl;

    cout << "Classement directement superieur (pre)  : " << ++c1 << endl; 
    --c1; 
    c1--;
    cout << "Classement directement inferieur (post) : " << c1 << endl;
    c1++;  
  }
  // ...
  catch	(InvalidClassementException tmp)
  {
 	 cout << "erreur" << tmp.getMsg() << endl;
  }
  
  cout << endl;
}

//**********************************************************************************************
void Essai4()
{
  cout << "----- 4. Test du mot du passe de la classe Secretaire --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ...
  try
  {
    char txt[80];
    cout << "--- 4.1 Test de setPassword ---" << endl;
    Secretaire s1;
    cout << "Mot de passe : "; cin.getline(txt,80);
    s1.setPassword(txt);
    cout << "Mot de passe encode : " << s1.getPassword() << endl;

    cout << endl << "--- 4.2 Test du constructeur d'initialisation ---" << endl;
    cout << "Mot de passe : "; cin.getline(txt,80);
    Secretaire s2("Issier","Pol",112,"issipol",txt);
    cout << "Secretaire cree : " << s2 << endl; 

    cout << endl << "--- 4.3 Test de l'operateur >> ---" << endl;
    Secretaire s3;
    cout << "Encodez un secretaire :" << endl;
    cin >> s3;
    cout << "Secretaire encode : " << s3 << endl; 
  }
  // ...
  catch (InvalidPasswordException tmp)
  {
		cout << " erreur passwor";
		tmp.perror("Probleme");
  }
  
  cout << endl;
}

//**********************************************************************************************
void Essai5()
{
  cout << "----- 5. Gestion de plusieurs exceptions simultanement ---" << endl;
  // A COMPLETER : Traitez TOUTES les exceptions susceptible d'etre lancee par le bloc de code suivant (try...catch)

  // ...
  try
  {
    char txt[80];
    cout << "Encodez un classement sous forme de chaine : "; cin.getline(txt,80);
    Classement c(txt);
    cout << "Classement cree = " << c << endl << endl;

    Secretaire s;
    cout << "Encodez un secretaire :" << endl;
    cin >> s;
    cout << "Secretaire encode : " << s << endl; 
  }
  // ...
  catch	(InvalidClassementException tmp)
  {
 	 cout << "erreur" << tmp.getMsg() << endl;
  }
  catch (InvalidPasswordException tmp)
  {
		cout << "erreur password "; 
		tmp.perror("Probleme");
  }
  
}


