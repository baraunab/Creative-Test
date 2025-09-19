#include<stdio.h>
#include <stdlib.h>
#include<locale.h>

int main ()
{   
    FILE*rpg;
    rpg=fopen("arquivo.txt", "w");
    if(rpg==NULL){
        printf("falha na abertura");
        return 1;
    }
    int numero, id, esc;
    char nome[100], prof[100], jog[100], nasc[100], res[100], perso[500], anot[500];
 	setlocale(LC_ALL,"portuguese");   
    printf("\n\n\t\tBEM VINDO A SUA FICHA DE RPG :) \n\n");
    printf("\t\tESCOLHA UMA DAS OPÇÕES ABAIXO PARA INICIAR: \n\n");
    printf ("\t1- INICIAR FICHA \n");
    printf ("\t2- SAIR\n");
    printf ("\t3- SOBRE\n");
    printf ("\t4- VEJA O MODELO DA FICHA\n");
    
	scanf ("%d",&numero);
    switch(numero)
    {
        case 1:
	    system ("cls");
        printf ("\n\tINSIRA OS DADOS DO SEU PERSONAGEM!!\n\n\tUSE SUA CRIATIVIDADE :D\n\n");
        printf("PLAYER: ");
        fflush(stdin);
        fgets(jog,100,stdin);
        printf("NOME: ");
        fflush(stdin);
        fgets(nome,100,stdin);
        printf ("IDADE: ");
        fflush(stdin);
        scanf ("%d",&id);
		printf ("PROFISSÃO: ");
		fflush(stdin);
		fgets(prof,100,stdin);
		printf ("LOCAL DE NASC.: ");
		fflush(stdin);
		fgets(nasc,100,stdin);
		printf ("LOCAL DE RESIDÊNCIA: ");
		fflush(stdin);
		fgets(res,100,stdin);
		printf ("\nPERSONALIDADE - DESCREVA COMO O SEU PERSONAGEM É, FALE SOBRE SUAS CARACTERÍSTICAS E INFORMAÇÕES RELEVANTES!\n");
		fflush(stdin);
		fgets(perso,500,stdin);
		
		printf ("\n\n\nDESEJA ADICIONAR MAIS INFORMAÇÕES?\n\nSIM - 1 \t NÃO - 2\n");
		scanf("%d",&esc);
		if (esc==1){
            printf("\nANOTAÇÕES ADICIONAIS: ");
			fflush(stdin);
			fgets(anot,500,stdin);            }
            else if (esc==2){
                printf ("\n\nSUA FICHA ESTÁ PRONTA!! ACESSE SEUS ARQUIVOS PARA CONFERIR OS DADOS!");
		}
		
		fprintf(rpg,"\n\t * * * * * * * * \n ");
        fprintf(rpg,"\t*\t\t * PLAYER: %s", jog);
        fprintf(rpg,"\t*\t o\t * NOME: %s",nome);  
        fprintf(rpg,"\t*\t/l>\t * IDADE: %d\n", id); 
        fprintf(rpg,"\t*\t/ |\t * PROFISSÃO: %s", prof);
        fprintf(rpg,"\t*\t\t * LOCAL DE NASC.: %s", nasc);
        fprintf(rpg,"\t*\t\t * LOCAL DE RESIDÊNCIA: %s", res);
        fprintf(rpg,"\t * * * * * * * * ");
        fprintf(rpg, "\n\n\tPERSONALIDADE: \n\t - %s", perso);
        if (esc==1){
        	fprintf(rpg,"\n\tANOTAÇÕES ADICIONAIS: \n\t - %s", anot);
		}
		system("cls");
		
		printf ("\n\tSUA FICHA  ESTÁ PRONTA!\n");
		
        break;
        case 2:
        system ("cls");
        printf("\n\tATÉ LOGO :) ");
        system ("PAUSE");
        break;
        case 3:
        system ("cls");
        printf ("\n\t- OBJETIVO: \n\tESSE SOFTWARE FOI DESENVOLVIDO COM O OBJETIVO DE CRIAR UMA FICHA DE INFORMAÇÕES DO SEU OC (PERSONAGEM ORIGINAL)! \nADICIONE DADOS SOBRE SUA CRIAÇÃO E ACESSE SEUS ARQUIVOS PARA VERIFICAR O ARQUIVO DE TEXTO \nCRIADO POR ESSE PROGRAMA!");
        printf ("\n\n\tCASO ESTEJA COM DÚVIDAS SOBRE O QUE TIPOS DE DADOS COLOCAR, \nVEJA UM EXEMPLO A SEGUIR DA FICHA DE UM PERSONAGEM ORIGINAL \nDE UM DOS DESENVOLVEDORES DO SISTEMA :D");
		printf("\t * * * * * * * *  \n");
        printf("\t*\t\t * PLAYER: WILL \n");
        printf("\t*\t o\t * NOME: SOL\n");
        printf("\t*\t/l>\t * IDADE: 12\n");
        printf("\t*\t/ |\t * PROFISSÃO: DESIGNER\n");
        printf("\t*\t\t * LOCAL DE NASC.: BRASIL\n");
        printf("\t*\t\t * LOCAL DE RESIDÊNCIA: IFAM\n");
        printf("\t * * * * * * * * ");
        printf("\n\n\t PERSONALIDADE: SOL É UM GAROTO MUITO GENTIL (PERTO DE SEUS AMIGOS)\n");
        printf("\n\n\t ANOTAÇÕES ADICIONAIS: SOL GOSTA DE AMARELO E LER LIVROS\n");
        printf("\n\npressione ENTER para continuar...");
        getchar();
        printf("\n\t- INSPIRAÇÃO:\nESSE SOFTWARE SE INSPIROU EM UM ESTILO DE JOGO CHAMADO 'RPG DE MESA', \nONDE TODOS OS OS JOGADORES POSSUEM UM PERSONAGEM E UMA FICHA SOBRE ELE \nCOM INFORMAÇÕES SOBRE AS CARACTERÍSTICAS E HABILIDADES QUE ELES PODEM \nUTILIZAR NESSE UNIVERSO FICTÍCIO, DESCREVENDO AS SUAS AÇÕES APENAS POR \nMEIO DE DIÁLOGOS QUE OCORRE ENTRE OS JOGADORES E O NARRADOR DA HISTÓRIA.\n\nUSANDO ESSE ESTILO DE JOGO, NOSSA IDEIA É PROPOR UM MODELO MAIS SIMPLIFICADO \nDESSA FICHA DE RPG PARA ");
		break;
         case 4:
        system ("cls");
        printf ("\n\tESSE É O MODELO DA SUA FICHA!\n\n");
        printf("\t * * * * * * * *  \n");
        printf("\t*\t\t * PLAYER: \n");
        printf("\t*\t o\t * NOME: \n");
        printf("\t*\t/l>\t * IDADE: \n");
        printf("\t*\t/ |\t * PROFISSÃO: \n");
        printf("\t*\t\t * LOCAL DE NASC.: \n");
        printf("\t*\t\t * LOCAL DE RESIDÊNCIA:\n");
        printf("\t * * * * * * * * ");
        printf("\n\n\t PERSONALIDADE: \n");
        printf("\n\n\t ANOTAÇÕES ADICIONAIS: \n");
    }
    
    return 0;
}


