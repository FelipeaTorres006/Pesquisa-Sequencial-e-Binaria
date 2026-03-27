// Um professor possui um vetor com os números de matrícula dos alunos presentes em sala:
// [512, 102, 678, 205, 789, 317, 404]
// Durante a chamada, ele deseja verificar se um aluno específico está presente.
// Tarefa:
// Implemente um algoritmo de busca sequencial que receba a matrícula e informe se o
// aluno está presente.
// Retorne também a posição do aluno no vetor (caso encontrado).

#include <stdio.h>

int busca_sequencial(int lista[], int tamanho, int alvo) {
    for( int i = 0; i < tamanho; i++){
        printf("\nProcurando na lista a posicao [%d] do mesmo %d == %d\n", i, lista[i], alvo);
        if( lista[i] != alvo){
            printf("O numero %d e refente a matricula do fulano\n", lista[i], alvo);
        }
        if( lista[i] == alvo){

            printf("\nFelipe esta presente na aula %d\n", lista[i]);
            return i;
        }

    }
    printf("\nPelo visto o Felipe faltou hoje\n");
    return -1;
}

int main(){

    int matriculas[] = {512, 102, 678, 205, 789, 317, 404};
    int tamanho = sizeof(matriculas) / sizeof(matriculas[0]);
    int alvo = 504;

    printf("\nIniciando a chamadinha: \n\n");
    int resultado = busca_sequencial(matriculas, tamanho, alvo);

    return 0;
}