/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_orders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:14:55 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/22 07:54:30 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_ra(t_list **head)
{
	ft_rotate_list(head, "ra");
}
void ft_rb(t_list **head)
{
	ft_rotate_list(head, "rb");
}

void ft_rr(t_list **list_a, t_list **list_b)
{
	ft_rotate_list(list_a, "");
	ft_rotate_list(list_b, "");
	ft_printf("rr\n");
}

void ft_rra(t_list **head)
{
	ft_rev_rotate_list(head, "rra");
	ft_printf("rra\n");
}
void ft_rrb(t_list **head)
{
	ft_rev_rotate_list(head, "rrb");
}

void ft_rrr(t_list **list_a, t_list **list_b)
{
	ft_rev_rotate_list(list_a, "");
	ft_rev_rotate_list(list_b, "");
	ft_printf("rrr\n");
}

void ft_sa(t_list **list)
{
	ft_switch_list(list, "sa");
}
