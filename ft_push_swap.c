/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:36 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/12 20:17:11 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(void)
{
    t_list *list;
    // t_list *list2;

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

    t_list **head1 = &list;
    t_list **head2 = NULL;
    
    ft_add_back(list, ft_create_list(content4));
    ft_add_back(list, ft_create_list(content5));
    ft_add_back(list, ft_create_list(content6));
    ft_add_back(list, ft_create_list(content7));
    ft_add_front(head1, ft_create_list(content2));
    ft_add_front(head1, ft_create_list(content1));


    ft_printf("Initial lists :\n");
    ft_print_list(head1);
    ft_print_list(head2);

    push_list(head1, &head2);

    ft_printf("Final lists :\n");
    ft_print_list(head1);
    ft_print_list(head2);
}