/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 16:24:28 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:08 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	choice_fractal(t_fractol *fractol, char **argv)
{
	if (ft_atoi(argv[1]) == 1)
	{
		fractol->color = (t_color){.color = 0x180588, .color2 = 0xBBEB55};
		fractol->fractal_choice = 1;
	}
	else if (ft_atoi(argv[1]) == 2)
	{
		fractol->color = (t_color){.color = 0x180588, .color2 = 0xBBEB55};
		fractol->fractal_choice = 2;
	}
	else if (ft_atoi(argv[1]) == 3)
	{
		fractol->color = (t_color){.color = 0x447BA5, .color2 = 0xBCF229};
		fractol->fractal_choice = 3;
	}
	else if (ft_atoi(argv[1]) == 4)
	{
		fractol->color = (t_color){.color = 0x12C6CF, .color2 = 0x0B4CA9};
		fractol->fractal_choice = 4;
	}
}

void	*choice_algo(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	mlx_destroy_image(fractol->mlx_ptr, fractol->image.img_ptr);
	init_image(fractol);
	fractol->step_x = (fractol->x2 - fractol->x1) / WIN_SIZE_X;
	fractol->step_y = (fractol->y2 - fractol->y1) / WIN_SIZE_Y;
	if (fractol->fractal_choice == 1)
	{
		init_triangle(fractol);
		tri_fractol(fractol, fractol->triangle, 0);
	}
	else
		create_thread(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
	fractol->image.img_ptr, 0, 0);
	return (0);
}
