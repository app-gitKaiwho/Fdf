/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:46:55 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:55 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	is_num;

	is_num = 1;
	if (!(c >= '0' && c <= '9'))
	{
		is_num = 0;
	}
	return (is_num);
}
