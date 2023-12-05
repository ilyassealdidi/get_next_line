#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
}