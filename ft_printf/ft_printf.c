/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:00:48 by yookamot          #+#    #+#             */
/*   Updated: 2024/11/13 19:14:35 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *format, size_t i, va_list args)
{
	if (format[i] == 'c')
		return (print_c(args));
	else if (format[i] == 's')
		return (print_s(args));
	else if (format[i] == 'p')
		return (print_p(args));
	else if (format[i] == 'd')
		return (print_d(args));
	else if (format[i] == 'i')
		return (print_i(args));
	else if (format[i] == 'u')
		return (print_u(args));
	else if (format[i] == 'x')
		return (print_small_x(args));
	else if (format[i] == 'X')
		return (print_large_x(args));
	else if (format[i] == '%')
		return (print_percent());
	return (-1);
}

int	handle_format_char(const char *format, size_t *i, va_list args,
		int *total_count)
{
	int	print_count;

	if (format[*i] == '%' && format[*i + 1])
	{
		print_count = check_type(format, *i + 1, args);
		if (print_count == -1)
		{
			va_end(args);
			return (-1);
		}
		*total_count += print_count;
		*i += 2;
	}
	else
	{
		if (write(1, &format[*i], 1) == -1)
		{
			va_end(args);
			return (-1);
		}
		(*total_count)++;
		(*i)++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	static size_t	i;
	int				total_count;

	if (!format)
		return (-1);
	i = 0;
	total_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (handle_format_char(format, &i, args, &total_count) == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (total_count);
}
