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

long	ft_atol(const char *nbr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result = result * 10 + (nbr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_integer(char *str)
{
	int	i;
	int	a;

	a = 0;
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		a = 1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i > 10 + a)
		return (0);
	return (1);
}

int	ft_atoi(const char *nbr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '-')
		sign = -1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		n = nbr[i] + n * 10 - 48;
		i++;
	}
	return (n * sign);
}

void	sort_two(struct s_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	sort_three(struct s_stack **stack, struct s_stack **stack_b)
{
	while (!is_sorted(*stack))
	{
		if ((*stack)->num > (*stack)->next->num)
			sa(stack);
		else if ((*stack)->num < (*stack)->next->next->num)
		{
			pb(stack, stack_b);
			ra(stack);
			pa(stack_b, stack);
		}
		else
			rra(stack);
	}
}
