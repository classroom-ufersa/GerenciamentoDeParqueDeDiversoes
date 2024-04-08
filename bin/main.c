#include "../include/atracao.h"

int main(){
    Atracoes*atracao=criaListaAtracao();
    int valorId=0;
    atracao = copiarArquivo(&atracao,&valorId);
    menuPrincipal(atracao,&valorId);
    return 0;
}