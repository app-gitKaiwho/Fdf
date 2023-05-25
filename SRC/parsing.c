/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:47:51 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:42:46 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_list	line_to_list(t_list li, char *str)
{
	char	**split;
	int		i;

	i = 0;
	if (str)
	{
		split = ft_split(str, ' ');
		free(str);
		while (split[i])
		{
			li = push_front(li, 0, split[i]);
			i++;
		}
		free(split);
	}
	return (li);
}

int	*tab_to_int_array(t_list li)
{
	int		*output;
	int		i;
	t_list	tmp;

	tmp = li;
	i = 0;
	output = malloc(sizeof(int) * (li->pos + 1));
	if (!output)
		error_handler("malloc error", 1);
	while (tmp)
	{
		output[i] = ft_atoi(tmp->mot);
		free(tmp->mot);
		tmp = tmp->last;
		i++;
	}
	li = freelist(li, 0);
	return (output);
}

int	*line_treatmentplant(t_data *d, char *a)
{
	int		fd;
	char	*join;
	t_list	li;

	li = NULL;
	join = ft_strjoin("./test_maps/", a);
	fd = open(join, O_RDONLY);
	if (fd < 0 || ft_strncmp(&join[ft_strlen(join) - 4], ".fdf", 4))
		error_handler("file not found", 1);
	if (join)
		free(join);
	while (1)
	{
		join = get_next_line(fd);
		if (!join)
			break ;
		li = line_to_list(li, join);
		d->m.j++;
	}
	d->m.i = (li->pos + 1) / d->m.j;
	close(fd);
	if (join)
		free(join);
	return (tab_to_int_array(li));
}

void	centermap(t_data *d)
{
	t_point		delt;
	t_iterator	it;

	it = (t_iterator){0, 0, 0};
	delt = (t_point){d->m.points[d->m.j - 1][d->m.i - 1].x
		/ 2, d->m.points[d->m.j - 1][d->m.i - 1].y / 2, 0};
	while (it.j < d->m.j)
	{
		it.i = 0;
		while (it.i < d->m.i)
		{
			d->m.points[it.j][it.i].x -= delt.x;
			d->m.points[it.j][it.i].y -= delt.y;
			it.i++;
		}
		it.j++;
	}
}

void	getmap(t_data *d, char *a)
{
	int			*rawdata;
	t_iterator	it;

	it = (t_iterator){0, 0, 0};
	rawdata = line_treatmentplant(d, a);
	d->m.points = malloc(sizeof(t_point) * (d->m.j) + 1);
	while (it.j < d->m.j)
	{
		d->m.points[it.j] = malloc(sizeof(t_point) * (d->m.i) + 1);
		if (!d->m.points[it.j])
			error_handler("malloc error", 1);
		it.j++;
	}
	it = (t_iterator){-1, -1, 0};
	while (++it.j < d->m.j)
	{
		it.i = -1;
		while (++it.i < d->m.i)
			d->m.points[it.j][it.i] = (t_point){it.i, it.j,
				rawdata[it.i + it.j * d->m.i]};
	}
	free(rawdata);
	resize(d);
	centermap(d);
}
