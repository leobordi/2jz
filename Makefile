# Nome dell'eseguibile
TARGET = 2jz

# Compilatore e flag
CC = gcc
CFLAGS = -O2 -Wall -Wextra -Iinclude
LIBS = -lSDL3

# Cartelle
SRC_DIR = src
OBJ_DIR = obj

# Trova tutti i file .c nella cartella src
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Converte i nomi da .c a .o nella cartella obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regola di default
all: $(TARGET)

# Link dell'eseguibile
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

# Compilazione dei file oggetto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crea la cartella obj se non esiste
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Pulizia dei file compilati
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
