#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// variaveis globais
#define MAX 256

// estruturas
typedef struct {
    char jogador[MAX];
    char nome[MAX];
    char profissao[MAX];
    char local_nasc[MAX];
    char personalidade[MAX];
    char anotacoes[MAX];
} Dados;

// prototipacao de funções
void menu();

// funções
void menu() {
    int opcao = 1;
    system("clear");
    /* * * * * * * * * * * * * * * *
     *  TITULO E VERSÃO DO PROJETO *
     * * * * * * * * * * * * * * * */
    printf("\n\t\tCREATIVE TEST V 1.1.1");
    printf("\n\t1 - CRIAR FICHA");
    printf("\n\t2 - EXIBIR FICHA");
    printf("\n\t0 - SAIR");
    
    printf("\n\nEscolha: \n> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: 
            system("clear");
            printf("\n\t\tCRIAR FICHA\n");
            break;

        case 2: 
            system("clear");
            printf("\n\t\tEXIBIR FICHA\n");
            break;

        case 0:
            system("clear");
            printf("\ntchauu !\n");
            return;
        
        default:
            printf("opção inválida! tente novamente...\n> ");
            getchar();
            getchar();
            menu(opcao);
    }

}

// função principal
int main () {
    // definindo linguagem pt-br
    setlocale(LC_ALL, "Portuguese");

    // abertura do arquivo e dados para ficha
    FILE *arquivo = fopen("ficha.txt", "w");
    Dados dados = {0};
    
    if (arquivo == NULL) {
        printf("erro na abertura de arquivo");
        return 1;
    }
    
    // menu de opcoes
    menu();
     
    fclose(arquivo);
}
