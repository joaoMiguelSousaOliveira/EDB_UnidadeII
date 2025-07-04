import matplotlib.pyplot as plt
import pandas as pd

# Conjunto de dados aleatórios

cores = ['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd']
dados = pd.read_csv('CSV/resultados.csv', delimiter=';', encoding='utf-8')

fig, ax = plt.subplots(figsize=(10, 6))

plt.title('Tempo Médio: Conjunto de Dados Aleatórios')
plt.xlabel('Método de Ordenação')
plt.ylabel('Tempo Médio (microsegundos)')
plt.grid(True)  

plt.bar(dados['Método de ordenação'], dados['Tempo médio (microsegundos)'], color=cores[:len(dados)])
plt.savefig('graficos/grafico_aleatorios.png')
# Conjunto de dados parcialmente ordenados

dados_parcialmente = pd.read_csv('CSV/resultados_parcialmente_ordenado.csv', delimiter=';', encoding='utf-8')

fig, ax = plt.subplots(figsize=(10, 6))

plt.title('Tempo Médio: Conjunto de Dados Parcialmente Ordenados')
plt.xlabel('Método de Ordenação')
plt.ylabel('Tempo Médio (microsegundos)')
plt.grid(True)  

plt.bar(dados_parcialmente['Método de ordenação'], dados_parcialmente['Tempo médio (microsegundos)'], color=cores[:len(dados_parcialmente)])
plt.savefig('graficos/grafico_parcialmente.png')

# Conjunto de dados inversamente ordenados

dados_inversamente = pd.read_csv('CSV/resultados_inversamente_ordenado.csv', delimiter=';', encoding='utf-8')

fig, ax = plt.subplots(figsize=(10, 6))

plt.title('Tempo Médio: Conjunto de Dados Inversamente Ordenados')
plt.xlabel('Método de Ordenação')
plt.ylabel('Tempo Médio (microsegundos)')
plt.legend()
plt.grid(True)  

plt.bar(dados_inversamente['Método de ordenação'], dados_inversamente['Tempo médio (microsegundos)'], color=cores[:len(dados_inversamente)])
plt.savefig('graficos/grafico_inversamente.png')


plt.show()