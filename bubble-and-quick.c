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

int particionar(Prato pratos[], int baixo, int alto) {
    Prato pivo = pratos[alto];
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++){
        if (pratos[j].prioridade > pivo.prioridade ||
        	(pratos[j].prioridade == pivo.prioridade && pratos[j].tempo < pivo.tempo)) {
            i++;
            trocar(&pratos[i], &pratos[j]);
        }
    }
    trocar(&pratos[i + 1], &pratos[alto]);
    return i + 1;
}

void quicksort(Prato pratos[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(pratos, baixo, alto);
        quicksort(pratos, baixo, pi - 1);
        quicksort(pratos, pi + 1, alto);
    }
}

int main() {
    int n;
    Prato pratos[MAX_PRATOS];

    printf("Digite o número de pratos: ");
    scanf("%d", &n);

    printf("Digite os pratos (prioridade tempo nome):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %s", &pratos[i].prioridade, &pratos[i].tempo, pratos[i].nome);
    }

    Prato pratosBubble[MAX_PRATOS];
    for (int i = 0; i < n; i++) {
        pratosBubble[i] = pratos[i];
    }
    
    Prato pratosQuick[MAX_PRATOS];
    for (int i = 0; i < n; i++) {
        pratosQuick[i] = pratos[i];
    }

    printf("\nResultado Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", pratosBubble[i].nome);
    }

    printf("\nResultado Quicksort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", pratosQuick[i].nome);
    }

    return 0;
}
