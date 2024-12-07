CC = gcc
CFLAGS = -Wall

# Filnavne
SRC = main.c gamelogic.c
OBJ = $(SRC:.c=.o)
EXE = battleship

# Standard mål
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

run: $(EXE)
	./$(EXE)