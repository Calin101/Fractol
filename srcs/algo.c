/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:38:45 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:10 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		algo(t_index index, t_fractol *fractol)
{
	int			i;
	double		tmp;
	t_complex	c;
	t_complex	z;

	i = 0;
	c = (t_complex){.r = index.j * fractol->step_x + fractol->x1,
	.i = index.i * fractol->step_y + fractol->y1};
	z = (t_complex){.r = 0, .i = 0};
	while (z.r * z.r + z.i * z.i < fractol->born &&
	i++ < fractol->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * (fractol->fractal_choice == 2 ? z.i * tmp : fabs(z.i * tmp))
		+ c.i;
	}
	return (i);
}

void	*mandelship_algo(void *t)
{
	t_index		index;
	t_fractol	*fractol;
	t_thread	*thread;
	int			i;

	thread = (t_thread *)t;
	fractol = thread->fractol;
	index = (t_index){.i = 0, .j = 0};
	while (index.i < WIN_SIZE_X)
	{
		index.j = thread->i_min;
		while (index.j < thread->i_max)
		{
			i = algo(index, fractol);
			fractol->image.img_int[index.i * WIN_SIZE_X + index.j] =
			get_color(i * 2, fractol, fractol->color);
			index.j++;
		}
		index.i++;
	}
	return (0);
}

int		algo2(t_index index, t_fractol *fractol)
{
	int			i;
	double		tmp;
	t_complex	c;
	t_complex	z;

	c = (t_complex){.r = fractol->julia.r, .i = fractol->julia.i};
	z = (t_complex){.r = index.j * fractol->step_x + fractol->x1,
	.i = index.i * fractol->step_y + fractol->y1};
	i = 0;
	while (z.r * z.r + z.i * z.i < fractol->born &&
	i++ < fractol->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
	}
	return (i);
}

void	*julia_algo(void *t)
{
	t_index		index;
	t_fractol	*fractol;
	t_thread	*thread;
	int			i;

	thread = (t_thread *)t;
	fractol = thread->fractol;
	index = (t_index){.i = 0, .j = 0};
	while (index.i < WIN_SIZE_X)
	{
		index.j = thread->i_min;
		while (index.j < thread->i_max)
		{
			i = algo2(index, fractol);
			fractol->image.img_int[index.i * WIN_SIZE_X + index.j] =
			get_color(i * 2, fractol, fractol->color);
			index.j++;
		}
		index.i++;
	}
	return (0);
}
