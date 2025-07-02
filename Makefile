# Define o compilador C++ a ser usado
CXX = g++

# Define as flags de compilação
# -Wall: Habilita todos os warnings (boas práticas)
# -g: Inclui informações de depuração para depuração
# -std=c++17: Usa o padrão C++17 (pode mudar para c++11, c++14, etc., se preferir)
# -I$(INCDIR): Informa ao compilador para procurar arquivos de cabeçalho no diretório 'include/'
CXXFLAGS = -Wall -g -std=c++17 -I$(INCDIR)

# Diretórios
SRCDIR = src       # Diretório onde estão os arquivos fonte (.cpp)
OBJDIR = obj       # Diretório onde os arquivos objeto (.o) serão gerados
INCDIR = include   # Diretório dos arquivos de cabeçalho (.hpp)
CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -I$(INCDIR)

SRCDIR = src
OBJDIR = obj
INCDIR = include
TARGET = atividade_02

SRCS = $(wildcard $(SRCDIR)/*.cpp)
MAIN = main.cpp
HPP_FILES = $(wildcard $(INCDIR)/*.hpp)

OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS)) $(OBJDIR)/main.o

# --- REGRAS DO MAKEFILE ---

# Regra padrão: constrói o executável
all: $(TARGET)

# Regra para criar o diretório de objetos, se ele não existir
# É um alvo "phoney" e será executado se necessário como pré-requisito
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regra para vincular os arquivos objeto e criar o executável
# Depende de todos os arquivos objeto
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regra para compilar cada arquivo .cpp em um arquivo .o no diretório OBJDIR
# $<: o caminho completo para o arquivo .cpp (ex: src/buble_sort.cpp)
# $@: o caminho completo para o arquivo .o (ex: obj/buble_sort.o)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HPP_FILES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra específica para compilar o arquivo main.cpp
$(OBJDIR)/main.o: main.cpp $(HPP_FILES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra de limpeza: remove o diretório de objetos e o executável gerados
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Define alvos "fictícios" (phony targets) que não correspondem a nomes de arquivos
# Isso evita que o make procure por arquivos chamados 'all', 'clean', 'obj', etc.
.PHONY: all clean $(OBJDIR)