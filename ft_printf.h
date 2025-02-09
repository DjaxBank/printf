/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:27 by dbank             #+#    #+#             */
/*   Updated: 2024/11/27 22:27:22 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		putnbr_printf(intmax_t nbr);
int		put_unsignednbr_printf(uintmax_t n);
int		putstr_printf(char *c);
int		putaddr(void *addr);
int		puthex(uintptr_t n, char x);

#endif
