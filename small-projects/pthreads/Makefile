target="pthreads"
all:
	make build
	make run
build:
	cc pthreads-test.c -o pthreads-test -O3 -Wall -Wextra -lpthread
run: pthreads-test
	./pthreads-test
