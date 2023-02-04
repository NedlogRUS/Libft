#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    if(!lst)
    return ;
    t_list *new;

    while(*lst)
    {
        new = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new;
    }
}