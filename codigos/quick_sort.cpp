#include <iostream>
#include <vector>
#include "../include/include.hpp"

using namespace std;

void quick_sort (vector<int>& vetor, int inicio, int fim) {
    if (fim == -1) fim = vetor.size() - 1;
    if (inicio < fim) {
        int pivo = partition(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo - 1);
        quick_sort(vetor, pivo + 1, fim);
    }
}

int partition (vector<int>& vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            swap(vetor[i], vetor[j]);
            i++;
        }
    }
    swap(vetor[i], vetor[fim]);
    return i;
}

void quick_sort_wrapper(vector<int>& vetor) {
    quick_sort(vetor, 0, -1);
}