/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:42:31 by budal-bi          #+#    #+#             */
/*   Updated: 2019/11/22 12:57:59 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelem;
	t_list	*newlst;
	void	*newctnt;

	if (!lst || !f)
		return (NULL);
	newctnt = f(lst->content);
	if (!(newelem = ft_lstnew(newctnt)))
		return (NULL);
	newlst = newelem;
	while (lst->next)
	{
		lst = lst->next;
		newctnt = f(lst->content);
		if (!(newelem->next = ft_lstnew(newctnt)))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newelem = newelem->next;
	}
	newelem->next = NULL;
	return (newlst);
}
