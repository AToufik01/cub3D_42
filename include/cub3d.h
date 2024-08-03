#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h> /////

#include "MLX42.h"
#define WIDTH_TEXTUER 64
#define HEIGHT_TEXTUER 64
#define TILE_SIZE 128
#define NBR_RAYS 2000
#define WINDOW_WHIDTH 1500 ///
#define WINDOW_HEIGHT 900 ///
#define WALL_STRIP_WIDTH 1
#define SIZE_MINI_MAP 0.05
#define FOV_ANGLE (60 * (M_PI / 180))

typedef struct s_player
{
    float  x;
    float  y;
    int  radius;
    double  view_player;
    int     turnDirection;
    int     walkDirection;
    float   rotationAngle;
    float   moveSpeed;
    mlx_image_t *img_player;
    // uint32_t *walltexteur;
    mlx_texture_t*walltexteur; //// 
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
    float  dx;
    float  dy;
    float   x_intercept;
    float   y_intercept;
    bool    ray_is_up;
    bool    ray_is_down;
    bool    ray_is_left;
    bool    ray_is_right;
}   t_ray;

typedef struct s_data
{
    mlx_t   *mlx;
    t_map *map;
    t_player *player;
    t_ray   *ray;
}   t_data;


// static uint32_t color_table[6] = {
//     0xFF0000FF, // Blue
//     0xFF00FF00, // Green
//     0xFFFF0000, // Red
//     0xFFFFFF00, // Yellow
//     0xFFFF00FF, // Magenta
//     0xFF00FFFF  // Cyan
// };

void ft_player(t_data *data);
void init_data(t_data   *data,t_map *map, t_player *player);
void    draw_circle(t_data *data,int color);
int ft_check_wall(t_data *data, float x,float y);
void ft_update_env(void  *d);
int ft_update_position_player(t_data *data);
void rest_image(mlx_image_t *image);
void draw_line(t_data *data, float x0, float y0, float x1, float y1, int color);
void    ft_map(t_data *data);
void    draw_rect(t_data *data,float size_x,float size_y , int color);
void    ft_cast_all_rays(t_data *data,int color);


float ft_normalizeangle(float rayangle);
t_ray ft_rays_horizontal(t_data *data, t_ray *ray,float ray_angle);
t_ray ft_rays_vertical(t_data *data, t_ray *ray, float ray_angle);
float  ft_intrecetion(t_data *data, float rayangle,int color);
///part test 
void rays(t_data *data, float ray_angle,int color);////

void    ft_projection3D(t_data *data,float d,int sig , t_ray *ray, double raydistance);
int ft_check_wall_intersection(t_data *data ,float x , float y);
// void ft_rays_horizontal(t_data *data, float ray_angle);




////
// void ft_update_env(void  *data);

// void ft_render_map(t_data *data);
// int ft_check_wall(t_data *data, int x,int y);

// // raycasting
// void    ft_cast_all_rays(t_data *data,int color);
// float  ft_intrecetion(t_data *data, double rayangle,int color);
// t_ray ft_rays_horizontal(t_data *data, double ray_angle);
// t_ray ft_rays_vertical(t_data *data, double ray_angle);
// // void initialize_rays(t_data *data,int color);
// void add_1px(t_data *data);
// // void draw_view_rays(t_data *data,float rayangle ,int color);
// void draw_view_rays(t_data *data,float rayangle ,double distance,int color);
// void draw_line(t_data *data, float x0, float y0, float x1, float y1, int color);
// //

// void rest_image(mlx_image_t *image);
// //
// void draw_wall(t_data *data,float x,float wall_top_pixel ,float wall_bottom_pixel, int color);
// //
void draw_wall(t_data *data, int x, int y, int width, int height, double raydistance);
// double ft_normalizeangle(double rayangle);
// void     printf_para(t_data *data);
//
#endif