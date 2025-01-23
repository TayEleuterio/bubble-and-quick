#include <stdio.h>
#include <string.h>

#define MAX_PRATOS 300000
#define MAX_NOME 51

typedef struct {
    int prioridade;
    int tempo;
    char nome [MAX_NOME];
} Prato;

void trocar(Prato *a, Prato *b) {
    Prato temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
void bubbleSort(Prato pratos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pratos[j].prioridade < pratos[j + 1].prioridade ||
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo)) {
                    trocar(&pratos[j], &pratos[j + 1]);
            }
        }
    }
}

