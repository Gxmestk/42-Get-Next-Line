#!/bin/bash

clear  

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c  -D BUFFER_SIZE=1 && ./a.out

rm a.out