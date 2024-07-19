/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:34:43 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/19 23:34:46 by erferrei         ###   ########.fr       */
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
	struct s_stack 	*next;
};


void	insert_at_beginning(int data, struct s_stack **head);
void	insert_at_end(int data, struct s_stack **head);
void	rra(struct s_stack **stack);
void	rrb(struct s_stack **stack);
void	pa(struct s_stack **stack1, struct s_stack **stack2);
void	pb(struct s_stack **stack1, struct s_stack **stack2);
void	sa(struct s_stack **stack);
void	sb(struct s_stack **stack);
void	ra(struct s_stack **stack);
void	rb(struct s_stack **stack);
#endif
