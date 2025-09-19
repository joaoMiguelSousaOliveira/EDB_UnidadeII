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


// Permite passar funções como parâmetros e argumentos variáveis
template<typename Func, typename... Args>
// Calcula o tempo médio de execução de uma função em nanosegundos
long long tempo_medio_execucao(const vector<int>& vetor, Func funcao, Args... args) {
    long long duracao = 0;

    for (int i = 0; i < 100; i++) {

        vector<int> copia_vetor = vetor;
        auto inicio = high_resolution_clock::now();
        funcao(copia_vetor, args...);

        auto fim = high_resolution_clock::now();

        duracao += duration_cast<nanoseconds>(fim - inicio).count();
    }
    return duracao / 100;
}

// Salva os resultados em um arquivo CSV
void salvar_tempo_execucao(const string& arquivo, int n, const string& tipo_array, const string&metodo, long long tempo) {
    ofstream file(arquivo, ios::app);
    if (file.is_open()) {
        file << n << ";" << tipo_array << ";" << metodo << ";" << tempo << "\n";
        file.close();
    } else {
        cerr << "Não foi possível abrir o arquivo: " << arquivo << endl;
    }
}



int main() {

    // Define o nome do arquivo de saída .csv e cria o cabeçalho
    string nome_arquivo_saida = "CSV/resultados.csv";
    ofstream file_out(nome_arquivo_saida);
    file_out << "Tamanho do array (n);Tipo de array;Método;Tempo (nanosegundos)\n";
    file_out.close();

    // Define os tamanhos do array e os valores mínimo e máximo
    vector<int> tamanho_array = {500, 1000, 5000, 10000, 50000};
    int min_valor = 1;
    int max_valor = 1000000;

    // Loop intera para cada tamanho do array
    for (int entrada_n : tamanho_array) {
        cout << "Gerando arrays de tamanho " << entrada_n << "..." << endl;

        // Gera os arrays
        vector<int> array_aleatorio = gera_array_aleatorio(entrada_n, min_valor, max_valor);
        vector<int> array_parcialmente_ordenado = gera_array_parcialmente_ordenado(entrada_n, min_valor, max_valor);
        vector<int> array_inversamente_ordenado = gera_array_inversamente_ordenado(entrada_n, min_valor, max_valor);

        // Métodos de Ordenação

        // Array Aleatório
        // Calcula o tempo médio de execução para cada método de ordenação
        long long tempo_bubble_aleatorio = tempo_medio_execucao(array_aleatorio, bublesort);
        long long tempo_quick_aleatorio = tempo_medio_execucao(array_aleatorio, quick_sort_wrapper);

        // Exibe os resultados no terminal
        cout << "\nResultados dos Métodos de Ordenação para " << entrada_n << " elementos" << "(Array Aleatório): " << endl;
        cout << "Bubble Sort: " << tempo_bubble_aleatorio << " nanosegundos" << endl;
        cout << "Quick Sort: " << tempo_quick_aleatorio << " nanosegundos" << endl;

        // Salva os resultados no arquivo .csv
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Aleatório", "Bubble Sort", tempo_bubble_aleatorio);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Aleatório", "Quick Sort", tempo_quick_aleatorio); 
        

        // Array Inversamente Ordenado
        // Calcula o tempo médio de execução para cada método de ordenação
        long long tempo_bubble_inversamente_ordenado = tempo_medio_execucao(array_inversamente_ordenado, bublesort);
        long long tempo_quick_inversamente_ordenado = tempo_medio_execucao(array_inversamente_ordenado, quick_sort_wrapper);

        // Exibe os resultados no terminal
        cout << "\nResultados dos Métodos de Ordenação para " << entrada_n << " elementos" << "(Array Inversamente Ordenado): " << endl;
        cout << "Bubble Sort: " << tempo_bubble_inversamente_ordenado << " nanosegundos" << endl;
        cout << "Quick Sort: " << tempo_quick_inversamente_ordenado << " nanosegundos" << endl;

        // Salva os resultados no arquivo .csv
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Inversamente Ordenado", "Bubble Sort", tempo_bubble_inversamente_ordenado);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Inversamente Ordenado", "Quick Sort", tempo_quick_inversamente_ordenado); 
        
        // Array Parcialmente Ordenado
        // Calcula o tempo médio de execução para cada método de ordenação
        long long tempo_bubble_parcialmente_ordenado = tempo_medio_execucao(array_parcialmente_ordenado, bublesort);
        long long tempo_quick_parcialmente_ordenado = tempo_medio_execucao(array_parcialmente_ordenado, quick_sort_wrapper);

        // Exibe os resultados no terminal
        cout << "\nResultados dos Métodos de Ordenação para " << entrada_n << " elementos" << "(Array Parcialmente Ordenado): " << endl;
        cout << "Bubble Sort: " << tempo_bubble_parcialmente_ordenado << " nanosegundos" << endl;
        cout << "Quick Sort: " << tempo_quick_parcialmente_ordenado << " nanosegundos" << endl;

        // Salva os resultados no arquivo .csv
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Parcialmente Ordenado", "Bubble Sort", tempo_bubble_parcialmente_ordenado);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Parcialmente Ordenado", "Quick Sort", tempo_quick_parcialmente_ordenado); 

        // Métodos de Busca

        // Gera e garante que o array está ordenado para busca binária
        vector<int> array_ordenado = array_aleatorio;
        quick_sort_wrapper(array_ordenado); 

        // Define os casos principais dos métodos de busca
        int melhor_caso = array_ordenado[0]; // Primeiro elemento
        int pior_caso = array_ordenado[entrada_n - 1]; // Último elemento
        int caso_medio = array_ordenado[entrada_n / 2]; // Elemento do meio

        cout << "\nResultados dos Métodos de Busca (Array ordenado, tamanho " << entrada_n << "):" << endl;
        cout << "--------------------------------------------------" << endl;

        // Busca Binária
        // Calcula o tempo médio de execução para os pricipais casos da busca binária
        long long tempo_busca_binaria_melhor = tempo_medio_execucao(array_ordenado, busca_binaria, melhor_caso);
        long long tempo_busca_binaria_pior = tempo_medio_execucao(array_ordenado, busca_binaria, pior_caso);
        long long tempo_busca_binaria_medio = tempo_medio_execucao(array_ordenado, busca_binaria, caso_medio);

        // Exibe os resultados no terminal
        cout << "\nResultados dos Métodos de Busca para " << entrada_n << " elementos: " << endl;

        cout << "Busca Binária (Melhor caso) " << tempo_busca_binaria_melhor << " nanosegundos" << endl;
        cout << "Busca Binária (Pior caso) " << tempo_busca_binaria_pior << " nanosegundos" << endl;
        cout << "Busca Binária (Médio caso) " << tempo_busca_binaria_medio << " nanosegundos" << endl;
        
        // Salva os resultados no arquivo .csv
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Ordenado", "Busca Binária - Melhor Caso", tempo_busca_binaria_melhor);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Ordenado", "Busca Binária - Pior Caso", tempo_busca_binaria_pior);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Ordenado", "Busca Binária - Caso Médio", tempo_busca_binaria_medio);

        // Busca Sequencial
        // Calcula o tempo médio de execução para os pricipais casos da busca sequencial
        long long tempo_busca_sequencial_melhor = tempo_medio_execucao(array_ordenado, busca_sequencial, melhor_caso);
        long long tempo_busca_sequencial_pior = tempo_medio_execucao(array_ordenado, busca_sequencial, pior_caso);
        long long tempo_busca_sequencial_medio = tempo_medio_execucao(array_ordenado, busca_sequencial, caso_medio);

        // Exibe os resultados no terminal
        cout << "Busca Sequencial (Melhor caso) " << tempo_busca_sequencial_melhor << " nanosegundos" << endl;
        cout << "Busca Sequencial (Pior caso) " << tempo_busca_sequencial_pior << " nanosegundos" << endl;
        cout << "Busca Sequencial (Médio caso) " << tempo_busca_sequencial_medio << " nanosegundos" << endl;
        
        // Salva os resultados no arquivo .csv
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Ordenado", "Busca Sequencial - Melhor Caso", tempo_busca_sequencial_melhor);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n , "Array Ordenado", "Busca Sequencial - Pior Caso", tempo_busca_sequencial_pior);
        salvar_tempo_execucao(nome_arquivo_saida, entrada_n, "Array Ordenado", "Busca Sequencial - Caso Médio", tempo_busca_sequencial_medio);

        cout << "Dados salvos para N = " << entrada_n << "\n" << endl;
        cout << "--------------------------------------------------" << endl;
    }

    return 0;
}