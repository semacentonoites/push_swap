/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:39:56 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/20 18:29:31 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	per2(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	highest;

	highest = find_highest(*stack_b);
	if (find_index(*stack_b, highest) == 1)
	{
		sb(stack_b);
		pa(stack_b, stack_a);
	}
	else
		pusha(find_index(*stack_b, highest),
			stack_len(*stack_b), stack_b, stack_a);
}

int	is_sorted(struct s_stack *stack)
{
	struct s_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_doubles(struct s_stack *stack)
{
	struct s_stack	*temp;
	struct s_stack	*temp2;

	temp = stack;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->num == temp2->num)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

double	pow(double x, double y)
{
	double	res;

	res = 1;
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return (res);
}
