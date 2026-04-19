#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include "algoritmos.hpp"
#include <fstream>

using namespace std;

// Definição de um tipo para facilitar a leitura: 
// Uma função que recebe dois ints e retorna um int
typedef int (*EstrategiaCalculo)(int, int);

// Função de processar o alg e salvar o tempo na matriz
void processarESalvarMatriz(vector<vector<int>>& mat, EstrategiaCalculo algoritmo, string nomeArquivo) {
    int linhas = mat.size();
    int colunas = mat[0].size();

    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                mat[i][j] = algoritmo(i, j); // Chama a função recebida por parâmetro
                arquivo << mat[i][j] << (j == colunas - 1 ? "" : ",");// Salva no arquivo
            }
            arquivo << "\n";
        }
        arquivo.close();
        cout << "Arquivo " << nomeArquivo << " gerado com sucesso!" << endl;
    }
}

int somaIndices(int a, int b) {
    return a + b;
}

int multiplicaIndices(int a, int b) {
    return a * b;
}

//-----------------------------------------------------------------------------

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
    const int L = 30;
    const int C = 16;
    vector<vector<int>> matriz(L, vector<int>(C, 0));

    // Função processarESalvarMatriz com somaIndices como parametro
    processarESalvarMatriz(matriz, somaIndices, "soma.csv");

    // Função processarESalvarMatriz com multiplicaIndices como parametro
    processarESalvarMatriz(matriz, multiplicaIndices, "multiplicacao.csv");

    return 0;
}
