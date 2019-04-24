/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:34:33 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 15:19:47 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# define WIN_SIZE_X 1200
# define WIN_SIZE_Y 1200
# define NB_THREAD	8

typedef struct			s_index
{
	int					i;
	int					j;
}						t_index;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_dot
{
	double				x;
	double				y;
}						t_dot;

typedef	struct			s_triangle
{
	t_dot				dot1;
	t_dot				dot2;
	t_dot				dot3;
}						t_triangle;

typedef struct			s_color
{
	int					color;
	int					color2;
}						t_color;

typedef struct			s_image
{
	void				*img_ptr;
	int					*img_int;
	int					bpp;
	int					size_line;
	int					endian;
}						t_image;

typedef	struct			s_thread
{
	pthread_t			thread;
	int					i_min;
	int					i_max;
	struct s_fractol	*fractol;
}						t_thread;

typedef struct			s_fractol
{
	int					fractal_choice;
	void				*win_ptr;
	void				*mlx_ptr;
	int					max_iter;
	t_image				image;
	t_triangle			triangle;
	t_complex			origin;
	t_complex			julia;
	t_color				color;
	t_thread			thread_tab[NB_THREAD];
	double				step_x;
	double				step_y;
	double				zoom_x;
	double				zoom_y;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	int					born;
	int					index;
	int					var_pause;
	int					index_max;
	int					thread_index;
}						t_fractol;

t_fractol				init_struct(void);
t_index					new_index(int i, int j);
t_complex				new_complex(int r, int i);
void					*julia_algo(void *thread);
void					*choice_algo(void *fractol);
void					*mandelship_algo(void *thread);
void					init_image(t_fractol *fractol);
void					init_triangle(t_fractol *fractol);
void					create_thread(t_fractol *fractol);
void					change_iter(t_fractol *fractol, int keycode);
void					change_color(t_fractol *fractol, int keycode);
void					move_up_down(t_fractol *fractol, int keycode);
void					choice_fractal(t_fractol *fractol, char **argv);
void					move_left_right(t_fractol *fractol, int keycode);
void					tri_fractol(t_fractol *fractol, t_triangle triangle,
						int index);
int						keypress(int keycode, void *param);
int						mouse_move(int x, int y, void *param);
int						mouse_press(int button, int x, int y, void *param);
int						get_color(int i, t_fractol *fractol, t_color color);

#endif
