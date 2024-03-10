all: compile run work

compile:
	g++ -IC:\SFML-2.5.1\include -c test.cpp -o test.o

run:
	g++ -LC:\SFML-2.5.1\lib .\test.o -o test.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows

work:
	.\test


