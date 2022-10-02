#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test1", O_RDONLY);
	char *ret = (char *)1;
	/*printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");*/
	while(ret != 0)
	{
		ret = get_next_line(fd);
		printf("ret = %s\n", ret);
		printf("-----------------------------------\n");
	}

	close(fd);

	return 0;
}