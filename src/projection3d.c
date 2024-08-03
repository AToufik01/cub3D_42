/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:57:48 by ataoufik          #+#    #+#             */
/*   Updated: 2024/08/03 10:53:35 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int    ft_color(int r, int g, int b, int a)
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}
void    ft_floor(t_data *data,int x, int start_y)
{
    int j;
    uint32_t floorcolor =0x20B2AAFF;
    j = start_y;
    while (j < data->mlx->height)
    {
        if (j >= 0 && j < data->mlx->height) 
        {
            if (x >= 0 && x < data->mlx->width)
                mlx_put_pixel(data->player->img_player, x, j, floorcolor);
        }
        j++;
    }
}


void    ft_ceil(t_data *data,int x, int end_y)
{
    int j;
    uint32_t ceilcolor =0xD2BDBDFF;
    j = 0;
    while (j < end_y)
    {
        if (j >= 0 && j < data->mlx->height) 
        {
            if (x >= 0 && x < data->mlx->width)
                mlx_put_pixel(data->player->img_player, x, j, ceilcolor);
        }
        j++;
    }
}
void    ft_projection3D(t_data *data,float d,int sig , t_ray *ray, double raydistance)
{

    double d_projectplan;
    double wallheight;
    d_projectplan = (data->mlx->width / 2) * tan(FOV_ANGLE /2);
    wallheight = (TILE_SIZE / raydistance) * d_projectplan;
    uint32_t texcolor = ft_color(244, 255, 255, 255 * exp(-0.004 * raydistance));
    int offset_x;
    int offset_y;
    if (sig == 0)
    {
        offset_x = (int)ray->y_intercept % TILE_SIZE;
        texcolor = 0x4B0082FF;
    }
    else
    {
        offset_x = (int)ray->x_intercept % TILE_SIZE;
        texcolor = 0x800000FF ;
    }
    int x = d * WALL_STRIP_WIDTH;
    int y = (data->mlx->height / 2) - (wallheight / 2);
    int i;
    int j;
    i = 0;
    ft_ceil(data,x,y);
    ft_floor(data,x,y + wallheight);
    j = 0;
    while (j < wallheight && raydistance > 2)
    {
        int py = y + j;
        if (py >= 0 && py < data->mlx->height) 
        {
            // offset_y = (j * HEIGHT_TEXTUER) / wallheight + 0;
            // int tex_index = (WIDTH_TEXTUER * offset_y) + offset_x;
            // if (tex_index >= 0 && tex_index < (WIDTH_TEXTUER * HEIGHT_TEXTUER))
            // {
                // uint32_t texcolor = data->player->walltexteur[tex_index];
                if (x >= 0 && x < data->mlx->width)
                    mlx_put_pixel(data->player->img_player, x, py, texcolor);
                // }
        }
        j++;
    }
}
