/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:04:29 by yookamot          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:56 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i])
	{
		str[j] = str2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
