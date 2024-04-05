#include "outrasFuncoes.h"

int verificarEntradaChar(char entrada[]){
    if(strlen(entrada)==1){
        return 1;
    }else{
		limparBuffer();
        return 0;
    }
}

char *aumentaNome(char palavra[100],char novaPalavra[100]){
	int tamanho = strlen(palavra);
    int cont = 0;
    while (cont < tamanho) {
        novaPalavra[cont] = toupper(palavra[cont]);
        cont++;
    }
    novaPalavra[cont] = '\0';
    return novaPalavra;
}

int conferirDocumento(char documento[]){
	int tamanho=strlen(documento);
	int cont=0;
	while(cont<tamanho){
		if(!isdigit(documento[cont])){
			printf("\nERRO, insira apenas numero\n");
			return 0;
		}
		cont++;
	}
	return 1;
} 

int conferirAlfabeto(char palavra[]){
	int tamanho=strlen(palavra);
	int cont=0;
	while(cont<tamanho){
		if(isalpha(palavra[cont])==0 && palavra[cont]!=' '){
			printf("\nERRO, insira apenas caracteres do alfabeto\n");
			return 0;
		}
		cont++;
	}
	return 1;
}

void limparBuffer() {
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != '\0');
}

int documentoMin(char doc[]){
	int tamanho=strlen(doc);
	int contador=0;
	if(tamanho<8 && tamanho>12){
		printf("\nDocumento invalido -(poucos digitos)\n");
		return 0;
	}
	return 1;
}

int tamanhoHorarioMin(char horas[], char min[]){
	int tamanhoHoras=strlen(horas);
	int tamanhoMin=strlen(min);
	if(tamanhoHoras>2 && tamanhoMin>2){
		return 0;
	}
	return 1;
}

void horarioFormatado(char horasDeFuncionamento[], char minutosDeFuncionamento[]) {
    
    if (strlen(horasDeFuncionamento)<2) {
        char copia = horasDeFuncionamento[0];
        horasDeFuncionamento[0] = '0';
        horasDeFuncionamento[1] = copia;
		horasDeFuncionamento[2] = '\0';
    }

    if (strlen(minutosDeFuncionamento)<2) {
        char copia = minutosDeFuncionamento[0];
        minutosDeFuncionamento[0] = '0';
        minutosDeFuncionamento[1] = copia;
		minutosDeFuncionamento[2] = '\0';
    }
}
