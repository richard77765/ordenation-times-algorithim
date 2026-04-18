# Exercício: Relatório de Desempenho de Algoritmos de Ordenação

## 1. Objetivo
Desenvolver um relatório técnico comparando o tempo de execução de diferentes algoritmos de ordenação sob condições controladas.

---

## 2. Parâmetros dos Testes
Para a realização do experimento, devem ser seguidos os seguintes critérios:

* **Tamanho dos Vetores:** De 5.000 a 20.000 elementos.
* **Passo de Incremento:** 1.000 elementos (ex: 5.000, 6.000, 7.000...).
* **Dados de Entrada:** Vetores preenchidos com **números aleatórios** no intervalo $[0, 100.000]$.
* **Amostragem:** Realizar uma média de **30 execuções** para cada tamanho de vetor.

---

## 3. Requisitos da Entrega

### 📊 Relatório Técnico
O documento deve conter a descrição dos algoritmos utilizados, a metodologia aplicada e as tabelas com os tempos médios coletados.

### 📈 Análise Gráfica
Gere um gráfico de linhas relacionando o **Tamanho do Vetor (Eixo X)** com o **Tempo Médio de Execução (Eixo Y)**. O gráfico deve conter as curvas de todos os algoritmos testados para fins de comparação.

---

## 4. Tabela de Resultados (Sugestão)

| Tamanho do Vetor | Algoritmo A (ms) | Algoritmo B (ms) | Algoritmo C (ms) |
| :--- | :--- | :--- | :--- |
| 5.000 | | | |
| 6.000 | | | |
| ... | | | |
| 20.000 | | | |

---

## 5. Tabela de Resultados (Sugestão)
###Detalhe da estrutura dos teste
* cada teste nos algoritimos de ordenação será executado 16/30 = 480x
* poderiamos salvar a seed junto com o tempo mas como sabemos qual a seed usar previamente podemos salvar apenas uma matriz(vetor de vetore)
  
### Funções:
* Cria um novo vetor com valor do passo incrementando no valor
* Preenche o vetor com numeros aleatorios de 0 a 100000 respeitando a seed
* Salva o tempo de execução em uma matriz 16x30 respeitando cada iteração e depois exporta em txt a matriz 

