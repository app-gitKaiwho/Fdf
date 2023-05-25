/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:00:17 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:46 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	setup_img(t_data *d)
{
	if (d->i.img)
	{
		draw_grid(*d);
		mlx_put_image_to_window(d->s.mlx, d->s.win, d->i.img, 0, 0);
		mlx_destroy_image(d->s.mlx, d->i.img);
		d->i.img = mlx_new_image(d->s.mlx, d->s.l, d->s.h);
		d->i.data = mlx_get_data_addr(d->i.img, &d->i.bpp,
				&d->i.line_size, &d->i.endian);
	}
}

void	put_pixel(t_point p, t_data d)
{
	t_RGB	color;

	color.red = p.z * 3;
	if (color.red > 255)
		color.red = 255;
	if (color.red < 0)
		color.red = 0;
	p = raycast(p, d);
	p = (t_point){p.x + d.o.x + d.s.l / 2, p.y + d.o.y + d.s.h / 2, p.z};
	if (p.y > 0 && p.x > 0 && p.y < d.s.h && p.x < d.s.l)
	{
		d.i.data[(int)p.y * d.i.line_size + (int)p.x * d.i.bpp / 8]
			= d.c.blue - color.red;
		d.i.data[(int)p.y * d.i.line_size + (int)p.x * d.i.bpp / 8 + 1]
			= d.c.green - color.red;
		d.i.data[(int)p.y * d.i.line_size + (int)p.x * d.i.bpp / 8 + 2]
			= color.red;
	}
}

void	put_line(t_line l, t_data dt)
{
	t_point	inc;
	int		red;

	red = 1 + (fabs(dt.o.z * 0.05) + fabs(dt.h * 2));
	inc = (t_point){(l.z.x - l.a.x) / (dt.g_size * red), (l.z.y - l.a.y)
		/ (dt.g_size * red), (l.z.z - l.a.z) / (dt.g_size * red)};
	while (fabs(l.a.x - l.z.x) >= 1 || fabs(l.a.y - l.z.y) >= 1
		|| fabs(l.a.z - l.z.z) >= 1)
	{
		put_pixel(l.a, dt);
		l.a = (t_point){l.a.x + inc.x, l.a.y + inc.y, l.a.z + inc.z};
	}
}
