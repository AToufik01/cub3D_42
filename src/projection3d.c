/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:57:48 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/29 10:58:17 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void    ft_projection3D(t_data *data,float i,double ray_angle,double raydistance)
{

    double d_projectplan;
    double wallheight;
    d_projectplan = (data->mlx->width / 2) * tan(FOV_ANGLE /2);
    wallheight = (TILE_SIZE / raydistance) * d_projectplan;
    draw_wall(data, i, wallheight, (data->mlx->width / 2) - (wallheight / 2), 0xFFFFFFFF);
}

void    draw_wall(t_data *data,float x,float wall_top_pixel ,float wall_bottom_pixel, int color)
{
    float y;
    y = wall_top_pixel;
    while (y <= wall_bottom_pixel) 
    {
        if (y < data->map->img_map->height)
            mlx_put_pixel(data->player->img_player,x,y,color);
        y++;
    }
}