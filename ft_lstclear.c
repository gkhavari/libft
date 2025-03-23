#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (del == NULL)
		return ;
	head = *lst;
	while (head)
	{
		temp = head -> next;
		del(head -> content);
		free(head);
		head = temp;
	}
	*lst = NULL;
}

/*
void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;

    while (*lst)
    {
        temp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = temp;
    }
}
*/
