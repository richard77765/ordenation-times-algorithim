#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "algoritmos.hpp" 

using namespace std;

// cronometro
template <typename Func, typename... Args>
double medirTempo(Func algoritmo, Args... argumentos) {
    clock_t t1 = clock();
    algoritmo(argumentos...);
    clock_t t2 = clock();
    return ((double)(t2 - t1)) / CLOCKS_PER_SEC;
}

void executarExperimento() {
    const int inicio = 5000;
    const int passo = 1000;
    const int repeticoes = 30; 

    ofstream arquivoCSV("tempos_ordenacao_busca.csv");
    arquivoCSV << fixed << setprecision(9);
    arquivoCSV << "Tamanho,AlgBubbleSort,AlgInsertionSort,AlgSelectionSort,AlgMergeSort,AlgQuickSort,AlgBuscaSequencial,AlgBuscaBinaria\n";

    cout << "Iniciando experimento. Aguarde...\n\n";

    // impressao do header no terminal
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

    // configura o terminal para retornar os segundos com 6 casas decimais 
    cout << fixed << setprecision(6);

    for (int i = 0; i < 16; i++) {
        int n = inicio + (i * passo); // definindo o tamanho do vetor para cada iteração
        
        double tot_bubble = 0.0, tot_insertion = 0.0, tot_selection = 0.0,
         tot_merge = 0.0, tot_quick = 0.0, tot_seq = 0.0, tot_bin = 0.0;

        for (int exec = 0; exec < repeticoes; exec++) {
            srand(exec);
            vector<int> vetorBase(n); // criando o vetor com tamanho n
            for (int x = 0; x < n; x++) vetorBase[x] = rand() % 100001; // insere números entre 0 e 100000 no vetor base

            vector<int> vBubble = vetorBase;
            tot_bubble += medirTempo(algBubbleSort, vBubble.data(), n);

            vector<int> vInsert = vetorBase;
            tot_insertion += medirTempo(algInsertionSort, vInsert.data(), n);

            vector<int> vSelect = vetorBase;
            tot_selection += medirTempo(algSelectionSort, vSelect.data(), n);

            vector<int> vMerge = vetorBase;
            tot_merge += medirTempo(algMergeSort, vMerge.data(), n);

            vector<int> vQuick = vetorBase;
            tot_quick += medirTempo(algQuickSort, vQuick.data(), n);

                int k = rand() % 100001;  // valor a ser buscado, entre 0 e 100000

            vector<int> vSeq = vetorBase;
            tot_seq += medirTempo(algBuscaSeq, vSeq.data(), n, k);

            tot_bin += medirTempo(algBuscaBin, vQuick.data(), 0, n - 1, k);
        }

        double med_bub = tot_bubble / repeticoes;
        double med_ins = tot_insertion / repeticoes;
        double med_sel = tot_selection / repeticoes;
        double med_mer = tot_merge / repeticoes;
        double med_qui = tot_quick / repeticoes;
        double med_seq = tot_seq / repeticoes;
        double med_bin = tot_bin / repeticoes;

        // impressao dos dados na tabela
        cout << left 
             << setw(10) << n       << " | "
             << setw(10) << med_bub << " | "
             << setw(10) << med_ins << " | "
             << setw(10) << med_sel << " | "
             << setw(10) << med_mer << " | "
             << setw(10) << med_qui << " | "
             << setw(10) << med_seq << " | "
             << setw(10) << med_bin << "\n";

        // escreve a mesma linha no CSV
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
