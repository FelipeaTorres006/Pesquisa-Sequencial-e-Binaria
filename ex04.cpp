// Exercício 4 – Sistema de Login
// Um sistema possui uma lista de IDs de usuários ordenados:
// [101, 203, 305, 407, 509, 611, 713]
// Tarefa:
// •Implemente uma função de busca binária para validar se um ID existe.
// •Caso exista, retorne "Acesso permitdo", senão "Usuário não encontrado".

#include <stdio.h>

int pesquisaBinaria(int lista[], int esquerda, int direita, int alvo){
    int comparacoes = 0; // Aqui a comparacao esta comecando no 0
    while( esquerda <= direita ){ // Enquanto a esquerda for menor que a direita, isso vai acontecer.
        int meio = esquerda + ( direita - esquerda ) / 2; // Isso é para precaver de um erro de int. 

        // Aqui vai começar realmente os e ses

        if (lista[meio] == alvo ){
        printf("\nAcesso permitido\n");
        return meio;
        }
        else if (lista[meio] < alvo){
            printf("\nBuscando em nosso bando de dados\n"); //Aqui é para caso ele esteja para a direita
            esquerda = meio + 1;
        }
        else {
            printf("\nBuscando na fonte de dados\n"); //Aqui é para caso ele esteja para a esquerda
            direita = meio - 1;
        }
    }
    printf("\nUsuário não econtrado\n"); //Aqui é para caso ele não exista
    return -1;
}

int main() {
    int IDs[] = {101, 203, 305, 407, 509, 611, 713};
    int tamanho = sizeof(IDs) / sizeof(IDs[0]);
    int alvo = 611;

    printf("\nLendo identificador\n");
    int validarID = pesquisaBinaria(IDs, 0, tamanho -1, alvo);

    return 0;
}
