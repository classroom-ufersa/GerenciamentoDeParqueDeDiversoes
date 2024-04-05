#ifndef VISITANTE
#define VISITANTE

typedef struct visitante Visitante;
#include "outrasFuncoes.h"

/*Função que cria adiciona visitante na lista encadeada e retorna a lista*/
Visitante *adicionarVisitante(Visitante *visitante, char documento[]);

/*Função que cria a lista e o retorna iniciliazado*/
Visitante *criaListaVisitante(void);

/*Função que mostra todos os visitantes cadastrados na atração atual*/
void mostrarVisitante(Visitante*visitante);

/*Função que remove o visitante definido pelo usuario da lista e retorna a lista com essa modificação*/
Visitante *removerVisitante(Visitante*visitante);

/*Função que libera a memória alocada para a lista encadeada de visitantes*/
void liberarMemoriaVisitante(Visitante*visitante);


/*Função que edita os dados do visitante especificado pelo usuario*/
Visitante* editarVisitante(Visitante*visitante);

/*Função com o menu de opções para edição dos dados dos visitantes*/
int menuEditar(Visitante * visitante, char docAnterior[]);

/*Função para alterar o nome de um visitante especificado pelo usuario*/
void alterarNome(Visitante*visitante);

/*Função para alterar a idade de um visitante especificado pelo usuario*/
void alterarIdade(Visitante*visitante);

/*Função que retorna 0 se visitante estiver vazio e retorna 1 se não estiver*/
int visitantesVazia(Visitante*visitante);

/*Função para alterar o documento de um visitante especificado pelo usuario*/
void alterarDocumento(Visitante*visitante, char docAnterior[]);

/*Função para verificar dentro da lista de visitantes se existe documento semelhante ao documento cadastrado
Retornando 1 para documento unico e retornando 0 para documento semelhante encontrado dentro da lista */
int docUnico(Visitante*visitante, char doc[]);

/*Função que busca pelo nome e lista os visitantes com o nome buscado pelo usuário*/
void buscarPeloNome(Visitante*visitante);

/*Função que lê os visitantes presentes no arquivo de texto e os retorna para a função copiarArquivo*/
Visitante *lerVisitante(Visitante *visitante, char *linha);

/*Função que escreve os dados dos visitantes dentro do arquivo de texto*/
void salvaVisitante(Visitante *visitante,FILE *arquivo_saida);

#endif
