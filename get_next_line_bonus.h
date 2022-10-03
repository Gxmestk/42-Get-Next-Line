/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:29:01 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/03 20:59:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
	struct s_node	*start;
	long long		opt_bufs;
	int				fd;
}	t_slist;

typedef struct s_slst_bufcat_packet
{
	t_node	*walker;
	t_node	*tmp;
	int		n;
	int		i;
	int		stop;
}	t_slst_bufcat_packet;

char	*ft_strchr(const char *str, int c);
void	slst_addback(t_slist *lst, char *str);
void	slst_split(t_slist *buffer, char *tmp);
void	slst_malc(t_slist *buffer, int i, int n, char **rstr);
void	slst_bufcat(char **rstr, t_slist *buffer);
char	*get_next_line(int fd);

#endif