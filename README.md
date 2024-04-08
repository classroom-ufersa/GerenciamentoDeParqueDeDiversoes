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
[Cabeçalho da Estrutura Atração](docs/tadAtracao.md)

#### Visitantes
```c
struct visitante {
	char nome[100]; 
	int idade;
	char documento[100];
	struct visitante *prox;
};
```
[Cabeçalho da Estrutura Visitante](docs/tadVisitantes.md)

No projeto, utilizamos duas TAD's e dentro delas utilizamos lista encadeada simples, pois elas podem manipular qualquer nó da lista, seja o primeiro, ultimo ou algum do meio, facilitando a implementação das funções do tipo abstrato de dados.
Além disso, a lista encadeada permite a estrutura saber quem será o próximo facilitando o trajeto entre os nós das estruturas.

### Módulo
Para funções de uso geral, criamos o módulo outrasFuncoes.

[Cabeçalho do Módulo](docs/modulo.md)

## Desenvolvedores
- Allyson da Silva Felix
- Samuel Iago de Farias Cabral

