#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Essa estrutura armazena informações sobre cada território:
// nome, cor do exército e quantidade de tropas.
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército
    int tropas;      // Quantidade de tropas
} Territorio;

int main() {
    // Declaração de um vetor de 5 territórios
    Territorio territorios[5];

    // Cadastro dos territórios
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        // Entrada do nome do território
        printf("Digite o nome do território: ");
        scanf("%29s", territorios[i].nome); // Limite de 29 caracteres para evitar overflow

        // Entrada da cor do exército
        printf("Digite a cor do exército: ");
        scanf("%9s", territorios[i].cor); // Limite de 9 caracteres

        // Entrada da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n===== Dados dos Territórios Cadastrados =====\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}