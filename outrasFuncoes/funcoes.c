#include "funcoes.h"
#include "atracao.h"
#include "visitantes.h"
#include <stdio.h>

void menuPrincipal(void){
    char codigoMenu[2];
    int verificaAtracao=0,verificaVisitantes=0;
	while(codigoMenu!='0'){
		printf("\n\tMENU\t\n");
		printf("\nDigite 1 - - - Adicionar Atracoes");
		printf("\nDigite 2 - - - Remover Atracoes");
		printf("\n------------------------------");
		printf("\nDigite 3 - - - Adicionar Visitante");
		printf("\nDIgite 4 - - - Editar informacoes de visitante");
		printf("\nDigite 5 - - - Remover visitante");
		printf("\nDigite 6 - - - Buscar visitante por nome");
		printf("\n------------------------------");
		printf("\nDigite 7 - - - Listar Atracoes e o numero de visitantes presentes");
		printf("\n------------------------------");
		printf("\nDigite 0 - - - Sair do programa");
        //
        printf("\n\nDigite o codigo: ");
        scanf(" %s",&codigoMenu);
        //
        int verificaEntrada=verificarEntradaChar(codigoMenu);
        //
        if(verificaEntrada){
            if(codigoMenu=='0'){
                printf("\n\t---Fechando o Programa---\n");
            }else if(codigoMenu=='1'){
                // adicionar atraoes

            }else if(codigoMenu=='2'){
                // remover atracoes
                verificaAtracao=atracaoVazia(); 
                if(verificaAtracao != 0){
                    // se tiver atracao cadastrada
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }

            }else if(codigoMenu=='3'){
                // adicionar visitantes
                verificaAtracao=atracaoVazia(); 
                if(verificaAtracao != 0){
                    // se tiver visitantes cadastrada
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }

            }else if(codigoMenu=='4'){
                // editar informacoes do visitante
                verificaVisitantes=visitantesVazia(); 
                if(verificaVisitantes != 0){
                    // se tiver visitantes cadastrada
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }
                
            }else if(codigoMenu=='5'){
                // remover visitantes
                verificaVisitantes=visitantesVazia(); 
                if(verificaVisitantes != 0){
                    // se tiver visitantes cadastrada
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }

            }else if(codigoMenu=='6'){
                // buscar visitantes por nome
                verificaVisitantes=visitantesVazia(); 
                if(verificaVisitantes!= 0){
                    // se tiver visitantes cadastrada
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }

            }else if(codigoMenu=='7'){
                // listar atracoes e o numero de visitantes presentes
                verificaAtracao=atracaoVazia(); 
                if(verificaAtracao != 0){
                    // se tiver atracao cadastrada
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }

            }else{
                printf("\n\tCodigo nao existe\n");
            }
        }else{
            codigoMenu[1]='\0';
            codigoMenu[0]='9';
        }
    }
}

int verificarEntradaChar(char entrada[]){
    if(strlen(entrada)==1){
        return 1;
    }else{
		    limpaBuffer();
        return 0;
    }
}

void limpaBuffer(void){
    int guardado=0;
    while((guardado!=getchar())!= '\n' && guardado!=EOF ){

    }
}