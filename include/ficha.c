#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#include "ficha.h"


// menu de opcao
void menu() {
   
    system("clear");
    int opcao;
    /* * * * * * * * * * * * * * * *
     *  TITULO E VERSÃO DO PROJETO *
     * * * * * * * * * * * * * * * */
    printf("\n\t\tCREATIVE TEST V 1.2.0");
    printf("\n\t1 - CRIAR FICHA");
    printf("\n\t2 - EXIBIR FICHA");
    printf("\n\t0 - SAIR");
    
    printf("\n\nEscolha: \n> ");
    opcao = int_input(); 

    switch (opcao) {
        case 1: // criacao da ficha 
           criar_ficha();
           break;

        case 2: // exibicao da ficha
            ler_ficha();
            break;

        case 0: // sair do programa
            system("clear");
            printf("\ntchauu !\n");
            exit(0);
            break;
        
        default: // pega opcao errada e retorna ao menu
            printf("opção inválida!\n");
            sleep(1);
            menu();
            
    }

}

// funcao para entrada de int
int int_input() {
    char entrada[MAX]; // recebe numero como char
    int opcao; // recebe char convertido em int

    fgets(entrada, MAX, stdin);
    opcao = atoi(entrada);

    // retorna int
    return opcao;

}

// funcao de criar ficha
void criar_ficha () { 
    // abertura do arquivo e dados para ficha
    FILE *arquivo = fopen("ficha.txt", "w"); // arquivo da ficha
    Dados dados = {0}; // estrutura com dados da ficha
    
    // verifica abertura de arquivo
    if (arquivo == NULL) {
        printf("erro na abertura de arquivo");
        return;
    }
    
    // entrada de dados
    system("clear");
    printf("\n\t\tCRIAR FICHA\n");
    printf("\n\tJOGADOR: ");
    fgets(dados.jogador, MAX, stdin);
    printf("\n\tNOME: ");
    fgets(dados.nome, MAX, stdin);
    printf("\n\tIDADE: ");
    dados.idade = int_input();
    printf("\n\tPROFISSÃO: ");
    fgets(dados.profissao, MAX, stdin);
    printf("\n\tLOCAL DE NASC.: ");
    fgets(dados.local_nasc, MAX, stdin);
	printf ("\nPERSONALIDADE - DESCREVA COMO O SEU PERSONAGEM É, FALE SOBRE SUAS CARACTERÍSTICAS E INFORMAÇÕES RELEVANTES!\n");
    fgets(dados.personalidade, MAX, stdin);
  	
    // verifica se o usuario deseja uma espaco a mais para adicionar anotacoes
    printf ("\n\n\nDESEJA ADICIONAR MAIS INFORMAÇÕES?\n\nSIM - 1 \t NÃO - 2\n> "); 

    int opcao = int_input();

    if (opcao == 1){
        printf("\nANOTAÇÕES ADICIONAIS: ");
		fgets(dados.anotacoes,MAX,stdin);
	}
        
    // adicao das informacoes no arquivo
    fprintf(arquivo,"\n\t* * * * * * * * \n ");
    fprintf(arquivo,"\t*             * PLAYER: %s", dados.jogador);
    fprintf(arquivo,"\t*      o      * NOME: %s", dados.nome);  
    fprintf(arquivo,"\t*     /l>     * IDADE: %d\n", dados.idade); 
    fprintf(arquivo,"\t*     / |     * PROFISSÃO: %s", dados.profissao);
    fprintf(arquivo,"\t*             * LOCAL DE NASC.: %s", dados.local_nasc);
    fprintf(arquivo,"\t* * * * * * * * ");
    fprintf(arquivo, "\n\n\tPERSONALIDADE: \n\t - %s", dados.personalidade);

    // verifica se ha anotacoes adicionais
    if (opcao == 1){
        fprintf(arquivo,"\n\tANOTAÇÕES ADICIONAIS: \n\t - %s", dados.anotacoes);
    }
    
    fclose(arquivo); // fecha arquivo
    
    // volta para o menu
    printf ("\n\nSUA FICHA ESTÁ PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS!! :D\n> ");    
    getchar();
    menu();
 
}

// funcao para exbir a ficha para o usuario
void ler_ficha () {

    FILE *arquivo = fopen("ficha.txt", "r"); // arquivo a ser lido
    char *linha = NULL; // guarda cada linha do arquivo
    size_t tam = 0; // tamanho da linha 
    ssize_t leitura; // recebe a funcao getline

    // verifica a abertura do arquivo
    if (arquivo == NULL) {
        printf("ler_ficha - erro na abertura de arquivo");
        return;
    }
    
    // limpa a tela para exibir a ficha
    system("clear");
    printf("\n\t\tEXIBIR FICHA\n");

    // usa funcao getline no arquivo
    while ((leitura = getline(&linha, &tam, arquivo)) != -1) {\
        // printa a linha que esta lida
        printf("%s", linha);
    }

    free(linha); // libera variavel que estava recebendo linhas
    fclose(arquivo); // fecha arquivo
    
    // volta para o menu
    printf("\n\n> ");
    getchar();
    menu();

}


