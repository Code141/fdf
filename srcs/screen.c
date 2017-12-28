# include "mlx.h"
# include "screen.h"
# include "ctx.h"

t_screen	*new_screen(void *mlx, int width, int height)	
{
	t_screen *screen;

	screen = (t_screen*)malloc(sizeof(t_screen));
	screen->width = width;
	screen->height = height;
	screen->ar = width / height;
	screen->win = mlx_new_window(mlx, width, height, "FdF");
	return (screen);
}


t_img	*new_canevas(void *mlx, int width, int height)
{
	t_img	*canevas;
	int		bpp;
	int		size_line;
	int		endian;

	canevas = (t_img*)malloc(sizeof(t_img));
	canevas->width = width;
	canevas->height = height;
	size_line = width;
	canevas->id = mlx_new_image(mlx, canevas->width, canevas->height);
	canevas->data = mlx_get_data_addr(canevas->id, &bpp, &size_line, &endian);
	return (canevas);
}
