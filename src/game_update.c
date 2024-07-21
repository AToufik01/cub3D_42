/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:34:46 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/21 18:53:49 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
int ft_check_wall(t_data *data, int x,int y)
{
    int x_map = round(x / TILE_SIZE);
    int y_map = round(y / TILE_SIZE);
    if (data->map->arr_map[y_map][x_map] == '1')
        return 1;
    return 0;
    
}

int ft_update_position_player(t_data *data)
{
    data->player->rotationAngle += (data->player->turnDirection * data->player->rotationSpeed);
    int move_step;
    double new_x;
    double new_y;
    move_step = data->player->walkDirection * data->player->moveSpeed;
    new_x = data->player->x + cos(data->player->rotationAngle) * move_step;
    new_y = data->player->y + sin(data->player->rotationAngle) * move_step;
    
    if (ft_check_wall(data, new_x,new_y) != 1)
    {
        data->player->x = new_x;
        data->player->y = new_y;
    }
    return (0);
}


void ft_update_env(void  *d)
{
    t_data *data = (t_data *)d;
    
    if (mlx_is_key_down(data->mlx, MLX_KEY_UP) == 1|| mlx_is_key_down(data->mlx, MLX_KEY_DOWN) == 1) { // UP_ARROW or DOWN_ARROW
        data->player->turnDirection = 0;
    } else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == 1 || mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == 1) { // RIGHT_ARROW or LEFT_ARROW
        data->player->walkDirection = 0;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_UP) == 1) //
    {
        data->player->walkDirection = 1;
        ft_update_position_player(data);
        mlx_delete_image(data->mlx, data->player->img_player);
        ft_render_player(data);
    }
    else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == 1) //
    {
        data->player->turnDirection = -1;
        ft_update_position_player(data);
        mlx_delete_image(data->mlx, data->player->img_player);
        ft_render_player(data);
    }
    else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == 1) //
    {
        data->player->turnDirection = 1;
        ft_update_position_player(data);
        mlx_delete_image(data->mlx, data->player->img_player);
        
        ft_render_player(data);
    }
    else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) == 1) //
    {   
        data->player->walkDirection = -1;
        ft_update_position_player(data);
        mlx_delete_image(data->mlx, data->player->img_player);
        ft_render_player(data);
    }
    else if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE) == 1) //
       mlx_close_window(data->mlx);
}

