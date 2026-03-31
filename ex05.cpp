// Um sistema recebe a seguinte lista desordenada de números:
// [45, 12, 78, 3, 56, 89, 23, 67] --> Merge Sort, já que foi nosso trabalho e porque eu quero.
// Tarefa:
// 1. Ordene o vetor utlizando um algoritmo de ordenação à sua escolha (Bubble Sort,
// Selecton Sort, etc.).
// 2. Após ordenar, implemente a busca binária para encontrar um valor informado.
// 3. Mostre o vetor antes e depois da ordenação.

#include <stdio.h>

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Funcao para mesclar dois subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // Copiando os elementos para os subarrays L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Mesclar os dois subarrays ordenados de volta em arr[]
    while (i < n1 && j < n2) {
        printf("Comparando %d e %d\n", L[i], R[j]);
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Imprime o array atualizado APOS toda a mesclagem estar completa
    printf("Array ordenado: \n");
    imprimirArray(arr, r + 1);
}

// Funcao recursiva MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int buscaBinaria(int vetor[], int esquerda, int direita, int alvo ){
    int comparacoes = 0;
    while( esquerda <= direita ){
        int meio = esquerda + ( direita - esquerda) / 2; // Aqui é o fim do bloco da busca binaria

         if( vetor[meio] == alvo ){
            printf("Valor %d encontrado na posicao %d do vetor\n", alvo, meio);
            return alvo;
        }
        
        else if( vetor[meio] <= alvo){
            printf("O %d é menor que o %d, vamos para a parte a direita.\n", vetor[meio], alvo);
            esquerda = meio + 1;
        }

        else {
            printf("O %d é maior que o %d, vamos para a parte a direita.\n", vetor[meio], alvo);
            direita = meio + 1;
        }
    }

    printf("\nValor inexistente nesse vetor\n");
    return -1;
}

int main() {
    int array[] = {45, 12, 78, 3, 56, 89, 23, 67};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int alvo = 89;

    printf("\nIniciando os processos\n");

    printf("Array original: ");
    imprimirArray(array, tamanho);

    mergeSort(array, 0, tamanho - 1);

    printf("\nArray ordenado com Merge Sort: ");
    imprimirArray(array, tamanho);

    int resultado = buscaBinaria(array, 0, tamanho -1, alvo);

    return 0;
}