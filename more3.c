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

int	stack_len(struct s_stack *stack)
{
	int				i;
	struct s_stack	*temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	*stack_to_array(struct s_stack *stack)
{
	int				i;
	int				*array;
	struct s_stack	*temp;

	i = 0;
	temp = stack;
	array = (int *)malloc(sizeof(int) * stack_len(stack));
	while (temp != NULL)
	{
		array[i] = temp->num;
		i++;
		temp = temp->next;
	}
	return (array);
}

int	find_index(struct s_stack *stack, int num)
{
	int				i;
	struct s_stack	*temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->num == num)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

void	pushb(int index, int len,
			struct s_stack **stack_a, struct s_stack **stack_b)
{
	int				i;

	i = 0;
	if (index == 0 || len / index > 2)
	{
		while (i < index)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		while (len > index)
		{
			rra(stack_a);
			len--;
		}
	}
	pb(stack_a, stack_b);
}

void	pusha(int index, int len,
			struct s_stack **stack_a, struct s_stack **stack_b)
{
	int				i;

	i = 0;
	if (index == 0 || len / index > 2)
	{
		while (i < index)
		{
			rb(stack_a);
			i++;
		}
	}
	else
	{
		while (len > index)
		{
			rrb(stack_a);
			len--;
		}
	}
	pa(stack_a, stack_b);
}
