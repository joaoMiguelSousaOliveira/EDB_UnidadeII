#include <iostream>
#include <vector>

using namespace std;

void bublesort(vector<int>& vetor) {
    bool mudou = true;
    int fim = vetor.size() - 1;
    while (mudou) {
        mudou = false;
        for (int i = 0; i < fim; i++) {
            if (vetor[i] > vetor[i + 1]) {
                swap(vetor[i], vetor[i + 1]);
                mudou = true;
            }
        }
        fim--;
    }
}
