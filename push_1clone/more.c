/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-17 22:39:56 by erferrei          #+#    #+#             */
/*   Updated: 2024-07-17 22:39:56 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(struct s_stack **stack1, struct s_stack **stack2)
{
	struct s_stack	*temp;

	if (*stack1 == NULL)
		return ;
	insert_at_beginning((*stack1)->num, stack2);
	temp = *stack1;
	(*stack1) = (*stack1)->next;
	free(temp);
	write(1, "pb\n", 3);
}

void	sa(struct s_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	write(1, "sa\n", 3);
}

void	sb(struct s_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	write(1, "sb\n", 3);
}

void	ra(struct s_stack **stack)
{
	struct s_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	insert_at_end(temp->num, stack);
	free(temp);
	write(1, "ra\n", 3);
}

void	rb(struct s_stack **stack)
{
	struct s_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	insert_at_end(temp->num, stack);
	free(temp);
	write(1, "rb\n", 3);
}
