cacu: add_float.o add_int.o sub_float.o sub_int.o cacu.o
	gcc -o cacu ./add/add_float.o ./add/add_int.o ./sub/sub_float.o ./sub/sub_int.o cacu.o
add_float.o:
	gcc -c -o add/add_float.o add/add_float.c
add_int.o:
	gcc -c -o add/add_int.o add/add_int.c
sub_float.o:
	gcc -c -o sub/sub_float.o sub/sub_float.c
sub_int.o:
	gcc -c -o sub/sub_int.o sub/sub_int.c
cacu.o:
	gcc -c -o cacu.o cacu.c
clean:
	rm -rf ./add/add_float.o ./add/add_int.o ./sub/sub_float.o \
		./sub/sub_int.o cacu.o cacu
