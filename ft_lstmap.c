/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:57:59 by elie              #+#    #+#             */
/*   Updated: 2023/11/02 17:58:01 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;

	if (!lst || !f || !del)
		return (NULL);

	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));

		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);

		lst = lst->next;
	}

	return (new_lst);
}
