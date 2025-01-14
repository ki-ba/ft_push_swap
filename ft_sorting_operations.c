/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:26:48 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/12 18:51:47 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list **switch_list(t_list **head)
{
    t_list *first_element;
    t_list *second_element;

    first_element = *head;
    second_element = first_element->next;

    first_element->next = second_element->next;
    second_element->next = first_element;
    
    *head = second_element;

    return (head);
}

t_list **push_list(t_list **head_from, t_list ***head_to)
{
    t_list *new_head_from = (*head_from)->next;
    t_list *new_list;

    if (!*head_to)
    {
        new_list = ft_lstnew((*head_from)->content);
        *head_to = (t_list **)new_list;
        (**head_to)->next = NULL;
    }
    else
        ft_lstadd_front(*head_to, *head_from);
    *head_from = new_head_from;

    return (*head_to);
}