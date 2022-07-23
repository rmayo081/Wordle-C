#Make the executable
wordle: wordle.o io.o lexicon.o history.o
	gcc wordle.o io.o lexicon.o history.o -o wordle
#Make the wordle.o main componenet
wordle.o: wordle.c lexicon.h history.h io.h
	gcc -Wall -std=c99 -c wordle.c -o wordle.o
#Make the lexicon.o component
lexicon.o: lexicon.c io.h lexicon.h
	gcc -Wall -std=c99 -c lexicon.c -o lexicon.o
#Make the history.o component
history.o: history.c history.h
	gcc -Wall -std=c99 -c history.c -o history.o
#Make the io.o component
io.o: io.c io.h
	gcc -Wall -std=c99 -c io.c -o io.o
#Clean the directory of testing files and components
clean:
	rm -f wordle.o lexicon.o io.o history.o
	rm -f wordle
	rm -f output.txt
	rm -f scores.txt
	rm -f stderr.txt