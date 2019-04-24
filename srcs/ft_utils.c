/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:43:59 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:09 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_index		new_index(int i, int j)
{
	t_index	index;

	index.i = i;
	index.j = j;
	return (index);
}

t_complex	new_complex(int r, int i)
{
	t_complex	c;

	c.r = r;
	c.i = i;
	return (c);
}

void		init_image(t_fractol *fractol)
{
	fractol->image.img_ptr = mlx_new_image(fractol->mlx_ptr,
	WIN_SIZE_X, WIN_SIZE_Y);
	fractol->image.img_int = (int *)mlx_get_data_addr(fractol->image.img_ptr,
	&fractol->image.bpp, &fractol->image.size_line, &fractol->image.endian);
}

void		init_triangle(t_fractol *fractol)
{
	fractol->triangle = (t_triangle){.dot1 = (t_dot){.x = WIN_SIZE_X / 2,
									.y = 0},
						.dot2 = (t_dot){.x = 0, .y = WIN_SIZE_Y - 1},
						.dot3 = (t_dot){.x = WIN_SIZE_X, .y = WIN_SIZE_Y - 1}};
}

t_fractol	init_struct(void)
{
	t_fractol	fractol;

	fractol.origin = (t_complex){.r = 0, .i = 0};
	fractol.var_pause = 0;
	fractol.x1 = -2.1;
	fractol.x2 = 0.6;
	fractol.y1 = -1.2;
	fractol.y2 = 1.2;
	fractol.step_x = (fractol.x2 - fractol.x1) / WIN_SIZE_X;
	fractol.step_y = (fractol.y2 - fractol.y1) / WIN_SIZE_Y;
	fractol.thread_index = 0;
	fractol.max_iter = 50;
	fractol.born = 4;
	fractol.index = 0;
	fractol.zoom_x = 0.0;
	fractol.zoom_y = 0.0;
	fractol.julia = (t_complex){.r = -0.8, .i = 0.156};
	fractol.index_max = 1;
	fractol.mlx_ptr = mlx_init();
	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr, WIN_SIZE_X,
	WIN_SIZE_Y, "Fractol");
	return (fractol);
}
