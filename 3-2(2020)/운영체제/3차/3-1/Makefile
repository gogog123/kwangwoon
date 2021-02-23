all: gen_file.c Thread.c
	gcc -o gen_file gen_file.c
	gcc -pthread -o Thread Thread.c

gen_file: gen_file.c
	gcc -o gen_file gen_file.c

Thread: Thread.c
	gcc -pthread -o Thread Thread.c

clean:
	rm -rf tmp*
	sync
	echo 3 | sudo tee /proc/sys/vm/drop_caches

