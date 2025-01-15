/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:10 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/15 15:26:43 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list  *ft_create_list(int  *content)
{
    t_list  *lst;
    lst = malloc(sizeof(t_list));
    if(content)
        lst->content = content;
    lst->next = NULL;
    return (lst);
}

t_list *lst_last(t_list *list)
{
    t_list *current;

    current = list;
    while (current->next)
        current = current->next;
    return (current);
}

t_list *lst_second_to_last(t_list *list)
{
    t_list *current;
    t_list *next;
    current = list;
    while((current->next))
    {
        next = current->next;
        if(!(next->next))
            return (current);
        current = current->next;
    }
    return(current);

}

void ft_print_list(t_list **head)
{
    if (!head || !(*head))
    {
        ft_printf("[EMPTY LIST]\n");
        return ;
    }
    t_list *current;
    current = *head;
    while(current->next)
    {
        ft_printf("%d -> ", *(int *)(current->content));
        current = (current->next);
    }
    ft_printf("%d\n", *(int *)(current->content));
}
