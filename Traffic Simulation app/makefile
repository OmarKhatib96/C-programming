

main.o: main.c file.h SimulationTraffic.h projet.h constantes.h
	gcc -c main.c

projet.o: projet.c file.h constantes.h
	gcc -c projet.c
SimulationTraffic.o: SimulationTraffic.c file.h constantes.h projet.h
	gcc -c SimulationTraffic.c
file.o: file.c file.h
	gcc -c file.c
deplacement.o : deplacement.c constantes.h  file.h deplacement.h 
	gcc -c deplacement.c
application : main.o projet.o SimulationTraffic.o deplacement.o file.o
	gcc  main.o projet.o file.o deplacement.o SimulationTraffic.o -o application -lm













