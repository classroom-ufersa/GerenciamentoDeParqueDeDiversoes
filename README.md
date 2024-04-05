# Gerenciamento-de-Parque-de-Diversões
- Projeto- 04 Gerenciamento de Parque de Diversoes

## Desenvolvedores
- Allyson da Silva Felix
- Samuel Iago de Farias Cabral

## Sobre o projeto
O projeto foi feito, tendo em mente, o gerenciamento de um parque de diversões.
Para fazer o programa foi utilizado 2 TAD's distintas, uma para as atrações, outra para os visitantes e outra para funções gerais.

## Requisitos do projeto
O projeto teve os seguintes requisitos:

1. Adicionar atração
2. Remover atração
3. Adicionar visitante
4. Remover visitante
5. Editar a informação do visitante
6. Buscar visitante por nome
7. Listar atrações e o número de visitantes presentes
8. Sair
   
- A opção de sair é a única que permite sair do programa.
- Os dados devem ser armazenados em um txt após cada operação e quando o programa for iniciado, carregar os dados armazenados nesse txt.
- Ordenar os visitantes por nome e ordenar as atrações por id.

## Arquitetura

### Estruturas
#### Atração
- int id;
- int capacidade;
- int quantidaVisitantes;
- char horarioFuncionamento[5];
- struct atracao  *prox;
- Visitante *visitantes;

#### Visitantes
- char nome[100]; 
-	int idade;
-	char documento[100];
-	struct visitante *prox;

No projeto, utilizamos duas TAD's e dentro delas utilizamos lista encadeada simples, pois elas podem manipular qualquer nó da lista, seja o primeiro, ultimo ou algum do meio, facilitando a implementação das funções do tipo abstrato de dados.
Além disso, a lista encadeada permite a estrutura saber quem será o próximo facilitando o trajeto entre os nós das estruturas.


