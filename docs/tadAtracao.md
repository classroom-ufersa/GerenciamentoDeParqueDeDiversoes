# TAD Atração

Cabeçalhos das funções do tipo abstrato de dados:  

```c
//função que serve para buscar a atração escolhida pelo usuário
Atracoes *buscaDeAtracao(Atracoes*atracao);

//função que contém o menu principal do programa
void menuPrincipal(Atracoes *atracao, int *id);

//função que verifica se a atração tem espaço para inserir mais visitantes
Atracoes *visitanteNaAtracao(Atracoes*atracao);

//função que inicia a lista encadeada de atrações em NULL
Atracoes *criaListaAtracao(void);

//função que insere uma atração
Atracoes *inserirAtracao(Atracoes *atracao, int *id);

//função para verificar se a atracao está vazia
int atracaoVazia(Atracoes *atracao);

//função que vai remover a atração do nó de listas encadeadas de atração
Atracoes *removerAtracao(Atracoes *atracao);

//função que lista todas as atrações do programa e a quantidade de visitantes em cada uma
void listarAtracoes(Atracoes *atracao);

//função que libera as atrações da memória
void liberarListaAtracoes(Atracoes *atracao);

//função que vai escrever os dados do programa em um arquivo de texto
void imprimirArquvivo(Atracoes *listaAtracoes);

//função que vai ler os dados de um arquivo de texto e os armazena no programa
Atracoes *copiarArquivo(Atracoes **listaAtracoes, int *pontValorId);

//função para que caso não tenha visitante ainda aumente o total de atrações
int visitantesVazios(Atracoes*atracao);

//função que verifica que o documento do visitante a ser cadastrado é o único em todas as atrações
int documentoUnico(Atracoes*atracao,char documento[]);

```