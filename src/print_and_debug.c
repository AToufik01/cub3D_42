#include "../include/cub3d.h"



void     printf_para(t_data *data)
{
    // printf("player->x %f\n",data->player->x);
    // printf("player->y %f\n",data->player->y);
    // printf("turnDirection %d\n",data->player->turnDirection);
    // printf("walkDirection %d\n",data->player->walkDirection);
    // printf("radius%f\n",data->player->radius);
    printf("rotationAngle %f\n",data->player->rotationAngle);
    printf("rotationSpeed %f\n",data->player->rotationSpeed);
    // printf("wid %d\n",data->map->width);
    // printf("hei %d\n",data->map->height);

    // for (int i = 0; i < data->map->height; i++)
    //     printf("%s\n", data->map->arr_map[i]);

}
void add_1px(t_data *data)
{
    int i;
    int j;
    i = 0;
    while(i<data->map->height)
    {
        j = 0;
        while(j<data->map->width)
        {
            if (data->map->arr_map[i][j]=='1' && data->map->arr_map[i][j+1]=='0')
            {
                mlx_put_pixel(data->map->img_map,j * TILE_SIZE,i * TILE_SIZE,0xFF0000FF);
                mlx_put_pixel(data->map->img_map,j * TILE_SIZE+1,i * TILE_SIZE+1,0xFF0000FF);
            }
            j++;
        }
        i++;
    }
}