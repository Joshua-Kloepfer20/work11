#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

void genrand() {
	int fd = open("dev/random", O_WRONLY, 0);
	int x[10];
	int i = 0;
	for (i = 0; i < 10; i++) {
		x[i] = rand();

}
	write(fd, x, 40);
}

int main() {
	srand(time(NULL));
	genrand();
	int fd = open("dev/random", O_RDONLY, 0);
	int x[10];
	read(fd, &x, 40);
	int i = 0;
	printf("Reading from original file\n");
	for (i = 0; i < 10; i++) {
		printf("%d\n", x[i]);
	}
	int fd2 = open("dev/random2", O_RDWR, 0);
	printf("Writing to new file\n");
	write(fd2, x, 40);
	printf("Reading from new file\n");
	read(fd2, x, 40);
	for (i = 0; i < 10; i++) {
		printf("%d\n", x[i]);
	}
	return 0;
}
