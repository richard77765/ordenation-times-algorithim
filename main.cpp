#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>        // <-- Nova biblioteca para formatar a tabela
#include "algoritmos.hpp" 
#include "utils.hpp"      

using namespace std;

const unsigned int SEEDS[30] = {
    42, 123, 777, 999, 10, 55, 88, 101, 
    202, 303, 404, 505, 606, 707, 808, 909, 
    143, 232, 365, 474 , 535, 676, 767, 
    897, 976, 105, 117, 126, 153, 144
};

vector<int> gerarVetorPorIndice(int indiceNoLoop, int tamanho) {
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
    const int repeticoes = 30; 

    ofstream arquivoCSV("tempos_ordenacao_busca.csv");
    arquivoCSV << "Tamanho,BubbleSort,InsertionSort,SelectionSort,MergeSort,QuickSort,BuscaSequencial,BuscaBinaria\n";

    cout << "Iniciando experimento. Aguarde...\n\n";

    // --- IMPRESSÃO DO CABEÇALHO DA TABELA NO TERMINAL ---
    cout << left 
         << setw(10) << "Tamanho" << " | "
         << setw(10) << "Bubble"  << " | "
         << setw(10) << "Insert"  << " | "
         << setw(10) << "Select"  << " | "
         << setw(10) << "Merge"   << " | "
         << setw(10) << "Quick"   << " | "
         << setw(10) << "B.Seq"   << " | "
         << setw(10) << "B.Bin"   << "\n";
    cout << string(105, '-') << "\n";

    // Configura o terminal para imprimir números float com 6 casas decimais fixas
    cout << fixed << setprecision(6);

    for (int i = 0; i < 16; i++) {
        int n = inicio + (i * passo);
        
        double tot_bubble = 0.0, tot_insertion = 0.0, tot_selection = 0.0;
        double tot_merge = 0.0, tot_quick = 0.0;
        double tot_seq = 0.0, tot_bin = 0.0;

        for (int exec = 0; exec < repeticoes; exec++) {
            srand(exec);
            vector<int> vetorBase(n);
            for (int x = 0; x < n; x++) vetorBase[x] = rand() % 100001;

            vector<int> vBubble = vetorBase;
            tot_bubble += medirTempo(bubbleSort, vBubble.data(), n);

            vector<int> vInsert = vetorBase;
            tot_insertion += medirTempo(insertionSort, vInsert.data(), n);

            vector<int> vSelect = vetorBase;
            tot_selection += medirTempo(selectionSort, vSelect.data(), n);

            vector<int> vMerge = vetorBase;
            tot_merge += medirTempo(mergeSort, vMerge.data(), n);

            vector<int> vQuick = vetorBase;
            tot_quick += medirTempo(quickSort, vQuick.data(), n);

            int k = rand() % 100001; 
            clock_t t1, t2;

            // Busca Sequencial — vetor não precisa estar ordenado
            vector<int> vSeq = vetorBase;
            t1 = clock();
            buscaSequencial(vSeq.data(), n, k);
            t2 = clock();
            tot_seq += ((double)(t2 - t1)) / CLOCKS_PER_SEC;

            // Busca Binária — usa vQuick que já está ordenado pelo quickSort acima
            t1 = clock();
            buscaBinaria(vQuick.data(), 0, n - 1, k);
            t2 = clock();
            tot_bin += ((double)(t2 - t1)) / CLOCKS_PER_SEC;
        }

        double med_bub = tot_bubble / repeticoes;
        double med_ins = tot_insertion / repeticoes;
        double med_sel = tot_selection / repeticoes;
        double med_mer = tot_merge / repeticoes;
        double med_qui = tot_quick / repeticoes;
        double med_seq = tot_seq / repeticoes;
        double med_bin = tot_bin / repeticoes;

        // --- IMPRESSÃO DA LINHA DE DADOS NA TABELA ---
        cout << left 
             << setw(10) << n       << " | "
             << setw(10) << med_bub << " | "
             << setw(10) << med_ins << " | "
             << setw(10) << med_sel << " | "
             << setw(10) << med_mer << " | "
             << setw(10) << med_qui << " | "
             << setw(10) << med_seq << " | "
             << setw(10) << med_bin << "\n";

        // Escreve a mesma linha no CSV
        arquivoCSV << n << "," << med_bub << "," << med_ins << "," << med_sel << "," 
                   << med_mer << "," << med_qui << "," << med_seq << "," << med_bin << "\n";
    }

    arquivoCSV.close();
    cout << string(105, '-') << "\n";
    cout << "Experimento finalizado! Arquivo 'tempos_ordenacao_busca.csv' gerado com sucesso.\n";
}

int main() {
    executarExperimento();
    return 0;
}
