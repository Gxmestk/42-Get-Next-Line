#!/bin/bash

clear  

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -g  -D BUFFER_SIZE=1 && ./a.out

valgrind --leak-check=full a.out.dSYM
rm a.out