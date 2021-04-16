CC=clang
CFLAGS=-I. -O2
tests_build:
	$(CC) probabil.c ./tests/tests.c -o full-tests

tests_run:
	./full-tests

tests:
	tests_build
	tests_run

lib:
	$(CC) -shared -o libprobabil.so -fPIC probabil.c

clean:
	rm -f ./full-tests ./libprobabil.so 
