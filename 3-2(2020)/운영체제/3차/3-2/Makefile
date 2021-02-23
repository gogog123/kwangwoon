all: gen_file.c schedtest.c
	gcc -o gen_file gen_file.c
	gcc -o schedtest schedtest.c 

gen_file: gen_file.c
	gcc -o gen_file gen_file.c

schedtest: schedtest.c
	gcc -o schedtest schedtest.c

clean:
	rm -rf tmp*
	sync
	echo 3 | sudo tee /proc/sys/vm/drop_caches


