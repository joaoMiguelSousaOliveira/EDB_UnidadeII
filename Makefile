# Define o compilador C++ a ser usado
CXX = g++


CXXFLAGS = -Wall -g -std=c++17 -I$(INCDIR)

CSV_DIR = CSV
PNG_DIR = Graficos
OBJDIR = obj       
INCDIR = include   
SRCDIR = src
OBJDIR = obj
TARGET = aplicacao

SRCS = $(wildcard $(SRCDIR)/*.cpp)
HPP_FILES = $(wildcard $(INCDIR)/*.hpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS)) $(OBJDIR)/main.o

all: $(TARGET) graficos

graficos: 
	python3 graficos.py


$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HPP_FILES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(OBJDIR)/main.o: main.cpp $(HPP_FILES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)
	rm -f $(CSV_DIR)/*.csv
	rm -f $(PNG_DIR)/*.png

.PHONY: all clean 