.SILENT:
ALLPROG= Test1 Test2 Test3 Test4 Test5 Test6 Test7 main mainTest
ALLOBJ = Joueur.o Matricule.o Classement.o Personne.o Membre.o Secretaire.o InvalidClassementException.o InvalidPasswordException.o ListeBase.o Liste.o ListeTriee.o Iterateur.o Equipe.o Club.o
ALLCPP = 
ALLHEADER = 
TMP = commentaire de base
CFLAGS = 

all:
	clear
	clear
	make mainTest

Test:
	make clean
	clear
	clear
	echo all test avec clean
	make Test1
	make Test2
	make Test3
	make Test4
	make Test5
	make Test6
	make Test7
	
	
# -------------------------------------------------

#les executable final

main: main.o $(ALLOBJ)
	echo $@
	g++ main.o $(ALLOBJ) -o main -Wall

mainTest: mainTest.o $(ALLOBJ)
	echo $@
	g++ mainTest.o $(ALLOBJ) -o mainTest -Wall

Test1: test1.o $(ALLOBJ)
	echo $@
	g++ test1.o $(ALLOBJ)  -o Test1 -Wall

Test2: test2.o $(ALLOBJ)
	echo $@
	g++ test2.o $(ALLOBJ) -o Test2 -Wall

Test3: test3.o $(ALLOBJ)
	echo $@
	g++ test3.o $(ALLOBJ) -o Test3 -Wall

Test4: test4.o $(ALLOBJ)
	echo $@
	g++ test4.o $(ALLOBJ) -o Test4 -Wall
	
Test5: test5.o $(ALLOBJ)
	echo $@
	g++ test5.o $(ALLOBJ) -o Test5 -Wall

Test6: test6.o $(ALLOBJ)
	echo $@
	g++ test6.o $(ALLOBJ) -o Test6 -Wall

Test7: test7.o $(ALLOBJ)
	echo $@
	g++ test7.o $(ALLOBJ) -o Test7 -Wall





# -------------------------------------------------

#les executable .o

test1.o: Test1.cpp
	echo $@
	g++ Test1.cpp -c -o test1.o -Wall

test2.o: Test2.cpp
	echo $@
	g++ Test2.cpp -c -o test2.o -Wall

test3.o: Test3.cpp
	echo $@
	g++ Test3.cpp -c -o test3.o -Wall

test4.o: Test4.cpp
	echo $@
	g++ Test4.cpp -c -o test4.o -Wall

test5.o: Test5.cpp
	echo $@
	g++ Test5.cpp -c -o test5.o -Wall

test6.o: Test6.cpp
	echo $@
	g++ Test6.cpp -c -o test6.o -Wall

test7.o : Test7.cpp
	echo $@
	g++ Test7.cpp -c -o test7.o -Wall

main.o: main.cpp
	echo $@
	g++ main.cpp -c -o main.o -Wall
	
mainTest.o: mainTest.cpp
	echo $@
	g++ mainTest.cpp -c -o mainTest.o -Wall





# -------------------------------------------------

# les classe et autres

Joueur.o: Joueur.h Joueur.cpp
	echo $@
	g++ Joueur.cpp -c -o Joueur.o -Wall

Matricule.o: Matricule.h Matricule.cpp
	echo $@
	g++ Matricule.cpp -c -o Matricule.o

Classement.o: Classement.h Classement.cpp
	echo $@
	g++ Classement.cpp -c -o Classement.o

Personne.o: Personne.h Personne.cpp
	echo $@
	g++ Personne.cpp -c -o Personne.o

Membre.o: Membre.h Membre.cpp
	echo $@
	g++ Membre.cpp -c -o Membre.o

Secretaire.o: Secretaire.h Secretaire.cpp
	echo $@
	g++ Secretaire.cpp -c -o Secretaire.o

InvalidClassementException.o: InvalidClassementException.h InvalidClassementException.cpp
	echo $@
	g++ InvalidClassementException.cpp -c -o InvalidClassementException.o

InvalidPasswordException.o: InvalidPasswordException.h InvalidPasswordException.cpp
	echo $@
	g++ InvalidPasswordException.cpp -c -o InvalidPasswordException.o

Iterateur.o: Iterateur.cpp Iterateur.h
	echo $@
	g++ Iterateur.cpp -c -o Iterateur.o

ListeBase.o: ListeBase.cpp ListeBase.h
	echo $@
	g++ ListeBase.cpp -c -o ListeBase.o

Liste.o: Liste.cpp Liste.h
	echo $@
	g++ Liste.cpp -c -o Liste.o

ListeTriee.o: ListeTriee.cpp ListeTriee.h
	echo $@
	g++ ListeTriee.cpp -c -o ListeTriee.o

Club.o: Club.cpp Club.h
	echo $@
	g++ Club.cpp -c -o Club.o

Equipe.o: Equipe.cpp Equipe.h
	echo $@
	g++ Equipe.cpp -c -o Equipe.o




# -------------------------------------------------

#special compiler tout les cpp
%.o: %.c
	clear
	clear
	echo $@
	$(CC) -o $@ -c $< $(CFLAGS)






# -------------------------------------------------

## autre
git:
	clear
	clear
	echo git
	git add -A
	git commit -m "$(TMP)"
	git push


clean:
	clear
	clear
	echo clean
	rm -f *.o makefile~ *.o~ $(ALLPROG)
	
	
	
	
	
	
	
	
	
	
	
	
	
	
