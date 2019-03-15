SRC = word_map.c
OBJ = word_map.o
PROG = exec

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)

clean:
	rm -f $(OBJ) $(PROG) *~
