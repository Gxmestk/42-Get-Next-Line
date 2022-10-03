/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/03 18:01:21 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(t_slist *buffer)
{
	char		*tmp;
	long long	rb;
	char		*tmp2;

	while (1)
	{
		tmp = (char *)malloc(sizeof(char) * buffer->opt_bufs + 1);
		if (tmp == NULL)
			return (0);
		tmp2 = tmp;
		while (1)
		{
			if (tmp2 - tmp >= buffer->opt_bufs)
			{
				slst_addback(buffer, tmp);
				break ;
			}
			rb = read(buffer->fd, tmp2, BUFFER_SIZE);
			if (rb != -1)
				tmp2[rb] = '\0';
			if (rb == 0 || rb == -1)
			{
				if (buffer->first == NULL && *tmp == '\0')
				{
					free(tmp);
					return (0);
				}
				if (*tmp != 0)
					slst_addback(buffer, tmp);
				else
					free(tmp);
				return (1);
			}
			else if (ft_strchr(tmp2, '\n'))
			{
				slst_split(buffer, tmp);
				free(tmp);
				return (1);
			}
			tmp2 += rb;
		}
	}
}

static void	slst_malc(t_slist *buffer, int i, int n, char **rstr)
{
	t_node	*walker;

	walker = buffer->first;
	while (walker != NULL)
	{
		while (walker->str[i] != '\n' && walker->str[i] != '\0')
		{
			i++;
			n++;
		}
		walker = walker->next;
	}
	*rstr = (char *)malloc(sizeof(char) * n + 2);
	if (*rstr == NULL)
		return ;
	(*rstr)[n] = '\0';
}
typedef struct s_slst_bufcat_packet
{
	t_node	*walker;
	t_node	*tmp;
	int		n;
	int		i;
	int		stop;
}	t_slst_bufcat_packet;

static void	slst_bufcat(char **rstr, t_slist *buffer)
{
	t_slst_bufcat_packet	p;

	slst_malc(buffer, 0, 0, rstr);
	
	p.n = 0;
	p.walker = buffer->first;
	p.stop = 0;
	while (p.walker != NULL && !p.stop)
	{
		p.i = 0;
		while (p.walker->str[p.i] != '\n' && p.walker->str[p.i] != '\0')
			(*rstr)[p.n++] = p.walker->str[p.i++];
		if (p.walker->str[p.i] == '\n')
		{
			p.stop = 1;
			(*rstr)[p.n] = '\n';
			(*rstr)[++p.n] = '\0';
		}
		else if (p.walker->str[p.i] == '\0')
			(*rstr)[p.n] = '\0';
		p.tmp = p.walker;
		p.walker = p.walker->next;
		free(p.tmp->str);
		free(p.tmp);
	}
	buffer->first = p.walker;
}

char	*get_next_line(int fd)
{
	static t_slist	buffer[MAX_FILES];
	char			*rstr;
	int				buf_size;

	rstr = NULL;
	if (fd < 0 || fd >= MAX_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd].fd = fd;
	buf_size = BUFFER_SIZE;
	if (buf_size <= 1000)
		buffer[fd].opt_bufs = buf_size * 1000;
	else if (buf_size <= 100000)
		buffer[fd].opt_bufs = buf_size * 10;
	else
		buffer[fd].opt_bufs = buf_size ;
	if (read_line(&buffer[fd]))
		slst_bufcat(&rstr, &buffer[fd]);
	return (rstr);
}
