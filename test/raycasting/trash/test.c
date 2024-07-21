#include <math.h>
#include <stdlib.h>
#include "../../../include/MLX42.h"
#include <stdio.h>

#define TILE_SIZE 64

typedef struct s_player {
    int x;
    int y;
    int radius;
    float rotationAngle;
    mlx_image_t *img_player;
} t_player;

typedef struct s_map {
    int width;
    int height;
    char **arr_map;
    mlx_image_t *img_map;
} t_map;

typedef struct s_data {
    mlx_t *mlx;
    t_player *player;
    t_map *map;
} t_data;

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    printf(" Player X  -> %d, Player Y -> %d\n", x0, y0);
    printf("End X -> %d, End Y -> %d\n", x1, y1);
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++)
    {
        mlx_put_pixel(data->player->img_player, round(X), round(Y), color);
        X += Xinc;
        Y += Yinc;
    }
}

void draw_view_player(t_data *data, int color)
{
    int start_x = data->player->x + cos(data->player->rotationAngle) * data->player->radius;
    int start_y = data->player->y + sin(data->player->rotationAngle) * data->player->radius;
    int end_x = data->player->x + cos(data->player->rotationAngle) * (data->player->radius + 30);
    int end_y = data->player->y + sin(data->player->rotationAngle) * (data->player->radius + 30);
    printf("Player X -> %d, Player Y -> %d\n", data->player->x, data->player->y);
    printf("View Start X -> %d, View Start Y -> %d\n", start_x, start_y);
    printf("View End X -> %d, View End Y -> %d\n", end_x, end_y);
    draw_line(data, start_x, start_y, end_x, end_y, color);
}

void draw_player(t_data *data, int color)
{
    int r = data->player->radius;
    for (int x = -r; x < r; x++)
    {
        for (int y = -r; y < r; y++)
        {
            if (x * x + y * y < r * r)
            {
                int px = r + x;
                int py = r + y;
                mlx_put_pixel(data->player->img_player, px, py, color);
            }
        }
    }
}



void ft_render_player(t_data *data)
{
    int color = 0xFF0000FF;
    data->player->img_player = mlx_new_image(data->mlx, 800, 600);
    draw_player(data, color);
    draw_view_player(data, 0x00FF00FF);
    mlx_image_to_window(data->mlx, data->player->img_player, data->player->x - data->player->radius, data->player->y - data->player->radius);
}

int main()
{
    t_data data;
    t_player player;

    // Initialize MiniLibX
    data.mlx = mlx_init(800, 600, "Draw Line Test", true);
    if (!data.mlx)
        return 1; // Handle initialization failure

    // Initialize player
    player.x = 400;
    player.y = 300;
    player.radius = 10;
    player.rotationAngle = M_PI / 4; // 45 degrees
    data.player = &player;

    // Create an image for the player
    player.img_player = mlx_new_image(data.mlx, 800, 600);
    if (!player.img_player)
    {
        mlx_terminate(data.mlx);
        return 1; // Handle image creation failure
    }

    // Render the player and their view direction
    ft_render_player(&data);

    // Start the MiniLibX loop
    mlx_loop(data.mlx);

    // Cleanup
    mlx_delete_image(data.mlx, player.img_player);
    mlx_terminate(data.mlx);
    
    return 0;
}
