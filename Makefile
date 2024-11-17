# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# Dossiers
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Fichiers sources et objets
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/dominon

# Règle par défaut
all: create_dirs $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	@echo "Linking: $(TARGET)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling: $<"
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Création des répertoires nécessaires (compatible Windows)
create_dirs:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Nettoyage des fichiers générés
clean:
	@echo "Cleaning up..."
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)

.PHONY: all clean create_dirs

#Pour compiler le projet utiliser la commande : mingw32-make sur VsCode
#Pour executer le projet utiliser la commande : ./bin/dominion 