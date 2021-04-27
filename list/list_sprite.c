/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:40:43 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/24 21:17:21 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list_sprite	*new_node_sprite(t_sprite *data)
{
	t_list_sprite	*node;

	node = malloc(sizeof(t_list_sprite));
	node->sprite.x = data->x;
	node->sprite.y = data->y;
	node->next = 0;
	return (node);
}

t_list_sprite	*push_back_sprite(t_list_sprite *root, t_sprite *data)
{
	t_list_sprite	*curr;

	if (!root)
		root = new_node_sprite(data);
	else
	{
		curr = root;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node_sprite(data);
	}
	return (root);
}

void	free_list_sprite(t_list_sprite *root)
{
	t_list_sprite	*next;

	next = root;
	while (root)
	{
		next = root->next;
		free(root);
		root = next;
	}
}

int	count_node_sprite(t_list_sprite *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	while (root)
	{
		count++;
		root = root->next;
	}
	return (count);
}
