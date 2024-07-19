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

int	len_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	index_arr_aux(int num, int a, int **i_array, int **s_array)
{
	int	l;
	int	j;
	int	len;

	len = len_arr(*s_array);
	l = -1;
	j = 0;
	while (num > a)
	{
		l += len / log_two(len);
		(*i_array)[j] = (*s_array)[l];
		j++;
		num--;
	}
	if (a == 1)
		(*i_array)[j] = (*s_array)[len - 1];
}

int	*index_arr(struct s_stack *stack, int *size)
{
	int				*s_array;
	int				*i_array;
	int				num;
	int				a;
	struct s_stack	*array;

	array = sort_list(stack);
	s_array = stack_to_array(array);
	free_list(&array);
	num = log_two(stack_len(stack));
	a = 0;
	if (num * (stack_len(stack) / num) < stack_len(stack))
	{
		num++;
		a = 1;
	}
	*size = num;
	i_array = (int *)malloc(sizeof(int) * num);
	index_arr_aux(num, a, &i_array, &s_array);
	free(s_array);
	return (i_array);
}

void	per(int num, struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->num <= num)
		{
			pushb(find_index(*stack_a, temp->num),
				stack_len(*stack_a), stack_a, stack_b);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
}

int	find_highest(struct s_stack *stack)
{
	struct s_stack	*temp;
	int				highest;

	temp = stack;
	highest = temp->num;
	while (temp != NULL)
	{
		if (temp->num > highest)
			highest = temp->num;
		temp = temp->next;
	}
	return (highest);
}
