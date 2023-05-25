/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:52:19 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:19 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include   <stdarg.h>

int	printc(char c);
int	printnbr(int nbr);
int	printptr(void *ptr);
int	printstr(char *str);
int	printfx(unsigned long nbr, char mode);
int	printunbr(unsigned int n);
int	ft_printf(const char *str, ...);

#endif /* !FT_PRINTF_H */