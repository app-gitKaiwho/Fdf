/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:51:27 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:27 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_printf.h"

int	printunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += printnbr(n / 10);
		i += printnbr(n % 10);
	}
	else
		i += printc(n + 48);
	return (i);
}
