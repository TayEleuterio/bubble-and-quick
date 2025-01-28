# bubble-and-quick

Este repositório contém a implementação das atividades relacionadas à disciplina de Estrutura de Dados I, compreendendo os métodos de ordenação Bubble sort e Quicksort.

A proposta da atividade é implementar os algorítimos **Bubble Sort** e **Quick Sort** para ordenar a lista de pratos de um restaurante, seguindo as seguintes regras:

1. Ordenar pela prioridade em ordem decrescente.
2. Caso haja empate na priordade, o prato com menor tempo de preparo é priorizado.
3. Cada prato possui três atributos: prioridade, tempo de preparo (em minutos) e nome (uma string sem espaços).


#Relatório

Bubble Sort:

* Simples de implementar.
* Complexidade 𝑂(n²), tornando-o ineficiente para grandes conjuntos de dados.

QuickSort:

* Mais eficiente, com complexidade 𝑂(𝑛 log 𝑛) O(nlogn) em média.
* Escolha de pivô:
  * O pivô atual é o último elemento do intervalo.
  * Melhorias possíveis: pivô aleatório ou mediana de três para evitar casos extremos.
