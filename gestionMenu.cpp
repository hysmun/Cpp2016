#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits>
#include <fstream>
#include <termios.h>
#include <unistd.h>
using namespace std;
#include "Equipe.h"
#include "Club.h"
#include "Classement.h"
#include "Joueur.h"
#include "Membre.h"
#include "Personne.h"
#include "Secretaire.h"
#include "ListeBase.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "InvalidClassementException.h"
#include "InvalidPasswordException.h"
#include "ExceptionMessage.h"
#include "Matricule.h"
#include "Iterateur.h"
#include "utils.h"
#include "gestionMenu.h"

extern int verbose;
extern int error;

int mygetch ( void ) 
{
  int ch;
  struct termios oldt, newt;

  tcgetattr ( 0, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  newt.c_cc[VMIN] = 1;
  tcsetattr ( 0, TCSANOW, &newt );
  read(0, &ch, 1);
  tcsetattr ( 0, TCSANOW, &oldt );

  return ch;
}


int cleanScreen()
{
	for(int i =0; i<75; i++)
	{
		cout << endl;
	}
	return 1;
}

char WaitHit()
{
	char c;
	cout << endl<<"Appuyez sur une touche pour continuez "<<endl;
	//while(kbhit() != 1);
	c = mygetch();
	return c;
}


int modifierPassword(Liste<Secretaire> *listeSec, Secretaire *s, char *newpass)
{
	if(strlen(newpass) != 8)
	{
		throw ExceptionMessage("mauvais mots de pass dans modifierPassword");
	}
	Iterateur<Secretaire> itSec(*listeSec);
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		if(!strcmp((&itSec)->getLogin(), s->getLogin()) && !strcmp((&itSec)->getPassword(), s->getPassword()))
		{
			(&itSec)->setPassword(newpass);
			return 0;
		}
	}
	return -1;
}

int showSec(Liste<Secretaire> listeSec,bool type)
{
	Iterateur<Secretaire> itSec(listeSec);
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		if((&itSec)->getNumClub() == 0 && (type == 0))
		{
			cout << "******************" << endl;
			cout << "Nom : " << (&itSec)->getNom() << endl;
			cout << "Prénom : " << (&itSec)->getPrenom() << endl;
		}
		else if((&itSec)->getNumClub() != 0 && (type == 1))
		{
			cout << "******************" << endl;
			cout << "Nom : " << (&itSec)->getNom() << endl;
			cout << "Prénom : " << (&itSec)->getPrenom() << endl;
			cout << "Numéro de club : " << (&itSec)->getNumClub() << endl;
		}
	}
}

int supprimerSec(char* firstname,char* lastname,Liste<Secretaire> *listeSec)
{
	Iterateur<Secretaire> itSec(*listeSec);
	int nClub;
	for(itSec.reset();itSec.end() == 0;itSec++)
	{
		if(!strcmp((&itSec)->getPrenom(), firstname) && !strcmp((&itSec)->getNom(), lastname))
		{
			nClub = (&itSec)->getNumClub();
			//Test s'il reste une secretaire dans le club
			Iterateur<Secretaire> itTmp(*listeSec);
			for(itTmp.reset();itTmp.end() == 0;itTmp++)
			{
				if((strcmp((&itTmp)->getPrenom(), firstname) != 0) && (strcmp((&itTmp)->getNom(),lastname) != 0) && ((&itTmp)->getNumClub() == nClub))
				{
					itSec.remove();
					return 0;
				}
			}
			return -1;
		}
	}

}

int supprimerEqu(int numero, Liste<Equipe> *listeEquipe)
{
	Iterateur<Equipe> it(*listeEquipe);
	for(it.reset();it.end() == 0;it++)
	{
		if((&it)->getNumero() == numero)
		{
			
			it.remove();
			
			return 0;
		}
	}
	return -1;
}

int addClub(ListeTriee<Club> *listeClub, Liste<Secretaire> *listeSec)
{
	Club cTmp;
	Secretaire sTmp;
	char tmp[100], pass[100];
	int tmpint, test =0;
	Personne tmpp;
	if(listeClub == NULL || listeSec == NULL)
	{
		throw ExceptionMessage("Erreur add club");
	}
	
	//encodage club
	cout << "encodage du club " << endl;
	cin >> cTmp;
	
	
	//Test s'il reste une secretaire dans le club
	Iterateur<Secretaire> itTmp(*listeSec);
	for(itTmp.reset();itTmp.end() == 0;itTmp++)
	{
		if(((&itTmp)->getNumClub() == cTmp.getNumClub()))
		{
			test = 1;
		}
	}
	if(test == 0)
	{
		//encodage Secretaire du club
		cout << endl <<"encodage de la secretaire"<< endl;
		cin >> tmpp;
		sTmp.setNom(tmpp.getNom());
		sTmp.setPrenom(tmpp.getPrenom());
	
		sTmp.setNumClub(cTmp.getNumClub());
		cout << "Encodez le login : " << flush;
		cin >> tmp;
		sTmp.setLogin(tmp);
		cout << "Encodez le password : " << flush;
		cin >> pass;
		sTmp.setPassword(pass);
	}
	
	//verifie que le club et la secretaire n'existe pas déjà
	if(!listeClub->SearchDoublet(cTmp)  &&  !listeSec->SearchDoublet(sTmp))
	{
		listeClub->insere(cTmp);
		listeSec->insere(sTmp);
	}
	else
	{
		throw ExceptionMessage("Erreur création club !!!!");
		return -1;
	}
	
	
	return 1;
}


int supprimerJoueur(Matricule m, ListeTriee<Joueur> *listeJoueur)
{
	Iterateur<Joueur> itJoueur(*listeJoueur);
	for(itJoueur.reset();itJoueur.end() == 0;itJoueur++)
	{
		if(!strcmp((&itJoueur)->getMatricule().getDateInscription(),m.getDateInscription()) && ((&itJoueur)->getMatricule().getNumero() == m.getNumero()))
		{
			itJoueur.remove();
			return 0;
		}
	}
	return -1;
}

int importFichierJoueur(ListeTriee<Joueur> *listeJoueur, char* nomFich, int numeroClub)
{
	ifstream fichiertxt(nomFich,ios::in);
	Iterateur<Joueur> itJoueur(*listeJoueur);
	char c;
	int matriculeint, pass=0;
	char *nomtmp,*prenomtmp,*matrictmp,*classtmp, tmpS2[256], dummyline[255], tmpS[256];
	if(!(fichiertxt.is_open()))
	{
		if(error == 1 || verbose==1)
			cout << "Erreur nom de fichier" << endl;
		return -1;
	}
	else
	{
		fichiertxt.getline(dummyline,255);
		fichiertxt.get(c);
		for(int i=0; !fichiertxt.eof(); i++)
		{
			Joueur jtmp;
			try
			{
				
				pass = 0;
				fichiertxt.seekg(-1, ios::cur);
				fichiertxt.getline(tmpS, 255, '\n');
				strcpy(tmpS2, tmpS);
				
				nomtmp = strtok(tmpS, ",");
				prenomtmp = strtok(NULL, ",");
				matrictmp = strtok(NULL, ",");
				classtmp = strtok(NULL, " ,\n\0");
				
				
				cout << "Lu : " <<tmpS2<<endl;
				
				
				matriculeint=atoi(matrictmp);
				jtmp.setNom(nomtmp);
				jtmp.setPrenom(prenomtmp);
				jtmp.setNumClub(numeroClub);
				Matricule mtmp;
				mtmp.setNumero(matriculeint);
				jtmp.setMatricule(mtmp);
				
				
				
				if(classtmp[0] == 'N' && classtmp[1] == 'C')
				{
					if(error == 1 || verbose==1)
						cout << "Ajout d'un joueur non classé" << classtmp << endl;
					//jtmp.setClassement(NULL);
				}
				else
				{
					Classement cltmp(classtmp);
					jtmp.setClassement(&cltmp);
				}
				
				//cout << jtmp<<endl;
				
				for(itJoueur.reset();itJoueur.end() == 0;itJoueur++)
				{
					if((&itJoueur)->getMatricule().getNumero() == jtmp.getMatricule().getNumero())
					{
						//cout << "Joueur déja présent dans la liste" << endl;
						pass = 1;
					}
				}
				if( pass == 0)
				{
					if(verbose==1)
						cout << "insertion d'un joueur "<<endl;
					listeJoueur->insere(jtmp);
				}
				
			}
			catch(InvalidClassementException &e)
			{
				//erreur classement
				if(error == 1 || verbose==1)
					cerr << "erreur classement !"<<e.getMsg()<<endl;
				
			}
			catch(ExceptionMessage &e)
			{
				//erreur generale
			}
			
			
			
			
			fichiertxt.get(c);
			classtmp = NULL;
			nomtmp = NULL;
			prenomtmp = NULL;
			matrictmp = NULL;
			jtmp.setClassement(NULL);
		}
		fichiertxt.close();
		return 0;
	}
}


int CreeEquipe(ListeTriee<Club> *listeClub, Liste<Equipe> *listeEquipe, int num)
{
	//
	Equipe tmpE;
	Club *tmpC;
	
	if((tmpC = getClubWithNum(listeClub, num)) == NULL)
	{
		//erreur
		return -1;
	}
	else
	{
		tmpE.setClub(tmpC);
		
		cin >> tmpE;
		cout << endl;
		
		for(int i=0; i<4; i++)
		{
			tmpE.setJoueur(NULL, i);
		}
		
		listeEquipe->insere(tmpE);
		
		return 1;
	}
}




void bidonnageSec()
{
	try
	{
		ofstream fichier("secretaires.dat",ios::out);
		Secretaire s("admin","admin",0, "admin", "admin111");
		s.Save(fichier);
		fichier.close();
	}
	catch(ExceptionMessage &e)
	{
		if(error == 1 || verbose==1)
			cerr << "erreur : "<< e.getMsg()<<endl;
	}
	catch(InvalidPasswordException &e)
	{
		if(error == 1 || verbose==1)
			cerr << "password incorect "<< e.getMsg() << endl;
	}
	catch(...)
	{
		if(error == 1 || verbose==1)
			cerr << "erreur inconnue"<< endl;
	}
}



int testSecLogin(Liste<Secretaire> listeSec, Secretaire *sec)
{
	Iterateur<Secretaire> itSec(listeSec);
	if(verbose==1)
		cout << "test des secretaire login + mdp"<<endl;
	for(itSec.reset(); itSec.end() == 0; itSec++)
	{
		//cout << (&itSec)->getLogin() << " == "<< sec->getLogin()<<endl;
		//cout << (&itSec)->getPassword() << " == "<< sec->getPassword()<<endl<<endl;
		if(!strcmp((&itSec)->getLogin(), sec->getLogin()) && !strcmp((&itSec)->getPassword(), sec->getPassword()))
		{
			//cout << "AAAA"<< *(&itSec)<<endl<<sec;
			*sec = *(&itSec);
			//cout << "AAAA"<< *(&itSec) << endl << *sec << endl;
			if(verbose==1)
				cout << "trouver !"<< endl;
			return (&itSec)->getNumClub();
		}
	}
	return -1;
}

int printListeSec(Liste<Secretaire> listeSec)
{
	int i;
	Iterateur<Secretaire> pParc(listeSec);
	cout<< endl;
	for(i=0; pParc.end() == 0; i++)
	{
		cout << "secretaire "<< i<<endl;
		cout << &pParc <<endl;
		pParc++;
	}
	
}





int SaveJoueurAndEquipe(char *nomFichier, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe)
{
	
	int len, tmp, i;
	
	if(nomFichier == NULL || listeClub == NULL || listeJoueur == NULL | listeEquipe == NULL)
	{
		//erreur !!!
		throw ExceptionMessage("Erreur sauvegarde Joueur !!!!");
	}
	else
	{
		// on veut les jouers et equipe que de 1 seul clubs portant le nom : nomClub
		ofstream fichier(nomFichier,ios::out);
		Iterateur<Equipe> ItE(*listeEquipe);
		
		if(verbose==1)
			cout << "save j&e "<<endl;
		
		tmp = listeJoueur->getNombreElements();
		fichier.write((char *)&tmp, sizeof(int));
		
		//cout << "tmp = " << tmp <<endl;
		
		listeJoueur->Save(fichier);
		
		//cout << "joueur save !"<<endl;
		
		for(ItE.reset(); ItE.end() == 0; ItE++)
		{
			tmp = (&ItE)->getClub()->getNumClub();
			fichier.write((char *)&(tmp), sizeof(int));
			tmp = (&ItE)->getNumero();
			fichier.write((char *)&(tmp), sizeof(int));
			
			len = strlen((&ItE)->getDivision())+1;
			fichier.write((char *)&len, sizeof(int));
			fichier.write((&ItE)->getDivision(), len);
			
			//cout << "club fait "<<endl;
			
			for(i=0; i<4; i++)
			{
				if((&ItE)->getJoueur(i) != NULL)
				{
					tmp = (&ItE)->getJoueur(i)->getMatricule().getNumero();
					fichier.write((char *) &(tmp), sizeof(int));
				}
				else
				{
					tmp = 0;
					fichier.write((char *) &tmp, sizeof(int));
				}
				//cout << " joueur "<<i+1 <<" fait !"<<endl;
			}
			
		}
		if(verbose==1)
			cout << "fin save "<<endl;
		fichier.close();
		
	}
	return 1;
}







Club *getClubWithNum(ListeTriee<Club> *listeClub, int num)
{
	Iterateur<Club> ItClub(*listeClub);
	Club *tmpC;
	if(verbose==1)
		cout << "recheche num club "<<endl;
	for(ItClub.reset(); ItClub.end() == 0; ItClub++)
	{
		//cout << endl << "premier essais : "<< num << " == "<<(&ItClub)->getNumClub()<<endl;
		if((&ItClub)->getNumClub() == num)
		{
			//cout << "C : "<< (&ItClub)<<endl<< *(&ItClub)<<endl;
			tmpC = (&ItClub);
			if(verbose==1)
				cout << "Club trouver ! "<<endl;
			return tmpC;
		}
	}
	return NULL;
}



Joueur *getJoueurWithNum(ListeTriee<Joueur> *listeJoueur, int num)
{
	Iterateur<Joueur> ItJoueur(*listeJoueur);
	Joueur *tmpJ;
	if(verbose==1)
		cout << "recheche num Joueur "<<endl;
	for(ItJoueur.reset(); ItJoueur.end() == 0; ItJoueur++)
	{
		//cout << endl << "premier essais : "<< num << " == "<<(&ItJoueur)->getMatricule().getNumero()<<endl;
		if((&ItJoueur)->getMatricule().getNumero() == num)
		{
			//cout << "C : "<< (&ItJoueur)<<endl<< *(&ItJoueur)<<endl;
			tmpJ = (&ItJoueur);
			if(verbose==1)
				cout << "Joueur trouver "<<endl;
			return tmpJ;
		}
	}
	return NULL;
}


Equipe *getEquipeWithNum(Liste<Equipe> *listeEquipe, char lettre, Club tmpC)
{
	Iterateur<Equipe> It(*listeEquipe);
	Equipe *tmpE;
	if(verbose==1)
		cout << "recheche Equipe "<<endl;
	for(It.reset(); It.end() == 0; It++)
	{
		//cout << endl << "premier essais : "<< lettre << " == "<<(&It)->getNumero()<<endl;
		if( ((&It)->getNumero() == lettre) && (tmpC.getNumClub() == ((&It)->getClub()->getNumClub()) ) )
		{
			//cout << "C : "<< (&ItClub)<<endl<< *(&ItClub)<<endl;
			tmpE = (&It);
			if(verbose==1)
				cout << "Equipe trouver "<<endl;
			return tmpE;
		}
	}
	return NULL;
}


int printListeJoueur(ListeTriee<Joueur> listeJoueur)
{
	if(listeJoueur.estVide() == true)
	{
		cout << "liste Joueur vide  !"<<endl;
		return -1;
	}
	Iterateur<Joueur> It(listeJoueur);
	cout << "liste des joueurs : "<<endl;
	for(It.reset(); It.end() == 0; It++)
	{
		if((&It) == NULL)
		{
			cout << "Fin liste des joueurs !"<<endl<<endl;
			return -1;
		}
		cout  << "Nom : "<< (&It)->getNom() <<endl;
		cout  << "Prenom : "<< (&It)->getPrenom() <<endl;
		if(((&It)->getClassement()) != NULL)
			cout  << "Classement : "<< *((&It)->getClassement()) <<endl;
		else
			cout << "Classement : NC"<<endl;
		cout  << "Matricule : "<< (&It)->getMatricule().getNumero() <<endl<<endl;
		
	}
	return 1;
}


int printListeEquipe(Liste<Equipe> listeEquipe)
{
	if(listeEquipe.estVide() == true)
	{
		cout << "liste Equipe vide  !"<<endl;
		return -1;
	}
	Iterateur<Equipe> It(listeEquipe);
	int j;
	cout << "liste des equipes : "<<endl;
	int cpt=0;
	for(It.reset(), j=0; It.end() == 0; It++, j++)
	{
		if(&It == NULL || (&It)->getClub()->getNom() == NULL || ((&It)->getDivision()) == NULL)
		{
			cout << "Fin liste des equipes !"<<endl<<endl;
			return -1;
		}
		cout << "Equipe "<<j<<endl;
		cout  << "Nom : " << (&It)->getClub()->getNom()<<flush;
		cout  <<  (&It)->getNumero() <<endl;
		cout  << "Division : "<< ((&It)->getDivision()) <<endl;
		
		for(int i=0; i<4; i++)
		{
			if((&It)->getJoueur(i) != NULL)
			{
				cpt++;
			}
		}
		cout <<endl;
		//cout << "Nombre de joueurs : " << cpt << endl;
		
	}
	return 1;
}



int LoadJoueurAndEquipe(char *nomFichier, ListeTriee<Club> *listeClub, ListeTriee<Joueur> *listeJoueur, Liste<Equipe> *listeEquipe)
{
	int NbrJ, i, tmpI, len;
	Joueur tmpJ;
	char tmpS[255];

	
	if(nomFichier == NULL || listeClub == NULL || listeJoueur == NULL | listeEquipe == NULL)
	{
		//erreur !!!
	}
	else
	{
		// on veut les jouers et equipe que de 1 seul clubs portant le nom : nomClub
		ifstream fichier(nomFichier,ios::in);
		
		if(verbose==1)
			cout << "Load j&e for "<< nomFichier<<endl;
		
		if(!(fichier.is_open()) )
		{
			return -1;
		}
		Iterateur<Club> ItC(*listeClub);
		
		Club *tmpC;
		
		//lecture des joueurs
		fichier.read((char *)&NbrJ, sizeof(int));
		for(i=0; i < NbrJ; i++)
		{
			//lecture du joueur et insertion
			tmpJ.Load(fichier);
			listeJoueur->insere(tmpJ);
		}
		
		//lecture des equipes
		if(verbose==1)
			cout << "lecture equipe "<<endl;
		char c;
		fichier.get(c);
		for(i=0; !fichier.eof(); i++)
		{
				Equipe tmpE;
			fichier.seekg(-1, ios::cur);
			fichier.read((char *)&tmpI, sizeof(int));
			tmpC = getClubWithNum(listeClub, tmpI);
			if(tmpC != NULL)
			{
				//on a le club
				tmpE.setClub(tmpC);
				
				fichier.read((char *)&tmpI, sizeof(int));
				tmpE.setNumero(tmpI);
				
				fichier.read((char *)&len, sizeof(int));
				fichier.read(tmpS, len);
				tmpE.setDivision(tmpS);
				
				for(int j=0; j<4; j++)
				{
					fichier.read((char *)&tmpI, sizeof(int));
					//cout<< "joueur "<< j <<" -- "<<tmpI<<endl;
					if(tmpI != 0)
					{
						//le joueur existe
						tmpE.setJoueur(getJoueurWithNum(listeJoueur, tmpI), j);
					}
					else
					{
						//le joueur n'existe pas
						tmpE.setJoueur(NULL, j);
					}
				}
			}
			else
			{
				//erreur 
			}
			//cout << "Equipe "<<i<<endl;
			//cout <<tmpE<<endl<<endl;
			fichier.get(c);
			listeEquipe->insere(tmpE);
		}
		
	}
	return 1;
}



int removeJoueurFromEquipe(Equipe *tmpE, Joueur *tmpJ)
{
	int tmpI;
	
	for(int i=0; i<4; i++)
	{
		if(*(tmpE->getJoueur(i)) == *tmpJ)
		{
			tmpE->setJoueur(NULL, i);
		}
	}
}


void showJoueurWthClassement(ListeTriee<Joueur> listeJoueur,char letclass)
{
	Iterateur<Joueur> It(listeJoueur);
	int CptJoueur = 0;
	for(It.reset();It.end() == 0;It++)
	{
		if((&It)->getClassement()==NULL && letclass == 'N')
		{
			cout << "Nom : " << (&It)->getNom() << endl;
			cout << "Prénom : " << (&It)->getPrenom() << endl;
			cout << "Classement : NC" << endl;
			cout << "Numéro de matricule : " << (&It)->getMatricule().getNumero() << endl;
			cout << "Date d'inscription : " << (&It)->getMatricule().getDateInscription() << endl;
			cout << "****************************" << endl;
			CptJoueur++;
		}
		else if((&It)->getClassement()!=NULL && ((&It)->getClassement()->getLettre() == letclass))
		{
			cout << "Nom : " << (&It)->getNom() << endl;
			cout << "Prénom : " << (&It)->getPrenom() << endl;
			cout << "Classement : " << *((&It)->getClassement()) << endl;
			cout << "Numéro de matricule : " << (&It)->getMatricule().getNumero() << endl;
			cout << "Date d'inscription : " << (&It)->getMatricule().getDateInscription() << endl;
			cout << "****************************" << endl;
			CptJoueur++;
		}
	}
	cout << "Nombre de joueurs trouvés : " << CptJoueur << endl;
	return;	
}


void showInfoJoueur(ListeTriee<Joueur> listeJoueur,int matriculeint)
{
	Iterateur<Joueur> It(listeJoueur);
	int CptJoueur = 0;
	for(It.reset();It.end() == 0;It++)
	{
		if((&It)->getMatricule().getNumero() == matriculeint)
		{
			cout << "Nom : " << (&It)->getNom() << endl;
			cout << "Prénom : " << (&It)->getPrenom() << endl;
			if((&It)->getClassement()!=NULL)
				cout << "Classement : " << *(&It)->getClassement() << endl;
			else
				cout << "Classement : NC" << endl;
			cout << "Numéro de matricule : " << (&It)->getMatricule().getNumero() << endl;
			cout << "Date d'inscription : " << (&It)->getMatricule().getDateInscription() << endl;
			CptJoueur++;
		}
	}
	if(CptJoueur == 0)
		cout << "Joueur introuvable" << endl;
	return;
}
















