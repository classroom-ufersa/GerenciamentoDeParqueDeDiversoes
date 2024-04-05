#ifndef ATRACAO
#define ATRACAO
#include"../Visitantes/visitantes.h"

typedef struct atracao Atracoes;

//função que serve para buscar a atração escolhida pelo usuário e retornar a atracao escolhida
Atracoes * buscaDeAtracao(Atracoes*atracao);

//função que contém o menu principal do programa
void menuPrincipal(Atracoes *atracao, int *id);


/*função que verifica se a atração tem espaço para inserir mais visitantes e guarda informacao do visitante desenvolvendo 
um link com a tad atracao que retorna a atracao com a lista ja preenchida */
Atracoes *visitanteNaAtracao(Atracoes*atracao);

//função que inicia a lista encadeada de atrações em NULL e retorna a atracao inicializada
Atracoes *criaListaAtracao(void);

//função que insere os dados de uma atracao e o retorna preenchido
Atracoes *inserirAtracao(Atracoes *atracao, int *id);


//função para verificar se a atracao está vazia e retorna 1 para nao vazia e 0 para vazia
int atracaoVazia(Atracoes *atracao);


//função que vai remover a atração da lista e retorna a lista sem a atracao escolhida
Atracoes *removerAtracao(Atracoes *atracao);


//função que lista todas as atrações do programa e a quantidade de visitantes em cada uma
void listarAtracoes(Atracoes *atracao);


//função que libera as atrações da memória
void liberarListaAtracoes(Atracoes *atracao);


//função que vai escrever os dados do programa em um arquivo de texto
void imprimirArquvivo(Atracoes *listaAtracoes);


/*função que vai ler os dados de um arquivo de texto e os armazena no programa
retornando a atracao preenchida com os dados do arquivo */
Atracoes *copiarArquivo(Atracoes **listaAtracoes, int *pontValorId);


//função para verificar se os visitantes estao vazios 
int visitantesVazios(Atracoes*atracao);


/*função que verifica que o documento do visitante a ser cadastrado é o único em todas as 
atrações retornando 1 para unico e 0 para documento nao unico */
int documentoUnico(Atracoes*atracao,char documento[]);

#endif
