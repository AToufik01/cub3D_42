/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:28:39 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/30 13:18:34 by ataoufik         ###   ########.fr       */
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
        rayangle = ft_normalizeangle(rayangle);
        data->ray->ray_is_down = rayangle > 0 && rayangle < M_PI;
        data->ray->ray_is_up = !data->ray->ray_is_down;
        data->ray->ray_is_right = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
        data->ray->ray_is_left = !data->ray->ray_is_right;
        distance = ft_intrecetion(data,rayangle,color);
        cdistance = distance * cos(rayangle - data->player->rotationAngle);
        ft_projection3D(data,i,rayangle,cdistance);
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
    float xstep,ystep;
    float x_intercept,y_intercept;
    
    y_intercept = floor(data->player->y /TILE_SIZE) *TILE_SIZE;
    if (data->ray->ray_is_down == true)
        y_intercept += TILE_SIZE;
    x_intercept = data->player->x + (y_intercept - data->player->y) / tan(ray_angle);
    ystep = TILE_SIZE;
    if (data->ray->ray_is_up == true)
        ystep *= -1;
    xstep = TILE_SIZE / tan(ray_angle);
    if (data->ray->ray_is_left == true && xstep > 0)
        xstep *= -1;
    if (data->ray->ray_is_right == true && xstep < 0)
        xstep *= -1;
    float new_x =x_intercept;
    float new_y =y_intercept;
    while (1)
    {
        if (ft_check_wall(data, new_x , new_y - (data->ray->ray_is_up ?1:0))==1)
            break;
        else
        {
            new_x +=xstep;
            new_y +=ystep;
        }
    }
    float dx;
    float dy;
    dx = new_x - data->player->x;
    dy = new_y - data->player->y;
    return (t_ray){dx,dy};
}

t_ray    ft_rays_vertical(t_data *data, float ray_angle)
{
    float xstep,ystep;
    float x_intercept,y_intercept;
    
    x_intercept = floor(data->player->x /TILE_SIZE) * TILE_SIZE;
    if (data->ray->ray_is_right == true)
        x_intercept += TILE_SIZE;
    y_intercept = data->player->y + (x_intercept - data->player->x) * tan(ray_angle);
    xstep = TILE_SIZE;
    if (data->ray->ray_is_left == true)
        xstep *= -1;
    ystep = TILE_SIZE * tan(ray_angle);
    if (data->ray->ray_is_up == true && ystep > 0)
        ystep *= -1;
    if (data->ray->ray_is_down == true && ystep < 0)
        ystep *= -1;
    float new_x =x_intercept;
    float new_y =y_intercept;
    while (1)
    {
        if (ft_check_wall(data, new_x - (data->ray->ray_is_left ?1:0 ), new_y)==1)
            break;
        else
        {
            new_x +=xstep;
            new_y +=ystep;
        }
    }
    float dx;
    float dy;
    dx = new_x - data->player->x;
    dy = new_y - data->player->y;
    return (t_ray){dx,dy};
    
}