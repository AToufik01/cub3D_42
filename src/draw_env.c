/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:14:18 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/29 11:06:19 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    draw_circle(t_data *data,int color)
{
    int x;
    int y;
    float px;
    float py;
    int r;

    r = data->player->radius;
    x = -r;
    while (x < r)
    {
        y = -r;
        while (y < r)
        {
            if (pow(x, 2) + pow(y, 2) < pow(r, 2))
            {
                px = data->player->x + x;
                py = data->player->y + y;
                if (px < data->player->img_player->width && py < data->player->img_player->height && px>=0 && py>=0)
                    mlx_put_pixel(data->player->img_player,SIZE_MINI_MAP*px,SIZE_MINI_MAP*py,color);
            }

            y++;
        }
        x++;
    }
    
    
}

void draw_line(t_data *data, float x0, float y0, float x1, float y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps;
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
        if (X < data->player->img_player->width && Y < data->player->img_player->height && X>=0 && Y>=0)
            mlx_put_pixel(data->player->img_player, X, Y, color);
        X += Xinc;
        Y += Yinc;
        i++;
    }
}