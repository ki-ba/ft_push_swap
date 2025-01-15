/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:25 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/15 15:35:18 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

//LST UTILS
t_list *lst_last(t_list *list);
void ft_print_list(t_list **head);
t_list *lst_second_to_last(t_list *list);


// SORTING_UTILS.C
int get_highest_number_index(t_list *lst);
t_list *get_node_by_index(t_list *lst, int index);
int get_node_index(t_list *lst, t_list *node);


// SORTING BASIC OPERATIONS

t_list **switch_list(t_list **head);
void push_list(t_list **head_from, t_list **head_to);
void ft_rotate_list(t_list **head);

/*
ss
ra
rb
rr
rra
rrb
rrr
*/
#endif
