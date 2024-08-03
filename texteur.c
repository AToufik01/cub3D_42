#include "include/cub3d.h"

mlx_texture_t *texture;

int main(void)
{
    mlx_t *mlx = mlx_init(100,100,"texteur",1);


    // Load the PNG texture
    texture = mlx_load_png("./Tileable1e.png");
    if (!texture)
    {
        fprintf(stderr, "Failed to load texture\n");
        return 1;
    }
    printf("%hhu\n",texture->pixels[0]);

    
    // Create an image from the texture
    mlx_image_t *img = mlx_texture_to_image(mlx, texture);
    if (!img)
    {
        fprintf(stderr, "Failed to create image from texture\n");
        return 1;
    }

    // Put the image to the window
   mlx_image_to_window(mlx,img,0,0);

    // Run the MLX loop
    mlx_loop(mlx);

    // Free the texture (and other resources if needed)
    mlx_delete_texture(texture);

    return 0;
}
