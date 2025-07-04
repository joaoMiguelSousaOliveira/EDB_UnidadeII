#include <iostream> 
#include <vector>
#include "../include/include.hpp"

using namespace std;

void quick_sort (vector<int>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = partition(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo - 1);
        quick_sort(vetor, pivo + 1, fim);
    }
}

int partition (vector<int>& vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) { 
            i++;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i + 1], vetor[fim]);
    return i + 1;
}

void quick_sort_wrapper(vector<int>& vetor) {
    quick_sort(vetor, 0, vetor.size() - 1);
}