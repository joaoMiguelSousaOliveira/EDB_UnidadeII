#include <iostream>
#include <vector>
#include "../include/include.hpp"

using namespace std;

void merge(vector<int>& vetor, int inicio, int meio, int fim) {
    vector<int> esquerda = vector<int>(vetor.begin() + inicio, vetor.begin() + meio);
    vector<int> direita = vector<int>(vetor.begin() + meio, vetor.begin() + fim);

    size_t top_esquerda = 0, top_direita = 0;

    for (int k = inicio; k < fim; k++) {
        if (top_esquerda >= esquerda.size()) {
            vetor[k] = direita[top_direita];
            top_direita++;
        }
        else if (top_direita >= direita.size()) {
            vetor[k] = esquerda[top_esquerda];
            top_esquerda++;
        }

        else if (esquerda[top_esquerda] < direita[top_direita]) {
            vetor[k] = esquerda[top_esquerda];
            top_esquerda++;
        } else {
            vetor[k] = direita[top_direita];
            top_direita++;
        }
    }
}

void merge_sort(vector<int>& vetor, int inicio, int fim) {
    if (fim - inicio <= 1) {
        return;
    } 
    int meio = inicio + (fim - inicio) / 2;
    merge_sort(vetor, inicio, meio);
    merge_sort(vetor, meio, fim);
    merge(vetor, inicio, meio, fim);
    
}

void merge_sort_wrapper(vector<int>& vetor) {
    if (vetor.empty()) {
        return;
    }
    merge_sort(vetor, 0, vetor.size() - 1);
}

