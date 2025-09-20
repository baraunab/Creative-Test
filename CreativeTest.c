#include <stdio.h> // Biblioteca de entrada e sa�da de dados
#include <stdlib.h> // Biblioteca de convers�o das strings
#include <conio.h> // Biblioteca de manipula��o de caracteres
#include <locale.h> // Biblioteca de acentua��o de caracteres
#include <windows.h> // Biblioteca dos c�digos do cmd

int a,b,L,L2; // Declara��o das v�riaveis das setas
int co,co2,co_f,co_i,L3,L4; // Novas declara��es do menu

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
    setlocale(LC_ALL, "Portuguese"); // Definindo portugu�s como linguagem padr�o
    SetConsoleTitle("Creative Test"); // T�tulo do programa
    co=3;       //co � a coluna onde colocar a barra//
    L=23;b=1;   //L � a linha onde fica as op��es//
    co2=co;     //*co2 � onde estava a barra *//
    co_f=co+69;  //co_f � a coluna final do menu  precisa ver o valor certo aqui � 69  j� no seu n�o sei//
    co_i=co;     //co_i � a coluna de inicio do menu//
    do{
        inicio:
        opcao=0;
        system("cls"); // Limpar a tela dos comandos anteriores
        system("color 1F"); // Definindo a cor do fundo e a letra no cmd
        printf("Dica: Precione a tecla ESC a qualquer momento para voltar para o menu principal!\n\nA nossa interface � interativa, ent�o para selecionar a op��o desejada voc� deve usar as setas do teclado e o bot�o ENTER para clicar na op��o que quiser :D " );


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
            gotoxy(co,L);           //gotoxy posiciona o cursor, o co � a coluna e L � a linha onde imprimir a seta//
            printf("====");         //imprime a seta//
            gotoxy(0,0);            //posiciona o cursor fora da tela para ele n�o ficar piscando//
            if(kbhit){a=getch();}   //se alguma tecla foi pressionada a igual a tecla//
            if(a == 77){            //80 � valor do cactere seta p/direita do teclado//
                co2=co;             //co2 � posi��o onde estava a barra para apagar senao fica duas setas//
                if(b==1){co+=14;}   //precisa ver se os espa�os sao esses mesmos aqui � 14, tem que testar//
                if(b==2){co+=20;}   //precisa ver se os espa�os sao esses mesmos aqui � 20, tem que testar//
                if(b==3){co+=23;}   //precisa ver se os espa�os sao esses mesmos aqui � 23, tem que testar//
                if(b==4){co+=12;}   //precisa ver se os espa�os sao esses mesmos aqui � 12, tem que testar//
                b++;
                if(b>5){b=1;co=co_i;}//a barra estando no sair e for movida p/direita ela vai para a primeira op��o//
            }
            if(a == 75){             //75 � valor do cactere seta p/esquerda do teclado//
                co2=co;              //co2 � onde estava a barra, para apagar//
                if(b==2){co-=14;}
                if(b==3){co-=20;}
                if(b==4){co-=23;}
                if(b==5){co-=12;}
                b--;
                if(b<1){b=5;co=co_f;}//a seta estando no 1 e for movida p/esquerda ela vai para a ultima op��o//
            }
            if(co!=co2){             /*se a barra for movida */
                gotoxy(co2,L);       //posicione o cursor onde estava a barra//
                printf("    ");      //imprime espa�os em branco(que sao pretos) em cima da barra para apaga-la//
                co2=co;              //co2 igual a nova posi��o da barra//
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
		printf ("PROFISS�O: ");
		fflush(stdin);
		fgets(prof,100,stdin);
		printf ("LOCAL DE NASC.: ");
		fflush(stdin);
		fgets(nasc,100,stdin);
		printf ("LOCAL DE RESID�NCIA: ");
		fflush(stdin);
		fgets(res,100,stdin);
		printf ("\nPERSONALIDADE - DESCREVA COMO O SEU PERSONAGEM �, FALE SOBRE SUAS CARACTER�STICAS E INFORMA��ES RELEVANTES!\n");
		fflush(stdin);
		fgets(perso,500,stdin);
		
		printf ("\n\n\nDESEJA ADICIONAR MAIS INFORMA��ES?\n\nSIM - 1 \t N�O - 2\n");
		scanf("%d",&esc);
		if (esc==1){
            printf("\nANOTA��ES ADICIONAIS: ");
			fflush(stdin);
			fgets(anot,500,stdin);   
		    }
            else if (esc==2){
                printf ("\n\nSUA FICHA EST� PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS!! :D");
		}
		
		fprintf(rpg,"\n\t * * * * * * * * \n ");
        fprintf(rpg,"\t*\t\t * PLAYER: %s", jog);
        fprintf(rpg,"\t*\t o\t * NOME: %s", nome);  
        fprintf(rpg,"\t*\t/l>\t * IDADE: %d\n", id); 
        fprintf(rpg,"\t*\t/ |\t * PROFISS�O: %s", prof);
        fprintf(rpg,"\t*\t\t * LOCAL DE NASC.: %s", nasc);
        fprintf(rpg,"\t*\t\t * LOCAL DE RESID�NCIA: %s", res);
        fprintf(rpg,"\t * * * * * * * * ");
        fprintf(rpg, "\n\n\tPERSONALIDADE: \n\t - %s", perso);
        if (esc==1){
        	fprintf(rpg,"\n\tANOTA��ES ADICIONAIS: \n\t - %s", anot);
		}
		system("cls");
		
		printf ("\n\tSUA FICHA  EST� PRONTA!! FECHE O PROGRAMA E ACESSE SEUS ARQUIVOS OU O APP BLOCO DE NOTAS PARA CONFERIR OS DADOS :D\n\n");
		
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 2:
        system("cls");
        printf("Voc� pediu para sair, fechando programa...");
        for(a=0;a<10;a++){
            printf(".");
            Sleep(300);
        }
        printf("!\n\n");
		exit(0);
    case 3:
        system ("cls");
        printf ("\n\tESSE � O MODELO DA SUA FICHA!\n\n");
        printf("\t * * * * * * * *  \n");
        printf("\t*\t\t * PLAYER: \n");
        printf("\t*\t o\t * NOME: \n");
        printf("\t*\t/l>\t * IDADE: \n");
        printf("\t*\t/ |\t * PROFISS�O: \n");
        printf("\t*\t\t * LOCAL DE NASC.: \n");
        printf("\t*\t\t * LOCAL DE RESID�NCIA:\n");
        printf("\t * * * * * * * * ");
        printf("\n\n\t PERSONALIDADE: \n");
        printf("\n\n\t ANOTA��ES ADICIONAIS: \n");
		printf ("\n\tSUA FICHA  EST� PRONTA!\n");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 4:
        system ("cls");
        printf ("\n\t- OBJETIVO: \n\tESSE SOFTWARE FOI DESENVOLVIDO COM O OBJETIVO DE CRIAR UMA FICHA DE INFORMA��ES DO SEU OC (PERSONAGEM ORIGINAL)! \n\tADICIONE DADOS SOBRE SUA CRIA��O E ACESSE SEUS ARQUIVOS PARA VERIFICAR O ARQUIVO DE TEXTO \n\tCRIADO POR ESSE PROGRAMA!\n");
        printf ("\n\n\tCASO ESTEJA COM D�VIDAS SOBRE O QUE TIPOS DE DADOS COLOCAR, \n\tVEJA UM EXEMPLO A SEGUIR DA FICHA DE UM PERSONAGEM ORIGINAL \n\tDE UM DOS DESENVOLVEDORES DO SISTEMA :D\n");
		printf("\n\t * * * * * * * *  \n");
        printf("\t*\t\t * PLAYER: WILL \n");
        printf("\t*\t o\t * NOME: SOL\n");
        printf("\t*\t/l>\t * IDADE: 12\n");
        printf("\t*\t/ |\t * PROFISS�O: DESIGNER\n");
        printf("\t*\t\t * LOCAL DE NASC.: BRASIL\n");
        printf("\t*\t\t * LOCAL DE RESID�NCIA: IFAM\n");
        printf("\t * * * * * * * * ");
        printf("\n\n\t PERSONALIDADE: SOL � UM GAROTO MUITO GENTIL (PERTO DE SEUS AMIGOS)\n");
        printf("\n\n\t ANOTA��ES ADICIONAIS: SOL GOSTA DE AMARELO E LER LIVROS\n");
        printf("\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   \n");
        printf("\n\t- INSPIRA��O:\n\tESSE SOFTWARE SE INSPIROU EM UM ESTILO DE JOGO CHAMADO 'RPG DE MESA', \n\tONDE TODOS OS OS JOGADORES POSSUEM UM PERSONAGEM E UMA FICHA SOBRE ELE \n\tCOM INFORMA��ES SOBRE AS CARACTER�STICAS E HABILIDADES QUE ELES PODEM \n\tUTILIZAR NESSE UNIVERSO FICT�CIO, DESCREVENDO AS SUAS A��ES APENAS POR \n\tMEIO DE DI�LOGOS QUE OCORRE ENTRE OS JOGADORES E O NARRADOR DA HIST�RIA.\n\n\tUSANDO ESSE ESTILO DE JOGO, NOSSA IDEIA � PROPOR UM MODELO MAIS SIMPLIFICADO \n\tDESSA FICHA DE RPG PARA ARMAZENAR INFORMA��ES DOS SEU PR�PRIO PERSONAGEM EM \n\tUM ARQUIVO GERADO PELO NOSSO PROGRAMA!!");
        printf ("\n\n\tESPERAMOS QUE VOC� APROVEITE O SOFTWARE\n\n\tFEITO COM CARINHO \n\tASS.: OS DEVS =)");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    default:
        system("cls");
        printf("Voc� deve escolher uma op��o v�lida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
        }
    }while(opcao!=5);
    return 0;
}

