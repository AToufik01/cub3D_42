/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:09:41 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/21 18:50:33 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int instalize_data(t_data   *data,t_map *map, t_player *player)
{
    char **map1 = (char *[]){
    "1111111111111111111",
    "1011001001001000001",
    "1011000001000001001",
    "1001001001111101111",
    "1001111000001001001",
    "1000000000000001001",
    "1001111111111001001",
    "1111000000000001011",
    "1000000001000000001",
    "1111111111111111111"
};

    map->width = 20;
    map->height = 10;
    map->arr_map = (char **)malloc(11 * sizeof(char *));
    for (int i = 0; i < map->height; i++)
    {
        map->arr_map[i] = (char *)malloc((strlen(map1[i]) + 1) * sizeof(char));
        strcpy(map->arr_map[i], map1[i]); /// 
    }
    player->x = map->width * TILE_SIZE / 2;
    player->y = map->height * TILE_SIZE / 2;
    player->radius = 8;
    player->img_p_width = map->width* TILE_SIZE;//
    player->img_p_height =map->height*TILE_SIZE ;//
    player->view_player = TILE_SIZE;
    player->turnDirection = 0;
    player->walkDirection = 0;
    player->rotationAngle = M_PI/2;
    player->moveSpeed = 4.0;
    player->rotationSpeed = 3 * (M_PI / 180);
    data->map = map;
    data->player = player;
    return (0);
}

int main()
{
    t_player    player;
    t_map   map;
    t_data  data_mlx;
    
    instalize_data(&data_mlx,&map,&player);
    // printf_para(&data_mlx);
    data_mlx.mlx = mlx_init((data_mlx.map->width -1) * TILE_SIZE, data_mlx.map->height *TILE_SIZE,"cub3D",1);
    ft_render_map(&data_mlx);
    ft_render_player(&data_mlx);
    mlx_loop_hook(data_mlx.mlx,ft_update_env,&data_mlx);
    mlx_loop(data_mlx.mlx);

    return (0);
}


