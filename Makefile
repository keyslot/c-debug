CC=gcc
TEST=test
SRC=src/debug
LIB=-Iinclude/debug
FLAGS=-Wall -Wextra 

.PHONY : clean main test

main :   
	$(CC) -o $(TEST).exe $(TEST)/*.c $(SRC)/*.c $(LIB) $(FLAGS)

test:   main 
	./$(TEST).exe

clean :
	rm -f $(TEST).exe $(TEST).log
