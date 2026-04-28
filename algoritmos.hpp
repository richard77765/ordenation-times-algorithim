#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

// Algoritmos de Ordenação
void algBubbleSort(int* a, int n);
void algInsertionSort(int* a, int n);
void algSelectionSort(int* a, int n);
void algMergeSort(int* a, int n);
void algQuickSort(int* a, int n);

// Algoritmos de Busca
bool algBuscaSeq(int *a, int n, int k);
bool algBuscaBin(int *a, int l, int r, int k);

#endif