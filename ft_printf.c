/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:36:38 by dbank             #+#    #+#             */
/*   Updated: 2024/11/28 01:02:10 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_finder(va_list *input, size_t *i, const char *s)
{
	char	c;

	if (s[*i] != '%')
		return (write(1, &s[*i], 1));
	(*i)++;
	if (s[*i] == 'c')
	{
		c = va_arg(*input, int);
		return (write(1, &c, 1));
	}
	else if (s[*i] == '%')
		return (write(1, "%", 1));
	else if (s[*i] == 's')
		return (putstr_printf(va_arg(*input, char *)));
	else if (s[*i] == 'u')
		return (put_unsignednbr_printf(va_arg(*input, unsigned int)));
	else if (s[*i] == 'd' || s[*i] == 'i')
		return (putnbr_printf(va_arg(*input, int)));
	else if (s[*i] == 'x' || s[*i] == 'X')
		return (puthex(va_arg(*input, unsigned int), s[*i]));
	else if (s[*i] == 'p')
		return (putaddr(va_arg(*input, void *)));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	input;
	size_t	i;
	int		totalwritten;
	int		written;

	if (s == NULL)
		return (-1);
	if (ft_strchr(s, '%') == NULL)
		return (write(1, (char *)s, ft_strlen(s)));
	i = 0;
	totalwritten = 0;
	va_start(input, s);
	while (s[i] != '\0')
	{
		written = convert_finder(&input, &i, s);
		if (written == -1)
		{
			va_end(input);
			return (-1);
		}
		totalwritten += written;
		i++;
	}
	va_end(input);
	return (totalwritten);
}
