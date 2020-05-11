all:
	gcc main.c get_next_line_func/get_next_line.c get_next_line_func/get_next_line_utils.c get_next_line_func/get_next_line.h -Wall -Werror -Wextra -D BUFFER_SIZE=5000

debug:
	gcc -g main.c get_next_line_func/get_next_line.c get_next_line_func/get_next_line_utils.c get_next_line_func/get_next_line.h
