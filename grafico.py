import matplotlib.pyplot as plt
import pandas as pd

# Carregar dados
data = pd.read_csv('resultados.csv')

plt.figure(figsize=(12, 7))

# Plotar cada algoritmo
plt.plot(data['n'], data['bubble'], label='Bubble Sort', marker='o')
plt.plot(data['n'], data['insertion'], label='Insertion Sort', marker='s')
plt.plot(data['n'], data['selection'], label='Selection Sort', marker='^')
plt.plot(data['n'], data['quick'], label='Quick Sort', marker='x')
plt.plot(data['n'], data['merge'], label='Merge Sort', marker='d')

plt.title('Comparação de Algoritmos de Ordenação')
plt.xlabel('Tamanho do Vetor (n)')
plt.ylabel('Tempo Médio (segundos)')
plt.legend()
plt.grid(True)
plt.savefig('grafico_resultados.png') # Salva a imagem para o relatório
plt.show()
