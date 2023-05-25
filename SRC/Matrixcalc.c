/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrixcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:55 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:45 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//-M_PI 'cause tthe image is fliped around z
t_point	rotation_x(t_point point, t_data d)
{
	t_point	rotated;
	t_point	angle;

	angle.x = ((d.a.x * -M_PI) / 180);
	rotated.x = point.x;
	rotated.y = point.y * cos(angle.x) - point.z * sin(angle.x);
	rotated.z = point.y * sin(angle.x) + point.z * cos(angle.x);
	return (rotated);
}

//-M_PI 'cause tthe image is fliped around z
t_point	rotation_y(t_point point, t_data d)
{
	t_point	rotated;
	t_point	angle;

	angle.y = ((d.a.y * -M_PI) / 180);
	rotated.x = point.x * cos(angle.y) + point.z * sin(angle.y);
	rotated.y = point.y;
	rotated.z = -point.x * sin(angle.y) + point.z * cos(angle.y);
	return (rotated);
}

//+180 do mirror the image
t_point	rotation_z(t_point point, t_data d)
{
	t_point	rotated;
	t_point	angle;

	angle.z = (((d.a.z + 180) * M_PI) / 180);
	rotated.x = point.x * cos(angle.z) - point.y * sin(angle.z);
	rotated.y = point.x * sin(angle.z) + point.y * cos(angle.z);
	rotated.z = point.z;
	return (rotated);
}

t_point	rotation(t_point point, t_data d)
{
	point = rotation_x(point, d);
	point = rotation_y(point, d);
	point = rotation_z(point, d);
	return (point);
}

t_point	raycast(t_point point, t_data d)
{
	t_point	castedpoint;

	point.z *= d.h;
	point = rotation(point, d);
	castedpoint.x = ((point.z + d.o.z + d.f) / d.f) * point.x;
	castedpoint.y = ((point.z + d.o.z + d.f) / d.f) * point.y;
	castedpoint.z = point.z;
	return (castedpoint);
}
