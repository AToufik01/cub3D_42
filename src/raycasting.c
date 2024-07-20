/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:04:53 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/20 20:15:59 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_cast_all_rays(t_data *data,int color)
{
    int i;
    float rayangle = data->player->rotationAngle - (FOV_ANGLE / 2);
    i = 0;
    while (i < NBR_RAYS)
    {
        draw_view_rays(data,rayangle ,color);
        rayangle += FOV_ANGLE / NBR_RAYS;
        i++;
    }
}

void draw_view_rays(t_data *data,float rayangle ,int color)
{
    int centerX = data->player->img_p_width /2; 
    int centerY = data->player->img_p_height /2;
    int i = 0;
    while (i < NBR_RAYS)
    {
        int x1 = centerX + cos(rayangle) * 200;
        int y1 = centerY + sin(rayangle) * 200;
        draw_line(data, centerX, centerY, x1, y1, color);
        i++;
    }
    
}