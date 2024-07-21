/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:04:53 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/21 18:54:56 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_cast_all_rays(t_data *data,int color)
{
    int i;
    double dist;
    double rayangle = data->player->rotationAngle - (FOV_ANGLE / 2);
    i = 0;
    while (i < NBR_RAYS)
    {
        // rayangle = ft_normalizeangle(rayangle);
        dist = ft_intersection_rays_y(data ,rayangle);
        draw_view_rays(data,rayangle ,dist,color);
        rayangle += FOV_ANGLE / NBR_RAYS;
        i++;
    }
}

void draw_view_rays(t_data *data,float rayangle ,double distance,int color)
{
    int centerX = data->player->x - 4 + data->player->radius/2; 
    int centerY = data->player->y - 4 + data->player->radius/2;
    int i = 0;
    while (i < NBR_RAYS)
    {
        int x1 = centerX + cos(rayangle) * distance;
        int y1 = centerY + sin(rayangle) * distance;
        draw_line(data, centerX, centerY, x1, y1, color);
        i++;
    }
    
}
double ft_normalizeangle(double rayangle)
{
    rayangle = fmod(rayangle, 2.0 * M_PI);
    if (rayangle < 0)
        rayangle += 2.0 * M_PI;
    return rayangle;
}
int is_facingray_up_down(float rayangle)
{
    if (rayangle > 0 && rayangle < M_PI) //up
        return (1);
    return (0);//down 
}

int is_facingray_left_right(float rayangle)
{
    if (rayangle < M_PI / 2 || rayangle > (3 * M_PI) / 2) //right
        return (1);
    return (0);//left
}

// void    ft_intersection_rays_x(t_data *data);
double    ft_intersection_rays_y(t_data *data ,float rayangle)
{
    long    dlta_x;
    long    dlta_y;
    double  distance;
    long    first_intersept;
    int     x_post_intersept;
    int     y_post_intersept;
    dlta_y = TILE_SIZE;
    dlta_x =  dlta_y / tan(rayangle);
    y_post_intersept = round(data->player->y / TILE_SIZE) * TILE_SIZE;
    if (is_facingray_up_down(rayangle) == 0)
        y_post_intersept += TILE_SIZE;
    x_post_intersept = data->player->x + (data->player->y - y_post_intersept) / tan(rayangle);

    //
    if (is_facingray_up_down(rayangle)== 1)
        dlta_y *= -1;
    if (is_facingray_left_right(rayangle) == 0 && dlta_x > 0)
        dlta_x *= -1;
    if (is_facingray_left_right(rayangle) == 1 && dlta_x < 0)
        dlta_x *= -1;
    first_intersept = sqrt(pow((y_post_intersept - data->player->y),2) + pow((x_post_intersept - data->player->x),2));
    distance = first_intersept;
    int x;
    int y;
    x =  x_post_intersept;
    y =  y_post_intersept;
    while (1)
    {
        if (ft_check_wall(data, x, y)==1)
        {
            distance  += sqrt(pow((y - data->player->y),2) + pow((x - data->player->x),2));
            return distance;
            break;
        }
        else
        {
            x += dlta_x;
            y += dlta_y;
        }
        /* code */
    }
    return (10);
}