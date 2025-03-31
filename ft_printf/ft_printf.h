/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:09:02 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/31 19:48:23 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_c(va_list args);
int		print_s(va_list args);
int		print_p(va_list args);
int		print_d(va_list args);
int		print_i(va_list args);
int		print_u(va_list args);
int		print_small_x(va_list args);
int		print_large_x(va_list args);
int		print_percent(void);
int		print_hex_ptr(unsigned long num);
char	*ft_utoa(unsigned int n);
int		print_hex(unsigned long num, int is_upper);

#endif