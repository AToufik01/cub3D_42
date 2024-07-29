/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:36:08 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/29 09:03:27 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    draw_map(t_data *data,float size_x,float size_y , int color)
{
    float x;
    float y;
    x = 0;
    y = 0;
    while (x < TILE_SIZE -1)// - 1 px
    {
        y = 0;
        while (y <TILE_SIZE -1)// - 1px 
        {
            mlx_put_pixel(data->map->img_map,size_x + x,size_y + y,color);
            y++;
        }
        x++;
    }
}
void draw_line(t_data *data, float x0, float y0, float x1, float y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    float steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    float i = 0;
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
    float centerX = data->player->x - 4 + data->player->radius/2; 
    float centerY = data->player->y - 4 + data->player->radius/2;
    float x1 = centerX + cos(data->player->rotationAngle) * 40;
    float y1 = centerY + sin(data->player->rotationAngle) * 40;
    draw_line(data, SIZE_MINI_MAP* centerX, SIZE_MINI_MAP* centerY, SIZE_MINI_MAP* x1, SIZE_MINI_MAP* y1, color);
}

void    draw_player(t_data *data,int color)
{
    float x;
    float y;
    float px;
    float py;
    float r = data->player->radius;
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
                mlx_put_pixel(data->player->img_player,SIZE_MINI_MAP* px,SIZE_MINI_MAP* py,color);
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
    float tileX;
    float tileY;
    int color;
    data->map->img_map = mlx_new_image(data->mlx,data->map->width * TILE_SIZE,data->map->height * TILE_SIZE);
    while (i < data->map->height)
    {
        j= 0;
        while (j < data->map->width -1)
        {
            tileX = j * TILE_SIZE ;
            tileY = i * TILE_SIZE ;
            if (data->map->arr_map[i][j] == '1')
                color = 0x000000FF;
            else
                color = 0xF8F8FFFF;
            draw_map(data,SIZE_MINI_MAP * tileX,SIZE_MINI_MAP * tileY,color);
            j++;
        }
        i++;
    }
}


void rest_image(mlx_image_t *image)
{
    uint32_t x = 0;
    uint32_t y = 0;
    while (x < image->width)
    {
        y = 0;
        while (y < image->height)
        {
            mlx_put_pixel(image, x, y, 0);
            y++;
        }
        x++;
    }
}
void    ft_render_player(t_data *data)
{
    int color = 0x0000CDFF;
    int color_rays =0xA30000FF;
    rest_image(data->player->img_player);
    ft_cast_all_rays(data,color_rays);
    draw_player(data,color);
    draw_view_player(data,color);
}
