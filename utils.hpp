#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <ctime>
#include <cstdlib>

// 1. Cronômetro Universal
template <typename Func, typename... Args>
double medirTempo(Func algoritmo, Args... argumentos) {
    clock_t t1 = clock();
    algoritmo(argumentos...); 
    clock_t t2 = clock();
    return ((double)(t2 - t1)) / CLOCKS_PER_SEC;
}

// 2. Gerador de Vetores (Pode ser implementado aqui por ser curto)
std::vector<int> gerarVetorConsistente(int tamanho, unsigned int seed) {
    srand(seed);
    std::vector<int> v(tamanho);
    for (int i = 0; i < tamanho; i++) {
        v[i] = rand() % 100001;
    }
    return v;
}

#endif