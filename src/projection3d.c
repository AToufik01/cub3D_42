/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:38:28 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/25 13:03:47 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_projection3D(t_data *data,int i,double ray_angle,double raydistance)
{

    double d_projectplan;
    double wallheight;
    d_projectplan = (data->mlx->width / 2) * tan(FOV_ANGLE /2);
    wallheight = (TILE_SIZE / raydistance) * d_projectplan;
    draw_wall(data, i, wallheight, (data->mlx->width / 2) - (wallheight / 2), 0xAFAFAFFF);
}

// draw_wall(t_data *data, int x, double wall_top_pixel, double wall_bottom_pixel, int color);

void    draw_wall(t_data *data,int x,int wall_top_pixel ,double wall_bottom_pixel, int color)
{
    int y;
    y = (int)wall_top_pixel;
    while (y <= (int)wall_bottom_pixel)
    {
        if (y < data->map->img_map->height)
            mlx_put_pixel(data->player->img_player,x,y,color);
        y++;
    }
}


// void draw_wall(t_data *data, int x, double wall_top_pixel, double wall_bottom_pixel, int color) {
//     // Implement your drawing logic here
//     int y = (int)wall_top_pixel;
//     while (y <= (int)wall_bottom_pixel) {
//         // Plot pixel at (x, y) with the given color
//         if (y < data->map->img_map->height)
//             mlx_put_pixel(data->player->img_player,x,y,color);
//         y++;
//     }
// }