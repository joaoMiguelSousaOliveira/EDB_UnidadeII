#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& vetor, int inicio = 0, int fim = NULL) {
    if (fim == NULL) {
        fim = vetor.size();
    }

    if(fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(vector<int>& vetor, int inicio, int meio, int fim) {
    vector<int> esquerda = vector<int>(vetor.begin() + inicio, vetor.begin() + meio);
    vector<int> direita = vector<int>(vetor.begin() + meio, vetor.begin() + fim);

    int top_esquerda = 0, top_direita = 0;

    for (size_t k : vetor) {
        if (top_esquerda >= esquerda.size()) {
            vetor[k] = direita[top_direita];
            top_direita++;
        }
        else if (top_direita >= direita.size()) {
            vetor[k] = esquerda[top_esquerda];
            top_esquerda++;
        }

        else if (esquerda[top_esquerda] < direita[top_direita]) {
            vetor[top_direita] = esquerda[top_esquerda];
            top_esquerda++;
        } else {
            vetor[top_direita] = direita[top_esquerda];
            top_direita++;
        }
    }
}