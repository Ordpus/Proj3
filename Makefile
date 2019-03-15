SRC = word_map.c
OBJ = word_map.o
PROG = exec

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)

clean:
<<<<<<< HEAD
	rm -f $(OBJ) $(PROG) *~
=======
	rm -f $(OBJ) $(PROG) *~
>>>>>>> 1f055011d9a3cd373ef08f45533ad3e5350fa065
