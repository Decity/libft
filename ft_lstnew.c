#include "libft.h"

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

// int main() {
//     int		data1 = 42;
//     char	data2[] = "Hello, world!";
//     double	data3 = 3.14159;

//     t_list *node1 = ft_lstnew(&data1);
//     t_list *node2 = ft_lstnew(data2); 
//     t_list *node3 = ft_lstnew(&data3);

//     if (!node1 || !node2 || !node3) {
//         printf("Failed to create  node(s)\n");
//         return 1;
//     }

//     printf("Node 1 (int): %d\n", *((int *)(node1->content)));
//     printf("Node 2 (string): %s\n", (char *)(node2->content));
//     printf("Node 3 (double): %lf\n", *((double *)(node3->content)));

//     free(node1);
//     free(node2);
//     free(node3);

//     return 0;
// }