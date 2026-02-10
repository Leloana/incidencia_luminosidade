# 1. Configurações de Diretórios
SRC_DIR     = src
INCLUDE_DIR = include
OBJ_DIR     = obj
BIN_DIR     = bin

TARGET_NAME = a.exe
TARGET      = $(BIN_DIR)/$(TARGET_NAME)

CXX      = g++

CXXFLAGS = -Wall -g -O2 -I$(INCLUDE_DIR)

# 4. Lista de Fontes
_SRCS = main.cpp SceneParser.cpp Geometry.cpp TargetPoint.cpp FotonPoint.cpp Rectangle.cpp Obstacles.cpp Circle.cpp Line.cpp
# Adiciona o caminho src/ na frente dos nomes
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))

# 5. Lista de Objetos
# Transforma src/main.cpp em obj/main.o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# --- Regras ---

# Regra Principal
all: directories $(TARGET)

# Cria o executável na pasta BIN
$(TARGET): $(OBJS)
	@echo Linkando o executavel em $(TARGET)...
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar cada .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Compilando $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria as pastas necessárias (obj e bin) se não existirem
directories:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Limpeza
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)
	@echo Limpeza concluida.

# Rodar o programa
run: all
	./$(TARGET)

.PHONY: all clean run directories