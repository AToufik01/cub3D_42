/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:04:53 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/25 12:44:01 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_cast_all_rays(t_data *data,int color)
{
    int i;
    double distance;
    double rayangle = data->player->rotationAngle - (FOV_ANGLE/ 2);
    i = 0;
    while (i < NBR_RAYS)
    {
        rayangle = ft_normalizeangle(rayangle);
        distance = ft_intrecetion(data,rayangle,color);
        ft_projection3D(data,i,rayangle,distance);
        rayangle += FOV_ANGLE / NBR_RAYS;
        i++;
    }
}
double  ft_intrecetion(t_data *data, double rayangle,int color)
{
    t_ray horizontal;
    t_ray vertical;
    horizontal = ft_rays_horizontal(data ,rayangle);
    vertical = ft_rays_vertical(data ,rayangle);
    double d_h = pow(horizontal.dx , 2) + pow(horizontal.dy, 2);
    double d_v = pow(vertical.dx , 2) + pow(vertical.dy, 2);;
    if (d_h<d_v)
    {
        draw_line(data,SIZE_MINI_MAP* data->player->x,SIZE_MINI_MAP* data->player->y,SIZE_MINI_MAP* (data->player->x +horizontal.dx) ,SIZE_MINI_MAP* (data->player->y+horizontal.dy),color);
        return (sqrt(d_h));
    }
    else
    {
        draw_line(data,SIZE_MINI_MAP* data->player->x,SIZE_MINI_MAP* data->player->y,SIZE_MINI_MAP* (data->player->x +vertical.dx),SIZE_MINI_MAP* (data->player->y+vertical.dy),color);
         return (sqrt(d_v));
    }
}
    
double ft_normalizeangle(double rayangle)
{
    rayangle = fmod(rayangle, 2.0 * M_PI);
    if (rayangle < 0)
        rayangle += 2.0 * M_PI;
    return rayangle;
}

t_ray ft_rays_vertical(t_data *data, double ray_angle)
{
    double dx;
    double dy;
    double x_pos_intercept;
    int direct;
    direct = 1;
    
    x_pos_intercept = (floor(data->player->x / TILE_SIZE) + 1)* TILE_SIZE;
    if (ray_angle > 0.5 * M_PI  && ray_angle < 1.5 * M_PI)
    {
        direct = -1;
        x_pos_intercept = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
    }
    dx = x_pos_intercept - data->player->x;
    dy = dx * tan(ray_angle);
    while (1)
    {
        int new_x = data->player->x + direct + dx;
        int new_y = data->player->y  +direct + dy;
        if (ft_check_wall(data, new_x , new_y)==1)
            break;
        else
        {
            dx += TILE_SIZE * direct;
            dy = dx * tan(ray_angle);
        }
    }
    return (t_ray){dx,dy};
}

t_ray ft_rays_horizontal(t_data *data, double ray_angle)
{
    double dx, dy;
    double y_pos_intercept;
    int direct;
    direct = -1;
    y_pos_intercept = floor(data->player->y / TILE_SIZE ) * TILE_SIZE;
    if (ray_angle > 0 && ray_angle < M_PI)
    {
        direct = 1;
        y_pos_intercept += TILE_SIZE;
    }
    dy = y_pos_intercept - data->player->y;
    dx = dy / tan(ray_angle);
    while (1)
    {
        int new_y = data->player->y+direct+ dy;
        int new_x = data->player->x +(dy+direct)/tan(ray_angle);
        if (ft_check_wall(data, new_x , new_y)==1)
            break;
        else
        {
            dy += TILE_SIZE * direct ;
            dx = dy / tan(ray_angle);
        }
    }

    return (t_ray){dx,dy};
}
