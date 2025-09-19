#pragma once

#include <vector>

using namespace std;

// Buble Sort
void bublesort(vector<int>& vetor);

// Quick Sort
void quick_sort(vector<int>& vetor, int inicio, int fim);

int partition(vector<int>& vetor, int inicio, int fim);

void quick_sort_wrapper(vector<int>& vetor);

// Busca Binária
int busca_binaria(const vector<int>& vetor, int chave);

// Busca Sequencial
int busca_sequencial(const vector<int>& vetor, int chave);

// Gerador de Array
vector<int> gera_array_aleatorio(int tamanho, int min_valor, int max_valor);

// Gerador de Array Parcialmente Ordenado
vector<int> gera_array_parcialmente_ordenado (int tamanho, int min_valor, int max_valor);

// Gerador de Array Inversamente Ordenado
vector<int> gera_array_inversamente_ordenado (int tamanho, int min_valor, int max_valor);