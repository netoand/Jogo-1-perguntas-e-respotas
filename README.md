#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void perguntas_respostas() {
    char jogar_novamente;
    
    do {
        system("cls");
        printf("=== Pergunta e Resposta ===\n\n");
        
        // Pergunta 1
        printf("1. Qual a capital do Brasil?\n");
        printf("a) Rio de Janeiro\nb) Brasilia\nc) Sao Paulo\nd) Salvador\n");
        char resposta1;
        scanf(" %c", &resposta1);
        if (tolower(resposta1) == 'b') {
            printf("Correto!\n");
        } else {
            printf("Incorreto! A resposta correta é b) Brasilia.\n");
        }
        
        // Pergunta 2
        printf("\n2. Quantos lados tem um triangulo?\n");
        printf("a) 2\nb) 3\nc) 4\nd) 5\n");
        char resposta2;
        scanf(" %c", &resposta2);
        if (tolower(resposta2) == 'b') {
            printf("Correto!\n");
        } else {
            printf("Incorreto! A resposta correta é b) 3.\n");
        }
        
        // Pergunta 3
        printf("\n3. Qual o maior planeta do sistema solar?\n");
        printf("a) Terra\nb) Marte\nc) Jupiter\nd) Saturno\n");
        char resposta3;
        scanf(" %c", &resposta3);
        if (tolower(resposta3) == 'c') {
            printf("Correto!\n");
        } else {
            printf("Incorreto! A resposta correta é c) Jupiter.\n");
        }
        
        // Pergunta 4
        printf("\n4. Quem pintou a Mona Lisa?\n");
        printf("a) Van Gogh\nb) Picasso\nc) Da Vinci\nd) Monet\n");
        char resposta4;
        scanf(" %c", &resposta4);
        if (tolower(resposta4) == 'c') {
            printf("Correto!\n");
        } else {
            printf("Incorreto! A resposta correta é c) Da Vinci.\n");
        }
        
        // Pergunta 5
        printf("\n5. Qual o resultado de 2 + 2 * 2?\n");
        printf("a) 6\nb) 8\nc) 4\nd) 2\n");
        char resposta5;
        scanf(" %c", &resposta5);
        if (tolower(resposta5) == 'a') {
            printf("Correto!\n");
        } else {
            printf("Incorreto! A resposta correta é a) 6.\n");
        }
        
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
    } while (tolower(jogar_novamente) == 's');
}

int main() {
    perguntas_respostas();
    return 0;
}
