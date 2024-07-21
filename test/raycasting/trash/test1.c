#include <math.h>
#include <mlx.h>

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
} t_data;

void    draw_line(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx = fabs(x1 - x0);
    int dy = fabs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF); // Color: White
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_rotated_line(t_data *data, int x, int y, double rotationAngle, int length)
{
    int x1 = x + (int)(cos(rotationAngle) * length);
    int y1 = y + (int)(sin(rotationAngle) * length);
    draw_line(data, x, y, x1, y1);
}

int main()
{
    t_data  data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Line Drawing");

    int x = 400; // starting x-coordinate
    int y = 300; // starting y-coordinate
    double rotationAngle = M_PI / 4; // 45 degrees in radians
    int length = 30;

    draw_rotated_line(&data, x, y, rotationAngle, length);

    mlx_loop(data.mlx_ptr);

    return 0;
}
