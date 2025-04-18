/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoga2 <marcoga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:45:05 by marco             #+#    #+#             */
/*   Updated: 2025/04/18 12:00:57 by marcoga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*failed_alloc(void *temp_content, t_list **first, void (*del)(void *))
{
	del(temp_content);
	ft_lstclear(first, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*last;
	t_list	*first;
	void	*temp_content;

	if (!lst || !f)
		return (NULL);
	last = NULL;
	first = NULL;
	while (lst)
	{
		temp_content = f(lst->content);
		new = ft_lstnew(temp_content);
		if (!new)
			return (failed_alloc(temp_content, &first, del));
		if (!first)
			first = new;
		else
			last->next = new;
		last = new;
		lst = lst->next;
	}
	return (first);
}
