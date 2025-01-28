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
    int n = 0;
    Prato pratos[MAX_PRATOS];
    char linha[256];
    FILE *arquivo;
    
    arquivo = fopen("restaurante_pratos.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo csv.\n");
        return 1;
    }
    
    while (fgets(linha, sizeof(linha), arquivo)) {
       if (sscanf(linha, "%d,%d,%50s", &pratos[n].prioridade, &pratos[n].tempo, pratos[n].nome) != 3) {
            printf("Erro no formato do arquivo CSV na linha %d.\n", n + 1);
            fclose(arquivo);
            return 1;
    }
    n++;
    if (n >= MAX_PRATOS) break;
    }
        
    fclose(arquivo);
    
    if (n == 0) {
        printf("Nenhum dado encontrado no arquivo CSV.\n");
        return 1;
    }

    Prato pratosBubble[MAX_PRATOS];
     Prato pratosQuick[MAX_PRATOS];
    for (int i = 0; i < n; i++) {
        pratosBubble[i] = pratos[i];
        pratosQuick[i] = pratos[i];
    }

    bubbleSort(pratosBubble, n);
    quicksort(pratosQuick, 0, n - 1);
  
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
