#include <stdio.h> // Biblioteca de entrada e saída de dados
#include <stdlib.h> // Biblioteca de conversão das strings
#include <conio.h> // Biblioteca de manipulação de caracteres
#include <locale.h> // Biblioteca de acentuação de caracteres
#include <windows.h> // Biblioteca dos códigos do cmd

int a,b,L,L2; // Declaração das váriaveis das setas
int co,co2,co_f,co_i,L3,L4; // Novas declarações do menu

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main() {
	
	FILE* rpg;
    rpg=fopen("arquivo ficha.txt", "w");
    if(rpg==NULL){
    printf("falha na abertura");
    return 1;
    }			
    int numero, id, esc;
    char nome[100], prof[100], jog[100], nasc[100], res[100], perso[500], anot[500];
    /* MENU */
    int opcao;
    setlocale(LC_ALL, "Portuguese"); // Definindo português como linguagem padrão
    SetConsoleTitle("Creative Test"); // Título do programa
    co=3;       //co é a coluna onde colocar a barra//
    L=23;b=1;   //L é a linha onde fica as opções//
    co2=co;     //*co2 é onde estava a barra *//
    co_f=co+69;  //co_f é a coluna final do menu  precisa ver o valor certo aqui é 69  já no seu não sei//
    co_i=co;     //co_i é a coluna de inicio do menu//
    do{
        inicio:
        opcao=0;
        system("cls"); // Limpar a tela dos comandos anteriores
        system("color 1F"); // Definindo a cor do fundo e a letra no cmd
        printf("Dica: Precione a tecla ESC a qualquer momento para voltar para o menu principal!\n\nA nossa interface é interativa, então para selecionar a opção desejada você deve usar as setas do teclado e o botão ENTER para clicar na opção que quiser :D " );


        gotoxy(15,11); printf("=======  ======   =======       /\\     ========  ==  \\        /  =======");
        gotoxy(15,12); printf("||       ||    =  ||           /  \\       ||     ||   \\      /   ||");
        gotoxy(15,13); printf("||       ||= = =  =======     /====\\      ||     ||    \\    /    =======");
        gotoxy(15,14); printf("||       ||  =    ||         /      \\     ||     ||     \\  /     ||");
        gotoxy(15,15); printf("=======  ||    =  =======   /        \\    ||     ||      \\/      =======");

        gotoxy(12,17); printf("========  =======  =======   ========");
        gotoxy(12,18); printf("   ||     ||       ||           ||");
        gotoxy(12,19); printf("   ||     =======  =======      ||");
        gotoxy(12,20); printf("   ||     ||            ||      ||");
        gotoxy(12,21); printf("   ||     =======  ======       ||");

        gotoxy(2,24);   printf("INICIAR");
        gotoxy(17,24);  printf("SAIR");
        gotoxy(33,24);  printf("MODELO FICHA");
        gotoxy(60,24);  printf("SOBRE");
        
        opcao=0;
        system("color 3F");         /// Definindo a cor do fundo e a letra no cmd/

        do{                         //loop para movimentar a seta//
            gotoxy(co,L);           //gotoxy posiciona o cursor, o co é a coluna e L é a linha onde imprimir a seta//
            printf("====");         //imprime a seta//
            gotoxy(0,0);            //posiciona o cursor fora da tela para ele não ficar piscando//
            if(kbhit){a=getch();}   //se alguma tecla foi pressionada a igual a tecla//
            if(a == 77){            //80 é valor do cactere seta p/direita do teclado//
                co2=co;             //co2 é posição onde estava a barra para apagar senao fica duas setas//
                if(b==1){co+=14;}   //precisa ver se os espaços sao esses mesmos aqui é 14, tem que testar//
                if(b==2){co+=20;}   //precisa ver se os espaços sao esses mesmos aqui é 20, tem que testar//
                if(b==3){co+=23;}   //precisa ver se os espaços sao esses mesmos aqui é 23, tem que testar//
                if(b==4){co+=12;}   //precisa ver se os espaços sao esses mesmos aqui é 12, tem que testar//
                b++;
                if(b>5){b=1;co=co_i;}//a barra estando no sair e for movida p/direita ela vai para a primeira opção//
            }
            if(a == 75){             //75 é valor do cactere seta p/esquerda do teclado//
                co2=co;              //co2 é onde estava a barra, para apagar//
                if(b==2){co-=14;}
                if(b==3){co-=20;}
                if(b==4){co-=23;}
                if(b==5){co-=12;}
                b--;
                if(b<1){b=5;co=co_f;}//a seta estando no 1 e for movida p/esquerda ela vai para a ultima opção//
            }
            if(co!=co2){             /*se a barra for movida */
                gotoxy(co2,L);       //posicione o cursor onde estava a barra//
                printf("    ");      //imprime espaços em branco(que sao pretos) em cima da barra para apaga-la//
                co2=co;              //co2 igual a nova posição da barra//
            }
            if(a == 13){             //se a tecla enter for pressionada//
                opcao=b;             /*opcao igual a b */
            }
        }while(opcao == 0);          //repete enquanto opcao igual a zero//

    switch (opcao) {
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
			fgets(anot,500,stdin);   
		    }
            else if (esc==2){
                printf ("\n\nSUA FICHA ESTÁ PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS!! :D");
		}
		
		fprintf(rpg,"\n\t * * * * * * * * \n ");
        fprintf(rpg,"\t*\t\t * PLAYER: %s", jog);
        fprintf(rpg,"\t*\t o\t * NOME: %s", nome);  
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
		
		printf ("\n\tSUA FICHA  ESTÁ PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS :D\n\n");
		
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 2:
        system("cls");
        printf("Você pediu para sair, fechando programa...");
        for(a=0;a<10;a++){
            printf(".");
            Sleep(300);
        }
        printf("!\n\n");
		exit(0);
    case 3:
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
		printf ("\n\tSUA FICHA  ESTÁ PRONTA!\n");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 4:
        system ("cls");
        printf ("\n\t- OBJETIVO: \n\tESSE SOFTWARE FOI DESENVOLVIDO COM O OBJETIVO DE CRIAR UMA FICHA DE INFORMAÇÕES DO SEU OC (PERSONAGEM ORIGINAL)! \n\tADICIONE DADOS SOBRE SUA CRIAÇÃO E ACESSE SEUS ARQUIVOS PARA VERIFICAR O ARQUIVO DE TEXTO \n\tCRIADO POR ESSE PROGRAMA!\n");
        printf ("\n\n\tCASO ESTEJA COM DÚVIDAS SOBRE O QUE TIPOS DE DADOS COLOCAR, \n\tVEJA UM EXEMPLO A SEGUIR DA FICHA DE UM PERSONAGEM ORIGINAL \n\tDE UM DOS DESENVOLVEDORES DO SISTEMA :D\n");
		printf("\n\t * * * * * * * *  \n");
        printf("\t*\t\t * PLAYER: WILL \n");
        printf("\t*\t o\t * NOME: SOL\n");
        printf("\t*\t/l>\t * IDADE: 12\n");
        printf("\t*\t/ |\t * PROFISSÃO: DESIGNER\n");
        printf("\t*\t\t * LOCAL DE NASC.: BRASIL\n");
        printf("\t*\t\t * LOCAL DE RESIDÊNCIA: IFAM\n");
        printf("\t * * * * * * * * ");
        printf("\n\n\t PERSONALIDADE: SOL É UM GAROTO MUITO GENTIL (PERTO DE SEUS AMIGOS)\n");
        printf("\n\n\t ANOTAÇÕES ADICIONAIS: SOL GOSTA DE AMARELO E LER LIVROS\n");
        printf("\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   \n");
        printf("\n\t- INSPIRAÇÃO:\n\tESSE SOFTWARE SE INSPIROU EM UM ESTILO DE JOGO CHAMADO 'RPG DE MESA', \n\tONDE TODOS OS OS JOGADORES POSSUEM UM PERSONAGEM E UMA FICHA SOBRE ELE \n\tCOM INFORMAÇÕES SOBRE AS CARACTERÍSTICAS E HABILIDADES QUE ELES PODEM \n\tUTILIZAR NESSE UNIVERSO FICTÍCIO, DESCREVENDO AS SUAS AÇÕES APENAS POR \n\tMEIO DE DIÁLOGOS QUE OCORRE ENTRE OS JOGADORES E O NARRADOR DA HISTÓRIA.\n\n\tUSANDO ESSE ESTILO DE JOGO, NOSSA IDEIA É PROPOR UM MODELO MAIS SIMPLIFICADO \n\tDESSA FICHA DE RPG PARA ARMAZENAR INFORMAÇÕES DOS SEU PRÓPRIO PERSONAGEM EM \n\tUM ARQUIVO GERADO PELO NOSSO PROGRAMA!!");
        printf ("\n\n\tESPERAMOS QUE VOCÊ APROVEITE O SOFTWARE\n\n\tFEITO COM CARINHO \n\tASS.: OS DEVS =)");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    default:
        system("cls");
        printf("Você deve escolher uma opção válida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
        }
    }while(opcao!=5);
    return 0;
}

