/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:48:24 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/26 22:32:56 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list_map	*new_node_map(char *data)
{
	t_list_map	*node;

	node = malloc(sizeof(t_list_map));
	node->data = ft_strdup(data);
	node->next = 0;
	return (node);
}

t_list_map	*push_back_map(t_list_map *root, char *data)
{
	t_list_map	*curr;

	if (!root)
		root = new_node_map(data);
	else
	{
		curr = root;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node_map(data);
	}
	return (root);
}

void	free_list_map(t_list_map *root)
{
	t_list_map	*next;

	next = root;
	while (root)
	{
		next = root->next;
		free(root->data);
		free(root);
		root = next;
	}
}

void	count_node(t_list_map *root, t_global *global)
{
	global->mlx_data.map.height = 0;
	if (!root)
		return ;
	while (root)
	{
		global->mlx_data.map.height++;
		root = root->next;
	}
}

void	max_len(t_list_map *root, t_global *global)
{
	global->mlx_data.map.width = 0;
	if (!root)
		return ;
	while (root)
	{
		if ((int)ft_strlen(root->data) > global->mlx_data.map.width)
			global->mlx_data.map.width = ft_strlen(root->data);
		root = root->next;
	}
}
