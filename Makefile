all: give_question.o solve.o Sudoku.o
	g++ -o give_question Sudoku.o give_question.o
	g++ -o solve solve.o Sudoku.o
give_question.o: give_question.cpp Sudoku.h
	g++ -c give_question.cpp
solve.o: solve.cpp Sudoku.h
	g++ -c solve.cpp
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
clean:
	rm Sudoku.o give_question.o solve.o

