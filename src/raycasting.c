/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:28:39 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/29 11:11:42 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/cub3d.h"


void rays(t_data *data, float ray_angle,int color)
{

    float centerX = data->player->x;
    float centerY = data->player->y;
    float x1 = centerX + cos(ray_angle) * 90;
    float y1 = centerY + sin(ray_angle) * 90;
    draw_line(data, centerX,centerY, x1,y1, color);
}
void    ft_cast_all_rays(t_data *data,int color)
{
    int i;
    float distance;
    float cdistance;
    float rayangle = data->player->rotationAngle - (FOV_ANGLE/ 2);
    i = 0;
    while (i < NBR_RAYS)
    {
        // rays(data,rayangle,color);
        rayangle = ft_normalizeangle(rayangle);
        // ft_intrecetion(data,rayangle,color);
        // ft_projection3D(data,i,rayangle,cdistance);
        distance = ft_intrecetion(data,rayangle,color);
        cdistance = distance * cos(rayangle - data->player->rotationAngle);
        // ft_projection3D(data,i,rayangle,cdistance);
        rayangle += FOV_ANGLE / NBR_RAYS;
        i++;
    }
}

float  ft_intrecetion(t_data *data, float rayangle,int color)
{
    t_ray horizontal;
    t_ray vertical;
    horizontal = ft_rays_horizontal(data ,rayangle);
    vertical = ft_rays_vertical(data ,rayangle);
    float d_h = pow(horizontal.dx, 2) + pow(horizontal.dy , 2);
    float d_v = pow(vertical.dx, 2) + pow(vertical.dy  , 2);;
    if (d_h <= d_v)
    {
        draw_line(data, SIZE_MINI_MAP*data->player->x,SIZE_MINI_MAP* data->player->y,SIZE_MINI_MAP*(data->player->x +horizontal.dx) ,SIZE_MINI_MAP*(data->player->y+horizontal.dy),color);
        return (sqrt(d_h));
    }
    else
    {
        draw_line(data,SIZE_MINI_MAP*data->player->x,SIZE_MINI_MAP*data->player->y,SIZE_MINI_MAP*(data->player->x +vertical.dx),SIZE_MINI_MAP*(data->player->y+vertical.dy),color);
         return (sqrt(d_v));
    }
}
float ft_normalizeangle(float rayangle)
{
    rayangle = fmod(rayangle, 2.0 * M_PI);
    if (rayangle < 0)
        rayangle += 2.0 * M_PI;
    return rayangle;
}

t_ray ft_rays_horizontal(t_data *data, float ray_angle)
{
    float dx;
    float dy;
    float y_pos_intercept;
    float direct = -1;
    y_pos_intercept = floor(data->player->y / (float)TILE_SIZE) * (float)TILE_SIZE ;
    if (ray_angle > 0 && ray_angle < M_PI)
    {
        direct = 1;
        y_pos_intercept += TILE_SIZE ;
    }
    dy = y_pos_intercept - data->player->y;
    dx = dy / tan(ray_angle);
    while (1)
    {
        float new_x = data->player->x + (dy+direct)/tan(ray_angle);
        float new_y = data->player->y +dy+direct;
        if (ft_check_wall(data, new_x,new_y) == 1)
            break;
        else
        {
            dy +=TILE_SIZE * direct;
            dx = dy / tan(ray_angle);
        }
    }
    return (t_ray){dx,dy};
}

t_ray    ft_rays_vertical(t_data *data, float ray_angle)
{
    float dx;
    float dy;
    float direct;
    float x_pos_intercept;
    direct = 1;
    
    x_pos_intercept = (floor(data->player->x / (float)TILE_SIZE + (float)1)* (float)TILE_SIZE);
    if(ray_angle > M_PI/2 && ray_angle < 3 * M_PI /2)
    {
        direct = -1;
        x_pos_intercept = floor(data->player->x / (float)TILE_SIZE)* (float)TILE_SIZE;
    }
    dx = x_pos_intercept - data->player->x ;
    dy = dx * tan(ray_angle);
    while (1)
    {
        int new_x = data->player->x + direct + dx;
        int new_y = data->player->y  +(direct + dx) * tan(ray_angle);
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
