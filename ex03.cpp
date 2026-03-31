// Exercício 3 – Biblioteca Digital
// Uma biblioteca armazena IDs de livros ordenados:
// [10, 23, 35, 47, 59, 62, 78, 91]
// Tarefa:
// •Implemente a busca binária para encontrar um livro.
// •Mostre o número de iterações realizadas até encontrar (ou não encontrar).

#include <stdio.h>

int pesquisaBinaria(int arr[], int esquerda, int direita, int alvo) {
    int comparacoes = 0;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        printf("\n--> Comparacao %d:\n", ++comparacoes);
        printf("Intervalo atual: esquerda = %d, direita = %d\n", esquerda, direita);
        printf("Indice do meio: %d (alvo = %d)\n", meio, arr[meio]);

        if (arr[meio] == alvo) {
            printf("Valor encontrado na posicao %d\n", meio);
            return meio;
        } else if (arr[meio] < alvo) {
            printf("%d e maior que %d, indo para a metade direita\n", alvo, arr[meio]);
            esquerda = meio + 1;
        } else {
            printf("%d e menor que %d, indo para a metade esquerda\n", alvo, arr[meio]);
            direita = meio - 1;
        }
    }
    printf("Valor nao encontrado no vetor\n");
    return -1;
}

int main() {
    int IDs[] = {10, 23, 35, 47, 59, 62, 78, 91};
    int tamanho = sizeof(IDs) / sizeof(IDs[0]);
    int alvo = 101;

    printf("Iniciando pesquisa binaria...\n");
    int resultado = pesquisaBinaria(IDs, 0, tamanho -1, alvo);

    return 0;
}