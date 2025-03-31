/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:40:58 by yookamot          #+#    #+#             */
/*   Updated: 2024/11/11 20:57:34 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	tmp;
	size_t			len;

	len = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	print_hex(unsigned long num, int is_upper)
{
	int		count;
	char	digit;

	if (num == 0)
		return (0);
	count = print_hex(num / 16, is_upper);
	if (count == -1)
		return (-1);
	digit = num % 16;
	if (digit < 10)
		digit += '0';
	else
	{
		if (is_upper)
			digit += 'A' - 10;
		else
			digit += 'a' - 10;
	}
	return (count + write(1, &digit, 1));
}
