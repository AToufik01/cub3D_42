/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:36:08 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/23 15:09:53 by ataoufik         ###   ########.fr       */
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
void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    int i = 0;
    while (i <= steps)
    {
        if (X < data->map->img_map->width && Y < data->map->img_map->height && X>=0 && Y>=0)
            mlx_put_pixel(data->player->img_player, X, Y, color);
        X += Xinc;
        Y += Yinc;
        i++;
    }
}

void draw_view_player(t_data *data, int color)
{
    int centerX = data->player->x - 4 + data->player->radius/2; 
    int centerY = data->player->y - 4 + data->player->radius/2;
    double x1 = centerX + cos(data->player->rotationAngle) * 40;
    double y1 = centerY + sin(data->player->rotationAngle) * 40;
    draw_line(data, centerX, centerY, x1, y1, color);
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
                px = data->player->x + x;
                py = data->player->y + y;
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
                color = 0x686868FF;
            else
                color = 0x2A2A2AFF;
                draw_map(data,tileX,tileY,color);
            j++;
        }
        i++;
    }
    mlx_image_to_window(data->mlx,data->map->img_map,0,0);
    
}


void rest_image(mlx_image_t *image)
{
    for (uint32_t x = 0; x < image->width; x++)
    {
        for (uint32_t y = 0; y < image->height; y++)
        {
            mlx_put_pixel(image, x, y, 0);
        }
    }
}
void    ft_render_player(t_data *data)
{
    int color = 0xFF0000FF;
    int color_rays =0xD7B0A1FF;
    int view_color = 0x00FF00FF;
    // mlx_delete_image(data->mlx,data->player->img_player);
    // data->player->img_player = mlx_new_image(data->mlx, data->player->img_p_width,data->player->img_p_height);
    rest_image(data->player->img_player);
    draw_player(data,color);
    draw_view_player(data,view_color);
    ft_cast_all_rays(data,color_rays);
    // mlx_image_to_window(data->mlx,data->player->img_player,0,0);// HHHDHHD
}
