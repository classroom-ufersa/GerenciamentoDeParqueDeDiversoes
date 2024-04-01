typedef struct visitantes Visitante;

/*Função que cria a lista e o retorna iniciliazado*/
Visitante *criaLista(void);

/*Função que cria adiciona visitante na lista encadeada e retorna a lista*/
Visitante * adicionarVisitante(Visitante *visitante);

/*Função que remove o visitante definido pelo usuario da lista e retorna a lista com essa modificação*/
Visitante *removerVisitante(Visitante*visitante);


/*Função que edita os dados do visitante especificado pelo usuario*/
void editarVisitante(Visitante*visitante);

/*Função com o menu de opções para edição dos dados dos visitantes*/
void menuEditar(Visitante * visitante);

/*Função para alterar o nome de um visitante especificado pelo usuario*/
void alterarNome(Visitante*visitante);

/*Função para alterar a idade de um visitante especificado pelo usuario*/
void alterarIdade(Visitante*visitante);

/*Função para alterar o documento de um visitante especificado pelo usuario*/
void alterarDocumento(Visitante*visitante);

/*Função para verificar dentro da lista de visitantes se existe documento semelhante ao documento cadastrado
Retornando 1 para documento unico e retornando 0 para documento semelhante encontrado dentro da lista */
int docUnico(Visitante*visitante, char doc[]);

/*Função que busca pelo nome e lista os visitantes com o nome buscado pelo usuário*/
void buscarPeloNome(Visitante*visitante);
