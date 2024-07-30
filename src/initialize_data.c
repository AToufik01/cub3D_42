/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:48:28 by ataoufik          #+#    #+#             */
/*   Updated: 2024/07/30 13:18:46 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void init_data(t_data   *data,t_map *map, t_player *player)
{
       char **map1 = (char *[]){
    "1111111111111111111",
    "1011001001001000001",
    "1011000001000001001",
    "1001001000000001111",
    "1000110000000001001",
    "1000000000000001001",
    "1001111110000001001",
    "1111000000000001011",
    "1000000001000000001",
    "1111111111111111111"
};

    map->width = 20;
    map->height = 10;
    map->arr_map = (char **)malloc(11 * sizeof(char *));
    for (int i = 0; i < map->height; i++)
    {
        map->arr_map[i] = (char *)malloc((strlen(map1[i])+1) * sizeof(char));
        strcpy(map->arr_map[i], map1[i]); /// 
    }
    player->x = map->width * TILE_SIZE / 2 ;
    player->y = map->height * TILE_SIZE / 2;
    player->radius = 5;
    player->turnDirection = 0;
    player->walkDirection = 0;
    player->rotationAngle =  2;
    player->moveSpeed = 6.0;
    player->rotationSpeed = 3* (M_PI / 180);
    data->map = map;
    data->player = player;
    
}