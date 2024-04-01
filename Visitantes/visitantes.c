#include "atracao.h"
#include "visitantes.h"
#include "ctype.h"
#include <stdio.h>
#include <stdlib.h>

struct visitantes{
    char nome[100];
    int idade;
    char documento[12];
    struct visitantes * prox;
};


Visitante *criaLista(void){
	Visitante*l=NULL;
	return l ;
}

Visitante * adicionarVisitante(Visitante *visitante){
	Visitante *novo = (Visitante*) malloc(sizeof(Visitante));
		if(novo == NULL){
		printf("Erro na alocacao");
		exit(1);
	}
	printf("Insira o nome\n");
	scanf(" %[^\n]s",novo->nome);
	printf("Insira o Documento\n");
	scanf(" %s",novo->documento);
	printf("Insira a idade\n");

	if(conferirAlfabeto(novo->nome) && conferirDocumento(novo->documento) && scanf("%d",&novo->idade) && docUnico(visitante,novo->documento) && novo->idade>0){
	
        char nomeTempNovo[100];
        strcpy(novo->nome,aumentaNome(novo->nome,nomeTempNovo));

        // funcao para add visitante em tal atracao
        //visitanteNaAtracao(novo,atracao);
        
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
		return visitante;
		//adicionarVisitante(visitante);
	} 
}

Visitante *removerVisitante(Visitante*visitante){
	char documentoTemp[12];
	printf("\nDigite o documento do visitante que sera retirado: ");
	scanf(" %s",documentoTemp);
	//limpaBuffer();
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

void editarVisitante(Visitante*visitante){
	Visitante *contador;
	//
	char docTemp[100];
	printf("\nDigite o documento do usuario: ");
	scanf(" %[^\n]s",docTemp);
	if(conferirDocumento(docTemp)){
		// usar busca pelo doc
		for(contador=visitante;contador!=NULL;contador=contador->prox){
			if(strcmp(contador->documento,docTemp)==0){
				printf("a");
				menuEditar(contador);
			}
		}
	}else{
		printf("\nNOME INVALIDO ERRADO\n");
		docTemp[0]='\0';
		editarVisitante(visitante);
	}
}

void menuEditar(Visitante * visitante){
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
			}else if(codigoMenu[0]=='2'){
				alterarIdade(visitante);
			}else if(codigoMenu[0]=='3'){
				alterarDocumento(visitante);
			}else{
				printf("\n\tOpcao invalida\n");
			}
		}else{
			printf("\nCODIGO INVALIDO\n");
		}
	}
}


void alterarNome(Visitante*visitante){
	char nomeTemp[100];
	printf("\nDigite o novo nome do visitante: ");
	scanf(" %[^\n]",nomeTemp);
	//limparBuffer();
	if(conferirAlfabeto(nomeTemp)){
        strcpy(visitante->nome,aumentaNome(nomeTemp,visitante->nome));
	}else{
		printf("\nNOME INVALIDO\n");
	}
}

void alterarIdade(Visitante*visitante){
	int idadeTemp;
	printf("\nDigite a nova idade do visitante: ");
	if(scanf("%d",&idadeTemp)){
		visitante->idade=idadeTemp;
	}else{
		idadeTemp=0;
		printf("\nIDADE INVALIDA\n");
		alterarIdade(visitante);
	}
}

void alterarDocumento(Visitante*visitante){
	char documentoTemp[12];
	printf("\nDigite o novo documento do visitante: ");
	scanf(" %s",documentoTemp);
	//limparBuffer();
	if(conferirDocumento(documentoTemp)){
		strcpy(visitante->documento,documentoTemp);
	}else{
		documentoTemp[0]='\0';
		printf("\nDOCUMENTO INVALIDO\n");
		alterarDocumento(visitante);
	}
}

int docUnico(Visitante*visitante, char doc[]){
	Visitante*contador;
	for(contador=visitante;contador!=NULL;contador=contador->prox){
		if(strcmp(doc,contador->documento)==0){
			return 0;
		}
	}
	return 1;
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
	fflush(stdin);
  strcpy(nomeRecebido,aumentaNome(nomeRecebido,nomeRecebido));
	//limpaBuffer();
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

