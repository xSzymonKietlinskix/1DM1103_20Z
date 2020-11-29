DEPS=main.o czytanie.o liczenie.o

main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lm

%.o: %.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

test: main
	./main norm dane.txt
