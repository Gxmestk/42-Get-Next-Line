/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:31 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/03 17:54:43 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
