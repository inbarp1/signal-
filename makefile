all: signal.c
	gcc -o yas signal.c
run: all
	./yas