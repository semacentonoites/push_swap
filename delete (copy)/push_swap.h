/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:39:01 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/20 18:31:10 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

struct s_stack
{
	int				num;
	struct s_stack	*next;
};

void			insert_at_beginning(int data, struct s_stack **head);
void			insert_at_end(int data, struct s_stack **head);
void			rra(struct s_stack **stack);
void			rrb(struct s_stack **stack);
void			pa(struct s_stack **stack1, struct s_stack **stack2);
void			pb(struct s_stack **stack1, struct s_stack **stack2);
void			sa(struct s_stack **stack);
void			sb(struct s_stack **stack);
void			ra(struct s_stack **stack);
void			rb(struct s_stack **stack);
int				log_two(int num);
void			print_list(struct s_stack *stack);
void			free_list(struct s_stack **head);
struct s_stack	*copy_list(struct s_stack *lst);
struct s_stack	*sort_list(struct s_stack *lst);
int				stack_len(struct s_stack *stack);
int				*stack_to_array(struct s_stack *stack);
int				find_index(struct s_stack *stack, int num);
void			pushb(int index, int len,
					struct s_stack **stack_a, struct s_stack **stack_b);
void			pusha(int index, int len,
					struct s_stack **stack_a, struct s_stack **stack_b);
int				len_arr(int *arr);
int				index_arr_aux(int num, int a, int **i_array, int **s_array);
int				*index_arr(struct s_stack *stack, int *size);
void			per(int num, struct s_stack **stack_a,
					struct s_stack **stack_b);;
int				find_highest(struct s_stack *stack);
void			per2(struct s_stack **stack_a, struct s_stack **stack_b);
int				is_sorted(struct s_stack *stack);
int				is_doubles(struct s_stack *stack);
int				is_digit(char *str);
double			pow(double x, double y);
long			ft_atol(const char *nbr);
int				is_integer(char *str);
int				ft_atoi(const char *nbr);
void			sort_two(struct s_stack **stack);
void			sort_three(struct s_stack **stack, struct s_stack **stack_b);

#endif
