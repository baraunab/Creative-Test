#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// variaveis globais
#define MAX 256

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
void menu();
void criar_ficha();

// funções
void menu() {
    int opcao = 1;
    /* * * * * * * * * * * * * * * *
     *  TITULO E VERSÃO DO PROJETO *
     * * * * * * * * * * * * * * * */
    printf("\n\t\tCREATIVE TEST V 1.1.2");
    printf("\n\t1 - CRIAR FICHA");
    printf("\n\t2 - EXIBIR FICHA");
    printf("\n\t0 - SAIR");
    
    printf("\n\nEscolha: \n> ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1: 
            system("clear");
            printf("\n\t\tCRIAR FICHA\n");
            criar_ficha();
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

void criar_ficha () { 
    // abertura do arquivo e dados para ficha
    FILE *arquivo = fopen("ficha.txt", "w");
    Dados dados = {0};
    
    if (arquivo == NULL) {
        printf("erro na abertura de arquivo");
        return;
    }

    printf("\n\tJOGADOR: ");
    fgets(dados.jogador, MAX, stdin);
    printf("\n\tNOME: ");
    fgets(dados.nome, MAX, stdin);
    printf("\n\tIDADE: ");
    scanf("%d", &dados.idade);
    getchar();
    printf("\n\tPROFISSÃO: ");
    fgets(dados.profissao, MAX, stdin);
    printf("\n\tLOCAL DE NASC.: ");
    fgets(dados.local_nasc, MAX, stdin);
	printf ("\nPERSONALIDADE - DESCREVA COMO O SEU PERSONAGEM É, FALE SOBRE SUAS CARACTERÍSTICAS E INFORMAÇÕES RELEVANTES!\n");
    fgets(dados.personalidade, MAX, stdin);
  	
    printf ("\n\n\nDESEJA ADICIONAR MAIS INFORMAÇÕES?\n\nSIM - 1 \t NÃO - 2\n> "); 

    int opcao = 0;
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1){
        printf("\nANOTAÇÕES ADICIONAIS: ");
		fgets(dados.anotacoes,MAX,stdin);
        printf ("\n\nSUA FICHA ESTÁ PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS!! :D\n> ");
        getchar();
	} else {
        printf ("\n\nSUA FICHA ESTÁ PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS!! :D\n> ");
        getchar();
	}

    fprintf(arquivo,"\n\t* * * * * * * * \n ");
    fprintf(arquivo,"\t*             * PLAYER: %s", dados.jogador);
    fprintf(arquivo,"\t*      o      * NOME: %s", dados.nome);  
    fprintf(arquivo,"\t*     /l>     * IDADE: %d\n", dados.idade); 
    fprintf(arquivo,"\t*     / |     * PROFISSÃO: %s", dados.profissao);
    fprintf(arquivo,"\t*             * LOCAL DE NASC.: %s", dados.local_nasc);
    fprintf(arquivo,"\t* * * * * * * * ");
    fprintf(arquivo, "\n\n\tPERSONALIDADE: \n\t - %s", dados.personalidade);
    if (opcao == 1){
        fprintf(arquivo,"\n\tANOTAÇÕES ADICIONAIS: \n\t - %s", dados.anotacoes);
    }
    
    fclose(arquivo);
    
    system("clear");
    menu();
}


// função principal
int main () {
    // definindo linguagem pt-br
    setlocale(LC_ALL, "Portuguese");
    
    // menu de opcoes
    system("clear");
    menu();
     
}
