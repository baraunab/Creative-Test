#ifdef FICHA_C
#define FICHA_C

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
void menu(); // menu de escolhas
int int_input(); // recebe input de int por meio de fgets e converte com atoi
void criar_ficha(); // cria arquivo de ficha do personagem
void ler_ficha(); // le o arquivo de ficha e mostra no terminal

#endif
