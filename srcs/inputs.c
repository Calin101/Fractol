/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inputs.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 17:35:51 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:36 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom(t_fractol *fractol, int x, int y, int button)
{
	double dx;
	double dy;

	dx = fractol->x2 - fractol->x1;
	dy = fractol->y2 - fractol->y1;
	fractol->zoom_x = ((double)x / WIN_SIZE_X * dx) - dx / 2 + fractol->zoom_x;
	fractol->zoom_y = ((double)y / WIN_SIZE_Y * dy) - dy / 2 + fractol->zoom_y;
	if (x >= 0 && x <= WIN_SIZE_X)
	{
		if (button == 5)
		{
			fractol->x2 = fractol->zoom_x + (dx / 1.3) / 2;
			fractol->x1 = fractol->zoom_x - (dx / 1.3) / 2;
			fractol->y1 = fractol->zoom_y - (dy / 1.3) / 2;
			fractol->y2 = fractol->zoom_y + (dy / 1.3) / 2;
		}
		else
		{
			fractol->x2 = fractol->zoom_x + (dx * 1.3) / 2;
			fractol->x1 = fractol->zoom_x - (dx * 1.3) / 2;
			fractol->y1 = fractol->zoom_y - (dy * 1.3) / 2;
			fractol->y2 = fractol->zoom_y + (dy * 1.3) / 2;
		}
	}
}

void		add_triangle(t_fractol *fractol, int keycode)
{
	if (keycode == 43 && fractol->index_max > 0)
		fractol->index_max -= 1;
	if (keycode == 47 && fractol->index_max < 10)
		fractol->index_max += 1;
}

void		change_fractal(t_fractol *fractol, int keycode)
{
	if (keycode == 83)
		fractol->fractal_choice = 1;
	else if (keycode == 84)
		fractol->fractal_choice = 2;
	else if (keycode == 85)
		fractol->fractal_choice = 3;
	else if (keycode == 86)
		fractol->fractal_choice = 4;
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	if (button == 4 || button == 5)
		zoom(fractol, x, y, button);
	choice_algo(fractol);
	return (0);
}

int			keypress(int keycode, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21)
		change_color(fractol, keycode);
	if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86)
		change_fractal(fractol, keycode);
	if (keycode == 69 || keycode == 78)
		change_iter(fractol, keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->image.img_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		exit(0);
	}
	if (keycode == 43 || keycode == 47)
		add_triangle(fractol, keycode);
	if (keycode == 49)
		fractol->var_pause = (fractol->var_pause == 0) ? 1 : 0;
	if (keycode == 126 || keycode == 125)
		move_up_down(fractol, keycode);
	if (keycode == 123 || keycode == 124)
		move_left_right(fractol, keycode);
	choice_algo(fractol);
	return (0);
}
