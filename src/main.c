/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:30:18 by ataoufik          #+#    #+#             */
/*   Updated: 2024/08/04 16:36:37 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    inite_data_player(t_data *data)
{
    data->player->radius = 5;
    data->player->turnDirection = 0;
    data->player->walkDirection = 0;
    data->player->moveSpeed = 6.0;
    data->player->rotationSpeed = 5* (M_PI / 180);
    if (data->player->isFacing== 'N')
        data->player->rotationAngle =  3 * M_PI / 2;
    else if (data->player->isFacing== 'E')
        data->player->rotationAngle =  0;
    else if (data->player->isFacing== 'S')
        data->player->rotationAngle = M_PI / 2;
    else if (data->player->isFacing== 'W')
        data->player->rotationAngle =  M_PI;
}

void parsing(t_data *data, char *av)
{
    fill_list(data, av);
    is_valid_Map(data);
    inite_data_player(data);
    // print_elements(data);
}

int		main(int ac, char **av)
{
    t_player    player;
    t_map   map;
    t_data  data_mlx;
    parsing(&data_mlx, av[1]);
    data_mlx.mlx = mlx_init(WINDOW_WHIDTH,WINDOW_HEIGHT,"cub3D",0);
    data_mlx.player->img_player = mlx_new_image(data_mlx.mlx,data_mlx.mlx->width,data_mlx.mlx->height);
    // ft_map(&data_mlx);
    ft_player(&data_mlx);
    // mlx_image_to_window(data_mlx.mlx,data_mlx.map->img_map,0,0);
    mlx_image_to_window(data_mlx.mlx,data_mlx.player->img_player,0,0);
    mlx_loop_hook(data_mlx.mlx,ft_update_env,&data_mlx);
    mlx_loop(data_mlx.mlx);
    return 0;
}