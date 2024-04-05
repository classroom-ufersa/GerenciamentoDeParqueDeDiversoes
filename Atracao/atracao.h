#ifndef ATRACAO
#define ATRACAO
#include"../Visitantes/visitantes.h"

typedef struct atracao Atracoes;

//função que serve para buscar a atração escolhida pelo usuário
Atracoes * buscaDeAtracao(Atracoes*atracao);

//função que contém o menu principal do programa
void menuPrincipal(Atracoes *atracao, int *id);


//função que verifica se a atração tem espaço para inserir mais visitantes
Atracoes *visitanteNaAtracao(Atracoes*atracao);

//função que inicia a lista encadeada de atrações em NULL
Atracoes *criaListaAtracao(void);

//função que insere uma atração
Atracoes *inserirAtracao(Atracoes *atracao, int *id);

int atracaoVazia(Atracoes *atracao);

Atracoes *removerAtracao(Atracoes *atracao);

void listarAtracoes(Atracoes *atracao);

void liberarListaAtracoes(Atracoes *atracao);

void imprimirArquvivo(Atracoes *listaAtracoes);

Atracoes *copiarArquivo(Atracoes **listaAtracoes, int *pontValorId);

int visitantesVazios(Atracoes*atracao);

int documentoUnico(Atracoes*atracao,char documento[]);

#endif