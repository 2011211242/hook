main: myhook.c main.c
	gcc -o libmymalloc.so -fPIC -shared -D_GNU_SOURCE myhook.c -ldl 
	gcc -o main main.c -L./ -lmymalloc
#
clean:
	rm main libmymalloc.so
