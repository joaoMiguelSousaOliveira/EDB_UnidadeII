#include <iostream>
#include <vector>
#include "include/include.hpp"

using namespace std;

void imprime_vetor (const vector<int>& vetor, const string& mensagem) {
    cout << mensagem;
    for (int num : vetor) cout << num << " ";
    cout << endl;
}

template<typename Func> // Permite que uma função seja passada como parâmetro
void imprime_sort(vector<int>& vetor, Func sort_func, const string& mensagem) {
    imprime_vetor(vetor, "Vetor original: ");
    sort_func(vetor);
    imprime_vetor(vetor, "Vetor após " + mensagem + ": ");
    cout << endl;
}

int main() {
    int tamanho_array = 5;
    int min_valor = 1;
    int max_valor = 100;

    vector<int> selection_arr = gera_array(tamanho_array, min_valor, max_valor);
    vector<int> insertion_arr = gera_array(tamanho_array, min_valor, max_valor);
    vector<int> buble_arr = gera_array(tamanho_array, min_valor, max_valor);
    vector<int> merge_arr = gera_array(tamanho_array, min_valor, max_valor);
    vector<int> quick_arr = gera_array(tamanho_array, min_valor, max_valor);

    imprime_sort(selection_arr, selection_sort, "Selection Sort");
    imprime_sort(insertion_arr, insertion_sort, "Insertion Sort");
    imprime_sort(buble_arr, bublesort, "Bubble Sort");
    imprime_sort(merge_arr, merge_sort_wrapper, "Merge Sort");
    imprime_sort(quick_arr, quick_sort_wrapper, "Quick Sort");

    return 0;
}