#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h> /////

#include "MLX42.h"
#define TILE_SIZE 64
#define NBR_RAYS 1200
#define SIZE_MINI_MAP 0.2
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
    int img_p_width;
    int img_p_height;
    mlx_image_t *img_player;
    float rotationSpeed;

}   t_player;

typedef struct s_map
{
    // int fd;
    int width;
    int height;
    mlx_image_t *img_map;
    char **arr_map;
}   t_map;
typedef struct s_ray
{
    double  dx;
    double  dy;
}   t_ray;

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

int ft_check_wall(t_data *data, int x,int y);



// raycasting
void    ft_cast_all_rays(t_data *data,int color);
double  ft_intrecetion(t_data *data, double rayangle,int color);
t_ray ft_rays_horizontal(t_data *data, double ray_angle);
t_ray ft_rays_vertical(t_data *data, double ray_angle);
// void initialize_rays(t_data *data,int color);
void add_1px(t_data *data);
// void draw_view_rays(t_data *data,float rayangle ,int color);
void draw_view_rays(t_data *data,float rayangle ,double distance,int color);
void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);
//

void    ft_projection3D(t_data *data,int i,double ray_angle,double raydistance);
void rest_image(mlx_image_t *image);


//
void draw_wall(t_data *data,int x,int wall_top_pixel ,double wall_bottom_pixel, int color);
//
double ft_normalizeangle(double rayangle);
void     printf_para(t_data *data);
//
#endif