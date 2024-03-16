#include "funcoes.h"
#include "atracao.h"
#include "visitantes.h"

void menuPrincipal(void){
    char codigoMenu;
    int verificaAtracao=0,verificaVisitantes=0;
	while(codigoMenu!='0'){
		printf("\n\tMENU\t\n");
		printf("\nDigite 1 - - - Adicionar Atracoes\n");
		printf("\nDigite 2 - - - Remover Atracoes\n");
		printf("\n------------------------------\n");
		printf("\nDigite 3 - - - Adicionar Visitante\n");
		printf("\nDIgite 4 - - - Editar informacoes de visitante\n");
		printf("\nDigite 5 - - - Remover visitante\n");
		printf("\nDigite 6 - - - Buscar visitante por nome\n");
		printf("\n------------------------------\n");
		printf("\nDigite 7 - - - Listar Atracoes e o numero de visitantes presentes\n");
		printf("\n------------------------------\n");
		printf("\nDigite 0 - - - Sair do programa\n");
        //
        printf("\n\nDigite o codigo: ");
        scanf(" %c",&codigoMenu);
        if(codigoMenu=='0'){
            printf("\n\t---Fechando o Programa---\n");
            // colocar a funcao de escrever atracoes no arquivo
            // colocar a funcao de escrever visitantes no arquivo
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
    }
}