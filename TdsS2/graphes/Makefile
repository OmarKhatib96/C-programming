




td1 : td1.o listeAdjacence.o AffichagesSommets.o insertionSommet.o file.o
	gcc td1.o    listeAdjacence.o   AffichagesSommets.o insertionSommet.o  file.o -o td1

td1.o: td1.c  td1.h  listeAdjacence.h AffichagesSommets.h insertionSommet.h  file.h
	gcc -c -g td1.c

file.o: file.c file.h
	gcc -c -g file.c



AffichagesSommets.o: AffichagesSommets.c AffichagesSommets.h file.h listeAdjacence.h
	gcc -c -g  AffichagesSommets.c

insertionSommet.o: insertionSommet.c insertionSommet.h file.h listeAdjacence.h
	gcc -c -g insertionSommet.c
listeAdjacence.o: listeAdjacence.c listeAdjacence.h file.h
	gcc -c -g listeAdjacence.c



















