#include <iostream>
#include <vector>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <string>
#include "include/include.hpp"

using namespace std;
namespace fs = std::filesystem;
using namespace std::chrono;



template<typename Func>
long long tempo_medio_exec(const vector<int>& vetor, Func sort_func){
    long long duracao = 0;

    for (int i = 0; i < 100; i++) {

        vector<int> copia_vetor = vetor;
        auto inicio = high_resolution_clock::now();
        sort_func(copia_vetor);

        auto fim = high_resolution_clock::now();

        duracao += duration_cast<microseconds>(fim - inicio).count();
    }
    return duracao / 100;
}

void mostrar_tempo_exec(const string& mensagem, const vector<int>& vetor) {
    cout << "Selection Sort: " << tempo_medio_exec(vetor, selection_sort) << " microsegundos" << endl;
    cout << "Insertion Sort: " << tempo_medio_exec(vetor, insertion_sort) << " microsegundos" << endl;
    cout << "Bubble Sort: " << tempo_medio_exec(vetor, bublesort) << " microsegundos" << endl;
    cout << "Merge Sort: " << tempo_medio_exec(vetor, merge_sort_wrapper) << " microsegundos" << endl;
    cout << "Quick Sort: " << tempo_medio_exec(vetor, quick_sort_wrapper) << " microsegundos" << endl;
    cout << endl;
}

void salvar_tempo_exec(const string& arquivo, const vector<int>& vetor) {
    ofstream file(arquivo);
    file << "Método de ordenação;Tempo médio (microsegundos)\n";
    file << "Selection Sort;" << tempo_medio_exec(vetor, selection_sort) << "\n";
    file << "Insertion Sort;" << tempo_medio_exec(vetor, insertion_sort) << "\n";
    file << "Bubble Sort;" << tempo_medio_exec(vetor, bublesort) << "\n";
    file << "Merge Sort;" << tempo_medio_exec(vetor, merge_sort_wrapper) << "\n";
    file << "Quick Sort;" << tempo_medio_exec(vetor, quick_sort_wrapper) << "\n";
    file.close();
}



int main() {
    int tamanho_array = 10000;
    int min_valor = 1;
    int max_valor = 100;

    vector<int> array = gera_array(tamanho_array, min_valor, max_valor);
    vector<int> array_parcialmente_ordenado = gera_array_parcialmente_ordenado(tamanho_array, min_valor, max_valor);
    vector<int> array_inversamente_ordenado = gera_array_inversamente_ordenado(tamanho_array, min_valor, max_valor);

    cout << "Resultados para um array de tamanho " << tamanho_array << " com valores entre " << min_valor << " e " << max_valor << ":" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Array Aleatório:" << endl << endl;
    mostrar_tempo_exec("Array Aleatório", array);

    cout << "Array Parcialmente Ordenado:" << endl << endl;
    mostrar_tempo_exec("Array Parcialmente Ordenado", array_parcialmente_ordenado);

    cout << "Array Inversamente Ordenado:" << endl << endl;
    mostrar_tempo_exec("Array Inversamente Ordenado", array_inversamente_ordenado);
    
    salvar_tempo_exec("CSV/resultados.csv", array);
    salvar_tempo_exec("CSV/resultados_parcialmente_ordenado.csv", array_parcialmente_ordenado);
    salvar_tempo_exec("CSV/resultados_inversamente_ordenado.csv", array_inversamente_ordenado); 

    return 0;
}