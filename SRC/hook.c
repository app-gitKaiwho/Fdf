/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:46:36 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:44 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

void	keyhook2(int keycode, t_data *d)
{
	if (keycode == BARREL_ROLL_LEFT)
		d->a.z -= 5;
	if (keycode == BARREL_ROLL_RIGHT)
		d->a.z += 5;
	if (keycode == PLUS)
		d->o.z += 50;
	if (keycode == MINUS && d->o.z >= -d->f * 0.7)
		d->o.z -= 50;
	if (keycode == ISO_VIEW)
		d->a = (t_point){45.0, 30.0, -20.0};
	if (keycode == FRONT_VIEW)
		d->a = (t_point){0.0, 0.0, 0.0};
	if (keycode == UPPY_H && d->h < 5)
		d->h += 0.1;
	if (keycode == LOWER_H && d->h > -5)
		d->h -= 0.1;
	if (keycode == RESET)
	{
		d->a = (t_point){45.0, 30.0, -20.0};
		d->o = (t_point){0.0, 0.0, 100.0};
		d->h = 1;
	}
}

int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY)
		exit(EXIT_SUCCESS);
	if (keycode == ROT_UP)
		d->a.x += 5;
	if (keycode == ROT_DOWN)
		d->a.x -= 5;
	if (keycode == ROT_LEFT)
		d->a.y -= 5;
	if (keycode == ROT_RIGHT)
		d->a.y += 5;
	if (keycode == ARROW_UP)
		d->o.y -= 50;
	if (keycode == ARROW_DOWN)
		d->o.y += 50;
	if (keycode == ARROW_LEFT)
		d->o.x -= 50;
	if (keycode == ARROW_RIGHT)
		d->o.x += 50;
	keyhook2(keycode, d);
	return (0);
}

//mlx_pixel_put not used be stays to silence x and y
int	mouse_hook(int keycode, int x, int y, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	if (keycode == L_CLICK)
		mlx_pixel_put(d->s.mlx, d->s.win, x, y, 0x000000);
	if (keycode == SCROLL_UP)
		d->o.z += 200;
	if (keycode == SCROLL_DOWN && d->o.z >= -d->f * 0.7)
		d->o.z -= 200;
	return (0);
}
