/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:57:48 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/30 13:15:32 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int    ft_color(int r, int g, int b, int a)
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}

void    ft_projection3D(t_data *data,float i,double ray_angle,double raydistance)
{

    double d_projectplan;
    double wallheight;
    d_projectplan = (data->mlx->width / 2) * tan(FOV_ANGLE /2);
    wallheight = (TILE_SIZE / raydistance) * d_projectplan;
    draw_wall(data,i * WALL_STRIP_WIDTH,(data->mlx->height / 2) - (wallheight / 2),WALL_STRIP_WIDTH,wallheight,
    ft_color(255, 255, 255, 255 * exp(-0.004 * raydistance)));
}

void draw_wall(t_data *data, int x, int y, int width, int height, int color)
{
    int i;
    int j;
    i = 0;
    while (i < width)
    {
        j = 0;
        while (j < height)
        {
            int px = x + i;
            int py = y + j;
            if (px < data->player->img_player->width && py < data->player->img_player->height)
                mlx_put_pixel(data->player->img_player,x + i, y + j, color);
            j++;
        }
        i++;
    }
}