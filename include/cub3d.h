#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h> /////

#include "MLX42.h"
#define TILE_SIZE 32
#define FOV_ANGLE (60 * (M_PI / 180))

typedef struct s_player
{
    double  x;
    double  y;
    double  radius;
    double  view_player;
    int     turnDirection;
    int     walkDirection;
    float   rotationAngle;
    float   moveSpeed;
    mlx_image_t *img_player;
    float rotationSpeed;

}   t_player;

typedef struct s_map
{
    // int x;
    // int y;
    // int fd;
    int width;
    int height;
    mlx_image_t *img_map;
    char **arr_map;
    // int **arr_map;
}   t_map;

typedef struct s_data
{
    mlx_t   *mlx;
    t_map *map;
    t_player *player;
}   t_data;


void ft_update_env(void  *data);
int instalize_data(t_data   *data,t_map *map, t_player *player);

void ft_render_map(t_data *data);
void ft_render_player(t_data *data);

// int key_press(int keycode, t_data *data);
// int key_release(int keycode, t_data *data);
// ?

void     printf_para(t_data *data);
//
#endif