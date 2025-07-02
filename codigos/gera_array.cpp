#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<int> gera_array(int tamanho, int min_valor, int max_valor) {
    vector<int> array(tamanho);
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min_valor, max_valor);
    for (int i = 0; i < tamanho; i++) {
        array[i] = dis(gen);
    }
    return array;
}