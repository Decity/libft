#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// HELPER FUNCTIONS

void delete(void *ptr) {
	free(ptr);
}

void ft_strtoupper(void *data) {
    char *s = (char *)data;
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s = *s - ' ';
        }
        s++;
    }
}


// LLST FUNCTIONS



void	ft_lstdelone(t_list *lst, void(*del)(void *))
{
	if (!lst || !del)
		return;
	del(lst->content);
}

void	ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list *next;
	if (!del || !lst)
		return;

	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

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

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void print_node_strs(t_list *node){
	printf("List:\n");
	while (node){
		if (node->content)
			printf("content: %s\n", (char *)node->content);
		else
			printf("Content: no");
		if (node->next){
			printf("Next node: yes\n");
		}
		else
			printf("Next node: NULL\n");
       	node = node->next;
		printf("\n");
	}
}

// main

int	main(void)
{
	// ft_lstnew
	t_list *test_node = ft_lstnew("test node");
	t_list	*list = test_node;

	print_node_strs(list);

	// ft_lst_add_front
	t_list	*front_node = ft_lstnew("front");

	ft_lstadd_front(&list, front_node);
	print_node_strs(list);

	// ft_lst_add_back
	t_list *back_node = ft_lstnew("back");
	ft_lstadd_back(&list, back_node);
	print_node_strs(list);

	// ft_lstsize()
	printf("ft_lstsize: %d\n\n\n", (int)ft_lstsize(list));

	// ft_lstlast
	printf("ft_lstlast:\n");
	print_node_strs(ft_lstlast(list));





	// ft_lstiter











	// ft_delone()
	// t_list *node_to_delete = ft_lstnew("delete me!");
	// printf("before deletion:\n");
	// print_node_strs(node_to_delete);
	// ft_lstdelone(node_to_delete, delete);

	// This will make the program crash
	// printf("after deletion:\n");
	// 	print_node_strs(node_to_delete);




	return (0);

}

// lstadd_back x
// lstadd_front x
// ft_lst_clear
// ft_lstdelone x
// ft_lstiter
// ft_lstlast x
// ft_lstmap
// ft_lstnew x
// ft_lstsize x
