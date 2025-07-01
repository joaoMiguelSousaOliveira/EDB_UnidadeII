#include <iostream>
#include <vector>

using namespace std;

void selection_sort (vector<int>& vetor) {
    for (int i = 0; i < vetor.size() - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < vetor.size(); j++) {
            if (vetor[j] < vetor[min_i]) {
                min_i = j;
            }
        }
        if (min_i != i) {
            swap(vetor[i], vetor[min_i]);
        }
    }
}