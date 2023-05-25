/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:50:16 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:44 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_grid(t_data d)
{
	t_line		*l;
	t_iterator	a;

	l = malloc(sizeof(t_line) * (d.m.i * d.m.j * 2 - d.m.i - d.m.j));
	if (!l)
		error_handler("malloc value is NULL", 1);
	a = (t_iterator){-1, -1, 0};
	while (++a.j < d.m.j)
	{
		while (++a.i < d.m.i)
		{
			if (a.i < d.m.i - 1)
				l[a.k++] = (t_line){d.m.points[a.j][a.i],
					d.m.points[a.j][a.i + 1]};
			if (a.j < d.m.j - 1)
				l[a.k++] = (t_line){d.m.points[a.j][a.i],
					d.m.points[a.j + 1][a.i]};
		}
		a.i = -1;
	}
	while (++a.i < a.k)
		put_line(l[a.i], d);
	free(l);
}

void	error_handler(char *txt, int code)
{
	ft_printf("%s\n", txt);
	exit(code);
}

int	loopydyloop(void *param)
{
	struct data	*d;

	d = (t_data *)param;
	setup_img(d);
	return (0);
}

void	ini_data(t_data *d)
{
	d->s = (t_window){.l = SCREEN_LENGTH,
		.h = SCREEN_HEIGHT, .mlx = mlx_init()};
	if (!d->s.mlx)
		error_handler("window could not be initialized !", 2);
	d->s.win = mlx_new_window(d->s.mlx, d->s.l, d->s.h, "Fdf");
	d->i.img = mlx_new_image(d->s.mlx, d->s.l, d->s.h);
	d->i.data = mlx_get_data_addr(d->i.img, &d->i.bpp,
			&d->i.line_size, &d->i.endian);
	d->m = (t_map){.j = 0, .i = 0};
	d->c = (t_RGB){255, 255, 255};
	d->a = (t_point){45.0, 30.0, -20.0};
	d->o = (t_point){0.0, 0.0, 100.0};
	d->h = 1;
	d->f = 10000;
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
		error_handler("invalid arg. number", 1);
	ini_data(&d);
	getmap(&d, av[1]);
	mlx_hook(d.s.win, CLOSE_WINDOW_KEY, 0, &exit_hook, NULL);
	mlx_key_hook(d.s.win, &keyhook, &d);
	mlx_hook(d.s.win, 4, 0x4, &mouse_motion_handler, &d);
	mlx_hook(d.s.win, 4, 0, &mouse_hook, &d);
	mlx_loop_hook(d.s.mlx, loopydyloop, &d);
	mlx_loop(d.s.mlx);
	free(d.s.mlx);
}
