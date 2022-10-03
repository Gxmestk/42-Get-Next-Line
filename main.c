#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test", O_RDONLY);
	char *ret = (char *)1;
	int i = 1;
	ret = get_next_line(fd);
	while(ret != 0)
	{
		//printf("%s",ret);
		printf("gnl (%d) ret = %s", i,ret);
		free(ret);
		printf("\n-----------------------------------\n");
		ret = get_next_line(fd);
		i++;
	}
	free(ret);
	printf("gnl (%d) ret = %s\n", i,ret);
	free(ret);
	ret = get_next_line(fd);
	printf("-----------------------------------\n");
	free(ret);
	close(fd);
	return 0;
}