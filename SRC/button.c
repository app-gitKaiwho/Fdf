/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:55 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:42 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//should be in parsing but too much function
void	resize(t_data *d)
{
	t_iterator	it;

	it = (t_iterator){0, 0, 0};
	if (d->s.l / d->m.i < d->s.h / d->m.j)
		d->g_size = (d->s.l / (d->m.i + 2));
	else
		d->g_size = (d->s.h / (d->m.j + 2));
	while (it.j < d->m.j)
	{
		it.i = 0;
		while (it.i < d->m.i)
		{
			d->m.points[it.j][it.i].x *= d->g_size * 0.9;
			d->m.points[it.j][it.i].y *= d->g_size * 0.9;
			d->m.points[it.j][it.i].z *= (d->g_size / 5);
			it.i++;
		}
	it.j++;
	}
}

//button are not used
void	non_raycast_put_pixel(t_point p, t_data d, t_RGB c)
{
	if (p.y > 0 && p.x > 0 && p.y < d.s.h && p.x < d.s.l)
	{
		d.i.data[(int)p.y * d.i.line_size + (int)p.x * d.i.bpp / 8] = c.blue;
		d.i.data[(int)p.y * d.i.line_size
			+ (int)p.x * d.i.bpp / 8 + 1] = c.green;
		d.i.data[(int)p.y * d.i.line_size + (int)p.x * d.i.bpp / 8 + 2] = c.red;
	}
}

int	mouse_motion_handler(int button, int x, int y, t_data *d)
{
	if (y >= d->bp1.y.x && y <= d->bp1.y.y && x >= d->bp1.x.x
		&& x <= d->bp1.x.y && button)
		d->bp1.val ^= 1;
	return (0);
}

void	draw_rectangle(t_data d)
{
	t_iterator	it;
	t_RGB		color;

	color = (t_RGB){0, 255, 255};
	if (d.bp1.val)
		color = (t_RGB){255, 255, 255};
	it = (t_iterator){d.bp1.x.x, d.bp1.x.y, 0};
	while (it.j < d.bp1.y.y)
	{
		it.i = d.bp1.x.x;
		while (it.i < d.bp1.x.y)
		{
			non_raycast_put_pixel((t_point){it.i, it.j, 0}, d, color);
			it.i++;
		}
		it.j++;
	}
	mlx_string_put (d.s.mlx, d.s.win, 50, 50, 0xFFFFFF, d.bp1.text);
}
