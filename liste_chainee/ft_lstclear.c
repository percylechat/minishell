/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:28:25 by budal-bi          #+#    #+#             */
/*   Updated: 2019/11/27 19:05:41 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *buffer;
	t_list *bufferbis;

	if (!del || !lst)
		return ;
	buffer = *lst;
	while (buffer)
	{
		bufferbis = buffer->next;
		del(buffer->content);
		free(buffer);
		buffer = bufferbis;
	}
	*lst = NULL;
}
