/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:30:18 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/30 12:21:27 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main()
{
    t_player    player;
    t_map   map;
    t_data  data_mlx;

    init_data(&data_mlx,&map,&player);
    data_mlx.mlx = mlx_init((data_mlx.map->width - 4) * TILE_SIZE,(data_mlx.map->height) * TILE_SIZE,"cub3D",0);
    data_mlx.player->img_player = mlx_new_image(data_mlx.mlx,data_mlx.mlx->width,data_mlx.mlx->height);
    ft_map(&data_mlx);
    ft_player(&data_mlx);
    mlx_image_to_window(data_mlx.mlx,data_mlx.map->img_map,0,0);
    mlx_image_to_window(data_mlx.mlx,data_mlx.player->img_player,0,0);
    mlx_loop_hook(data_mlx.mlx,ft_update_env,&data_mlx);
    mlx_loop(data_mlx.mlx);
    return 0;
}