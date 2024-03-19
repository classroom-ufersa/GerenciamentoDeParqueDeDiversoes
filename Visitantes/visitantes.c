#include "atracao.c"
#include "visitantes.h"
#include <stdio.h>
#include <stdlib.h>

struct visitantes{
    char nome[100];
    int idade;
    char documento[12];
    struct visitantes * prox;
};