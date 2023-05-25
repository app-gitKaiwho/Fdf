/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:04 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct img
{
	void	*img;
	char	*data;
	int		bpp;
	int		line_size;
	int		endian;
}t_img;

typedef struct window
{
	void	*win;
	void	*mlx;
	int		l;
	int		h;
}t_window;

typedef struct point
{
	double	x;
	double	y;
	double	z;
}t_point;

typedef struct map
{
	t_point	**points;
	int		j;
	int		i;
}t_map;

typedef struct rgb
{
	int	red;
	int	green;
	int	blue;
}t_RGB;

//a début, z fin
typedef struct line
{
	t_point	a;
	t_point	z;
}t_line;

typedef struct button
{
	t_point	x;
	t_point	y;
	char	*text;
	int		val;
}t_button;

typedef struct data
{
	t_img		i;
	t_window	s;
	t_RGB		c;
	t_map		m;
	t_point		a;
	t_point		o;
	int			f;
	float		h;
	float		g_size;
	t_button	bp1;
}t_data;

typedef struct iterator
{
	int	j;
	int	i;
	int	k;
}t_iterator;

#endif /*!KEYCODE_H */