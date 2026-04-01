// Um vetor contém nomes de alunos:
// ["Daniel", "Ana", "Eduarda", "Carlos", "Bruna"]
// Tarefa:
// •Implemente uma busca sequencial para veriﬁcar se um nome está presente.
// •Retorne a posição e o nome encontrado.

#include <stdio.h>
#include <string.h> //biblioteca de strings

int buscaSequencial(const char* lista[], int tamanho, const char* alvo){ // Essa const char* é um ponteiro para uma string que não pode ser modificada.
    for (int i = 0; i < tamanho; i++){

        if (strcmp(lista[i], alvo) != 0){ // Comparacao entre duas strings
            printf("\nO nome %s e diferente do nome %s\n", lista[i], alvo);
        }

        if (strcmp(lista[i], alvo) == 0){
            printf("Achei o nome %s na posicao %d da lista\n", alvo, i);
            return i;
        }
    }

    printf("Esse nome nao existe na lista\n");
    return -1;
}

int main(){
    const char* nomes[] = {"Daniel", "Ana", "Eduarda", "Carlos", "Bruna"};
    int tamanho = sizeof(nomes) / sizeof(nomes[0]);
    const char* alvo = "Carlos";

    int resultado = buscaSequencial(nomes, tamanho, alvo);
}