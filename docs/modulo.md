#Módulo OutrasFunções

Esse módulo serviu para separar as funções utilizadas em todo o programa, seus cabeçalhos são:

```c
//função que verifica se existe apenas um caractere
int verificarEntradaChar(char entrada[]);

//função que transforma os nomes em maiusculo
char *aumentaNome(char palavra[100],char novaPalavra[100]);

//função que verifica se tem apenas números no documento
int conferirDocumento(char documento[]);

//função que verifica se tem apenas caracteres do alfabeto no nome
int conferirAlfabeto(char palavra[]);

//função que auxilia a liberação da memória
void limparBuffer();

//função que verifica se o tamanho do documento menor que 8
int documentoMin(char doc[]);

//função que impede do usuário de colocar mais de 2 valores nas horas e minutos
int tamanhoHorarioMin(char horas[], char min[]);

//função que formata as horas e minutos inseridos
void horarioFormatado(char horasDeFuncionamento[],char minutosDeFuncionamento[]);

```