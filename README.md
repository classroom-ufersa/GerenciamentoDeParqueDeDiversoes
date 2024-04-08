# Gerenciamento-de-Parque-de-Diversões
- Projeto- 04 Gerenciamento de Parque de Diversoes

## Sumário
- Sobre o projeto
- Requisitos
- Arquitetura
- Desenvolvedores


## Sobre o projeto
O projeto foi feito, tendo em mente, o gerenciamento de um parque de diversões.
Para fazer o programa foi utilizado 2 TAD's distintas, uma para as atrações, outra para os visitantes e criamos um módulo para funções gerais.

Para ler os dados do arquivo de texto e armazenar os dados dentro do programa, foi utilizado duas funções específicas, uma para ler as atrações e a outra os visitantes.
Isso foi feito pelo motivo de que não se pode chamar a TAD visitante dentro da TAD atracao, por isso, se utiliza funções específicas.

O programa, ao ler o arquivo de texto vai detectar quais instruções pertencem as atrações ou aos visitantes, após ler, ele vai armazenar os dados de maneira ordenada, as atrações serão armazenadas de acordo com o id e os visitantes de acordo com o seu nome.

Com os dados armazenados ele pode os modificar como for instruído, seja editanto alguma informação de algum visitante em específico, ou excluindo alguma atração.
Por fim, após cada modificação, o arquivo de texto será atualizado com os novos dados e quando for inicializado de novo após ser fechado, vai ler o arquivo de novo.

## Requisitos do projeto
O projeto tem os seguintes requisitos e funcionalidades:

1. Adicionar atração
2. Remover atração
3. Adicionar visitante
4. Remover visitante
5. Editar a informação do visitante
6. Buscar visitante por nome
7. Listar atrações e o número de visitantes presentes
8. Sair
   
- A opção de sair é a única que permite sair do programa.
- Os dados devem ser armazenados em um arquivo de texto após cada operação e quando o programa for iniciado, carregar os dados armazenados nesse arquivo de texto.
- Ordenar os visitantes por nome e ordenar as atrações por id.

## Tutorial
[Veja o Tutorial](docs/tutorial.md)

## Arquitetura

### Estruturas
#### Atração
```c
struct atracao{
    int id;
    int capacidade;
    int quantidaVisitantes;
    char horarioFuncionamento[5];
    struct atracao *prox;
    Visitante *visitantes;
};
```
#### Visitantes
```c
struct visitante {
	char nome[100]; 
	int idade;
	char documento[100];
	struct visitante *prox;
};
```
No projeto, utilizamos duas TAD's e dentro delas utilizamos lista encadeada simples, pois elas podem manipular qualquer nó da lista, seja o primeiro, ultimo ou algum do meio, facilitando a implementação das funções do tipo abstrato de dados.
Além disso, a lista encadeada permite a estrutura saber quem será o próximo facilitando o trajeto entre os nós das estruturas.

### TAD Atracoes
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
### TAD Visitantes
```c
//função que adiciona um visitante na atração atual
Visitante *adicionarVisitante(Visitante *visitante);

//função que inicia a lista encadeada de visitantes em NULL
Visitante *criaListaVisitante(void);

//função que mostra todos os visitantes cadastrados na atração atual
void mostrarVisitante(Visitante* visitante);

//função que remove o visitante da atração escolhida
Visitante *removerVisitante(Visitante *visitante);

//função que libera a memória alocada para a lista encadeada de visitantes
void liberarMemoriaVisitante(Visitante *visitante);

//função que edita um dos dados do visitante escolhido
void editarVisitante(Visitante*visitante);

//o menu que mostra as opções de editar o visitante
void menuEditar(Visitante *visitante);

//função para alterar a idade do visitante escolhido
void alterarIdade(Visitante *visitante);

//função para alterar o nome do visitante escolhido
void alterarNome(Visitante *visitante);

//função para verificar se tem um visitante ou não
int visitantesVazia(Visitante *visitante);

//função para buscar um visitante pelo seu nome
void buscarPeloNome(Visitante *visitante);

//função para ler os visitante do arquivo de texto
Visitante *lerVisitante(Visitante *visitante, char *linha);

//função para escrever os visitante no arquivo de texto
void salvaVisitante(Visitante *visitante,FILE *arquivo_saida);

//função para alterar o documento do visitante
void alterarDocumento(Visitante*visitante);

//função para verificar se o documento do visitante atual é o unico em relação aos outros visitantes
int docUnico(Visitante*visitante, char doc[]);
```
### Módulo
Para funções de uso geral, criamos o módulo outrasFuncoes
```c
//função que verifica se existe apenas um caractere
int verificarEntradaChar(char entrada[]);

//função que transforma os nomes em maiusculo
char *aumentaNome(char palavra[100],char novaPalavra[100]);

//função que verifica se tem apenas números no documento
int conferirDocumento(char documento[]);

//função que verifica se tem apenas caracteres do alfabeto no nome
int conferirAlfabeto(char palavra[]);

//função que auxilia a liberação da memória
void limparBuffer();

//função que verifica se o tamanho do documento menor que 8
int documentoMin(char doc[]);

//função que impede do usuário de colocar mais de 2 valores nas horas e minutos
int tamanhoHorarioMin(char horas[], char min[]);

//função que formata as horas e minutos inseridos
void horarioFormatado(char horasDeFuncionamento[],char minutosDeFuncionamento[]);

```

## Desenvolvedores
- Allyson da Silva Felix
- Samuel Iago de Farias Cabral

