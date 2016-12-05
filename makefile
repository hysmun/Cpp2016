ALLPROG= Test1 Test2 Test3 Test4 Test5 Test6 Test7
ALLOBJ = Joueur.o Matricule.o Classement.o Personne.o Membre.o Secretaire.o InvalidClassementException.o InvalidPasswordException.o
ALLCPP = 
ALLHEADER = 
TMP = commentaire de base
CFLAGS = 

all:
	clear
	clear
	make Test1
	make Test2
	make Test3
	make Test4
	make Test5

Test:
	make clean
	clear
	clear
	make Test1
	make Test2
	make Test3
	make Test4
	make Test5

Test1: test1.o $(ALLOBJ)
	g++ test1.o $(ALLOBJ)  -o Test1 -Wall

Test2: test2.o $(ALLOBJ)
	g++ test2.o $(ALLOBJ) -o Test2 -Wall

Test3: test3.o $(ALLOBJ)
	g++ test3.o $(ALLOBJ) -o Test3 -Wall

Test4: test4.o $(ALLOBJ)
	g++ test4.o $(ALLOBJ) -o Test4 -Wall
	
Test5: test5.o $(ALLOBJ)
	g++ test5.o $(ALLOBJ) -o Test5 -Wall


test1.o: Test1.cpp
	g++ Test1.cpp -c -o test1.o -Wall

test2.o: Test2.cpp
	g++ Test2.cpp -c -o test2.o -Wall

test3.o: Test3.cpp
	g++ Test3.cpp -c -o test3.o -Wall

test4.o: Test4.cpp
	g++ Test4.cpp -c -o test4.o -Wall

test5.o: Test5.cpp
	g++ Test5.cpp -c -o test5.o -Wall

Joueur.o: Joueur.h Joueur.cpp
	g++ Joueur.cpp -c -o Joueur.o -Wall

Matricule.o: Matricule.h Matricule.cpp
	g++ Matricule.cpp -c -o Matricule.o

Classement.o: Classement.h Classement.cpp
	g++ Classement.cpp -c -o Classement.o

Personne.o: Personne.h Personne.cpp
	g++ Personne.cpp -c -o Personne.o

Membre.o: Membre.h Membre.cpp
	g++ Membre.cpp -c -o Membre.o

Secretaire.o: Secretaire.h Secretaire.cpp
	g++ Secretaire.cpp -c -o Secretaire.o

InvalidClassementException.o: InvalidClassementException.h InvalidClassementException.cpp
	g++ InvalidClassementException.cpp -c -o InvalidClassementException.o

InvalidPasswordException.o: InvalidPasswordException.h InvalidPasswordException.cpp
	g++ InvalidPasswordException.cpp -c -o InvalidPasswordException.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


git:
	clear
	clear
	git add -A
	git commit -m "$(TMP)"
	git push


clean:
	clear
	rm -f *.o makefile~ *.o~ $(ALLPROG)
	
	
	
	
	
	
	
	
	
	
	
	
	
	
