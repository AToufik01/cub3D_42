/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:15:29 by aben-cha          #+#    #+#             */
/*   Updated: 2024/08/04 14:29:50 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    free_array(char **array)
{
    int i;

    i = 0;
    while (array && array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void    print_error(char *str)
{
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(str, 2);
    exit(1);
}

void    free_data(t_data *data, int flag)
{
    if (flag == 1)
        ft_lstclear(&data->list);
    free(data->texture->north_texture);
    free(data->texture->south_texture);
    free(data->texture->east_texture);
    free(data->texture->west_texture);
}
