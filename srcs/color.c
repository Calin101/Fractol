/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 05:50:23 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:09 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		getlight(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		get_color(int i, t_fractol *fractol, t_color color)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	percent = ((double)i) / (double)fractol->max_iter;
	red = getlight((color.color >> 16) & 0xff, (color.color2 >> 16) & 0xff,
	percent);
	green = getlight((color.color >> 8) & 0xff, (color.color2 >> 8) & 0xff,
	percent);
	blue = getlight(color.color & 0xff, color.color2 & 0xff, percent);
	return ((red << 16) | (green << 8) | blue);
}
