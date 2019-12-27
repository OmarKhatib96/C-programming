






hachage : hachage.o StructureDonnees.o InsertionClef.o AffichagesCollisions.o
	gcc hachage.o -g   StructureDonnees.o    InsertionClef.o AffichagesCollisions.o  -o  hachage -lm

hachage.o: hachage.c  hachage.h  StructureDonnees.h InsertionClef.h  AffichagesCollisions.h 
	gcc -c -g hachage.c


AffichagesCollisions.o: AffichagesCollisions.c StructureDonnees.h InsertionClef.h  AffichagesCollisions.h
	gcc -c -g AffichagesCollisions.c

InsertionClef.o: InsertionClef.c InsertionClef.h  StructureDonnees.h
	gcc -c -g InsertionClef.c
StructureDonnees.o: StructureDonnees.c StructureDonnees.h 
	gcc -c -g StructureDonnees.c



















