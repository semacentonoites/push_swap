/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-16 15:29:50 by erferrei          #+#    #+#             */
/*   Updated: 2024-07-16 15:29:50 by erferrei         ###   ########.fr       */
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
	int				i;
	int				*array;
	int				size;

	size = 0;
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i++ < ac)
	{
		if (!is_digit(av[i - 1]) || !is_integer(av[i - 1]))
			return (write(1, "Error\n", 6), free_list(&stack_a), 0);
		insert_at_end(ft_atoi(av[i - 1]), &stack_a);
	}
	if (error(&stack_a, &stack_b) == 0)
		return (0);
	array = index_arr(stack_a, &size);
	i = 0;
	while (i++ < size)
		per(array[i - 1], &stack_a, &stack_b);
//	print_list(stack_b);
	while (stack_b != NULL)
		per2(&stack_a, &stack_b);
//	print_list(stack_a);
	return (free(array), free_list(&stack_a), free_list(&stack_b), 0);
}
