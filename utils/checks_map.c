/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:05:45 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 20:26:29 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void		        check_first(char *str, t_global *global)
{
	char *curr;

	curr = str;
	while (*curr == '1' || *curr == ' ')
		curr++;
		
	if (*curr)
		error_handle(ERROR_MAP, global);
}

static int          check_sym(char c)
{
    return (c == '0' || c == '1' || c == '2' || c == ' ' 
    || c == 'N'
    || c == 'A'
    || c == 'W'
    || c == 'S');
}

static char         *get_last_str(t_list_map *list)
{
    while (list->next)
        list = list->next;
    return (list->data);
}

void                check_mid(char *str, t_global *global, t_list_map *list)
{
    int     i;
    char    *prev;
    i = 0;
    while (i < (int)ft_strlen(str))
    {
        if (!check_sym(str[i]))
            error_handle(ERROR_MAP_MID, global);
        i++;
    }
    
    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] != '1')
        error_handle(ERROR_MAP_MID, global);
   
    
    i = ft_strlen(str) - 1;
    while (str[i] == ' ')
        i++;
    if (str[i] != '1')
        error_handle(ERROR_MAP_MID, global);
    
    i = 0;
    prev = get_last_str(list);
    while (i < (int)ft_strlen(str) && i < (int)ft_strlen(prev))
    {
        if (prev[i] == ' ' && str[i] != '1' && str[i] != ' ')
            error_handle(ERROR_MAP_MID, global);
        i++;
    }
}

void                check_last(char *str, t_global *global, t_list_map *list)
{
    int     i;
    char    *prev;

    i = 0;
    while (i < (int)ft_strlen(str))
    {
        if (str[i] != '1' && str[i] != ' ')
            error_handle(ERROR_MAP_LAST, global);
        i++;
    }
    
    i = 0;
    prev = get_last_str(list);
    while (i < (int)ft_strlen(str) && i < (int)ft_strlen(prev))
    {
        if (str[i] == ' ')
            if (prev[i] != '1' && prev[i] != ' ')
                error_handle(ERROR_MAP_MID, global);
        i++;
    }
}