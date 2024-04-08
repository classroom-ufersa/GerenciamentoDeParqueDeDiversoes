#include "../include/visitante.h"

struct visitante {
	char nome[100]; 
	int idade;
	char documento[100];
	struct visitante *prox;
};

Visitante *criaListaVisitante(void){
	Visitante*l=NULL;
	return l ;
}

void mostrarVisitante(Visitante*visitante){
    Visitante*cont;
    for(cont=visitante;cont!=NULL;cont=cont->prox){
        printf("\nNome: %s\nIdade: %d\nDoc: %s\n",cont->nome,cont->idade,cont->documento);
    }
}

Visitante * adicionarVisitante(Visitante *visitante, char documento[]){
	Visitante *novo = (Visitante*) malloc(sizeof(Visitante));
		if(novo == NULL){
		printf("Erro na alocacao");
		exit(1);
	}
	printf("Insira o nome\n");
	scanf(" %[^\n]s",novo->nome);
	limparBuffer();
	printf("Insira a idade\n");

	if(conferirAlfabeto(novo->nome) && scanf("%d",&novo->idade)>0 && novo->idade>0){
		limparBuffer();
	    char nomeTempNovo[100];
        strcpy(novo->nome,aumentaNome(novo->nome,nomeTempNovo));
        strcpy(novo->documento,documento);
        // ordenar
        Visitante*listaPrimeira = visitante;
        Visitante*auxiliar= NULL;
        
        while(listaPrimeira != NULL && strcmp(novo->nome, listaPrimeira->nome)>0){
            auxiliar = listaPrimeira;
            listaPrimeira = listaPrimeira->prox;
        }
        if(auxiliar == NULL){
            novo->prox = listaPrimeira;
            return novo;
        }
        auxiliar->prox = novo;
        novo->prox = listaPrimeira;
        return visitante;
	
	}else{
		free(novo);
		printf("\nCadastro nao realizado\n");
		return NULL;
	} 
}

Visitante *removerVisitante(Visitante*visitante){
	char documentoTemp[12];
	printf("\nDigite o documento do visitante que sera retirado: ");
	scanf(" %s",documentoTemp);
	limparBuffer();
	Visitante*ant= NULL;
	Visitante *contador;
	if(conferirDocumento(documentoTemp)){
		for(contador=visitante;contador!= NULL;contador=contador->prox){
			if(strcmp(contador->documento,documentoTemp)==0){
				break;
			}
            ant = contador;
		} 
			if (contador == NULL){
            printf("\nDocumento nao encontrado\n");
            return visitante;
			}
        if (ant == NULL) {
            visitante = contador->prox;
        }else{
            ant->prox = contador->prox;
        }
        free(contador);
        return visitante;
		}else{
			printf("\nVOCE DIGITOU DOCUMENTO INVALIDO\n");
			return visitante;
	}
	
}

Visitante* editarVisitante(Visitante*visitante){
	Visitante *contador;
	//
	char documentoTemp[12];
	printf("\nDigite o documento do visitante: ");
	scanf(" %s",documentoTemp);
	limparBuffer();
	if(conferirDocumento(documentoTemp) && documentoMin(documentoTemp)){
	for(contador=visitante;contador!=NULL;contador=contador->prox){
		if(strcmp(contador->documento,documentoTemp)==0 && contador!=NULL){
			return contador;
		}
	}
	}else{
		printf("\nDOCUMENTO INVALIDO\n");
		return NULL;
	}
	printf("\nDOCUMENTO INVALIDO\n");
	return NULL;
}

int menuEditar(Visitante * visitante, char docAnterior[]){
	char codigoMenu[2];
	codigoMenu[0]='1';
	while(codigoMenu[0] !='0'){
		printf("\n-----------------------\n");
		printf("Digite 1 - - - Atualizar nome\n");
		printf("Digite 2 - - - Atualizar idade\n");
		printf("Digite 3 - - - Atualizar documento\n");
		printf("Digite 0 - - - Sair deste Menu\n");
		scanf(" %s",codigoMenu);
		if(verificarEntradaChar(codigoMenu)){
			if(codigoMenu[0]=='0'){
				printf("\n\tSaindo deste Menu\n");
			}else if(codigoMenu[0]=='1'){
				alterarNome(visitante);
				return 0;
			}else if(codigoMenu[0]=='2'){
				alterarIdade(visitante);
				return 0;
			}else if(codigoMenu[0]=='3'){
				return 1;
			}else{
				printf("\n\tOpcao invalida\n");
			}
		}else{
			printf("\nCODIGO INVALIDO\n");
		}
	}
}

void alterarIdade(Visitante*visitante){
	int idadeTemp;
	printf("\nDigite a nova idade do visitante: ");
	if(scanf("%d",&idadeTemp)){
		limparBuffer();
			visitante->idade=idadeTemp;
	}else{
		idadeTemp=0;
		printf("\nIDADE INVALIDA\n");
	}
}

void alterarDocumento(Visitante*visitante, char docAnterior[]){
	if(conferirDocumento(docAnterior) && docUnico(visitante,docAnterior)){
		strcpy(visitante->documento,docAnterior);
	}else{
		docAnterior[0]='\0';
		printf("\nDOCUMENTO INVALIDO\n");
	}
}

void alterarNome(Visitante*visitante){
	char nomeTemp[100];
	printf("\nDigite o novo nome do visitante: ");
	scanf(" %[^\n]",nomeTemp);
	limparBuffer();
	if(conferirAlfabeto(nomeTemp)){
        strcpy(visitante->nome,aumentaNome(nomeTemp,visitante->nome));
	}else{
		printf("\nNOME INVALIDO\n");
	}
}

void buscarPeloNome(Visitante*visitante){
	char nomeRecebido[100];
	int numLiberarNomes=0;
	Visitante ** nomes=(Visitante**)malloc(sizeof(Visitante*));
	if(nomes==NULL){
		printf("Erro na alocacao do nome");
		exit(1);
	}
	//
	printf("\n------------------------------------\n");
	printf("Digite o nome que almeja buscar: ");
	scanf(" %[^\n]s",nomeRecebido);
	limparBuffer();
    strcpy(nomeRecebido,aumentaNome(nomeRecebido,nomeRecebido));
	//
	if(conferirAlfabeto(nomeRecebido)){
		Visitante * cont;
		for(cont=visitante;cont!=NULL;cont=cont->prox){
			 if (strcmp(nomeRecebido, cont->nome) == 0) {
                nomes = (Visitante**)realloc(nomes, (numLiberarNomes + 1) * sizeof(Visitante*));
                if (nomes == NULL) {
                    printf("Erro na realocacao do nome");
                    exit(1);
                }
                // Aloca memória para uma nova estrutura Visitante e copia os dados
                nomes[numLiberarNomes] = (Visitante*)malloc(sizeof(Visitante));
                if (nomes[numLiberarNomes] == NULL) {
                    printf("Erro na alocacao de memoria");
                    exit(1);
                }
                strcpy(nomes[numLiberarNomes]->nome, cont->nome);
                nomes[numLiberarNomes]->idade = cont->idade;
                strcpy(nomes[numLiberarNomes]->documento, cont->documento);
                numLiberarNomes++;
            }
		}
		if((numLiberarNomes)>0){
			int contador=0;
			for(contador=0;contador<numLiberarNomes;contador++){
				printf("\nNome: %s\nIdade: %d\nDoc: %s\n",nomes[contador]->nome,nomes[contador]->idade,nomes[contador]->documento);
			}		
		}else{
				printf("\n\tNao existe este nome no sistema\n");
			}
	}else{
		printf("\nVoce nao digitou um nome valido");
	} 
	int contador=0;
	for(contador=0;contador<(numLiberarNomes);contador++){
		free(nomes[contador]);
	}
	free(nomes);
}

int visitantesVazia(Visitante*visitante) {
    if (visitante == NULL) {
        return 0;
    } else {
        return 1;
    }
}

void liberarMemoriaVisitante(Visitante*visitante){
	Visitante *cont = visitante;
	for(cont=visitante;cont!=NULL;cont=cont->prox){
		free(cont);
	}
}

int docUnico(Visitante*visitante, char doc[]){
	Visitante*contador;
	for(contador=visitante;contador!=NULL;contador=contador->prox){
		if(strcmp(doc,contador->documento)==0){
			printf("\nNao cadastrado, documento ja existe\n");
			return 0;
		}
	}
	return 1;
}
Visitante *lerVisitante(Visitante *visitante, char *linha){
    Visitante *novoVisitante = (Visitante *)malloc(sizeof(Visitante));
    if (novoVisitante == NULL) {
        printf("Erro ao alocar memoria para o novo visitante.\n");
        exit(1);
    }
    // Ajustando a leitura dos dados da linha
    sscanf(linha, "%[^\t]%d\t%s", novoVisitante->nome, &novoVisitante->idade, novoVisitante->documento);
    novoVisitante->prox = NULL;

    if (visitante == NULL) {
        visitante = novoVisitante;
    } else {
        Visitante *ultimoVisitante = visitante;
        while (ultimoVisitante->prox != NULL) {
            ultimoVisitante = ultimoVisitante->prox;
        }
        ultimoVisitante->prox = novoVisitante;
    }
    return visitante; // Retornando lista de visitantes atualizada
}

void salvaVisitante(Visitante *visitante,FILE *arquivo_saida){
        while (visitante != NULL) {
            fprintf(arquivo_saida, "%s\t%d\t%s\n", visitante->nome, visitante->idade, visitante->documento);
            visitante = visitante->prox;
        }
}

int CompararLista(Visitante *visitante, Visitante *temp) {
    Visitante *atual = visitante;
    Visitante *temporario = temp;

    while (atual != NULL && temporario != NULL) {
		if (atual->documento != temporario->documento){
            return 0; 
		}
        atual = atual->prox;
        temporario = temporario->prox;
    }
	return 1;
}