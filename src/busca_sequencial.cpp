#include "../include/include.hpp"
#include <vector>

int busca_sequencial(const vector<int>& vetor, int chave){

    int tamanho_vetor = vetor.size();

    for(int i = 0; i < tamanho_vetor; i ++){
        if(vetor[i]==chave){
            return i;
        }
    } 
    
    return -1;
    
}
