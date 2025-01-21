/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_orders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:14:55 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/21 08:21:52 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_ra(t_list **head)
{
	ft_rotate_list(head);
	ft_printf("ra\n");
}
void ft_rb(t_list **head)
{
	ft_rotate_list(head);
	ft_printf("rb\n");
}

void ft_rr(t_list **list_a, t_list **list_b)
{
	ft_rotate_list(list_a);
	ft_rotate_list(list_b);
	ft_printf("rr\n");
}

void ft_rra(t_list **head)
{
	ft_rev_rotate_list(head);
	ft_printf("rra\n");
}
void ft_rrb(t_list **head)
{
	ft_rev_rotate_list(head);
	ft_printf("rrb\n");
}

void ft_rrr(t_list **list_a, t_list **list_b)
{
	ft_rev_rotate_list(list_a);
	ft_rev_rotate_list(list_b);
	ft_printf("rrr\n");
}

void ft_sa(t_list **list)
{
	ft_switch_list(list);
	ft_printf("")
}
void ft_sb()

void ft_pa()

void ft_pb()
