#include <iostream>
#include <vector>
#include "../include/include.hpp"
using namespace std;

void bublesort(vector<int>& vetor) {
    int n = vetor.size();

    bool trocou;

    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
                trocou = true;
            }
        }
        // Se não houve troca, o vetor já está ordenado
        if (!trocou) {
            break;
        }
    }
}
