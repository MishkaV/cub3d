/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:16:35 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 16:39:58 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*curr;

	out = NULL;
	out = ft_lstnew(f(lst->content));
	if (lst && out)
	{
		curr = out;
		while (lst->next)
		{
			lst = lst->next;
			curr->next = ft_lstnew(f(lst->content));
			if (!curr->next)
			{
				ft_lstclear(&out, del);
				return (0);
			}
			curr = curr->next;
		}
	}
	return (out);
}
