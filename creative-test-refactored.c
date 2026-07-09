#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#include "ficha.h"

// função principal
int main () {
    // definindo linguagem pt-br
    setlocale(LC_ALL, "Portuguese");
    
    // menu de opcoes
    menu();
     
}
