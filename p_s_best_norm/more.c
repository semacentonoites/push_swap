/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:34:11 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/19 23:34:27 by erferrei         ###   ########.fr       */
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
	//prev = temp->next;

	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	new->num = (temp)->num;
	new->next = (*stack);
	prev->next= NULL;
	(*stack) = new;
	//temp->next = new;
	//(*stack) = prev;
	free(temp);
	printf("rra\n");
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
	//prev = temp->next;

	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	new->num = (temp)->num;
	new->next = (*stack);
	prev->next= NULL;
	(*stack) = new;
	//temp->next = new;
	//(*stack) = prev;
	free(temp);
	printf("rrb\n");
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
	printf("pa\n");
}

void	pb(struct s_stack **stack1, struct s_stack **stack2)
{
	struct s_stack	*temp;

	if (*stack1 == NULL)
		return ;
	insert_at_beginning((*stack1)->num, stack2);
	temp = *stack1;
	(*stack1) = (*stack1)->next;
	free(temp);
	printf("pb\n");
}

void	sa(struct s_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	printf("sa\n");
}

void	sb(struct s_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	printf("sb\n");
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
	printf("ra\n");
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
	printf("rb\n");
}
