/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:04:42 by obarais           #+#    #+#             */
/*   Updated: 2025/02/07 10:39:32 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int i)
{
	int		j;
	int		k;
	char	*str;

	j = 0;
	k = i;
	while (k > 0)
	{
		k /= 10;
		j++;
	}
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	str[j] = '\0';
	while (j--)
	{
		str[j] = i % 10 + '0';
		i /= 10;
	}
	put_trmnation(str);
	return (str);
}
