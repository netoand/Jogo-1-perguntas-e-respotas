#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para sortear um número entre min e max
int sortear(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    char *nomesPredefinidos[] = {
        "Amunet", "Horus", "Anubis", "Bastet", "Osiris", "Isis", "Thoth"
    };
    int numNomes = 7;
    
    char nomeJogador1[20], nomeJogador2[20];
    char jogadorAtual[20];
    int jogarNovamente = 1;
    
    while (jogarNovamente) {
        system("clear || cls"); // Limpa a tela (funciona no Linux e Windows)
        
        printf("=== COBRA NA CAIXA ===\n\n");
        
        // Seleção de nomes
        printf("Nomes predefinidos disponíveis:\n");
        for (int i = 0; i < numNomes; i++) {
            printf("%d. %s\n", i+1, nomesPredefinidos[i]);
        }
        
        // Jogador 1 escolhe nome
        printf("\nJogador 1, escolha seu nome (1-7 ou digite um novo): ");
        int escolha;
        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= numNomes) {
            strcpy(nomeJogador1, nomesPredefinidos[escolha-1]);
        } else {
            limparBuffer();
            printf("Digite um novo nome: ");
            scanf("%19s", nomeJogador1);
        }
        limparBuffer();
        
        // Jogador 2 escolhe nome
        printf("Jogador 2, escolha seu nome (1-7 ou digite um novo): ");
        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= numNomes) {
            strcpy(nomeJogador2, nomesPredefinidos[escolha-1]);
        } else {
            limparBuffer();
            printf("Digite um novo nome: ");
            scanf("%19s", nomeJogador2);
        }
        limparBuffer();
        
        // Sorteia quem começa
        int primeiroJogador = sortear(0, 1);
        if (primeiroJogador == 0) {
            strcpy(jogadorAtual, nomeJogador1);
        } else {
            strcpy(jogadorAtual, nomeJogador2);
        }
        
        printf("\n%s foi sorteado para começar!\n", jogadorAtual);
        
        // Loop principal do jogo
        int jogoAtivo = 1;
        while (jogoAtivo) {
            // Posiciona o botão e a cobra em caixas aleatórias diferentes
            int botao = sortear(1, 5);
            int cobra;
            do {
                cobra = sortear(1, 5);
            } while (cobra == botao);
            
            printf("\n%s, escolha uma caixa (1-5): ", jogadorAtual);
            int escolhaCaixa;
            scanf("%d", &escolhaCaixa);
            limparBuffer();
            
            if (escolhaCaixa < 1 || escolhaCaixa > 5) {
                printf("Escolha inválida! Digite um número entre 1 e 5.\n");
                continue;
            }
            
            if (escolhaCaixa == cobra) {
                printf("\nAAAARGH! A cobra mortal atacou %s!\n", jogadorAtual);
                printf("FIM DE JOGO! %s perdeu.\n", jogadorAtual);
                jogoAtivo = 0;
            } else if (escolhaCaixa == botao) {
                printf("\nPARABÉNS! %s encontrou o botão e escapou da tumba!\n", jogadorAtual);
                jogoAtivo = 0;
            } else {
                printf("A caixa %d está vazia. Continue tentando!\n", escolhaCaixa);
                // Alterna o jogador
                if (strcmp(jogadorAtual, nomeJogador1) == 0) {
                    strcpy(jogadorAtual, nomeJogador2);
                } else {
                    strcpy(jogadorAtual, nomeJogador1);
                }
            }
        }
        
        // Pergunta se quer jogar novamente
        printf("\nDeseja jogar novamente? (S/N): ");
        char opcao;
        scanf(" %c", &opcao);
        limparBuffer();
        
        if (toupper(opcao) != 'S') {
            jogarNovamente = 0;
        }
    }
    
    printf("\nObrigado por jogar Cobra na Caixa!\n");
    return 0;
}