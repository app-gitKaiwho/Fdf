/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:48:57 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:48:57 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	leni;
	size_t	lenj;	

	leni = ft_strlen(s1);
	lenj = ft_strlen(s2);
	res = (char *) malloc((leni + lenj + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, leni);
	ft_memcpy(res + leni, s2, lenj);
	res[leni + lenj] = '\0';
	return (res);
}
