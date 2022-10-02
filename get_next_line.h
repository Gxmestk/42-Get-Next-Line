/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:30 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/02 18:02:39 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FILES
#  define MAX_FILES 1000
# endif

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

typedef struct s_slist
{
	struct s_node	*first;
	struct s_node	*last;
	int				fd;
}	t_slist;

char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);

#endif