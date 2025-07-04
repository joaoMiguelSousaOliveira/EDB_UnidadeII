import matplotlib.pyplot as plt
import pandas as pd

dados = pd.read_csv('CSV/resultados.csv', delimiter=';', encoding='utf-8')

fig, ax = plt.subplots(figsize=(10, 6))

plt.title('Tempo Médio: Conjunto de Dados Aleatórios')
plt.xlabel('Método de Ordenação')
plt.ylabel('Tempo Médio (microsegundos)')

plt.bar(dados['Método de ordenação'], dados['Tempo médio (microsegundos)'], color='b')

plt.show()