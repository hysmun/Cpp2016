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
void Essai5();
void Essai6();
void Essai7();
void Essai8();
void Essai9();
void Essai10();

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
      case 9 : Essai9(); break;
      case 10 : Essai10(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

//******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 3 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de l'operateur = de la classe Joueur" << endl;
  cout << " 2. Tests de l'operateur - de la classe Classement" << endl;
  cout << " 3. Tests des operateurs < > et == de la classe Classement" << endl;
  cout << " 4. Tests des operateurs < > et == de la classe Joueur" << endl;
  cout << " 5. Test des operateurs << et >> de Classement et Joueur" << endl;
  cout << " 6. Tests des operateurs ++ de la classe Classement" << endl;
  cout << " 7. Tests des operateurs -- de la classe Classement" << endl;
  cout << " 8. Tests des operateurs ++ de la classe Joueur" << endl;
  cout << " 9. Tests des operateurs -- de la classe Joueur" << endl;
  cout << "10. Tests des operateurs + et - (int) de la classe Joueur" << endl;
  cout << "11. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
//*** Tests des operateurs = de la classe Joueur ********************************************************
//*******************************************************************************************************
void Essai1()
{ // Ne pas oublier d'ajouter la variable membre points à la classe Joueur
  cout << "********************************************************************" << endl;
  cout << "(1) ***** Test de l'operateur d'affectation de Joueur **************" << endl;
  cout << "********************************************************************" << endl;
  {
    Joueur j;
    {
      Joueur j1("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
      Classement cl("D2"); 
      j1.setClassement(&cl);
      j1.setPoints(10);
      cout << "j1 : " << endl;
      j1.Affiche();
      cout << endl << ">>>>> j = j1;" << endl;
      j = j1;
      cout << ">>>>> Destruction de j1" << endl << endl;
    }
    cout << "j : " << endl;
    j.Affiche();
    cout << "Points : " << j.getPoints() << endl << endl;
  }
}

//*******************************************************************************************************
//*** Tests de l'operateur - de la classe Classement ****************************************************
//*******************************************************************************************************
void Essai2()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(2) ***** Test de l'operateur - de Classement **********************" << endl;
  cout <<         "********************************************************************" << endl;
  Classement c1('A',2), c2("A7"), c3('B',4), c4("E6");
  cout << "c1 = "; c1.Affiche();
  cout << "c2 = "; c2.Affiche();
  cout << "c3 = "; c3.Affiche();
  cout << "c4 = "; c4.Affiche();
  cout << endl;
  cout << "c1 - c2 = " << (c1-c2) << "   (--> doit donner 5)" << endl;
  cout << "c2 - c1 = " << (c2-c1) << "   (--> doit donner -5)" << endl;
  cout << "c2 - c3 = " << (c2-c3) << "   (--> doit donner 7)" << endl;
  cout << "c4 - c3 = " << (c4-c3) << "   (--> doit donner -20)" << endl;

}

//*******************************************************************************************************
//*** Tests des operateurs < > et == de la classe Classement ********************************************
//*******************************************************************************************************
void Essai3()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(3) ***** Tests des operateurs < > et == de Classement *************" << endl;
  cout <<         "********************************************************************" << endl;
  Classement c1('B',4), c2("E6");
  cout << "c1 = "; c1.Affiche();
  cout << "c2 = "; c2.Affiche();
  cout << endl;
  if (c1 < c2) cout << "c1 est plus faible que c2" << endl;
  if (c1 > c2) cout << "c1 est plus fort que c2" << endl;
  if (c1 == c2) cout << "c1 est egal a c2" << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs < > et == de la classe Joueur ************************************************
//*******************************************************************************************************
void Essai4()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(4) ***** Tests des operateurs < > et == de Joueur *****************" << endl;
  cout <<         "********************************************************************" << endl;
  Joueur j1, j2, j3; // Rappel: par defaut, un joueur est NC (classement est NULL)
  Classement c1('B',4), c2("E6");
  j1.setClassement(&c1);
  j2.setClassement(&c2);
  cout << "--- j1 ---" << endl;
  j1.Affiche();
  cout << endl;
  cout << "--- j2 ---" << endl;
  j2.Affiche();
  cout << endl;
  cout << "--- j3 ---" << endl;
  j3.Affiche();
  cout << endl;
  if (j1 < j2) cout << "j1 est plus faible que j2" << endl;
  if (j1 > j2) cout << "j1 est plus fort que j2" << endl;
  if (j1 == j2) cout << "j1 a le meme classement que j2" << endl;
  if (j3 < j2) cout << "j3 est plus faible que j2" << endl;
  if (j3 > j2) cout << "j3 est plus fort que j2" << endl;
  if (j3 == j2) cout << "j3 a le meme classement que j2" << endl;
}

//*******************************************************************************************************
//*** Test des operateurs << et >> de la classe Classement et Joueur ************************************
//*******************************************************************************************************
void Essai5()
{
  cout << "**************************************************************************" << endl;
  cout << "(5) ********* Test des operateurs << et >> de Classement et Joueur *******" << endl;
  cout << "**************************************************************************" << endl;
  Joueur j1("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817)), j2;
  cout << j1 << endl;
  Classement cl("B4");
  cout << "Classement = ";
  cin >> cl;
  cout << cl;
  j1.setClassement(&cl);
  cout << j1 << endl <<endl;
}

//*******************************************************************************************************
//*** Tests des operateurs ++ de la classe Classement ***************************************************
//*******************************************************************************************************
void Essai6()
{
  Classement cl;
  cout << "Classement = ";
  cin >> cl;
  cout << endl;
  cout << "**********************************************************************" << endl;
  cout << "(6.1) ***** Test de l'operateur de pre-incrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "cl   : " << cl << ' ' << cl.getValeur() << endl;
  cout << "++cl : " << ++cl << ' ' << cl.getValeur() << endl;  // Si tout va bien, cl est incremente avant d'etre affiche !
  cout << "cl   : " << cl << ' ' << cl.getValeur() << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(6.2) ***** Test de l'operateur de post-incrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "cl   : " << cl << endl;
  cout << "cl++ : " << cl++ << endl;  // Si tout va bien, cl est incremente apres avoir ete affiche !
  cout << "cl   : " << cl << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs -- de la classe Classement ***************************************************
//*******************************************************************************************************
void Essai7()
{
  Classement cl;
  cout << "Classement = ";
  cin >> cl;
  cout << endl;
  cout << "**********************************************************************" << endl;
  cout << "(7.1) ***** Test de l'operateur de pre-decrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "cl   : " << cl << endl;
  cout << "--cl : " << --cl << endl;  // Si tout va bien, cl est decremente avant d'etre affiche !
  cout << "cl   : " << cl << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(7.2) ***** Test de l'operateur de post-decrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "cl   : " << cl << endl;
  cout << "cl-- : " << cl-- << endl;  // Si tout va bien, cl est decremente apres avoir ete affiche !
  cout << "cl   : " << cl << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs ++ de la classe Joueur *******************************************************
//*******************************************************************************************************
void Essai8()
{
  Joueur j;
  Classement cl;
  cout << "Classement = ";
  cin >> cl;
  j.setClassement(&cl);
  j.setPoints(19);
  cout << endl;
  cout << "**********************************************************************" << endl;
  cout << "(8.1) ***** Test de l'operateur de pre-incrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "j   : " << j << endl;
  cout << "++j : " << ++j << endl;  // Si tout va bien, j est incremente avant d'etre affiche !
  cout << "j   : " << j << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(8.2) ***** Test de l'operateur de post-incrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "j   : " << j << endl;
  cout << "j++ : " << j++ << endl;  // Si tout va bien, j est incremente apres avoir ete affiche !
  cout << "j   : " << j << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs -- de la classe Joueur *******************************************************
//*******************************************************************************************************
void Essai9()
{
  Joueur j;
  Classement cl;
  cout << "Classement = ";
  cin >> cl;
  j.setClassement(&cl);
  j.setPoints(-19);
  cout << endl;
  cout << "**********************************************************************" << endl;
  cout << "(9.1) ***** Test de l'operateur de pre-decrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "j   : " << j << endl;
  cout << "--j : " << --j << endl;  // Si tout va bien, j est decremente avant d'etre affiche !
  cout << "j   : " << j << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(9.2) ***** Test de l'operateur de post-decrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "j   : " << j << endl;
  cout << "j-- : " << j-- << endl;  // Si tout va bien, j est decremente apres avoir ete affiche !
  cout << "j   : " << j << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs (+/- int) de la classe Joueur ************************************************
//*******************************************************************************************************
void Essai10()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(10.1) ***** Test de l'operateur (Joueur + int) ********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Joueur j1("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
    Classement cl("D2"); 
    j1.setClassement(&cl);
    cout << "j1 (avant) : " << j1 << endl;

    Joueur j2;
    cout << ">>>>> j2 = j1 + 45;" << endl;
    j2 = j1 + 45;
    cout << "J2 : " << j2 << endl;
    cout << ">>>>> j2 = j2 + 7;" << endl;
    j2 = j2 + 7;
    cout << "j2 : " << j2 << endl << endl;
    cout << "j1 (apres) : " << j1 << endl; // j1 ne doit pas etre modifie !!!!
  }

  cout << endl << "********************************************************************" << endl;
  cout <<         "(10.2) ***** Test de l'operateur (Joueur - int) ********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Joueur j1("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
    Classement cl("D2"); 
    j1.setClassement(&cl);
    cout << "j1 (avant) : " << j1 << endl;

    Joueur j2;
    cout << ">>>>> j2 = j1 - 45;" << endl;
    j2 = j1 - 45;
    cout << "J2 : " << j2 << endl;
    cout << ">>>>> j2 = j2 - 7;" << endl;
    j2 = j2 - 7;
    cout << "j2 : " << j2 << endl << endl;
    cout << "j1 (apres) : " << j1 << endl; // j1 ne doit pas etre modifie !!!!
  }
}

