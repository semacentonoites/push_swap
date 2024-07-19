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

int	log_two(int num)
{
	int	i;

	i = 0;
	while (num > 1)
	{
		num /= 2;
		i++;
	}
	return (i);
}

void	print_list(struct s_stack *stack)
{
	struct s_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
}

void	free_list(struct s_stack **head)
{
	struct s_stack	*temp;

	temp = *head;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

struct s_stack	*copy_list(struct s_stack *lst)
{
	struct s_stack	*new_list;
	struct s_stack	**ptr;

	new_list = NULL;
	ptr = &new_list;
	while (lst != NULL)
	{
		*ptr = malloc(sizeof(struct s_stack));
		if (*ptr == NULL)
			return (NULL);
		(*ptr)->num = lst->num;
		(*ptr)->next = NULL;
		lst = lst->next;
		ptr = &((*ptr)->next);
	}
	return (new_list);
}

struct s_stack	*sort_list(struct s_stack *lst)
{
	int						sw;
	struct s_stack			*temp1;
	struct s_stack			*temp2;
	struct s_stack			*copy;

	copy = copy_list(lst);
	if (copy == NULL || copy->next == 0)
		return (copy);
	temp1 = copy;
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
	return (copy);
}
