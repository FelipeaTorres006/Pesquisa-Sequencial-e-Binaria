// Exercício 2 – Busca em Lisa de Produos
// Um sisema de esoque armazena códigos de produos em um vetor:
// [55, 12, 89, 33, 21, 90, 44]
// Tarefa:
// •Implemene uma busca sequencial para localizar um código informado pelo usuário.
// •Caso não exisa, informe claramente.

#include <stdio.h>

int busca_sequencial(int lista[], int tamanho, int alvo ) {
    for ( int i = 0; i < tamanho; i ++){
                printf("\nProcurando na lista a posicao [%d] do mesmo %d == %d\n", i, lista[i], alvo);
        if(lista[i] != alvo){
            printf("\nO numero %d referente ao produto x\n", lista[i]);
        }
        if (lista[i] == alvo){
            printf("\nO numero alvo foi achado no vetor %d\n", lista[i]);
            return i;
        }
    }
    printf("\nProduto não encontrado\n");
    return -1;
}

int main(){
    
    int produtos[] = {55, 12, 89, 33, 21, 90, 44};
    int tamanho = sizeof(produtos) / sizeof(produtos[0]);
    int alvo = 55;

    printf("\nIniciando a chamada \n");
    int resultado = busca_sequencial (produtos, tamanho, alvo);

    return 0;
}