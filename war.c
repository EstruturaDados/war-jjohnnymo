#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura que representa um território
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército
    int tropas;      // Quantidade de tropas
    int dono;        // Jogador dono do território (1 ou 2)
} Territorio;

// Função para rolar um dado de 1 a 6
int rolarDado() {
    return (rand() % 6) + 1;
}

// Função para exibir os territórios
void mostrarTerritorios(Territorio territorios[], int n) {
    printf("\n===== Estado Atual dos Territórios =====\n");
    for (int i = 0; i < n; i++) {
        printf("Território %d: %s | Cor: %s | Tropas: %d | Dono: Jogador %d\n",
               i + 1, territorios[i].nome, territorios[i].cor,
               territorios[i].tropas, territorios[i].dono);
    }
}

// Função de batalha entre territórios
void batalha(Territorio *atacante, Territorio *defensor) {
    printf("\n%s (Jogador %d) está atacando %s (Jogador %d)!\n",
           atacante->nome, atacante->dono, defensor->nome, defensor->dono);

    // Cada lado rola um dado
    int dadoAtacante = rolarDado();
    int dadoDefensor = rolarDado();

    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        defensor->tropas--;
        printf("Defensor perdeu 1 tropa!\n");
        if (defensor->tropas <= 0) {
            defensor->dono = atacante->dono;
            defensor->tropas = 1; // ganha o território com 1 tropa
            printf("%s foi conquistado pelo Jogador %d!\n", defensor->nome, atacante->dono);
        }
    } else {
        atacante->tropas--;
        printf("Atacante perdeu 1 tropa!\n");
    }
}

int main() {
    srand(time(NULL)); // inicializa gerador de números aleatórios

    Territorio territorios[5];

    // Cadastro inicial dos territórios
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Digite o nome do território: ");
        scanf("%29s", territorios[i].nome);

        printf("Digite a cor do exército: ");
        scanf("%9s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        // Alterna dono entre Jogador 1 e 2
        territorios[i].dono = (i % 2) + 1;
    }

    mostrarTerritorios(territorios, 5);

    // Loop de jogo simplificado
    int rodada = 1;
    while (1) {
        printf("\n===== Rodada %d =====\n", rodada);

        int atacante, defensor;
        printf("Jogador 1, escolha território atacante (1-5): ");
        scanf("%d", &atacante);
        printf("Escolha território defensor (1-5): ");
        scanf("%d", &defensor);

        if (atacante < 1 || atacante > 5 || defensor < 1 || defensor > 5) {
            printf("Territórios inválidos!\n");
            continue;
        }

        batalha(&territorios[atacante - 1], &territorios[defensor - 1]);
        mostrarTerritorios(territorios, 5);

        // Verifica se algum jogador conquistou todos os territórios
        int dono1 = 0, dono2 = 0;
        for (int i = 0; i < 5; i++) {
            if (territorios[i].dono == 1) dono1++;
            else dono2++;
        }
        if (dono1 == 5) {
            printf("\nJogador 1 venceu o jogo!\n");
            break;
        } else if (dono2 == 5) {
            printf("\nJogador 2 venceu o jogo!\n");
            break;
        }

        rodada++;
    }

    return 0;
}