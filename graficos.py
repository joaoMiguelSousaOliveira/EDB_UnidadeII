import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os

# Leitura dos dados do arquico CSV/resultados.csv
try:
    dados = pd.read_csv('CSV/resultados.csv', delimiter=';', encoding='utf-8')
    print("Dados carregados com sucesso")
    print("Colunas:", dados.columns.tolist())
    print("Tipos únicos:", dados['Tipo de array'].unique())
    print("Métodos únicos:", dados['Método'].unique())
except FileNotFoundError:
    print("Erro: O arquivo 'CSV/resultados.csv' não foi encontrado. Por favor, execute o programa principal para gerar os dados.")
    exit()

# Criação do diretório Graficos se não existir
if not os.path.exists('Graficos'):
    os.makedirs('Graficos')

# Definição das Funções Assintóticas
# Base para as curvas referentes às funções assintóticas
n_teorico = np.logspace(np.log10(100), np.log10(10000), 500)

# Funções Assintóticas
def O_n(n, C):
    return C * n

def O_log_n(n, C):
    return C * np.log(n)

def O_n_log_n(n, C):
    return C * n * np.log(n)

def O_n2(n, C):
    return C * n**2

# Geração dos Gráficos

# Configuração de plotagem
plt.rc('font', size=12)

# Filtra os dados referentes aos métodos de Ordenação
casos_ordenacao = ['Array Aleatório','Array Parcialmente Ordenado','Array Inversamente Ordenado']
metodos_ordenacao = ['Bubble Sort', 'Quick Sort']

# Gráficos para métodos de ordenação
for casos in casos_ordenacao:
    plt.figure(figsize=(12, 8))
    plt.title(f'Análise de Complexidade - {casos}', fontsize=16)
    plt.xlabel('Tamanho do Array (n)', fontsize=14)
    plt.ylabel('Tempo de Execução (nanosegundos)', fontsize=14)

    # Plotando o tempo médio de execução de cada Método de ordenação
    for metodo in metodos_ordenacao:
        dados_metodo_ordenacao = dados[(dados['Tipo de array'] == casos) & (dados['Método'] == metodo)]

        if not dados_metodo_ordenacao.empty:
            # Filtrar apenas dados com tempo > 0 para visualização melhor
            dados_filtrados = dados_metodo_ordenacao[dados_metodo_ordenacao['Tempo (nanosegundos)'] > 0]
            if not dados_filtrados.empty:
                plt.plot(dados_filtrados['Tamanho do array (n)'], dados_filtrados['Tempo (nanosegundos)'], marker='o', label=metodo, linewidth=2, markersize=8)
            else:
                print(f"Aviso: Nenhum dado com tempo > 0 para {metodo} em {casos}.")
    
    # Adicionando as curvas Assintóticas
    plt.plot(n_teorico, O_n2(n_teorico, 0.01), 'k--', label='O(n²)', alpha=0.7)
    plt.plot(n_teorico, O_n_log_n(n_teorico, 20), 'r--', label='O(n log n)', alpha=0.7)

    plt.legend()
    plt.xscale('log')
    plt.yscale('log')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()

    # Salvar o gráfico com um nome de arquivo apropriado
    nome_arquivo = casos.replace(" ", "_").replace("á", "a").replace("ó", "o").lower()
    plt.savefig(f'Graficos/{nome_arquivo}.png', dpi=300, bbox_inches='tight')
    plt.close()

    print(f"Gráfico salvo para {nome_arquivo}.png na pasta 'Graficos'.")

# Filtra os gráficos referentes aos métodos de Busca
casos_busca = [
    'Busca Binária - Melhor Caso',
    'Busca Binária - Pior Caso',
    'Busca Binária - Caso Médio',
    'Busca Sequencial - Melhor Caso',
    'Busca Sequencial - Pior Caso',
    'Busca Sequencial - Caso Médio'
    ]

plt.figure(figsize=(12, 8))
plt.title('Análise de Complexidade - Métodos de Busca', fontsize=16)
plt.xlabel('Tamanho do Array (n)', fontsize=14)
plt.ylabel('Tempo de Execução (nanosegundos)', fontsize=14)

# Cores para diferenciar os métodos
cores = ['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b']

# Plotando o tempo médio de execução de cada Método de busca
for i, metodo in enumerate(casos_busca):

    dados_metodos_busca = dados[(dados['Método'] == metodo) & (dados['Tipo de array'] == 'Array Ordenado')
                                ]
    if not dados_metodos_busca.empty:
        # Filtrar apenas dados com tempo > 0 para visualização melhor
        dados_filtrados = dados_metodos_busca[dados_metodos_busca['Tempo (nanosegundos)'] > 0]

        if not dados_filtrados.empty:
            plt.plot(dados_metodos_busca['Tamanho do array (n)'], dados_metodos_busca['Tempo (nanosegundos)'], marker='o', label=metodo, color=cores[i % len(cores)], linewidth=2, markersize=8)
        else:
            print(f"Aviso: Nenhum dado com tempo > 0 para {metodo} em {casos}.")
    
# Adicionando as curvas Assintóticas
plt.plot(n_teorico, O_log_n(n_teorico, 1), linestyle='--', label='O(log n)', color='black', alpha=0.7)
plt.plot(n_teorico, O_n(n_teorico, 0.01), linestyle='--', label='O(n)', color='red', alpha=0.7)

plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
plt.xscale('log')
plt.yscale('log')
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('Graficos/metodos_busca.png', dpi=300, bbox_inches='tight')
plt.close()
print("Gráfico salvo para metodos_busca.png na pasta 'Graficos'.")

print("Gráficos gerados e salvos na pasta 'Graficos'.")