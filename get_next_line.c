/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/02 20:12:21 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	slst_addback(t_slist *lst, char *str)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	if(lst->first == NULL)
	{
		lst->first = new;
		lst->last = new;
	}
	lst->last->next = new;
	lst->last = new;
	new->next = NULL;
	new->str = str;
}

static void slst_split(t_slist *buffer, char *tmp)
{
	char	*rbuf;
	char	*buf;
	char	*n;
	//int		i;

	//i = 0;
	while (*tmp != 0)
	{
		n = ft_strchr(tmp, '\n');
		if (n == 0)
			buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		else
			buf = (char *)malloc(sizeof(char) * (n - tmp) + 2);
		rbuf = buf;
		while (tmp <= n || (*tmp != '\0' && n == 0))
			*buf++ = *tmp++;
		*buf = '\0';

		slst_addback(buffer, rbuf);
		n = ft_strchr(tmp, '\n');

		/*printf("-----%d-----\n",i);
			t_node *walkers = buffer->first;
			while (walkers != NULL)
			{
				printf("BUFFER CHECK = %s\n",walkers->str);
				walkers = walkers->next;
			}
		i++;*/
	}
}

static int	read_line(t_slist *buffer)
{
	int		stop;
	char	*tmp;
	int		rb;

	stop = 0;

	while (!stop)
	{
		tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (0);
		rb = read(buffer->fd, tmp, BUFFER_SIZE);
		tmp[rb] = '\0';
		if (rb == 0 || rb == -1)
		{
			free(tmp);
			if (buffer->first == NULL)
					return (0);
			return (1);	
		}
		else if (ft_strchr(tmp, '\n') || rb < BUFFER_SIZE)
			stop = 1;
		
		slst_split(buffer, tmp);
		free(tmp);
	}
	return (1);
}

static void	slst_bufcat(char **rstr, t_slist *buffer)
{
	t_node	*walker;
	int		i;
	int		n;
	t_node	*tmp;
	int		stop;

	n = 0;
	walker = buffer->first;
	while (walker != NULL)
	{
		i = 0;
		while (walker->str[i] != '\n' && walker->str[i] != '\0')
		{
			i++;
			n++;
		}
		walker = walker->next;
	}
	*rstr = (char *)malloc(sizeof(char) * n + 1);
	if (*rstr == NULL)
		return ;
	(*rstr)[n] = '\0';
	n = 0;
	walker = buffer->first;
	stop = 0;
	while (walker != NULL && !stop)
	{
		i = 0;
		while (walker->str[i] != '\n' && walker->str[i] != '\0')
		{
			(*rstr)[n] = walker->str[i];
			i++;
			n++;
		}
		if (walker->str[i] == '\n')
		{
			stop = 1;
			(*rstr)[n] = '\n';
			(*rstr)[++n] = '\0';
		}
		else if (walker->str[i] == '\0')
			(*rstr)[n] = '\0';
		tmp = walker;
		walker = walker->next;
		free(tmp->str);
		free(tmp);
	}
	buffer->first = walker;
	//buffer->last = walker;
}

char	*get_next_line(int fd)
{
	static t_slist	buffer[MAX_FILES];
	char			*rstr;

	rstr = NULL;
	if (fd < 0 || fd >= MAX_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd].fd = fd;

	/*t_node *walker = buffer[fd].first;
	while (walker != NULL)
	{
		printf("BUFFER WHILE CALLING = %s\n",walker->str);
		walker = walker->next;
	}*/

	if (read_line(&buffer[fd]))
		slst_bufcat(&rstr, &buffer[fd]);

	/*walker = buffer[fd].first;
	while (walker != NULL)
	{
		printf("BUFFER BEFORE OUTPUT = %s\n",walker->str);
		walker = walker->next;
	}*/
	
	return (rstr);
}