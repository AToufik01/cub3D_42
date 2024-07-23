
// void castRay(t_data *data)
// {
//     double x_post_intersept, y_post_intersept;
//     double dlta_x, dlta_y;

//     bool foundHorzWallHit = false;
//     double horzWallHitX = 0;
//     double horzWallHitY = 0;

//     y_post_intersept = floor(data->player->y / TILE_SIZE) * TILE_SIZE;
//     y_post_intersept += RayFacingDown ? TILE_SIZE : 0;

//     x_post_intersept = data->player->x + (y_post_intersept - data->player->y) / tan(rayAngle);

//     dlta_y = TILE_SIZE;
//     dlta_y *= RayFacingUp ? -1 : 1;

//     dlta_x = TILE_SIZE / tan(rayAngle);
//     dlta_x *= (RayFacingLeft && dlta_x > 0) ? -1 : 1;
//     dlta_x *= (RayFacingRight && dlta_x < 0) ? -1 : 1;

//     double X = x_post_intersept;
//     double Y = y_post_intersept;

//     if (RayFacingUp)
//         Y--;
//     while (X >= 0 && X <= WINDOW_WIDTH && Y >= 0 && Y <= WINDOW_HEIGHT) {
//         if (hasWallAt(grid, X, Y)) {
//             foundHorzWallHit = true;
//             horzWallHitX = X;
//             horzWallHitY = Y;
//             break;
//         } else {
//             X += dlta_x;
//             Y += dlta_y;
//         }
//     }

// void castRay(t_data *data)
// {
//     double x_post_intersept, y_post_intersept;
//     double dlta_x, dlta_y;
//     bool foundVertWallHit = false;
//     double vertWallHitX = 0;
//     double vertWallHitY = 0;
//     x_post_intersept = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
//     x_post_intersept += ray->isRayFacingRight ? TILE_SIZE : 0;
//     y_post_intersept = data->player->y + (x_post_intersept - data->player->x) * tan(ray->rayAngle);
//     dlta_x = TILE_SIZE;
//     dlta_x *= ray->isRayFacingLeft ? -1 : 1;
//     dlta_y = TILE_SIZE * tan(ray->rayAngle);
//     dlta_y *= (ray->isRayFacingUp && ystep > 0) ? -1 : 1;
//     dlta_y *= (ray->isRayFacingDown && ystep < 0) ? -1 : 1;
//     double X = x_post_intersept;
//     double Y = y_post_intersept;
//     if (ray->isRayFacingLeft)
//          X--;
//     while (X >= 0 && X <= WINDOW_WIDTH && Y >= 0 && Y <= WINDOW_HEIGHT){
//         if (hasWallAt(grid, X, Y)) {
//             foundVertWallHit = true;
//             vertWallHitX = X;
//             vertWallHitY = Y;
//             break;
//         } else {
//             X += xstep;
//             Y += ystep;
//         }
//     }
// }



//     double horzHitDistance = (foundHorzWallHit)
//         ? distanceBetweenPoints(player->x, player->y, horzWallHitX, horzWallHitY)
//         : INFINITY;
//     double vertHitDistance = (foundVertWallHit)
//         ? distanceBetweenPoints(player->x, player->y, vertWallHitX, vertWallHitY)
//         : INFINITY;

//     ray->wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
//     ray->wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
//     ray->distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
//     ray->wasHitVertical = (vertHitDistance < horzHitDistance);
// }

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 64
#define NBR_RAYS 100
#define FOV_ANGLE (60 * (M_PI / 180)) // 60 degrees field of view
#define M_PI 3.14159265358979323846

typedef struct s_player {
    int x;
    int y;
    double rotationAngle;
    int radius;
} t_player;

typedef struct s_map {
    int width;
    int height;
    int *grid;
} t_map;

typedef struct s_data {
    t_player *player;
    t_map *map;
} t_data;

// Function prototypes
double ft_normalizeangle(double rayangle);
int is_facingray_up_down(float rayangle);
int is_facingray_left_right(float rayangle);
int ft_check_wall(t_data *data, int x, int y);
void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);
void draw_view_rays(t_data *data, float rayangle, double distance, int color);
void ft_cast_all_rays(t_data *data, int color);
double ft_intersection_rays_y(t_data *data, float rayangle);

// Function implementations

double ft_normalizeangle(double rayangle)
{
    rayangle = fmod(rayangle, 2.0 * M_PI);
    if (rayangle < 0)
        rayangle += 2.0 * M_PI;
    return rayangle;
}

int is_facingray_up_down(float rayangle)
{
    return (rayangle > 0 && rayangle < M_PI) ? 1 : 0; // 1 for up, 0 for down
}

int is_facingray_left_right(float rayangle)
{
    return (rayangle < M_PI / 2 || rayangle > (3 * M_PI) / 2) ? 1 : 0; // 1 for right, 0 for left
}

int ft_check_wall(t_data *data, int x, int y)
{
    int mapGridIndexX = x / TILE_SIZE;
    int mapGridIndexY = y / TILE_SIZE;

    if (mapGridIndexX < 0 || mapGridIndexX >= data->map->width || mapGridIndexY < 0 || mapGridIndexY >= data->map->height)
        return 0; // Out of bounds

    return data->map->grid[mapGridIndexY * data->map->width + mapGridIndexX] == 1;
}

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    // Implement line drawing function here
    // This is a placeholder for the actual drawing logic
    printf("Drawing line from (%d, %d) to (%d, %d) with color %d\n", x0, y0, x1, y1, color);
}

void draw_view_rays(t_data *data, float rayangle, double distance, int color)
{
    int centerX = data->player->x - 4 + data->player->radius / 2; 
    int centerY = data->player->y - 4 + data->player->radius / 2;
    int x1 = centerX + cos(rayangle) * distance;
    int y1 = centerY + sin(rayangle) * distance;
    draw_line(data, centerX, centerY, x1, y1, color);
}

void ft_cast_all_rays(t_data *data, int color)
{
    int i;
    double dist;
    double rayangle = data->player->rotationAngle - (FOV_ANGLE / 2);
    
    for (i = 0; i < NBR_RAYS; i++)
    {
        rayangle = ft_normalizeangle(rayangle);
        dist = ft_intersection_rays_y(data, rayangle);
        draw_view_rays(data, rayangle, dist, color);
        rayangle += FOV_ANGLE / NBR_RAYS;
    }
}

double ft_rays_horizontal(t_data *data, float rayangle)
{
    long dlta_x;
    long dlta_y;
    long distance;
    int x_post_intercept;
    int y_post_intercept;

    dlta_y = TILE_SIZE;
    dlta_x = dlta_y / tan(rayangle);
    y_post_intercept = round(data->player->y / TILE_SIZE) * TILE_SIZE;
    // if (is_facingray_up_down(rayangle) == 0)
    //     y_post_intercept += TILE_SIZE;
    x_post_intercept = data->player->x + (data->player->y-y_post_intercept ) / tan(rayangle);

    // if (is_facingray_up_down(rayangle) == 1)
    //     dlta_y *= -1;
    // if (is_facingray_left_right(rayangle) == 0 && dlta_x > 0)
    //     dlta_x *= -1;
    // if (is_facingray_left_right(rayangle) == 1 && dlta_x < 0)
    //     dlta_x *= -1;

    distance = sqrt(pow((y_post_intercept - data->player->y), 2) + pow((x_post_intercept - data->player->x), 2));

    int x = x_post_intercept;
    int y = y_post_intercept;
    while (x >= 0 && x <= data->map->width * TILE_SIZE && y >= 0 && y <= data->map->height * TILE_SIZE)
    {
        if (ft_check_wall(data, x - 1, y - 1) == 1)
        {
            printf("ggg\n");
            distance += sqrt(pow((y - data->player->y), 2) + pow((x - data->player->x), 2));
            return distance;
        }
        x += dlta_x;
        y += dlta_y;
    }
    return 10.0;
}

int main()
{
    // Setup the map
    int mapGrid[] = {
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 0, 1, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
    };
    t_map map = {5, 5, mapGrid};

    // Setup the player
    t_player player = {128, 128, 0, 8};

    // Setup the data
    t_data data = {&player, &map};

    // Cast all rays
    ft_cast_all_rays(&data, 0xFFFFFF);

    return 0;
}
