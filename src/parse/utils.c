/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:42:27 by aben-cha          #+#    #+#             */
/*   Updated: 2024/08/04 17:21:45 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    handle_space(char *s, int *i, int *j)
{
    *i = 0;
    *j = ft_strlen(s) - 1;
    if (*j && s[*j] == '\n')
        (*j)--; 
    while (s[*i] && s[*i] == ' ')
        (*i)++;
    while (*j && s[*j] && (s[*j] == ' '))
        (*j)--; 
}

int     check_wall(char *s, char c)
{
    while (s && *s)
    {
        while (*s && *s == ' ')
            s++;
        if (*s && *s != '\n' && *s != c)
            return (1);
        if (*s)
            s++;
    }
    return (0);
}

int     another_char(char *s, char *ptr)
{
	int		i;
	// char	*ptr;

	// ptr = "01NSEW ";
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!ft_check_line(ptr, s[i]))
			return (0);
		i++;
	}
	return (1);
}

int     is_adjacent(t_data *data, char **map, char space, char c)
{
    int y;
    int x;

    y = 0;
    while (++y < data->map->height - 1)
    {
        x = 0;
        while (++x < data->map->width - 1)
        {
            if (!another_char(data->map->arr_map[y], "01NSEW "))
                return (free_data(data, 1), print_error("another char exist"), 1);
            if (map[y][x] == space)
            {
                if (map[y][x + 1] == c || map[y][x - 1] == c 
                || map[y + 1][x] == c || map[y + 1][x + 1] == c 
                || map[y + 1][x - 1] == c|| map[y - 1][x] == c 
                || map[y - 1][x + 1] == c || map[y - 1][x - 1] == c)
                        return (free_data(data, 1), 1);
            }
        }
    }
    return (0);
}
