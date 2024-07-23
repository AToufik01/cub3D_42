/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:04:53 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/23 22:02:08 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_cast_all_rays(t_data *data,int color)
{
    int i;
    double dist;
    dist = 400;
    double rayangle = data->player->rotationAngle - (FOV_ANGLE / 2);
    i = 0;
    while (i < NBR_RAYS)
    {
        rayangle = ft_normalizeangle(rayangle);
        dist = ft_intrecetion(data,rayangle);
        // dist = ft_rays_vertical(data ,rayangle);
        // dist = ft_rays_horizontal(data ,rayangle);
        draw_view_rays(data,rayangle ,dist,color);
        rayangle += FOV_ANGLE / NBR_RAYS;
        i++;
    }
}
double  ft_intrecetion(t_data *data, float rayangle)
{
    double dx;
    double dy;
    dy = ft_rays_horizontal(data ,rayangle);
    dx = ft_rays_vertical(data ,rayangle);
    if (dy>=dx)
        return dx;
    else
        return dy;
}
void draw_view_rays(t_data *data,float rayangle ,double distance,int color)
{
    int centerX = data->player->x - 4 + data->player->radius/2; 
    int centerY = data->player->y - 4 + data->player->radius/2;
    int x1 = centerX + cos(rayangle) * distance;
    int y1 = centerY + sin(rayangle) * distance;
     
    draw_line(data, centerX, centerY, x1, y1, color); //fewwe
}
    
double ft_normalizeangle(double rayangle)
{
    rayangle = fmod(rayangle, 2.0 * M_PI);
    if (rayangle < 0)
        rayangle += 2.0 * M_PI;
    return rayangle;
}

double ft_rays_vertical(t_data *data, float ray_angle)
{
    double dx, dy;
    double x_pos_intercept;
    int direct;
    double distance = 0;
    direct = -1;
    
    x_pos_intercept = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
    if (ray_angle > 0 && ray_angle < M_PI)
    {
        direct = 1;
        x_pos_intercept += TILE_SIZE; 
    }
    dx = x_pos_intercept - data->player->x;
    dy = dx / tan(ray_angle);
    int i = 0;
    while (i < 20)
    {
        int new_y = data->player->y  +(dx+direct)/tan(ray_angle);
        int new_x = data->player->x +direct + dx;
        if (ft_check_wall(data, new_x , new_y)==1)
            break;
        else
        {
            dx += TILE_SIZE* direct  ;
            dy = dx / tan(ray_angle);
        }
        i++;
    }
    // draw_line(data,data->player->x,data->player->y,data->player->x +dx,data->player->y+dy,0x8000FFFF);
    distance = sqrt((dx * dx) + (dy * dy));
    return distance;
}


double ft_rays_horizontal(t_data *data, float ray_angle)
{
    double dx, dy;
    double pos_intercept;
    int direct;
    double distance = 0;
    direct = -1;
    pos_intercept = floor(data->player->y / TILE_SIZE ) * TILE_SIZE;
    if (ray_angle > 0 && ray_angle < M_PI)
    {
        direct = 1;
        pos_intercept += TILE_SIZE;
    }

    dy = pos_intercept - data->player->y;
    dx = dy / tan(ray_angle);
    // printf("dx   = %f     ,   dy   = %f\n",dx,dy);
    int i = 0;
    while (i < 10)
    {
        int new_y = data->player->y+direct+ dy ;
        int new_x = data->player->x +(dy+direct)/tan(ray_angle);
        if (ft_check_wall(data, new_x , new_y)==1)
            break;
        else
        {
            dy += TILE_SIZE * direct ;
            dx = dy / tan(ray_angle);
            
        }
        i++;
    }
    // printf("------------------------------------------\n");
    distance = sqrt((dx * dx) + (dy * dy));

    return distance;
}
