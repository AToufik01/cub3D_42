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