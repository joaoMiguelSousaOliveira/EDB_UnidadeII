#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> gera_array(int tamanho, int min_valor, int max_valor) {
    vector<int> array(tamanho);
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min_valor, max_valor);
    for (int i = 0; i < tamanho; i++) {
        array[i] = dis(gen);
    }
    shuffle(array.begin(), array.end(), gen);
    return array;
}

vector<int> gera_array_parcialmente_ordenado (int tamanho, int min_valor, int max_valor) {

    vector<int> array = gera_array(tamanho, min_valor, max_valor);

    auto limite = static_cast<int>(tamanho * 0.5);
    sort(array.begin(), array.begin() + limite);

    return array;
}

vector<int> gera_array_inversamente_ordenado (int tamanho, int min_valor, int max_valor) {

    vector<int> array = gera_array(tamanho, min_valor, max_valor);
    sort(array.begin(), array.end(), greater<int>());

    return array;
}
