#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int *genrand() {
	int fd = open("dev/random.txt", O_RDWR, 0);
	int x[10];
	int i = 0;
	for (i = 0; i < 10; i++) {
		x[i] = rand();

}
	write(fd, x, 40);
	return x;
}

int main() {
	int fd = open("dev/random.txt", O_RDONLY, 0);
	char x[20];
	printf("%ld\n", read(fd, x, 24));
	printf("%s\n", x);
	return 0;
}
