#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


void print_usage(){
	printf("Usage: ./mycp file1 file2\n");
}

//num of arhuments, array of strings
int main(int argc, char *argv[]){
	int i;
	int fin, fout;
	char buffer[10];
	int bytes_read;
	int num_iter=0;

	// printf("Number of arguments: %d\n", argc);

	// for (int i = 0; i < argc; ++i)
	// {
		// printf("Argument %d: %s\n", i, argv[i]);
	// }

	if(argc != 3){
		print_usage();
		return 1;
	}

	fin = open(argv[1], O_RDONLY);
	fout = open(argv[2], O_WRONLY | O_CREAT);

	while(1){
		num_iter++;
		bytes_read = read(fin, buffer, 10);
		write(fout, buffer, bytes_read);

		printf("Amount: %d\n", bytes_read);
		if(bytes_read<10) break;
	}

	printf("# iterations: %d\n", num_iter);


	close(fin);
	close(fout);

	return 0;
}