/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:27:18 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 18:26:03 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void     arg_checker(int argc, char **argv)
{
    if (argc > 3 || argc < 2)
        error_handle(ERROR_ARG);

    if (!cub_check(argv[1]))
        error_handle(ERROR_ARG);

    if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
        error_handle(ERROR_ARG);
}
