// void ft_cast_all_rays(t_data *data, int color)
// {
//     int i;
//     double dist;
//     double ray_angle;

//     ray_angle = data->player->rotationAngle - (FOV_ANGLE / 2);
//     for (i = 0; i < NBR_RAYS; i++)
//     {
//         ray_angle = ft_normalizeangle(ray_angle);
//         dist = ft_intersection(data, ray_angle);
//         draw_view_rays(data, ray_angle, dist, color);
//         ray_angle += FOV_ANGLE / NBR_RAYS;
//     }
// }

// double ft_intersection(t_data *data, float ray_angle)
// {
//     double hor_dist = ft_rays_horizontal(data, ray_angle);
//     double vert_dist = ft_rays_vertical(data, ray_angle);
//     return (hor_dist < vert_dist) ? hor_dist : vert_dist;
// }

// void draw_view_rays(t_data *data, float ray_angle, double distance, int color)
// {
//     int centerX = data->player->x + data->player->radius / 2; 
//     int centerY = data->player->y + data->player->radius / 2;
//     int x1 = centerX + cos(ray_angle) * distance;
//     int y1 = centerY + sin(ray_angle) * distance;
//     draw_line(data, centerX, centerY, x1, y1, color);
// }

// double ft_normalizeangle(double ray_angle)
// {
//     ray_angle = fmod(ray_angle, 2.0 * M_PI);
//     if (ray_angle < 0)
//         ray_angle += 2.0 * M_PI;
//     return ray_angle;
// }

// double ft_rays_horizontal(t_data *data, float ray_angle)
// {
//     double dx, dy;
//     int stepY = TILE_SIZE;
//     double y_intercept, x_intercept;
//     double distance = 0;

//     if (ray_angle > 0 && ray_angle < M_PI)
//         stepY = TILE_SIZE;
//     else
//         stepY = -TILE_SIZE;

//     y_intercept = round(data->player->y / TILE_SIZE) * TILE_SIZE;
//     if (ray_angle > 0 && ray_angle < M_PI)
//         y_intercept += TILE_SIZE;

//     dy = y_intercept - data->player->y;
//     dx = dy / tan(ray_angle);

//     int x = data->player->x + dx;
//     int y = data->player->y + dy;

//     while (!ft_check_wall(data, x, y))
//     {
//         y += stepY;
//         x += stepY / tan(ray_angle);
//     }

//     distance = sqrt((dx * dx) + (dy * dy));
//     return distance;
// }

// double ft_rays_vertical(t_data *data, float ray_angle)
// {
//     double dx, dy;
//     int stepX = TILE_SIZE;
//     double x_intercept, y_intercept;
//     double distance = 0;

//     if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
//         stepX = TILE_SIZE;
//     else
//         stepX = -TILE_SIZE;

//     x_intercept = round(data->player->x / TILE_SIZE) * TILE_SIZE;
//     if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
//         x_intercept += TILE_SIZE;

//     dx = x_intercept - data->player->x;
//     dy = dx * tan(ray_angle);

//     int x = data->player->x + dx;
//     int y = data->player->y + dy;

//     while (!ft_check_wall(data, x, y))
//     {
//         x += stepX;
//         y += stepX * tan(ray_angle);
//     }

//     distance = sqrt((dx * dx) + (dy * dy));
//     return distance;
// }
