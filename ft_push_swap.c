/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:36 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/05 16:44:48 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(void)
{
    t_list *list;

    int *content1 = malloc(sizeof(int));
    int *content2 = malloc(sizeof(int));
    int *content3 = malloc(sizeof(int));
    int *content4 = malloc(sizeof(int));
    int *content5 = malloc(sizeof(int));
    int *content6 = malloc(sizeof(int));
    int *content7 = malloc(sizeof(int));

    *content1 = 1;
    *content2 = 2;
    *content3 = 3;
    *content4 = 4;
    *content5 = 55;
    *content6 = 6;
    *content7 = 7;

    list = ft_create_list(content3);
    t_list **head = &list;
    
    ft_add_back(list, ft_create_list(content4));
    ft_add_back(list, ft_create_list(content5));
    ft_add_back(list, ft_create_list(content6));
    ft_add_back(list, ft_create_list(content7));
    ft_add_front(head, ft_create_list(content2));
    ft_add_front(head, ft_create_list(content1));


    print_list(head);

    for(int i = 0; i < 7; ++i)
    {
        printf("value of node %d is %d\n", i, *(get_node_by_index(*head, i)->content));
    }

    printf("Highest value is node #%d (value : %d)\n", get_highest_number_index(*head), *(get_node_by_index(*head, get_highest_number_index(*head)))->content);
    return (0);
}