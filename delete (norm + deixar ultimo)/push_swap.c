/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:29:50 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:26 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	find_lowest(struct s_stack *stack)
{
	struct s_stack	*temp;
	int				lowest;

	temp = stack;
	lowest = temp->num;
	while (temp != NULL)
	{
		if (temp->num < lowest)
			lowest = temp->num;
		temp = temp->next;
	}
	return (lowest);
}

void	sort_less_ten(struct s_stack **stack_a, struct s_stack **stack_b)
{
	while (!is_sorted(*stack_a) && stack_len(*stack_a) > 3)
	{
		find_lowest(*stack_a);
		per(find_lowest(*stack_a), stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a, stack_b);
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}

void	sort_small(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	i;

	i = 0;
	while (!is_sorted(*stack_a) && stack_len(*stack_a) > 3)
	{
		find_lowest(*stack_a);
		per(find_lowest(*stack_a), stack_a, stack_b);
		i++;
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a, stack_b);
	while (i-- > 0)
		pa(stack_b, stack_a);
}

int	error(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if (is_doubles(*stack_a))
		return (write(1, "Error\n", 6), free_list(stack_a), 0);
	if (is_sorted(*stack_a))
		return (free_list(stack_a), 0);
	if (stack_len(*stack_a) == 2)
		return (sort_two(stack_a), free_list(stack_a), 0);
	if (stack_len(*stack_a) == 3)
		return (sort_three(stack_a, stack_b),
			free_list(stack_a), free_list(stack_b), 0);
	if (stack_len(*stack_a) < 10)
		return (sort_less_ten(stack_a, stack_b),
			free_list(stack_a), free_list(stack_b), 0);
	return (1);
}

int	main(int ac, char **av)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	static int		i;
	int				*array;
	static int		size;

	if (ac < 2)
		return (0);
	init_stack(&stack_a, &stack_b);
	while (++i < ac)
	{
		if (!is_digit(av[i]) || !is_integer(av[i]))
			return (write(1, "Error\n", 6), free_list(&stack_a), 0);
		insert_at_end(ft_atoi(av[i]), &stack_a);
	}
	if (error(&stack_a, &stack_b) == 0)
		return (0);
	array = index_arr(stack_a, &size);
	i = 0;
	while (i++ < size - 1)
		per(array[i - 1], &stack_a, &stack_b);
	sort_small(&stack_a, &stack_b);
	while (stack_b != NULL)
		per2(&stack_a, &stack_b);
	return (free(array), free_list(&stack_a), free_list(&stack_b), 0);
}
