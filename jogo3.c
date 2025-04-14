#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int furia;
} Gousma;

void gousmas_war() {
    char jogar_novamente;
    
    do {
        system("cls || clear"); // Limpa a tela (funciona no Windows e Linux/macOS)
        printf("=== Gousmas War ===\n\n");
        
        // Inicialização das Gousmas
        Gousma jogador1[2] = {{1}, {1}}; // Jogador 1 começa com 2 Gousmas (fúria 1)
        Gousma jogador2[2] = {{1}, {1}};  // Jogador 2 começa com 2 Gousmas (fúria 1)
        int qtd_jogador1 = 2, qtd_jogador2 = 2; // Quantidade de Gousmas de cada jogador
        int vez = rand() % 2; // Sorteia quem começa (0: Jogador 1, 1: Jogador 2)

        printf("%s comeca!\n", vez ? "Jogador 2" : "Jogador 1");

        // Loop principal do jogo
        while (qtd_jogador1 > 0 && qtd_jogador2 > 0) {
            printf("\n--- Turno do %s ---\n", vez ? "Jogador 2" : "Jogador 1");
            
            // Mostra as Gousmas do jogador atual
            printf("\nSuas Gousmas:\n");
            for (int i = 0; i < (vez ? qtd_jogador2 : qtd_jogador1); i++) {
                printf("%d. Fúria: %d\n", i+1, vez ? jogador2[i].furia : jogador1[i].furia);
            }

            // Mostra as Gousmas do oponente
            printf("\nGousmas do oponente:\n");
            for (int i = 0; i < (vez ? qtd_jogador1 : qtd_jogador2); i++) {
                printf("%d. Fúria: %d\n", i+1, vez ? jogador1[i].furia : jogador2[i].furia);
            }

            // Menu de ações
            printf("\n1. Atacar\n2. Dividir\nEscolha: ");
            int escolha;
            scanf("%d", &escolha);

            if (escolha == 1) { // Ataque
                if ((vez && qtd_jogador2 == 0) || (!vez && qtd_jogador1 == 0)) {
                    printf("\nVocê não tem Gousmas para atacar!\n");
                    continue;
                }

                printf("Escolha sua Gousma atacante (1-%d): ", vez ? qtd_jogador2 : qtd_jogador1);
                int atacante;
                scanf("%d", &atacante);
                atacante--;

                printf("Escolha a Gousma inimiga para atacar (1-%d): ", vez ? qtd_jogador1 : qtd_jogador2);
                int inimiga;
                scanf("%d", &inimiga);
                inimiga--;

                // Transferência de fúria
                if (vez) { // Jogador 2 ataca Jogador 1
                    jogador1[inimiga].furia += jogador2[atacante].furia;
                    jogador2[atacante].furia = 0;
                    printf("\nFúria transferida! A Gousma inimiga agora tem %d de fúria.\n", jogador1[inimiga].furia);

                    // Verifica se a Gousma explodiu (fúria > 5)
                    if (jogador1[inimiga].furia > 5) {
                        printf("\nA Gousma inimiga explodiu!\n");
                        // Remove a Gousma explodida
                        for (int i = inimiga; i < qtd_jogador1 - 1; i++) {
                            jogador1[i] = jogador1[i + 1];
                        }
                        qtd_jogador1--;
                    }
                } else { // Jogador 1 ataca Jogador 2
                    jogador2[inimiga].furia += jogador1[atacante].furia;
                    jogador1[atacante].furia = 0;
                    printf("\nFúria transferida! A Gousma inimiga agora tem %d de fúria.\n", jogador2[inimiga].furia);

                    if (jogador2[inimiga].furia > 5) {
                        printf("\nA Gousma inimiga explodiu!\n");
                        // Remove a Gousma explodida
                        for (int i = inimiga; i < qtd_jogador2 - 1; i++) {
                            jogador2[i] = jogador2[i + 1];
                        }
                        qtd_jogador2--;
                    }
                }
            } 
            else if (escolha == 2) { // Divisão de Gousmas
                if ((vez && qtd_jogador2 >= 2) || (!vez && qtd_jogador1 >= 2)) {
                    printf("\nVocê já tem o número máximo de Gousmas (2)!\n");
                    continue;
                }

                printf("Escolha a Gousma para dividir (1-%d): ", vez ? qtd_jogador2 : qtd_jogador1);
                int gousma;
                scanf("%d", &gousma);
                gousma--;

                printf("Quanta fúria transferir para a nova Gousma? ");
                int furia;
                scanf("%d", &furia);

                if (vez) { // Jogador 2 divide
                    if (furia > 0 && furia <= jogador2[gousma].furia) {
                        jogador2[gousma].furia -= furia;
                        jogador2[qtd_jogador2].furia = furia;
                        qtd_jogador2++;
                        printf("\nNova Gousma criada com %d de fúria!\n", furia);
                    } else {
                        printf("\nFúria inválida! A Gousma selecionada tem apenas %d de fúria.\n", jogador2[gousma].furia);
                    }
                } else { // Jogador 1 divide
                    if (furia > 0 && furia <= jogador1[gousma].furia) {
                        jogador1[gousma].furia -= furia;
                        jogador1[qtd_jogador1].furia = furia;
                        qtd_jogador1++;
                        printf("\nNova Gousma criada com %d de fúria!\n", furia);
                    } else {
                        printf("\nFúria inválida! A Gousma selecionada tem apenas %d de fúria.\n", jogador1[gousma].furia);
                    }
                }
            } else {
                printf("\nOpção inválida!\n");
            }

            vez = !vez; // Passa a vez para o outro jogador
        }

        // Fim do jogo
        printf("\n=== Fim do Jogo ===\n");
        printf("%s venceu!\n", qtd_jogador1 > 0 ? "Jogador 1" : "Jogador 2");

        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
    } while (tolower(jogar_novamente) == 's');
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    gousmas_war();
    return 0;
}