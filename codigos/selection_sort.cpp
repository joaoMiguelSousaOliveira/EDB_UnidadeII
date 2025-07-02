#include <iostream>
#include <vector>
#include "../include/include.hpp"

using namespace std;

void selection_sort (vector<int>& vetor) {
    for (size_t i = 0; i < vetor.size() - 1; i++) {
        size_t min_i = i;
        for (size_t j = i + 1; j < vetor.size(); j++) {
            if (vetor[j] < vetor[min_i]) {
                min_i = j;
            }
        }
        if (min_i != i) {
            swap(vetor[i], vetor[min_i]);
        }
    }
}