#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& vetor) {
    for (size_t i = 1; i < vetor.size(); i++) {
        int novo = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > novo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = novo;
    }
}

