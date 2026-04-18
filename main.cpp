#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include "algoritmos.hpp"

using namespace std;

// Função para gerar vetor aleatório
vector<int> gerarVetor(int n) {
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = rand() % 100001;
    return v;
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (a[j] > a[j-1]) {
                int aux = a[j-1];
                a[j-1] = a[j];
                a[j] = aux;
            }
        }
    }
}

double medirTempo(void (*algoritmo)(vector<int>&), int n) {
    double totalTime = 0;
    for(int i = 0; i < 30; i++) {
        vector<int> v = gerarVetor(n);
        clock_t t1 = clock();
        algoritmo(v);
        clock_t t2 = clock();
        totalTime += ((double)(t2 - t1)) / CLOCKS_PER_SEC;
    }
    return totalTime / 30.0;
}

int main() {
    srand(time(NULL));
    ofstream arquivo("resultados.csv");
    
    // Cabeçalho do CSV
    arquivo << "n,bubble,insertion,selection,quick,merge" << endl;

    for(int n = 5000; n <= 20000; n += 1000) {
        cout << "Testando n = " << n << "..." << endl;
        
        double tBubble = medirTempo(bubbleSort, n);
        double tInsert = medirTempo(insertionSort, n);
        double tSelect = medirTempo(selectionSort, n);
        
        // Para Quick e Merge que pedem parâmetros extras, 
        // você pode criar um "wrapper" ou ajustar a medirTempo
        
        arquivo << n << "," << tBubble << "," << tInsert << "," << tSelect << endl;
    }

    arquivo.close();
    cout << "Testes concluídos! Dados salvos em resultados.csv" << endl;
    return 0;
}
