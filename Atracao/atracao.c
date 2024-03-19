#include "atracao.h"
#include "visitantes.h"
#include <stdio.h>
#include <stdlib.h>

struct atracao{
    int identificacao;
    int capacidade;
    char horarioAtendimento;
    Visitantes * visitante;
    struct atracao * prox;
};
