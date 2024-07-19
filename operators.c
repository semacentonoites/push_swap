/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <erferrei@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-17 17:17:52 by erferrei          #+#    #+#             */
/*   Updated: 2024-07-17 17:17:52 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	insert_at_beginning(int data, struct s_stack **head)
{
	struct s_stack	*new;

	new = (struct s_stack *)malloc(sizeof(struct s_stack));
	new->num = data;
	new->next = *head;
	*head = new;
}

void	insert_at_end(int data, struct s_stack **head)
{
	struct s_stack	*temp;
	struct s_stack	*new;

	new = (struct s_stack *)malloc(sizeof(struct s_stack));
	new->num = data;
	new->next = NULL;
	temp = *head;
	if (*head != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
}

void	rra(struct s_stack **stack)
{
	struct s_stack	*temp;
	struct s_stack	*prev;
	struct s_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = (struct s_stack *)malloc(sizeof(struct s_stack));
	temp = *stack;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	new->num = (temp)->num;
	new->next = (*stack);
	prev->next = NULL;
	(*stack) = new;
	free(temp);
	write(1, "rra\n", 4);
}

void	rrb(struct s_stack **stack)
{
	struct s_stack	*temp;
	struct s_stack	*prev;
	struct s_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = (struct s_stack *)malloc(sizeof(struct s_stack));
	temp = *stack;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	new->num = (temp)->num;
	new->next = (*stack);
	prev->next = NULL;
	(*stack) = new;
	free(temp);
	write(1, "rrb\n", 4);
}

void	pa(struct s_stack **stack1, struct s_stack **stack2)
{
	struct s_stack	*temp;

	if (*stack1 == NULL)
		return ;
	insert_at_beginning((*stack1)->num, stack2);
	temp = *stack1;
	(*stack1) = (*stack1)->next;
	free(temp);
	write(1, "pa\n", 3);
}
