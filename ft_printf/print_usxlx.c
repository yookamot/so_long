/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usxlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:44 by yookamot          #+#    #+#             */
/*   Updated: 2024/11/11 20:26:28 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list args)
{
	unsigned int	num;
	char			*str;
	int				count;

	num = va_arg(args, unsigned int);
	str = ft_utoa(num);
	if (!str)
		return (-1);
	count = write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

int	print_small_x(va_list args)
{
	unsigned int	num;
	int				count;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	count = print_hex((unsigned long)num, 0);
	return (count);
}

int	print_large_x(va_list args)
{
	unsigned int	num;
	int				count;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	count = print_hex((unsigned long)num, 1);
	return (count);
}
