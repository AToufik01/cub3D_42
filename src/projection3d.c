/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:57:48 by ataoufik          #+#    #+#             */
/*   Updated: 2024/08/01 22:55:19 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int    ft_color(int r, int g, int b, int a)
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}

void    ft_projection3D(t_data *data,float d,int sig , t_ray *ray, double raydistance)
{

    double d_projectplan;
    double wallheight;
    d_projectplan = (data->mlx->width / 2) * tan(FOV_ANGLE /2);
    wallheight = (TILE_SIZE / raydistance) * d_projectplan;
    // draw_wall(data,d * WALL_STRIP_WIDTH,(data->mlx->height / 2) - (wallheight / 2),WALL_STRIP_WIDTH,wallheight,raydistance);
    int offset_x;
    int offset_y;
    if (sig == 0)
         offset_x = (int)ray->y_intercept % TILE_SIZE;
    else
        offset_x = (int)ray->x_intercept % TILE_SIZE;
    int x = d * WALL_STRIP_WIDTH;
    int y = (data->mlx->height / 2) - (wallheight / 2);
    int i;
    int j;
    i = 0;
    while (i < WALL_STRIP_WIDTH)
    {
        j = 0;
        while (j < wallheight)
        {
            int px = x + i;
            int py = y + j;
            if (py >= 0 && py < data->mlx->height) // Ensure py is within the window height
            {
                offset_y = (j * HEIGHT_TEXTUER) / wallheight + 0;
                int tex_index = (WIDTH_TEXTUER * offset_y) + offset_x;

                // Ensure tex_index is within bounds
                if (tex_index >= 0 && tex_index < (WIDTH_TEXTUER * HEIGHT_TEXTUER))
                {
                    uint32_t texcolor = data->player->walltexteur[tex_index];

                    if (px >= 0 && px < data->mlx->width) // Ensure px is within the window width
                    {
                        mlx_put_pixel(data->player->img_player, px, py, texcolor);
                    }
                }
            }
            j++;
        }
        i++;
    }
}
// void draw_wall(t_data *data, int x, int y, int width, int height,double raydistance)
// {
//     int i;
//     int j;
//     uint32_t texcolor =ft_color(244, 255, 255, 255 * exp(-0.004 * raydistance));
//     i = 0;
//     // offset_x
//     while (i < width)
//     {
//         j = 0;
//         while (j < height)
//         {
//             int px = x + i;
//             int py = y + j;
//             // texcolor = data->player->walltexteur[(WIDTH_TEXTUER *4) + 39];
//             if (px < data->player->img_player->width && py < data->player->img_player->height)
//                 mlx_put_pixel(data->player->img_player,x + i, y + j, texcolor);
//             j++;
//         }
//         i++;
//     }
// }

// void draw_wall(t_data *data, int x, int y, int width, int height, double raydistance)
// {
//     int i;
//     int j;
//     uint32_t texcolor;
//     double shading = exp(-0.004 * raydistance); // Calculate shading based on ray distance

//     for (i = 0; i < width; i++)
//     {
//         for (j = 0; j < height; j++)
//         {
//             int px = x + i;
//             int py = y + j;
//             int tex_x = (i * WIDTH_TEXTUER) / width;
//             int tex_y = (j * HEIGHT_TEXTUER) / height;

//             int color_index = (tex_x + tex_y) % 6; // Wrap around the color table
//             texcolor = color_table[color_index];
//             uint8_t r = ((texcolor >> 16) & 0xFF) * shading;
//             uint8_t g = ((texcolor >> 8) & 0xFF) * shading;
//             uint8_t b = (texcolor & 0xFF) * shading;
//             texcolor = (0xFF << 24) | (r << 16) | (g << 8) | b;
//             if (px < data->player->img_player->width && py < data->player->img_player->height)
//             {
//                 mlx_put_pixel(data->player->img_player, px, py, texcolor);
//             }
//         }
//     }
// }

