#ifndef FICHA_H
#define FICHA_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

// variaveis globais
#define MAX 256

#ifdef __linux__
#define CLEAR() system("clear")

#else
#define CLEAR() system("cls")

#endif 

// estruturas
typedef struct {
    char jogador[MAX];
    char nome[MAX];
    int idade;
    char profissao[MAX];
    char local_nasc[MAX];
    char personalidade[MAX];
    char anotacoes[MAX];
} Dados;

// prototipacao de funções
void menu(); // menu de escolhas
int int_input(); // recebe input de int por meio de fgets e converte com atoi
void criar_ficha(); // cria arquivo de ficha do personagem
void ler_ficha(); // le o arquivo de ficha e mostra no terminal

#endif // FICHA_H
