/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:37 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/03 21:20:41 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

void	slst_addback(t_slist *lst, char *str)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	if (lst->first == NULL)
	{
		lst->first = new;
		lst->last = new;
	}
	lst->last->next = new;
	lst->last = new;
	new->next = NULL;
	new->str = str;
}

void	slst_split(t_slist *buffer, char *tmp)
{
	char	*rbuf;
	char	*buf;
	char	*n;

	n = ft_strchr(tmp, '\n');
	while (*tmp != 0)
	{	
		if (n == 0)
			buf = (char *)malloc(sizeof(char) * buffer->opt_bufs + 2);
		else
			buf = (char *)malloc(sizeof(char) * (n - tmp) + 2);
		if (buf == NULL)
			return ;
		rbuf = buf;
		while (tmp <= n || (*tmp != '\0' && n == 0))
			*buf++ = *tmp++;
		*buf = '\0';
		slst_addback(buffer, rbuf);
		n = ft_strchr(tmp, '\n');
	}
}

void	slst_malc(t_slist *buffer, int i, int n, char **rstr)
{
	t_node	*walker;

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
	*rstr = (char *)malloc(sizeof(char) * n + 2);
	if (*rstr == NULL)
		return ;
	(*rstr)[n] = '\0';
}

void	slst_bufcat(char **rstr, t_slist *buffer)
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
