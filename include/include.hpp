#pragma once

#include <vector>

using namespace std;

// Buble Sort
void bublesort(vector<int>& vetor);

// Insertion Sort
void insertion_sort(vector<int>& vetor);

// Selection Sort
void selection_sort(vector<int>& vetor);

// Quick Sort
void quick_sort(vector<int>& vetor, int inicio, int fim);

int partition(vector<int>& vetor, int inicio, int fim);

void quick_sort_wrapper(vector<int>& vetor);

// Merge Sort
void merge(vector<int>& vetor, int inicio, int meio, int fim);

void merge_sort(vector<int>& vetor, int inicio, int fim);

void merge_sort_wrapper(vector<int>& vetor);

// Gerador de Array
vector<int> gera_array(int tamanho, int min_valor, int max_valor);

// Gerador de Array Parcialmente Ordenado
vector<int> gera_array_parcialmente_ordenado (int tamanho, int min_valor, int max_valor);

// Gerador de Array Inversamente Ordenado
vector<int> gera_array_inversamente_ordenado (int tamanho, int min_valor, int max_valor);