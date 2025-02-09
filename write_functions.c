/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:02:55 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 13:56:06 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_printf(char *s)
{
	size_t	i;

	if (s == NULL)
		return (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		return (write(1, s, i));
	}
}

int	putnbr_printf(intmax_t n)
{
	int			i;
	int			putnbrreturn;
	char		c;

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		i = 1;
	}
	else
		i = 0;
	if (n >= 10)
	{
		putnbrreturn = putnbr_printf(n / 10);
		if (putnbrreturn == -1)
			return (-1);
		else
			i += putnbrreturn;
	}
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (i + 1);
}

int	put_unsignednbr_printf(uintmax_t n)
{
	int		i;
	char	c;

	if (n >= 10)
	{
		i = put_unsignednbr_printf(n / 10);
		if (i == -1)
			return (-1);
	}
	else
		i = 0;
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (i + 1);
}

int	puthex(uintptr_t n, char x)
{
	int		i;
	char	*hexset;

	if (x == 'x')
		hexset = "0123456789abcdef";
	else if (x == 'X')
		hexset = "0123456789ABCDEF";
	if (n >= 16)
	{
		i = puthex (n / 16, x);
		if (i == -1)
			return (-1);
	}
	else
		i = 0;
	if (write(1, &hexset[n % 16], 1) == -1)
		return (-1);
	return (i + 1);
}

int	putaddr(void *addr)
{
	int	puthexreturn;

	if (addr == NULL)
		return (write(1, "(nil)", 5));
	if ((write(1, "0x", 2)) == -1)
		return (-1);
	puthexreturn = puthex((uintptr_t)addr, 'x');
	if (puthexreturn == -1)
		return (-1);
	else
		return (2 + puthexreturn);
}
