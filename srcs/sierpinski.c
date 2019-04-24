/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sierpinski.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 05:53:04 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:05 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		redefine_step(t_dot *step)
{
	int		k;

	if (fabs(step->x) > fabs(step->y))
	{
		k = fabs(step->x);
		step->x = 1;
		step->y /= fabs(step->x);
	}
	else
	{
		k = fabs(step->y);
		step->x /= fabs(step->y);
		step->y = 1;
	}
	return (k);
}

void	draw_line(t_fractol *fractol, t_dot src, t_dot dest)
{
	t_dot		step;
	t_dot		pos;
	int			index;
	int			k;

	index = 0;
	step = (t_dot){.x = dest.x - src.x, .y = dest.y - src.y};
	k = redefine_step(&step);
	while (index < k)
	{
		pos = (t_dot){.x = src.x + index * step.x, .y = src.y + index * step.y};
		if ((pos.x > 0 && pos.x < WIN_SIZE_X) &&
		(pos.y > 0 && pos.y < WIN_SIZE_Y))
			fractol->image.img_int[(int)pos.y * WIN_SIZE_X + (int)pos.x] =
			0xff0000;
		index++;
	}
}

void	tri_fractol(t_fractol *fractol, t_triangle tri, int index)
{
	t_triangle	tri1;
	t_triangle	tri2;
	t_triangle	tri3;

	if (fractol->max_iter > 0 && index++ == fractol->index_max)
	{
		draw_line(fractol, tri.dot1, tri.dot2);
		draw_line(fractol, tri.dot1, tri.dot3);
		draw_line(fractol, tri.dot2, tri.dot3);
		return ;
	}
	tri1 = (t_triangle){.dot1 = tri.dot1,
						.dot2 = (t_dot){.x = ((tri.dot2.x - tri.dot1.x) / 2) +
				tri.dot1.x, .y = ((tri.dot2.y - tri.dot1.y) / 2) + tri.dot1.y},
						.dot3 = (t_dot){.x = ((tri.dot3.x - tri.dot1.x) / 2) +
				tri.dot1.x, .y = ((tri.dot3.y - tri.dot1.y) / 2) + tri.dot1.y}};
	tri2 = (t_triangle){.dot1 = tri1.dot2,
						.dot2 = tri.dot2,
						.dot3 = (t_dot){.x = ((tri.dot3.x - tri.dot2.x) / 2) +
				tri.dot2.x, .y = ((tri.dot3.y - tri.dot2.y) / 2) + tri.dot2.y}};
	tri3 = (t_triangle){.dot1 = tri1.dot3, .dot2 = tri2.dot3, .dot3 = tri.dot3};
	tri_fractol(fractol, tri1, index);
	tri_fractol(fractol, tri2, index);
	tri_fractol(fractol, tri3, index);
}
