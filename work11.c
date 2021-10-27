#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int * genrand() {
	int fd = open("/dev/random", O_RDONLY, 0);
	int *x = malloc(40);
	read(fd, x, 40);
	return x;
}

int main() {
	int *x;
	x = genrand();
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d\n", x[i]);
	}
	int fd = open("dev/random", O_WRONLY, 0);
	printf("Writing to new file\n");
	write(fd, x, 40);
	printf("Reading from new file\n");
	int fd2 = open("dev/random", O_RDONLY, 0);
	int *x2 = malloc(40);
	read(fd2, x2, 40);
	for (i = 0; i < 10; i++) {
		printf("%d\n", x2[i]);
	}
	return 0;
}
