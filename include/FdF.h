/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:02 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SCREEN_LENGTH 2000
# define SCREEN_HEIGHT 1300
# define SIZE 100

# include "mlx.h"
# include "Keycode.h"
# include "stdlib.h"
# include "unistd.h"
# include "math.h"
# include "ft_libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "Struct.h"

void	error_handler(char *str, int e);

//hook

int		exit_hook(void);
int		exit_keyhook(int keycode);
int		keyhook(int keycode, void *param);
int		mouse_hook(int keycode, int x, int y, void *param);

//visu

void	put_grid(t_data d);
void	draw_grid(t_data d);
void	setup_img(t_data *d);
void	put_line(t_line l, t_data dt);
void	put_pixel(t_point p, t_data d);

//parsing

void	getmap(t_data *data, char *a);
void	resize(t_data *d);

//Vector

t_point	raycast(t_point point, t_data d);

//Button

void	draw_rectangle(t_data d);
int		mouse_motion_handler(int button, int x, int y, t_data *d);
#endif /*!FDF_H */