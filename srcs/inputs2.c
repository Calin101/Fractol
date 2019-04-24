/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inputs2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 04:45:37 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:08 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_left_right(t_fractol *fractol, int keycode)
{
	if (keycode == 123)
	{
		fractol->x1 += 0.05;
		fractol->x2 += 0.05;
	}
	else
	{
		fractol->x1 -= 0.05;
		fractol->x2 -= 0.05;
	}
}

void	change_color(t_fractol *fractol, int keycode)
{
	if (keycode == 18)
		fractol->color = (t_color){.color = 0x180588, .color2 = 0xBBEB55};
	else if (keycode == 19)
		fractol->color = (t_color){.color = 0x447BA5, .color2 = 0xBCF229};
	else if (keycode == 20)
		fractol->color = (t_color){.color = 0x12C6CF, .color2 = 0x0B4CA9};
	else if (keycode == 21)
		fractol->color = (t_color){.color = 0x000000, .color2 = 0xF50A87};
}

void	move_up_down(t_fractol *fractol, int keycode)
{
	if (keycode == 126)
	{
		fractol->y1 += 0.05;
		fractol->y2 += 0.05;
	}
	else
	{
		fractol->y1 -= 0.05;
		fractol->y2 -= 0.05;
	}
}

void	change_iter(t_fractol *fractol, int keycode)
{
	if (keycode == 69)
		fractol->max_iter += 5;
	else
		fractol->max_iter -= 5;
}

int		mouse_move(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->var_pause == 1)
		fractol->julia = (t_complex){.r = x * fractol->step_x + fractol->x1,
		.i = y * fractol->step_y + fractol->y1};
	choice_algo(fractol);
	return (0);
}
