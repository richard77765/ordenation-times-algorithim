#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "algoritmos.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// 1. Array de 16 seeds fixas (escolhidas arbitrariamente)
const unsigned int SEEDS[16] = {
    42, 123, 777, 999, 10, 55, 88, 101, 
    202, 303, 404, 505, 606, 707, 808, 909
};

// 2. Função que gera o vetor baseado no índice do teste
vector<int> gerarVetorPorIndice(int indiceNoLoop, int tamanho) {
    // Sempre usará a mesma seed para o mesmo tamanho de vetor
    srand(SEEDS[indiceNoLoop]); 

    vector<int> v(tamanho);
    for (int i = 0; i < tamanho; i++) {
        v[i] = rand() % 100001;
    }
    return v;
}

void executarExperimento() {
    const int inicio = 5000;
    const int passo = 1000;

    // Loop pelos 16 tamanhos (5k a 20k)
    for (int i = 0; i < 16; i++) {
        int n = inicio + (i * passo);

        // Este vetor será IDENTICO para todos os 8 algoritmos 
        // toda vez que você rodar o programa.
        vector<int> vetorBase = gerarVetorPorIndice(i, n);

        cout << "Tamanho: " << n << " | Seed: " << SEEDS[i] << " | Primeiro: " << vetorBase[0] << endl;

        /* funcCronometro(vetor1, funcBuscaX1)
           funcCronometro(vetor2, funcBuscaX2)
           ...
        */
    }
}

int main() {
    executarExperimento();
    return 0;
}
