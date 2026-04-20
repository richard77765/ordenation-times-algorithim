#include "algoritmos.hpp"

//Algoritimos de Ordenação _________________________________________________________________________________________________
// Implementação do algorítimo de ordenação Bubble Sort
void bubbleSort(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int aux = a[j - 1];
                a[j - 1] = a[j];
                a[j] = aux;
            }
        }
    }
}

// Implementação do algorítimo de ordenação Busca Binária
void insertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int e = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > e) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = e;
    }
}

// Implementação do algorítimo de ordenação Selection Sort
void selectionSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int aux = a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }
}

// Implementação do algorítimo de ordenação Merge Sort 
void merge(int* a, int ini, int fim, int meio) {
    int pos1 = ini;
    int pos2 = meio + 1;
    int posc = 0;
    int *c = new int[fim - ini + 1];

    while (pos1 <= meio && pos2 <= fim) {
        if (a[pos1] < a[pos2]) {
            c[posc] = a[pos1];
            pos1++;
        } else {
            c[posc] = a[pos2];
            pos2++;
        }
        posc++;
    }

    for (; pos1 <= meio; pos1++, posc++)
        c[posc] = a[pos1];
    for (; pos2 <= fim; pos2++, posc++)
        c[posc] = a[pos2];
        
    int j = 0;
    for (int i = ini; i <= fim; i++, j++)
        a[i] = c[j];
        
    delete[] c;
}

void msaux(int* a, int i, int f) {
    if (i < f) {
        int meio = (f + i) / 2;
        msaux(a, i, meio);
        msaux(a, meio + 1, f);
        merge(a, i, f, meio);
    }
}

void mergeSort(int* a, int n) {
    msaux(a, 0, n - 1);
}

// Implementação do algorítimo de ordenação Quick Sort
int particao(int* a, int l, int r) {
    int pivo = a[l];
    int i = l;
    int j = r;
    int aux;
    
    while (i < j) {
        // Correção: a trava 'i <= r' impede o acesso indevido à memória
        while (i <= r && a[i] <= pivo) {
            i++;
        }
        while (a[j] > pivo && j != l) {
            j--;
        }
        if (i < j) {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    } //while
    
    aux = a[j];
    a[j] = a[l];
    a[l] = aux;
    
    return j;
} //particao

void qsAux(int* a, int i, int f) {
    if (i < f) {
        int q = particao(a, i, f);
        qsAux(a, i, q - 1);
        qsAux(a, q + 1, f);
    }
}

void quickSort(int* a, int n) {
    qsAux(a, 0, n - 1);
}

//Algoritimos de busca ___________________________________________________________________________________________________
//Algorítimo de Busca Sequencial
bool buscaSequencial(int *a, int n, int k) {
    for(int i = 0; i < n; i++)
        if(a[i] == k) return true;

    return false;
}

//Algorítimo de Busca Binária
bool buscaBinaria(int *a, int l, int r, int k) {
    int m = (l + r) / 2;
    if (a[m] == k) {
        return true;
    }
    else if (l < r) {
        if (a[m] > k)
            return buscaBinaria(a, l, m - 1, k);
        else if (a[m] < k)
            return buscaBinaria(a, m + 1, r, k);
    }
    return false;
}
