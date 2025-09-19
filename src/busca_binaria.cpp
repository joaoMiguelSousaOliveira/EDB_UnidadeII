#include "../include/include.hpp"
#include <vector>

int busca_binaria(const vector<int>& vetor, int chave ){
    
    int tamanho_vetor = vetor.size();

    int esquerda = 0, direita = tamanho_vetor - 1;
    
    while (esquerda <= direita){
        int meio = (direita + esquerda) / 2;
        if (vetor[meio] == chave){
            return meio;
        }
        else if(vetor[meio] < chave ){
            esquerda = meio +1;
        }
        else{
            direita = meio -1;
        }
    } 
    
    return -1;
    
}