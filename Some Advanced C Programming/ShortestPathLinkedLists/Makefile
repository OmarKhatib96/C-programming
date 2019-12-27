







CC=gcc -g # variable donnant le compilateur



CFLAGS=

EXEC=PCC
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
all: $(EXEC)





PCC : PCC.o insertionSommet.o  listeAdjacence.o  AffichagesSommets.o
	$(CC)  $^ -o    $@

PCC.o: PCC.h  insertionSommet.h  listeAdjacence.h  AffichagesSommets.h




insertionSommet.o: insertionSommet.h  listeAdjacence.h
AffichagesSommets.o: AffichagesSommets.h listeAdjacence.h




listeAdjacence.o: listeAdjacence.h 

%.o: %.c
	$(CC) -c $< $(CFLAGS)


clean:
	rm -f *.o core
mrproper: clean
	rm -f $(EXEC)


















