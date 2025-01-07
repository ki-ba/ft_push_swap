/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:25 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/05 16:35:50 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
typedef struct s_list{
    int *content;
    struct s_list  *next;
} t_list;

t_list  *ft_create_list(int  *content);
t_list *lst_last(t_list *list);
t_list *ft_add_back(t_list *node, t_list *new);
t_list *ft_add_front(t_list **head, t_list *new);
void print_list(t_list **head);


// SORTING_UTILS.C
int get_highest_number_index(t_list *lst);
t_list *get_node_by_index(t_list *lst, int index);
int get_node_index(t_list *lst, t_list *node);
/*sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr
*/
#endif