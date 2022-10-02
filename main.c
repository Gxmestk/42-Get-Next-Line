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
	int i = 0;
	ret = get_next_line(fd);
	while(ret != 0)
	{
		//printf("%s",ret);
		printf("gnl (%d) ret = %s\n", i,ret);
		//free(ret);
		ret = get_next_line(fd);
		printf("-----------------------------------\n");
		i++;
	}
	close(fd);
	return 0;
}