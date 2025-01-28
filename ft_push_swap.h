/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:25 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/28 11:35:47 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define RADIX 10

# include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

//LST UTILS
t_list	*lst_last(t_list *list);
void	ft_print_list(t_list **head);
t_list	*lst_second_to_last(t_list *list);
int		ft_get_minimum(t_list **list);
int		get_value(t_list *list);

// SORTING_UTILS.C
int		get_highest_number_index(t_list *lst);
t_list	*get_node_by_index(t_list *lst, int index);
int		get_node_index(t_list *lst, t_list *node);
t_list	*get_node_by_value(t_list *lst, int number);
int		is_sorted(t_list **lst);
int		is_sorted_rotated(t_list **list);

// SORTING BASIC OPERATIONS

void	ft_switch_list(t_list **head, char list_id);
void	ft_push_list(t_list **head_from, t_list **head_to, char list_id);
void	ft_rev_rotate_list(t_list **head, char list_id);
void	ft_rotate_list(t_list **head, char list_id);

// FT_RADIX_SORT.C

int		ft_get_sd_from_node(t_list *list, int pos);
int		ft_nb_nodes_with_sd(t_list **head, int sd, int sd_position);
int		ft_radix_sort(t_list **list_a, t_list **list_b);
void	ft_print_lists_status(t_list **list_a, t_list **list_b);
void	ft_clean_exit(t_list **list_from, t_list **list_to, t_list *buckets[]);
void	ft_radix_pass(t_list **list_from, t_list **list_to, int pos, char from_char, char to_char);
#endif
