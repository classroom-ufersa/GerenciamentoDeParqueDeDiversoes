#include "../include/atracao.h"

struct atracao{
    int id;
    int capacidade;
    int quantidaVisitantes;
    char horarioFuncionamento[5];
    struct atracao  *prox;
    Visitante *visitantes;
};
//
Atracoes *criaListaAtracao(void) {
    Atracoes *l = NULL;
    return l;
} 

Atracoes *inserirAtracao(Atracoes *atracao, int *id) {
    int capacid = 0;
    char minutosDeFuncionamento[3], horasDeFuncionamento[3];
    Atracoes *novo = (Atracoes*) malloc(sizeof(Atracoes));
    if (novo == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return atracao;
    }

    printf("Insira a capacidade max da atracao:\n");
    char entradaCapacidade[100];
    int verifCapacidade = scanf(" %s", entradaCapacidade);
    limparBuffer();
    printf("Insira o horario de funcionamento da atracao:\n");
    printf("Digite a hora: ");
    scanf(" %3s",horasDeFuncionamento);
    limparBuffer();
    printf("Digite os minutos: ");
    scanf(" %3s",minutosDeFuncionamento);
    limparBuffer();
    
    if(conferirDocumento(horasDeFuncionamento) && conferirDocumento(minutosDeFuncionamento)){ 
        if(atoi(horasDeFuncionamento)>=0 && atoi(horasDeFuncionamento)<24 && atoi(minutosDeFuncionamento)>=0 && atoi(minutosDeFuncionamento)<=59 ){
            horarioFormatado(horasDeFuncionamento,minutosDeFuncionamento);
            strcpy(novo->horarioFuncionamento,horasDeFuncionamento);
            strcat(novo->horarioFuncionamento,":");
            strcat(novo->horarioFuncionamento,minutosDeFuncionamento);    
        }else{
            printf("\nHorario incorreto\n");
            free(novo);
            return atracao;  
        }
    } else{
        printf("\nHorario inserido de forma incorreta\n");
        free(novo);
        return atracao;    
    }

    if (verifCapacidade > 0 && conferirDocumento(entradaCapacidade)) {
            (*id)++;
            novo->id = (*id) + 9; 
            novo->visitantes = NULL; 
            novo->quantidaVisitantes=0;
            
            novo->capacidade=atoi(entradaCapacidade);
            
            
            Atracoes *listaPrimeira = atracao; 
            Atracoes *auxiliar = NULL;
            
            while (listaPrimeira != NULL && novo->id > listaPrimeira->id) {
                auxiliar = listaPrimeira;
                listaPrimeira = listaPrimeira->prox;
            }
            
            if (auxiliar == NULL) { 
                novo->prox = listaPrimeira;
                return novo;
            }
            
            auxiliar->prox = novo;
            novo->prox = listaPrimeira;
            return atracao;
        
    } else {
        printf("\n\tVoce digitou de forma incorreta os dados\n");
        free(novo);
        return atracao;
    }
}

int atracaoVazia(Atracoes *atracao) {
    if (atracao == NULL) {
        return 0;
    } else {
        return 1;
    }
}

Atracoes *removerAtracao(Atracoes *atracao) {
    int entradaId = 0;
    printf("\nDigite o ID da Atracao que sera retirada:\n");
    int verifEntrada = scanf("%d", &entradaId);
    limparBuffer();
    Atracoes *ant = NULL;
    Atracoes *contador;
    
    if (verifEntrada > 0) {
        for (contador = atracao; contador != NULL;contador = contador->prox) {
           if(entradaId == contador->id){
            break;
           }
            ant = contador;
        } 

        if (contador == NULL) {
            printf("\nId nao encontrado\n");
            return atracao;
        }
        
        if (ant == NULL) {
            atracao = contador->prox;
        } else {
            ant->prox = contador->prox;
        }
        listarAtracoes(atracao);
        liberarMemoriaVisitante(contador->visitantes);
        free(contador);
        return atracao;
    } else {
        printf("\nVOCE DIGITOU DOCUMENTO INVALIDO\n");
        return atracao;
    }
}

void listarAtracoes(Atracoes *atracao) {
    Atracoes *cont;
    if(atracao!=NULL){
    for (cont = atracao; cont != NULL; cont = cont->prox) {
        printf("\nAtracao: %d\tCapacidade: %d\tHorario de Funcionamento: %s\tQuatindade de Visitantes presentes: %d",
               cont->id, cont->capacidade, cont->horarioFuncionamento, cont->quantidaVisitantes);
               
    }
    }else{
        printf("LISTA VAZIA");
    }
}

void liberarListaAtracoes(Atracoes *atracao) {
    Atracoes *cont = atracao;
    for(cont=atracao;cont!=NULL;cont=cont->prox){
        free(cont);
    }
}

Atracoes *visitanteNaAtracao(Atracoes *atracao) {
    Atracoes* atracaoBuscada = buscaDeAtracao(atracao);
    if (atracaoBuscada != NULL) {
        if (atracaoBuscada->quantidaVisitantes == atracaoBuscada->capacidade) {
            printf("\nAtracao escolhida nao tem capacidade para mais visitantes\n");
        } else {
            char documento[12];
            if(documentoUnico(atracao,documento)){
                atracaoBuscada->visitantes=adicionarVisitante(atracaoBuscada->visitantes,documento);
                if(atracaoBuscada->visitantes!=NULL){
                    atracaoBuscada->quantidaVisitantes += 1;
                }
            }else{
                printf("\nDocumento incorreto \n");
                return atracao;
            }
        }
    } else {
        printf("\nAtracao nao encontrada ou ID invalido\n");
    }
    return atracao;
}  

Atracoes *buscaDeAtracao(Atracoes*atracao){
    int idEscolhido=0;
    listarAtracoes(atracao);
    printf("\nDigite o ID da atracao que voce almeja: ");
    if(scanf("%d",&idEscolhido)>0){ 
        limparBuffer();
        Atracoes*cont;
        for(cont=atracao;cont!=NULL;cont=cont->prox){
            if(cont->id==idEscolhido){
                return cont;
            }
        }
        printf("\n Id nao existe\n");
        return NULL;
    }else{
        limparBuffer();
        printf("\nDigite um ID válido\n");
        return NULL;
    }

}

void menuPrincipal(Atracoes *atracao, int *id){
    char codigoMenu[2];
    Atracoes*auxiliar=NULL; 
    int verificaAtracao=0,verificaVisitantes=0,verificarEntrada=0;
    while(codigoMenu[0]!='0'){
		printf("\n\tMENU\t\n");
		printf("Digite 1 - - - Adicionar Atracoes\n");
		printf("Digite 2 - - - Remover Atracoes\n");
		printf("------------------------------\n");
		printf("Digite 3 - - - Adicionar Visitante\n");
		printf("DIgite 4 - - - Editar informacoes de visitante\n");
		printf("Digite 5 - - - Remover visitante\n");
		printf("Digite 6 - - - Buscar visitante por nome\n");
		printf("------------------------------\n");
		printf("Digite 7 - - - Listar Atracoes e o numero de visitantes presentes\n");
		printf("------------------------------\n");
		printf("Digite 0 - - - Sair do programa\n");
        //
        printf("\nDigite o codigo: ");
        scanf(" %s",codigoMenu);
        verificarEntrada=verificarEntradaChar(codigoMenu);
        if(verificarEntrada==1){
            if(codigoMenu[0]=='0'){
                printf("\n\t---Fechando o Programa---\n");
                imprimirArquvivo(atracao);
                if(!atracaoVazia){
                    liberarListaAtracoes(atracao);
                    if(atracao->visitantes!=NULL){
                        liberarMemoriaVisitante(atracao->visitantes);
                    }
                }
            }else if(codigoMenu[0]=='1'){
                atracao=inserirAtracao(atracao,id);
                imprimirArquvivo(atracao);
            }else if(codigoMenu[0]=='2'){
                if(atracaoVazia(atracao)){
                    atracao=removerAtracao(atracao);
                    imprimirArquvivo(atracao);
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }
            }else if(codigoMenu[0]=='3'){
                // adicionar visitantes
                verificaAtracao=atracaoVazia(atracao); 
                if(verificaAtracao){
                    atracao=visitanteNaAtracao(atracao);
                    imprimirArquvivo(atracao);
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }
            }else if(codigoMenu[0]=='4'){
                // editar informacoes do visitante
                auxiliar=buscaDeAtracao(atracao);
                Visitante*auxVisitante=NULL;
                if(auxiliar!=NULL){
                    if(visitantesVazia(auxiliar->visitantes)){
                        char documento[12];
                        auxVisitante=editarVisitante(auxiliar->visitantes);
                        if(auxiliar->visitantes!=NULL){
                           int codMenuEditar=menuEditar(auxVisitante,documento);
                           if(codMenuEditar==1 && documentoUnico(atracao,documento)){
                                alterarDocumento(auxVisitante,documento);
                           }
                           imprimirArquvivo(atracao);
                    }
                    }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                    }
                }
            }else if(codigoMenu[0]=='5'){
                // remover visitante
                auxiliar=buscaDeAtracao(atracao);
                if(auxiliar!=NULL){
                    if(visitantesVazia(auxiliar->visitantes)){
                        Visitante*temp=auxiliar->visitantes;
                        auxiliar->visitantes=removerVisitante(auxiliar->visitantes);
                        if(CompararLista(auxiliar->visitantes,temp)){
                            auxiliar->quantidaVisitantes-=1;
                            imprimirArquvivo(atracao);  
                        }
                        
                    }
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }
            }else if(codigoMenu[0]=='6'){
                auxiliar=buscaDeAtracao(atracao);
                if(auxiliar!=NULL){
                    if(atracaoVazia(auxiliar)){
                        buscarPeloNome(auxiliar->visitantes);
                    }
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                }
            }else if(codigoMenu[0]=='7'){
                if(atracaoVazia(atracao)){
                    listarAtracoes(atracao);
                }else{
                    printf("\n\t---Nao e possivel acessar essa opcao do menu---\n");
                } 
            }else{
                printf("\n\tCodigo nao existe\n");
            }
        }else{
            codigoMenu[0]='\0';
            strcpy(codigoMenu,"9");
        }
    }
}

int visitantesVazios(Atracoes*atracao){
    Atracoes*cont;
    int totalAtracoes=0,vazios=0;
    for(cont=atracao;cont!=NULL;cont=cont->prox){
        vazios+=visitantesVazia(cont->visitantes);
        totalAtracoes++;
    }
    if(vazios!=0){
        return 0;
    }else{
        return 1;
    }
}
Atracoes *copiarArquivo(Atracoes **listaAtracoes, int *pontValorId) {
    Atracoes *atualAtracao; 
    FILE *arquivo_entrada = fopen("../test/relatorio.txt", "rt");
    char linha[200];
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    while (fgets(linha, sizeof(linha), arquivo_entrada)) {
        if (linha[0] >= '0' && linha[0] <= '9') { 
            atualAtracao = (Atracoes *)malloc(sizeof(Atracoes));
            if (atualAtracao == NULL) {
                printf("Erro ao alocar memória para a nova atração.\n");
                exit(1);
            }

            sscanf(linha, "%d\t%d\t%s", &atualAtracao->id, &atualAtracao->capacidade, atualAtracao->horarioFuncionamento);
            atualAtracao->visitantes = NULL;
            atualAtracao->prox = NULL;
            atualAtracao->quantidaVisitantes = 0;
            if (*listaAtracoes == NULL) {
                *listaAtracoes = atualAtracao;
            } else {
                Atracoes *ultimaAtracao = *listaAtracoes;
                while (ultimaAtracao->prox != NULL) {
                    ultimaAtracao = ultimaAtracao->prox;
                }
                ultimaAtracao->prox = atualAtracao;
            }
            *pontValorId = atualAtracao->id;
        } else { 
            if (atualAtracao == NULL) {
                printf("Erro: Visitante encontrado antes de uma atracao.\n");
                exit(1);
            }
            atualAtracao->visitantes = lerVisitante(atualAtracao->visitantes, linha);
            atualAtracao->quantidaVisitantes++;
            
        }
    }
    fclose(arquivo_entrada);
    return *listaAtracoes;
}


void imprimirArquvivo(Atracoes *listaAtracoes) {
    FILE *arquivo_saida = fopen("../test/relatorio.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        exit(1);
    }
    
    Atracoes *atualAtracao = listaAtracoes;
    while (atualAtracao != NULL) {
        fprintf(arquivo_saida, "%d\t%d\t%s\n", atualAtracao->id, atualAtracao->capacidade, atualAtracao->horarioFuncionamento);
        salvaVisitante(atualAtracao->visitantes,arquivo_saida);
        atualAtracao = atualAtracao->prox;
    }
    
    fclose(arquivo_saida);
}

int documentoUnico(Atracoes*atracao,char documento[]){
    Atracoes*cont;
    printf("Insira o Documento\n");
	scanf(" %s",documento);
	limparBuffer();
    if(documentoMin(documento) && conferirDocumento(documento)){
        for(cont=atracao;cont!=NULL;cont=cont->prox){
            Visitante*contadorVisitante=cont->visitantes;
            if(docUnico(cont->visitantes,documento)==0){
                return 0;
            }
        }
    }else{
        return 0;
    }

    return 1;
}