clear 

norminette get_next_line.h get_next_line.c get_next_line_utils.c  \
get_next_line_bonus.h get_next_line_bonus.c get_next_line_utils_bonus.c

norminette -R CheckForbiddenSourceHeader get_next_line.h get_next_line.c get_next_line_utils.c  \
get_next_line_bonus.h get_next_line_bonus.c get_next_line_utils_bonus.c

norminette -R CheckHeader get_next_line.h get_next_line.c get_next_line_utils.c  \
get_next_line_bonus.h get_next_line_bonus.c get_next_line_utils_bonus.c