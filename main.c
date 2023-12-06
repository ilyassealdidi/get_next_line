#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	// struct rlimit r_limit;
	// int a  = getrlimit(RLIMIT_NOFILE, &r_limit);

	int file1 = open("file1.txt", O_RDONLY);
	int file2 = open("file2.txt", O_RDONLY);
	char *str = get_next_line(file1);
	printf("'%s'\n", str);
	str = get_next_line(file2);
	printf("'%s'\n", str);
	// str = get_next_line(fd);
	// printf("'%s'\n", str);
	// str = get_next_line(fd);
	// printf("'%s\n'", str);
}