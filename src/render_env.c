/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:36:08 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/19 20:51:32 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    draw_map(t_data *data,int size_x,int size_y , int color)
{
    int x;
    int y;
    x = 0;
    y = 0;
    while (x < TILE_SIZE - 1)
    {
        y = 0;
        while (y < TILE_SIZE - 1)
        {
            mlx_put_pixel(data->map->img_map,size_x + x,size_y + y,color);
            y++;
        }
        x++;
    }
}
void    draw_view_player(t_data *data,int color)
{
    float a_cof;
    int x = data->player->x + cos(data->player->rotationAngle) * 30;
    int y = data->player->y + sin(data->player->rotationAngle) * 30;
    float x1 = data->player->x;
    
    a_cof = (y - data->player->y) / (x - data->player->x);

    while(x1 <= x)
    {
        mlx_put_pixel(data->player->img_player,x1,a_cof * x1,color);
        x1++;
    }
    
}

void    draw_player(t_data *data,int color)
{
    int x;
    int y;
    int px;
    int py;
    int r = data->player->radius;
    x = -r;
    y = -r;
    while (x < r)
    {
        y = -r;
        while (y < r)
        {
            if (pow(x,2) + pow(y,2)< pow(r,2))
            {
                px = r + x;
                py = r + y;
                mlx_put_pixel(data->player->img_player,px,py,color);
            }
            y++;
        }
        x++;
    }
    
}
void    ft_render_map(t_data *data)
{
    
    int i = 0;
    int j;
    int tileX;
    int tileY;
    int color;
    data->map->img_map = mlx_new_image(data->mlx,data->map->width * TILE_SIZE,data->map->height * TILE_SIZE);
    
    while (i < data->map->height)
    {
        j= 0;
        while (j < data->map->width)
        {
            tileX = j * TILE_SIZE;
            tileY = i * TILE_SIZE;
            if (data->map->arr_map[i][j] == '1')
                color = 0x22222;
            else
                color = 0xFFFFFF;
                draw_map(data,tileX,tileY,color);
            j++;
        }
        i++;
    }
    mlx_image_to_window(data->mlx,data->map->img_map,0,0);
    
}


void    ft_render_player(t_data *data)
{
    int color = 0xFF0000FF;
    data->player->img_player = mlx_new_image(data->mlx, 2 * data->player->radius,2* data->player->radius);
    draw_player(data,color);
    draw_view_player(data,color);
    mlx_image_to_window(data->mlx,data->player->img_player,data->player->x,data->player->y);
}
