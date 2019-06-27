all: install clean

install:
	cp src/*.c .
	cp inc/*.h .
	clang -std=c11 -Wall -Werror -Wextra -Wpedantic -lncurses -o endgame *.c

uninstall:
	rm -rf endgame

clean:
	rm -rf *.c
	rm -rf *.h
	rm -rf *.o

reinstall: uninstall install clean
