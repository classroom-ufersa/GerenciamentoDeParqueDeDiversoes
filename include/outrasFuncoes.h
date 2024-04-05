#ifndef OUTRASFUNCOES
#define OUTRASFUNCOES

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int verificarEntradaChar(char entrada[]);

char *aumentaNome(char palavra[100],char novaPalavra[100]);

int conferirDocumento(char documento[]);

int conferirAlfabeto(char palavra[]);

void limparBuffer();

int documentoMin(char doc[]);

int tamanhoHorarioMin(char horas[], char min[]);


void horarioFormatado(char horasDeFuncionamento[],char minutosDeFuncionamento[]);

#endif
