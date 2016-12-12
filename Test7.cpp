#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#include "Classement.h"
#include "Matricule.h"
#include "Joueur.h"
#include "InvalidClassementException.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
	try
	{
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
	}
	catch (InvalidClassementException)
	{
		cout << "ERREUR classement !"<< endl;
	}
	catch (...)
	{
		cout << "erreur autre" << endl;
	}
	
	
  return 0;
}

int Menu()
{
	
		cout << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "--- JEU DE TEST 7 ---------------------------------------------------------" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << " 1. Test des methodes Save et Load de la classe Classement" << endl;
		cout << " 2. Test des mathodes Save et Load de la classe Matricule" << endl;
		cout << " 3. Test des methodes Save et Load de la classe Joueur" << endl;
		cout << " 4. Test des operateurs << et >> de la classe Classement" << endl;
		cout << " 5. Quitter" << endl << endl;

		int ch;
		cout << "  Choix : ";
		cin >> ch; // Faites pas le biess !
		cin.ignore();
		return ch;
	
	
	return ch;
}

//*********************************************************************************************
void Essai1()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 1. Test des methodes Save et Load de la classe Classement ------" << endl;
  
  Classement c1('E',2);
  c1.Affiche();
  cout << endl;

  cout << "----- Sauvegarde du classement dans le fichier C.dat -----" << endl;
  ofstream fichier1("C.dat",ios::out);
  c1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement du classement situe dans le fichier C.dat -----" << endl;
  ifstream fichier2("C.dat",ios::in);
  Classement c2;
  c2.Load(fichier2);
  fichier2.close();
  c2.Affiche();
  cout << endl;
}

//*********************************************************************************************
void Essai2()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 2. Test des methodes Save et Load de la classe Matricule ------" << endl;
  
  Matricule m1("01/09/2016",26000);
  m1.Affiche();
  cout << endl;

  cout << "----- Sauvegarde du matricule dans le fichier M.dat -----" << endl;
  ofstream fichier1("M.dat",ios::out);
  m1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement du matricule situe dans le fichier M.dat -----" << endl;
  ifstream fichier2("M.dat",ios::in);
  Matricule m2;
  m2.Load(fichier2);
  fichier2.close();
  m2.Affiche();
  cout << endl;
}

//*********************************************************************************************
void Essai3()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 3. Test des methodes Save et Load de la classe Joueur ------" << endl;

  Joueur j("Wagner","Jean-Marc",112,Matricule("01/09/2014",14817));
  Classement c("D2");
  j.setClassement(&c);
  j.setPoints(13);
  j.Affiche();

  cout << "----- Sauvegarde du joueur dans le fichier J.dat -----" << endl;
  ofstream fichier1("J.dat",ios::out);
  j.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement du joueur situe dans le fichier J.dat -----" << endl;
  ifstream fichier2("J.dat",ios::in);
  Joueur j2;
  j2.Load(fichier2);
  fichier2.close();
  j2.Affiche();
  cout << endl;
}

//*********************************************************************************************
void Essai4()
{
  cout << "----- 4. Test des operateurs << et >> de la classe Classement ------" << endl;

  Classement c1("D2"),c2,c3('E',1),c4(Classement::A1);

  cout << "----- Ecriture dans le fichier texte classements.txt -----" << endl;
  ofstream fichier1("classements.txt",ios::out);
  fichier1 << c1 << endl;
  fichier1 << c2 << endl;
  fichier1 << c3 << endl;
  fichier1 << c4 << endl;
  fichier1.close();

  cout << "----- Lecture dans le fichier texte classements.txt -----" << endl;
  ifstream fichier2("classements.txt",ios::in);
  Classement c;
  for (int i=0 ; i<4 ; i++)
  {
    fichier2 >> c;
    cout << c << endl;
  }
  fichier2.close();
  cout << endl;
}

