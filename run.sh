#!/bin/bash

clear  

echo "-----------Mandatory Test----------"
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c  -D BUFFER_SIZE=42 && ./a.out

rm a.out