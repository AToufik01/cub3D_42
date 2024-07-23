/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:04:53 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/23 15:58:46 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void    ft_cast_all_rays(t_data *data,int color)
// {
//     int i;
//     double dist;
//     dist = 400;
//     double rayangle = data->player->rotationAngle - (FOV_ANGLE / 2);
//     i = 0;
//     while (i < NBR_RAYS)
//     {
//         rayangle = ft_normalizeangle(rayangle);
//         // dist = ft_intrecetion(data,rayangle);
//         dist =ft_rays_vertical(data,rayangle);
//         draw_view_rays(data,rayangle ,dist,color);
//         rayangle += FOV_ANGLE / NBR_RAYS;
//         i++;
//     }
// }
// double  ft_intrecetion(t_data *data, float rayangle)
// {
//     double dx;
//     double dy;
//     dy = ft_rays_horizontal(data ,rayangle);
//     dx = ft_rays_vertical(data ,rayangle);
//     if (dy>=dx)
//         return dx;
//     else
//         return dy;
// }
// void draw_view_rays(t_data *data,float rayangle ,double distance,int color)
// {
//     int centerX = data->player->x - 4 + data->player->radius/2; 
//     int centerY = data->player->y - 4 + data->player->radius/2;
//     int x1 = centerX + cos(rayangle) * distance;
//     int y1 = centerY + sin(rayangle) * distance;
//     draw_line(data, centerX, centerY, x1, y1, color);
// }
    
// double ft_normalizeangle(double rayangle)
// {
//     rayangle = fmod(rayangle, 2.0 * M_PI);
//     if (rayangle < 0)
//         rayangle += 2.0 * M_PI;
//     return rayangle;
// }

// double ft_rays_horizontal(t_data *data, float rayangle)
// {
//     double dx;
//     double dy;
//     int direct = -1;
//     double distance = 0;
//     double y_pos_intercept;
//     y_pos_intercept = round(data->player->y / TILE_SIZE) * TILE_SIZE;
//     if (rayangle < M_PI)
//     {
//         direct = 1;
//         y_pos_intercept += TILE_SIZE; 
//     }
//     dy = (y_pos_intercept - data->player->y);
//     dx = dy / tan(rayangle);
//     int i = 0;
//     while (i < 10)
//     {
//         int new_x = data->player->x  +direct+ dx;
//         int new_y = data->player->y  + direct+dy;
//         if (ft_check_wall(data, new_x , new_y)==1)
//             break;
//         else
//         {
//             dy += TILE_SIZE * direct;
//             dx += dy / tan(rayangle);
//         }
//         i++;
//     }
//     distance = sqrt(pow(dy,2) + pow(dx,2));
//     return distance;
// }

// double ft_rays_vertical(t_data *data, float rayangle)
// {
//     double dx;
//     double dy;
//     int direct = -1;
//     double distance = 0;
//     double x_pos_intercept;
//     x_pos_intercept = round(data->player->x / TILE_SIZE) * TILE_SIZE;
//     if (rayangle < 0.5 * M_PI && rayangle > 1.5*M_PI)
//     {
//         direct = 1;
//         x_pos_intercept += TILE_SIZE; 
//     }
//     dx = (x_pos_intercept - data->player->x);
//     dy = dx / tan(rayangle);
//     int i = 0;
//     while (i < 20)
//     {
//         int new_x = data->player->x  +direct+ dx;
//         int new_y = data->player->y  + direct+dy;
//         if (ft_check_wall(data, new_x , new_y)==1)
//             break;
//         else
//         {
//             dx += TILE_SIZE * direct;
//             dy += dx / tan(rayangle);
//         }
//         i++;
//     }
//     distance = sqrt(pow(dy,2) + pow(dx,2));
//     return distance;
// }


void ft_cast_all_rays(t_data *data, int color)
{
    int i;
    double dist;
    double ray_angle;

    ray_angle = data->player->rotationAngle - (FOV_ANGLE / 2);
    for (i = 0; i < NBR_RAYS; i++)
    {
        ray_angle = ft_normalizeangle(ray_angle);
        dist = ft_intersection(data, ray_angle);
        draw_view_rays(data, ray_angle, dist, color);
        ray_angle += FOV_ANGLE / NBR_RAYS;
    }
}

double ft_intersection(t_data *data, float ray_angle)
{
    double hor_dist = ft_rays_horizontal(data, ray_angle);
    double vert_dist = ft_rays_vertical(data, ray_angle);
    return (hor_dist < vert_dist) ? hor_dist : vert_dist;
}

void draw_view_rays(t_data *data,float rayangle ,double distance,int color)
{
    int centerX = data->player->x - 4 + data->player->radius/2; 
    int centerY = data->player->y - 4 + data->player->radius/2;
    int x1 = centerX + cos(rayangle) * distance;
    int y1 = centerY + sin(rayangle) * distance;
    draw_line(data, centerX, centerY, x1, y1, color);
}

double ft_normalizeangle(double ray_angle)
{
    ray_angle = fmod(ray_angle, 2.0 * M_PI);
    if (ray_angle < 0)
        ray_angle += 2.0 * M_PI;
    return ray_angle;
}

double ft_rays_horizontal(t_data *data, float ray_angle)
{
    double dx, dy;
    int stepY = TILE_SIZE;
    int dirct = -1;
    double y_intercept, x_intercept;
    double distance = 0;

    if (ray_angle > 0 && ray_angle < M_PI)
    {
        dirct = 1;
        stepY = TILE_SIZE;
    }
    else
        stepY = -TILE_SIZE;

    y_intercept = round(data->player->y / TILE_SIZE) * TILE_SIZE;
    if (ray_angle > 0 && ray_angle < M_PI)
        y_intercept += TILE_SIZE;

    dy = y_intercept - data->player->y;
    dx = dy / tan(ray_angle);

    // int x = data->player->x +dirct+ dx;
    // int y = data->player->y +dirct+ dy;

    int i = 0;
    while (i < 10)
    {
        int new_x = data->player->x  +dirct+ dx;
        int new_y = data->player->y  + dirct+dy;
        if (ft_check_wall(data, new_x , new_y)==1)
            break;
        else
        {
            dy += TILE_SIZE * dirct;
            dx += dy / tan(ray_angle);
        }
        i++;
    }
    distance = sqrt((dx * dx) + (dy * dy));
    return distance;
}

double ft_rays_vertical(t_data *data, float ray_angle)
{
    double dx, dy;
    int dirct = -1;
    int stepX = TILE_SIZE;
    double x_intercept, y_intercept;
    double distance = 0;

    if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
    {
        dirct = 1;
        stepX = TILE_SIZE;
    }
    else
        stepX = -TILE_SIZE;

    x_intercept = round(data->player->x / TILE_SIZE) * TILE_SIZE;
    if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
        x_intercept += TILE_SIZE;

    dx = x_intercept - data->player->x;
    dy = dx * tan(ray_angle);

    // int x = data->player->x +dirct+ dx;
    // int y = data->player->y + dirct+dy;

    // while (!ft_check_wall(data, x -1, y -1))
    // {
    //     x += stepX;
    //     y += stepX * tan(ray_angle);
    // }
    int i = 0;
    while (i < 20)
    {
        int new_x = data->player->x  + dirct + dx;
        int new_y = data->player->y  + dirct + dy;
        if (ft_check_wall(data, new_x , new_y)==1)
            break;
        else
        {
            dx += TILE_SIZE * dirct;
            dy += dx / tan(ray_angle);
        }
        i++;
    }
    distance = sqrt((dx * dx) + (dy * dy));
    return distance;
}
