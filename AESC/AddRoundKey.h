#ifndef ADD_H
#define ADD_H

#include <stdio.h>
#include "constantes.h"
#include <stdlib.h>


void AddRoundKey(unsigned char state[4][4], unsigned char key);
void Aff(unsigned char state[NBR][NBR]);
#endif
