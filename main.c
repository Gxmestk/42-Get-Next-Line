#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("tes", O_RDONLY);
	char *ret = get_next_line(fd);
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
	printf("---------------------------------\n");
	ret = get_next_line(fd);
	printf("MAIN: ret = %s\n", ret);
	printf("---------------------------------\n");
	/*while(ret != 0)
	{
		printf("ret = %s\n", ret);
		ret = get_next_line(fd);
		printf("-----------------------------------\n");
	}

	close(fd);*/

	return 0;
}