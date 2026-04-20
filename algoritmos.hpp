#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

// Algoritmos de Ordenação
void bubbleSort(int* a, int n);
void insertionSort(int* a, int n);
void selectionSort(int* a, int n);
void mergeSort(int* a, int n);
void quickSort(int* a, int n);

// Algoritmos de Busca
bool buscaSequencial(int *a, int n, int k);
bool buscaBinaria(int *a, int l, int r, int k);

#endif