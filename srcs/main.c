/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 15:03:54 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 14:09:08 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_thread(t_fractol *fractol)
{
	int i;

	i = 0;
	while (i < NB_THREAD)
	{
		fractol->thread_tab[i].i_min = i * WIN_SIZE_Y / NB_THREAD;
		fractol->thread_tab[i].i_max = (i + 1) * WIN_SIZE_Y / NB_THREAD;
		fractol->thread_tab[i].fractol = fractol;
		pthread_create(&fractol->thread_tab[i].thread, NULL,
		fractol->fractal_choice == 4 ? &julia_algo : &mandelship_algo,
		&fractol->thread_tab[i]);
		i++;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_join(fractol->thread_tab[i].thread, NULL);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 2 || (ft_atoi(argv[1]) != 1 && ft_atoi(argv[1]) != 2 &&
	ft_atoi(argv[1]) != 3 && ft_atoi(argv[1]) != 4))
		return (write(1, "usage: Fractol need one argument[1, 2, 3, 4]\n", 46));
	fractol = init_struct();
	init_image(&fractol);
	choice_fractal(&fractol, argv);
	choice_algo(&fractol);
	mlx_hook(fractol.win_ptr, 6, 0, mouse_move, &fractol);
	mlx_hook(fractol.win_ptr, 2, 0, keypress, &fractol);
	mlx_mouse_hook(fractol.win_ptr, mouse_press, &fractol);
	mlx_loop(fractol.mlx_ptr);
	return (0);
}
