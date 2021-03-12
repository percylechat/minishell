/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:36:27 by budal-bi          #+#    #+#             */
/*   Updated: 2019/11/27 12:36:04 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_el;

	if (!(new_el = (t_list*)malloc(sizeof(t_list*))))
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
