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


int		log_two(int num)
{
	int		i;

	i = 0;
	while (num > 1)
	{
		num /= 2;
		i++;
	}
	return (i);
}

void print_list(struct s_stack *stack)	
{	
	struct s_stack *temp = stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
}

void	free_list(struct s_stack **head)
{
	struct s_stack *temp;

	temp = *head;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	//free(*head);
}

struct s_stack *copy_list(struct s_stack *lst)
{
    struct s_stack *new_list = NULL;
    struct s_stack **ptr = &new_list;

    while (lst != NULL)
    {
        *ptr = malloc(sizeof(struct s_stack));
        if (*ptr == NULL) return NULL; // Falha na alocação de memória
        (*ptr)->num = lst->num;
        (*ptr)->next = NULL;
        lst = lst->next;
        ptr = &((*ptr)->next);
	}
    return new_list;
}

struct s_stack	*sort_list(struct s_stack *lst)
{
	int	sw;
	struct s_stack *temp1;
	struct s_stack *temp2;
	struct s_stack *copy = copy_list(lst); 

	if (copy == NULL || copy->next == 0)
		return(copy);
	temp1 = copy;
	temp2 = copy->next;
	while (temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->num > temp2->num)
			{
				sw = temp1->num;
				temp1->num = temp2->num;
				temp2->num = sw;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	//free_list(&lst);
	return (copy);
}

int		stack_len(struct s_stack *stack)
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

void	pushb(int index, int len, struct s_stack **stack_a, struct s_stack **stack_b)
{
	int				i;

	i = 0;
	if(index == 0 || len / index > 2)
		while (i < index)
		{
			ra(stack_a);
			i++;
		}
	else
		while (len > index)
		{
			rra(stack_a);
			len--;
		}
	pb(stack_a, stack_b);
}

void	pusha(int index, int len, struct s_stack **stack_a, struct s_stack **stack_b)
{
	int				i;

	i = 0;
	if(index == 0 || len / index > 2)
		while (i < index)
		{
			rb(stack_a);
			i++;
		}
	else
		while (len > index)
		{
			rrb(stack_a);
			len--;
		}
	pa(stack_a, stack_b);
}

int	len_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*index_arr(struct s_stack *stack, int *size)
{
	int	*s_array;
	int	*i_array;
	int	len;
	//int	div;
	int	num;
	int l;
	int a;

	len = stack_len(stack);
	//div = log_two(len);
	struct s_stack	*array;
	array = sort_list(stack);
	s_array = stack_to_array(array); //
	free_list(&array);
	num = log_two(len);
	a = 0;
	if (num * (len / num) < len)
		{num++;
		a = 1;
		}
	*size = num;
	i_array = (int *)malloc(sizeof(int) * num);
	l = -1;
	int j=0;
	while (num > a)
	{
		l += len / log_two(len);  
		i_array[j] = s_array[l];
		j++;
		num--;
	}
	if (a == 1)
		i_array[j] = s_array[len - 1];
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
			pushb(find_index(*stack_a, temp->num), stack_len(*stack_a), stack_a, stack_b);
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

void	per2(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int 			highest;

	highest = find_highest(*stack_b);
	//printf("highest: %d\n", highest);
	pusha(find_index(*stack_b, highest), stack_len(*stack_b), stack_b, stack_a);
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

double pow(double x, double y)
{
	double res = 1;
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return res;
}

long	ft_atol(const char *nbr)
{
		int i = 0;
		int sign = 1;
		long result = 0;

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

		return result * sign;
}

int is_integer(char *str)
{
	int	i;
	int	a;

	a = 0;
	//printf("%f\n", ft_atol("12"));
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
		if((*stack)->num > (*stack)->next->num)
			sa(stack);
		else if((*stack)->num < (*stack)->next->next->num)
		{
			pb(stack, stack_b);
			ra(stack);
			pa(stack_b, stack);
		}
		else
			rra(stack);
	}
}

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
	if(!is_sorted(*stack_a))
		sort_three(stack_a, stack_b);
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}


int	main(int ac, char **av)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				i;
 
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < ac)
	{
		if (!is_digit(av[i]) || !is_integer(av[i]))
		{
			printf("Error\n");
			free_list(&stack_a);
			return (0);
		}
		insert_at_end(ft_atoi(av[i]), &stack_a);
		i++;
	}
	if (is_doubles(stack_a))
	{
		printf("Error\n");
		free_list(&stack_a);
		return (0);
	}
	if (is_sorted(stack_a))
	{
		free_list(&stack_a);
		return (0);
	}
	if (stack_len(stack_a) == 2)
	{
		sort_two(&stack_a);
		free_list(&stack_a);
		return (0);
	}
	if(stack_len(stack_a) == 3)
	{
		sort_three(&stack_a, &stack_b);
		free_list(&stack_a);
		free_list(&stack_b);
		return (0);
	}
	if (stack_len(stack_a) < 10)
	{
		sort_less_ten(&stack_a, &stack_b);
		free_list(&stack_a);
		free_list(&stack_b);
		return (0);
	}
	int *array;
	int size = 0;
	array = index_arr(stack_a, &size);
	i = 0;

	while (i < size)
	{
		per(array[i], &stack_a, &stack_b);
		i++;
	}
	free(array);
	while (stack_b != NULL)
	{
		per2(&stack_a, &stack_b);
	}
	//free(array);
	//if (stack_a->next == NULL)
	//	return ();


//	p(&stack_a, &stack_b);
//	s(&stack_a);
//	r(&stack_a);
//	rr(&stack_a);
/*
	printf("A\n");
	print_list((stack_a));
	printf("\n");
	printf("B\n");
	print_list((stack_b));*/
		//print_list((stack_a));

	//rr(&stack_a);
	//((stack_a));
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
